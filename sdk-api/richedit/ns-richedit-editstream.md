# EDITSTREAM structure

## Description

Contains information that an application passes to a rich edit control in a [EM_STREAMIN](https://learn.microsoft.com/windows/win32/controls/em-streamin) or [EM_STREAMOUT](https://learn.microsoft.com/windows/win32/controls/em-streamout) message. The rich edit control uses the information to transfer a stream of data into or out of the control.

## Members

### `dwCookie`

Type: **[DWORD_PTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies an application-defined value that the rich edit control passes to the [EditStreamCallback](https://learn.microsoft.com/windows/win32/api/richedit/nc-richedit-editstreamcallback) callback function specified by the **pfnCallback** member.

### `dwError`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Indicates the results of the stream-in (read) or stream-out (write) operation. A value of zero indicates no error. A nonzero value can be the return value of the [EditStreamCallback](https://learn.microsoft.com/windows/win32/api/richedit/nc-richedit-editstreamcallback) function or a code indicating that the control encountered an error.

### `pfnCallback`

Type: **EDITSTREAMCALLBACK**

Pointer to an [EditStreamCallback](https://learn.microsoft.com/windows/win32/api/richedit/nc-richedit-editstreamcallback) function, which is an application-defined function that the control calls to transfer data. The control calls the callback function repeatedly, transferring a portion of the data with each call.

## See also

[EM_STREAMIN](https://learn.microsoft.com/windows/win32/controls/em-streamin)

[EM_STREAMOUT](https://learn.microsoft.com/windows/win32/controls/em-streamout)

[EditStreamCallback](https://learn.microsoft.com/windows/win32/api/richedit/nc-richedit-editstreamcallback)

**Reference**