import { Box, Typography } from '@material-ui/core';
import Layout from '../components/Layout';
import PostCard from '../components/PostCard';
import { getPosts } from '../lib/posts';

const renderPosts = (posts) => {
    return posts.map((p) => (
        <Box my={2} key={p.id}>
            <PostCard post={p} />
        </Box>
    ));
};
export default function Home({ posts }) {
    return (
        <Layout>
            <Typography variant="h4">Project updates</Typography>
            {renderPosts(posts)}
        </Layout>
    );
}

export async function getStaticProps() {
    const posts = await getPosts();

    return {
        props: { posts },
    };
}
