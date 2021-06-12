import { AppBar, Container, Toolbar, Typography } from '@material-ui/core';
import { createMuiTheme, makeStyles } from '@material-ui/core/styles';
import { ThemeProvider } from '@material-ui/styles';
import Link from 'next/link';

const theme = createMuiTheme({
    palette: {
        primary: {
            main: '#cfcfcf',
        },
    },
});

const useStyles = makeStyles({
    logo: {
        textDecoration: 'none',
        cursor: 'pointer',
    },
});

export default function Header() {
    const classes = useStyles();

    return (
        <ThemeProvider theme={theme}>
            <AppBar position="static">
                <Container maxWidth="sm">
                    <Toolbar disableGutters>
                        <Link href={'/'} passHref>
                            <Typography variant="h5" className={classes.logo}>
                                extrnl
                            </Typography>
                        </Link>
                    </Toolbar>
                </Container>
            </AppBar>
        </ThemeProvider>
    );
}
