# WTSSendMessageW function

## Description

Displays a message box on the client desktop of a
specified Remote Desktop Services session.

## Parameters

### `hServer` [in]

A handle to an RD Session Host server. Specify a handle opened by the
[WTSOpenServer](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenservera) function, or specify
**WTS_CURRENT_SERVER_HANDLE** to indicate the RD Session Host server on which your application
is running.

### `SessionId` [in]

A Remote Desktop Services session identifier. To indicate the current session, specify
**WTS_CURRENT_SESSION**. You can use the
[WTSEnumerateSessions](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsenumeratesessionsa) function to retrieve
the identifiers of all sessions on a specified RD Session Host server.

To send a message to another user's session, you need to have the Message permission. For more
information, see [Remote Desktop Services
Permissions](https://learn.microsoft.com/windows/desktop/TermServ/terminal-services-permissions). To modify permissions on a session, use the Remote Desktop Services Configuration administrative
tool.

### `pTitle` [in]

A pointer to a null-terminated string for the title bar of the message box.

### `TitleLength` [in]

The length, in bytes, of the title bar string.

### `pMessage` [in]

A pointer to a null-terminated string that contains the message to display.

### `MessageLength` [in]

The length, in bytes, of the message string.

### `Style` [in]

The contents and behavior of the message box. This value is typically
**MB_OK**. For a complete list of values, see the *uType*
parameter of the [MessageBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-messagebox) function.

### `Timeout` [in]

The time, in seconds, that the **WTSSendMessage** function waits for
the user's response. If the user does not respond within the time-out interval, the
*pResponse* parameter returns **IDTIMEOUT**. If the
*Timeout* parameter is zero, **WTSSendMessage** waits
indefinitely for the user to respond.

### `pResponse` [out]

A pointer to a variable that receives the user's response, which can be one of the following values.

#### IDABORT (3)

**Abort**

#### IDCANCEL (2)

**Cancel**

#### IDCONTINUE (11)

**Continue**

#### IDIGNORE (5)

**Ignore**

#### IDNO (7)

**No**

#### IDOK (1)

**OK**

#### IDRETRY (4)

**Retry**

#### IDTRYAGAIN (10)

**Try Again**

#### IDYES (6)

**Yes**

#### IDASYNC (32001 (0x7D01))

The *bWait* parameter was **FALSE**, so the function
returned without waiting for a response.

#### IDTIMEOUT (32000 (0x7D00))

The *bWait* parameter was **TRUE** and the time-out
interval elapsed.

### `bWait` [in]

If **TRUE**, **WTSSendMessage** does not return until
the user responds or the time-out interval elapses. If the *Timeout* parameter is zero,
the function does not return until the user responds.

If **FALSE**, the function returns immediately and the
*pResponse* parameter returns **IDASYNC**. Use this method for
simple information messages (such as print job–notification messages) that do not need to return the
user's response to the calling program.

##### - pResponse.IDABORT (3)

**Abort**

##### - pResponse.IDASYNC (32001 (0x7D01))

The *bWait* parameter was **FALSE**, so the function
returned without waiting for a response.

##### - pResponse.IDCANCEL (2)

**Cancel**

##### - pResponse.IDCONTINUE (11)

**Continue**

##### - pResponse.IDIGNORE (5)

**Ignore**

##### - pResponse.IDNO (7)

**No**

##### - pResponse.IDOK (1)

**OK**

##### - pResponse.IDRETRY (4)

**Retry**

##### - pResponse.IDTIMEOUT (32000 (0x7D00))

The *bWait* parameter was **TRUE** and the time-out
interval elapsed.

##### - pResponse.IDTRYAGAIN (10)

**Try Again**

##### - pResponse.IDYES (6)

**Yes**

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[MessageBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-messagebox)

## Remarks

> [!NOTE]
> The wtsapi32.h header defines WTSSendMessage as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).