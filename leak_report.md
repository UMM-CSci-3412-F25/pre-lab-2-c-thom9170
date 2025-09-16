# Leak report

Inside the check-whitespace.c file the leak is related to the strip call. It was never
released as it needed to allocate memory to create the new string of content but there was also the issue of no allocation when the string was empty. this was fixed quite easily by a if statement

Inside the tester file it calls the function scrip and clean but the strip for testing is
 never releasing the memory when finished casuing memory leaks when finished. 
First we would want to create a
"Free allocation memory" function seen at the top of the test file to reduce repeating this everytime we need to clean for it. Since there was a lot of testers to apply this, this
a effecient addition. Next we apply this to everywhere the strip function is called to plug those leaks 
