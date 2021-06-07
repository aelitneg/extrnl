import { Typography } from '@material-ui/core';
import Layout from '../components/Layout';
import PostList from '../components/PostList';

export default function Home() {
    return (
        <Layout>
            <Typography variant="h6">Project updates</Typography>
            <PostList />
        </Layout>
    );
}
