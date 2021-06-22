import {
    Card,
    CardActionArea,
    CardContent,
    CardHeader,
    CardMedia,
} from '@material-ui/core';
import { makeStyles } from '@material-ui/core/styles';
import Image from 'next/image';
import Link from 'next/link';

import { renderDate } from '../lib/dateUtils';

const useStyles = makeStyles({
    media: {
        height: 300,
    },
});

const renderImage = (src) => {
    if (!src) {
        return null;
    }

    return <Image src={src} height={300} width={533} />;
};

export default function PostCard({ post }) {
    const classes = useStyles();
    return (
        <Link href={`/posts/${post.slug}`} passHref>
            <Card>
                <CardActionArea>
                    <CardMedia className={classes.media}>
                        {renderImage(post.feature_image)}
                    </CardMedia>
                    <CardHeader
                        title={post.title}
                        subheader={renderDate(post.published_at)}
                    />
                    <CardContent>{post.excerpt}</CardContent>
                </CardActionArea>
            </Card>
        </Link>
    );
}
