# EnableRouter function

## Description

The
**EnableRouter** function turns on IPv4 forwarding on the local computer.
**EnableRouter** also increments a reference count that tracks the number of requests to enable IPv4 forwarding.

## Parameters

### `pHandle`

A pointer to a handle. This parameter is currently unused.

### `pOverlapped`

A pointer to an
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure. Except for the **hEvent** member, all members of this structure should be set to zero. The **hEvent** member should contain a handle to a valid event object. Use the
[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa) function to create this event object.

## Return value

If the **EnableRouter** function succeeds, the return value is ERROR_IO_PENDING.

If the function fails, use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One of the parameters is invalid. This error is returned if the *pOverlapped* parameter is **NULL**. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **EnableRouter** function is specific to IPv4 forwarding. If the process that calls
**EnableRouter** terminates without calling
[UnenableRouter](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-unenablerouter), the system decrements the reference count that tracks the number of requests to enable IPv4 forwarding as though the process had called
**UnenableRouter**.

## See also

[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)

[UnenableRouter](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-unenablerouter)