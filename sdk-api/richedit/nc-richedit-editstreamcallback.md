# EDITSTREAMCALLBACK callback function

## Description

The *EditStreamCallback* function is an application defined callback function used with the [EM_STREAMIN](https://learn.microsoft.com/windows/win32/controls/em-streamin) and [EM_STREAMOUT](https://learn.microsoft.com/windows/win32/controls/em-streamout) messages. It is used to transfer a stream of data into or out of a rich edit control. The
**EDITSTREAMCALLBACK** type defines a pointer to this callback function. *EditStreamCallback* is a placeholder for the application-defined function name.

## Parameters

### `dwCookie` [in]

Type: **[DWORD_PTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value of the
*dwCookie* member of the [EDITSTREAM](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-editstream) structure. The application specifies this value when it sends the [EM_STREAMIN](https://learn.microsoft.com/windows/win32/controls/em-streamin) or [EM_STREAMOUT](https://learn.microsoft.com/windows/win32/controls/em-streamout) message.

### `pbBuff` [in]

Type: **[LPBYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a buffer to read from or write to. For a stream-in (read) operation, the callback function fills this buffer with data to transfer into the rich edit control. For a stream-out (write) operation, the buffer contains data from the control that the callback function writes to some storage.

### `cb` [in]

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of bytes to read or write.

### `pcb` [in]

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to a variable that the callback function sets to the number of bytes actually read or written.

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The callback function returns zero to indicate success.

The callback function returns a nonzero value to indicate an error. If an error occurs, the read or write operation ends and the rich edit control discards any data in the
*pbBuff* buffer. If the callback function returns a nonzero value, the rich edit control uses the
*dwError* member of the [EDITSTREAM](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-editstream) structure to pass the value back to the application.

## Remarks

When you send the [EM_STREAMIN](https://learn.microsoft.com/windows/win32/controls/em-streamin) or [EM_STREAMOUT](https://learn.microsoft.com/windows/win32/controls/em-streamout) message to a rich edit control, the
*pfnCallback* member of the [EDITSTREAM](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-editstream) structure specifies a pointer to an *EditStreamCallback* function. The rich edit control repeatedly calls the function to transfer a stream of data into or out of the control.

When you send the [EM_STREAMIN](https://learn.microsoft.com/windows/win32/controls/em-streamin) or [EM_STREAMOUT](https://learn.microsoft.com/windows/win32/controls/em-streamout) message, you specify a value for the
*dwCookie* member of the [EDITSTREAM](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-editstream) structure. The rich edit control uses the
*dwCookie* parameter to pass this value to your *EditStreamCallback* function. For example, you might use
*dwCookie* to pass a handle to an open file. The callback function can then use the
*dwCookie* handle to read from or write to the file.

The control calls the callback function repeatedly, transferring a portion of the data with each call. The control continues to call the callback function until one of the following conditions occurs:

* The callback function returns a nonzero value.
* The callback function returns zero in the *
  *pcb* parameter.
* An error occurs that prevents the rich edit control from transferring data into or out of itself. Examples are out-of-memory situations, failure of a system function, or an invalid character in the read buffer.
* For a stream-in operation, the RTF code contains data specifying the end of an RTF block.
* For a stream-in operation on a single-line edit control, the callback reads in an end-of-paragraph character (CR, LF, VT, LS, or PS).

## See also

[EDITSTREAM](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-editstream)

[EM_STREAMIN](https://learn.microsoft.com/windows/win32/controls/em-streamin)

[EM_STREAMOUT](https://learn.microsoft.com/windows/win32/controls/em-streamout)

**Reference**