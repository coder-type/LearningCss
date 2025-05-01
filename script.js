const add = function(a, b) {
    return a + b;
};

function handleClick() {
    const first = document.querySelector('.first').value;
    const second = document.querySelector('.second').value;

    if (first === "" || second === "") {
        document.getElementById('result').textContent = "Please enter both numbers.";
        return;
    }

    const sum = add(Number(first), Number(second));
    document.getElementById('result').textContent = "The sum is: " + sum;
}
