import { Box, Typography } from '@material-ui/core';
import { makeStyles } from '@material-ui/core/styles';
import { renderDate } from '../../lib/dateUtils';
import { getPost, getPosts } from '../../lib/posts';
import Layout from '../../components/Layout';

const useStyles = makeStyles({
    image: {
        borderRadius: 4,
    },
});

export default function Post({ post }) {
    const classes = useStyles();

    return (
        <Layout>
            <img
                className={classes.image}
                width={'100%'}
                src={post.feature_image}
            />
            <Box mt={2} mb={4}>
                <Typography variant="h4">{post.title}</Typography>
                <Typography variant="subtitle2">
                    {renderDate(post.published_at)}
                </Typography>
            </Box>
            <span dangerouslySetInnerHTML={{ __html: post.html }} />
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
