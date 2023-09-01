function Book (title, author, pages, read) {
    this.title = title,
    this.author = author,
    this.pages = pages,
    this.read = (read)?"read":"not read yet",
    this.info = function () {
        // str = "";
        // str += (`${title} by ${author}, ${pages} pages,`,(read)?"read":"not read yet");
        // return str;

        str  = this.title + " by " + this.author + " ," + this.pages + " pages, " + this.read; 
        return str;
    }
}

const mybook = new Book('nice book', 'no one', 253, false);
console.log(mybook.info());

const book2 = new Book('another boook', 'ram', 245, true);
// book2.info()
console.log(book2.info());
