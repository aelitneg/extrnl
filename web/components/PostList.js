export default function PostList({ posts = [] }) {
    return <div>Post List</div>;
}

export async function getStaticProps() {
    const posts = [];

    return {
        posts,
    };
}
