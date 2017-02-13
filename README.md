# SignaturePassword
curses tutorial essentail for terminal manipulation: http://tldp.org/HOWTO/NCURSES-Programming-HOWTO/
This program in its initial build will be run through terminal. I want to put the speed of a users key speed at an equal importance to the contents of the password. With this software, I beleive I can detect if the user trying to login is the true user or a hacker. This would mean if someone is trying to break your password, they not only have to try all common password permutations but also all common sequences of key press delays.

Steps are as follow [This is for the first build]:
  1) Ask the user for a username
  2) Ask for a password
    2.1) using curses as characters are typed use the timer to track the delay between keys pressed
    2.2) store these times in the decrypted signature
  3) Reprompt for the password and see if the typig pattern matches (within a degree of difference) that of their initial typing speed
    3.1) If it matches it should be the owner of the account
    3.2) If not ... It is an hack! Close the gate!
    
Later goals include using Sha1 encryption and salting a users password with the serialized password signature (keystroke delay sequence) and using a simple database to check against and store the users averaged password signature
