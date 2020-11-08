#### Server Side:
```
1. Create two string variables for filenames and buffer.
2. Create three integer variables for request, response and file operations.
3. Create two FIFO files for response and request using the function and pass parameters.
4. Pass the request from the client side as any file to the FIFO.
5. Using file operation variables open the file in read mode.
6. Check the file for any characters contained in it if not present print file not found, else print the content the file by passing the content of file to the buffer.
7. print request sent message.
8. Unlink the request and response file descriptors.
```
#### Client Side:
```
1. Create two string variables for filename and buffer.
2. Create two integer variables for request file descriptor and response descriptors.
3. Using the request file descriptors open the fifo file which has request queue.
4. Pass the name of file to the filename variable.
5. Output the contained file name from server side.
6. Close the request and response descriptors using functions.
```
