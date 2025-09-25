## Description

The **DbgPrompt** routine displays a caller-specified user prompt string on the kernel debugger's display device and obtains a user response string.

## Parameters

### `Prompt` [in]

A pointer to a NULL-terminated constant character string that the debugger will display as a user prompt. The maximum size of this string is 512 characters.

### `Response` [out]

A pointer to a character array buffer that receives the user's response, including a terminating newline character. The maximum size of this buffer is 512 characters.

### `Length`

The size, in characters, of the buffer that receives the user's response. This size is the maximum number of characters that the routine will return.

## Return value

**DbgPrompt** returns the number of characters that the *Response* buffer received, including the terminating newline character. **DbgPrompt** returns zero if it receives no characters.

## Remarks

The **DbgPrompt** routine displays the specified prompt string on the kernel debugger's display device and then reads a line of user input text.

After **DbgPrompt** returns, the *Response* buffer contains the user's response, including the terminating newline character. The user response string is not NULL-terminated.

The following code example asks if the user wants to continue and accepts the letter "y" for yes and the letter "n" for no.

```cpp
CHAR Response[2];
BOOLEAN Continue = FALSE;
ULONG CharCount;
for (;;) {
 CharCount = DbgPrompt(
  "Do you want to continue? (Type y or n, then type Enter.) ",
  Response,
  sizeof(Response)
  );

 if (CharCount == 2) {
 if (Response[0] == 'y') {
  Continue = TRUE;
  break;
  } else if (Response[0] == 'n') {
  break;
     }
    }

    //
    // Incorrect response. Display the prompt again.
    //
}
```