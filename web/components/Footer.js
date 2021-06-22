import { Box, Container, Grid, Link, Typography } from '@material-ui/core';
import GitHubIcon from '@material-ui/icons/GitHub';
import { makeStyles } from '@material-ui/core/styles';
import { getYear } from '../lib/dateUtils';

const useStyles = makeStyles((theme) => ({
    root: {
        backgroundColor: theme.palette.primary.main,
        flexGrow: 1,
    },
    item: {
        textAlign: 'center',
        backgroundColor: 'none',
    },
    hoverGlow: {
        transition: 'color 300ms cubic-bezier(0.4, 0, 0.2, 1) 0ms',
        '&:hover': {
            color: theme.palette.secondary.main,
        },
    },
}));

export default function Footer() {
    const classes = useStyles();

    return (
        <Container className={classes.root}>
            <Grid container justify="center" className={classes.root}>
                <Grid item xs={12} className={classes.item}>
                    <Box p={4}>
                        <Link
                            href="https://github.com/agentile1990/extrnl"
                            target="_blank"
                            rel="noopener"
                            color="inherit"
                        >
                            <GitHubIcon
                                fontSize="large"
                                className={classes.hoverGlow}
                            />
                        </Link>
                        <Typography variant="body2">
                            ©&nbsp;
                            <Link
                                href="https://agentile.dev"
                                target="_blank"
                                rel="noopener"
                                color="inherit"
                                className={classes.hoverGlow}
                            >
                                Andrew Gentile
                            </Link>
                            &nbsp;
                            {getYear()}
                        </Typography>
                    </Box>
                </Grid>
            </Grid>
        </Container>
    );
}
