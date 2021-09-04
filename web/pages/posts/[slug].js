import { useEffect } from 'react';
import { Box, Typography } from '@material-ui/core';
import { makeStyles } from '@material-ui/core/styles';
import { renderDate } from '../../lib/dateUtils';
import { getPost, getPosts } from '../../lib/posts';
import Layout from '../../components/Layout';

/**
 * Image Gallery Support from Casper Ghost Theme
 * https://github.com/TryGhost/Casper/blob/main/assets/js/gallery-card.js
 */
const resizeImagesInGalleries = () => {
    const images = document.querySelectorAll('.kg-gallery-image img');
    images.forEach(function (image) {
        const container = image.closest('.kg-gallery-image');
        const width = image.attributes.width.value;
        const height = image.attributes.height.value;
        const ratio = width / height;
        container.style.flex = ratio + ' 1 0%';
    });
};

const useStyles = makeStyles({
    image: {
        display: 'block',
        marginLeft: 'auto',
        marginRight: 'auto',
        borderRadius: 4,
        maxHeight: 400,
    },
    content: {
        '& img': {
            display: 'block',
            marginLeft: 'auto',
            marginRight: 'auto',
            borderRadius: 4,
        },
    },
});

export default function Post({ post }) {
    const classes = useStyles();

    useEffect(() => resizeImagesInGalleries());

    return (
        <Layout>
            <img className={classes.image} src={post.feature_image} />
            <Box mt={2} mb={4}>
                <Typography variant="h4">{post.title}</Typography>
                <Typography variant="subtitle2">
                    {renderDate(post.published_at)}
                </Typography>
            </Box>
            <span
                className={classes.content}
                dangerouslySetInnerHTML={{ __html: post.html }}
            />
        </Layout>
    );
}

export async function getStaticPaths() {
    const posts = await getPosts();

    const paths = posts.map((post) => ({
        params: { slug: post.slug },
    }));

    return { paths, fallback: false };
}

export async function getStaticProps({ params }) {
    const post = await getPost(params.slug);

    return {
        props: { post },
    };
}
