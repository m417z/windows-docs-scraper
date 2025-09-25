# SetMailslotInfo function

## Description

Sets the time-out value used by the specified mailslot for a read operation.

## Parameters

### `hMailslot` [in]

A handle to a mailslot. The
[CreateMailslot](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createmailslota) function must create this handle.

### `lReadTimeout` [in]

The time a read operation can wait for a message to be written to the mailslot before a time-out occurs, in milliseconds. The following values have special meanings.

| Value | Meaning |
| --- | --- |
| 0 | Returns immediately if no message is present. (The system does not treat an immediate return as an error.) |
| **MAILSLOT_WAIT_FOREVER**<br><br>((DWORD)-1) | Waits forever for a message. |

This time-out value applies to all subsequent read operations and to all inherited mailslot handles.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The initial time-out value used by a mailslot for a read operation is typically set by
[CreateMailslot](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createmailslota) when the mailslot is created.

## See also

[CreateMailslot](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createmailslota)

[GetMailslotInfo](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getmailslotinfo)

[Mailslot Functions](https://learn.microsoft.com/windows/desktop/ipc/mailslot-functions)

[Mailslots Overview](https://learn.microsoft.com/windows/desktop/ipc/mailslots)