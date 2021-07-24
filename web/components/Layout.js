import { Box, Container, CssBaseline } from '@material-ui/core';
import { makeStyles } from '@material-ui/core/styles';
import { createMuiTheme } from '@material-ui/core/styles';
import { ThemeProvider } from '@material-ui/styles';
import Head from 'next/head';

import Header from './Header';
import Footer from './Footer';

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
    fullHeight: {
        display: 'flex',
        minHeight: '100vh',
        flexDirection: 'column',
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
            <Box className={classes.fullHeight}>
                <Header />
                <ThemeProvider theme={theme}>
                    <Box flex={1}>
                        <Container maxWidth="md">
                            <Box mt={4} mb={4}>
                                {children}
                            </Box>
                        </Container>
                    </Box>
                    <Footer />
                </ThemeProvider>
            </Box>
        </div>
    );
}
