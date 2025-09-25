# GetMailslotInfo function

## Description

Retrieves information about the specified mailslot.

## Parameters

### `hMailslot` [in]

A handle to a mailslot. The
[CreateMailslot](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createmailslota) function must create this handle.

### `lpMaxMessageSize` [out, optional]

The maximum message size, in bytes, allowed for this mailslot. This value can be greater than or equal to the value specified in the *cbMaxMsg* parameter of the
[CreateMailslot](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createmailslota) function that created the mailslot. This parameter can be **NULL**.

### `lpNextSize` [out, optional]

The size of the next message, in bytes. The following value has special meaning.

| Value | Meaning |
| --- | --- |
| **MAILSLOT_NO_MESSAGE**<br><br>((DWORD)-1) | There is no next message. |

This parameter can be **NULL**.

### `lpMessageCount` [out, optional]

The total number of messages waiting to be read, when the function returns. This parameter can be **NULL**.

### `lpReadTimeout` [out, optional]

The amount of time, in milliseconds, a read operation can wait for a message to be written to the mailslot before a time-out occurs. This parameter is filled in when the function returns. This parameter can be **NULL**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[CreateMailslot](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createmailslota)

[Mailslot Functions](https://learn.microsoft.com/windows/desktop/ipc/mailslot-functions)

[Mailslots Overview](https://learn.microsoft.com/windows/desktop/ipc/mailslots)

[SetMailslotInfo](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setmailslotinfo)