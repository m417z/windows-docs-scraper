# UnenableRouter function

## Description

The
**UnenableRouter** function decrements the reference count that tracks the number of requests to enable IPv4 forwarding. When this reference count reaches zero,
**UnenableRouter** turns off IPv4 forwarding on the local computer.

## Parameters

### `pOverlapped`

A pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure. This structure should be the same as the one used in the call to
the [EnableRouter](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-enablerouter) function.

### `lpdwEnableCount` [out, optional]

An optional pointer to a **DWORD** variable. This variable receives the number of references remaining.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, use
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error.

## Remarks

The **UnenableRouter** function is specific to IPv4 forwarding. Each call that a process makes to
**UnenableRouter** must correspond to a previous call to
[EnableRouter](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-enablerouter) by the same process. The system returns an error on extraneous calls to
**UnenableRouter**. As a result, a given process is not able to decrement the reference count that tracks the number of requests for enabling IPv4 forwarding for another process. Also, if IPv4 forwarding was enabled by a given process, it cannot be disabled by a different process.

It is not possible to accurately determine the reference count that tracks the number of requests for enabling IPv4 forwarding since there might be other outstanding [EnableRouter](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-enablerouter) requests.
So the value returned for the *lpdwEnableCount* parameter is always a large count equal to ULONG_MAX/2.

If the process that calls
[EnableRouter](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-enablerouter) terminates without calling
**UnenableRouter**, the system decrements the reference count that tracks requests to enable IPv4 forwarding as though the process had called
**UnenableRouter**.

After calling the
**UnenableRouter**, use the
[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) call to close the handle to the event object in the
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure.

## See also

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[EnableRouter](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-enablerouter)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)