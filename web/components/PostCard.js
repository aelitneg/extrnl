import {
    Box,
    Card,
    CardActionArea,
    CardContent,
    Grid,
    Typography,
} from '@material-ui/core';
import { makeStyles } from '@material-ui/core/styles';
import Link from 'next/link';

import { renderDate } from '../lib/dateUtils';

const useStyles = makeStyles({
    media: {
        display: 'block',
        marginLeft: 'auto',
        marginRight: 'auto',
        maxWidth: '100%',
        maxHeight: 150,
        borderRadius: 4,
    },
});

export default function PostCard({ post }) {
    const classes = useStyles();

    return (
        <Link href={`/posts/${post.slug}`} passHref>
            <Card>
                <CardActionArea>
                    <CardContent>
                        <Grid container spacing={3}>
                            <Grid
                                item
                                sm={3}
                                xs={12}
                                justify="center"
                                alignContent="center"
                                alignItems="center"
                            >
                                <img
                                    className={classes.media}
                                    src={post.feature_image}
                                />
                            </Grid>
                            <Grid item sm={9} xs={12}>
                                <Box>
                                    <Typography variant="h5">
                                        {post.title}
                                    </Typography>
                                    <Typography
                                        variant="subtitle1"
                                        color="textSecondary"
                                    >
                                        {renderDate(post.published_at)}
                                    </Typography>
                                </Box>
                                <Box>{post.excerpt}</Box>
                            </Grid>
                        </Grid>
                    </CardContent>
                </CardActionArea>
            </Card>
        </Link>
    );
}
