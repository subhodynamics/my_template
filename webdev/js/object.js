
const mySym = Symbol("hello");

// object literals
const jsUser = { //in js object work as key value pairs
    name: "subhadeep",
    [mySym]: "nice pic",
    age: 22,
    email: "subhadeep@google.com",
    isLoggedIn: false,
}

// console.log(jsUser.name);
// console.log(jsUser["name"]); //this in backend is treated as string
// console.log(jsUser[mySym]);
// console.log(jsUser);
 
// singleton object
const tinder = new Object();

const winner = {
    name: "subhadeep",
    declare: function () {
        console.log(this.name);
    }
}

function winnerObject(name) { // object constructor
    this.name = name,
    this.declare = function () {
        console.log(this.name);
    }
}

winner.name = "rahul";

const another = new winnerObject ();
another.name = "ramen";

another.declare();
console.log(winner);
winner.declare();

// console.log(tinder);