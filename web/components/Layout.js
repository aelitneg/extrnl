import {
    AppBar,
    Box,
    Container,
    CssBaseline,
    Toolbar,
    Typography,
} from '@material-ui/core';
import { createMuiTheme, makeStyles } from '@material-ui/core/styles';
import { ThemeProvider } from '@material-ui/styles';

import Head from 'next/head';
import Link from 'next/link';

const appBarTheme = createMuiTheme({
    palette: {
        primary: {
            main: '#cfcfcf',
        },
    },
});
const theme = createMuiTheme({
    palette: {
        primary: {
            main: '#197de6',
        },
        secondary: {
            main: '#17e27d',
        },
    },
});

const useStyles = makeStyles({
    logo: {
        textDecoration: 'none',
        cursor: 'pointer',
    },
});

export default function Layout({ children }) {
    const classes = useStyles();

    return (
        <div>
            <Head>
                <title>extrnl.io</title>
                <meta
                    name="description"
                    content="Extrnl lets you listen to audio from your DAW on a mobile device in real time."
                />
                <link rel="icon" href="/favicon.ico" />
                <link
                    rel="stylesheet"
                    href="https://fonts.googleapis.com/css?family=Roboto:300,400,500,700&display=swap"
                />
            </Head>
            <CssBaseline />
            <ThemeProvider theme={appBarTheme}>
                <AppBar position="static">
                    <Container maxWidth="sm">
                        <Toolbar disableGutters>
                            <Link href={'/'} passHref>
                                <Typography
                                    variant="h5"
                                    className={classes.logo}
                                >
                                    extrnl
                                </Typography>
                            </Link>
                        </Toolbar>
                    </Container>
                </AppBar>
            </ThemeProvider>
            <ThemeProvider theme={theme}>
                <Container maxWidth="sm">
                    <Box mt={4}>{children}</Box>
                </Container>
            </ThemeProvider>
        </div>
    );
}
