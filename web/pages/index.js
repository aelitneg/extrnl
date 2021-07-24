import { Box, Card, CardContent, Typography } from '@material-ui/core';
import { makeStyles } from '@material-ui/core/styles';
import Layout from '../components/Layout';
import PostCard from '../components/PostCard';
import { getPost, getPosts } from '../lib/posts';

const useStyle = makeStyles((theme) => ({
    card: {
        backgroundColor: theme.palette.primary.main,
        color: 'white',
    },
}));

const renderPosts = (posts) => {
    return posts.map((p) => (
        <Box my={4} key={p.id}>
            <PostCard post={p} />
        </Box>
    ));
};

export default function Home({ content, posts }) {
    const classes = useStyle();

    return (
        <Layout>
            <Typography variant="h2">{content.title}</Typography>
            <Box mt={2} mb={6}>
                <Card variant="outlined" className={classes.card}>
                    <CardContent>
                        <span
                            dangerouslySetInnerHTML={{ __html: content.html }}
                        />
                    </CardContent>
                </Card>
            </Box>
            <Typography variant="h4">Project updates</Typography>
            {renderPosts(posts)}
        </Layout>
    );
}

export async function getStaticProps() {
    const [content, posts] = await Promise.all([
        getPost('extrnl-home'),
        getPosts(),
    ]);

    return {
        props: { content, posts },
    };
}
