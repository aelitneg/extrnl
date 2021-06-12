import GhostContentAPI from '@tryghost/content-api';

const url = process.env.CMS_API_URL;
const key = process.env.CMS_API_KEY;

const api = new GhostContentAPI({
    url,
    key,
    version: 'v3',
});

export async function getPosts() {
    return await api.posts.browse();
}

export async function getPost(slug) {
    return await api.posts.read({ slug });
}
