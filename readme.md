# Ottendorf Cipher Encryption

Ottendorf Password Encryption is a password protection service that securely ties a typical password to a random number series and a particular book.
Both the number series and the book are useless independently, but combined give us our password.
This service would be useful for individuals who must carry multiple secure passwords, or have a need to write them down.

For a password of n characters, a number series of 3*n is assigned to it, corresponding to a particular book.
For each set of 3 numbers in the series: (a1,b1,c1)
A1 corresponds to the page number
B1 corresponds to the line number
C1 corresponds to the character number in that particular line
Hence every 3 numbers in the series gives us 1 character of our password


