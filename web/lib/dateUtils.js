export const Months = Object.freeze([
    'Jan',
    'Feb',
    'Mar',
    'Apr',
    'May',
    'Jun',
    'Jul',
    'Aug',
    'Sep',
    'Oct',
    'Nov',
    'Dec',
]);

export const renderDate = (date) => {
    const d = new Date(date);
    return `${d.getDate()} ${Months[d.getMonth()]} ${d.getFullYear()}`;
};

export const getYear = () => {
    const d = new Date();
    return `${d.getFullYear()}`;
};
