import {
    AppBar,
    Box,
    Container,
    CssBaseline,
    Toolbar,
    Typography,
} from '@material-ui/core';
import { createMuiTheme } from '@material-ui/core/styles';
import { ThemeProvider } from '@material-ui/styles';

import Head from 'next/head';

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

export default function Layout({ children }) {
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
                            <Typography variant="h5">extrnl</Typography>
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