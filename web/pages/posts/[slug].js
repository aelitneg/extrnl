import { Typography } from '@material-ui/core';
import Image from 'next/image';
import { renderDate } from '../../lib/dateUtils';
import { getPost, getPosts } from '../../lib/posts';
import Layout from '../../components/Layout';

export default function Post({ post }) {
    return (
        <Layout>
            <Image width={533} height={300} src={post.feature_image} />
            <Typography variant="h4">{post.title}</Typography>
            <Typography variant="subtitle2">
                {renderDate(post.published_at)}
            </Typography>
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
