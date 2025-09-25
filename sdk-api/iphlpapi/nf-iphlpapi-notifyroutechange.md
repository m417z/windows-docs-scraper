# NotifyRouteChange function

## Description

The
**NotifyRouteChange** function causes a notification to be sent to the caller whenever a change occurs in the IPv4 routing table.

## Parameters

### `Handle` [out]

A pointer to a **HANDLE** variable that receives a handle to use in asynchronous notification.

### `overlapped` [in]

A pointer to an
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure that notifies the caller of any changes in the routing table.

## Return value

If the function succeeds, the return value is NO_ERROR if the caller specifies **NULL** for the *Handle* and *overlapped* parameters. If the caller specifies non-**NULL** parameters, the return value for success is ERROR_IO_PENDING. If the function fails, use
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error.

| Return code | Description |
| --- | --- |
| **ERROR_CANCELLED** | The context is being deregistered, so the call was canceled immediately. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed. This error is returned if the both the *Handle* and *overlapped* parameters are not **NULL**, but the memory specified by the input parameters cannot be written by the calling process. This error is also returned if the client already has made a change notification request, so this duplicate request will fail. |
| **ERROR_NOT_ENOUGH_MEMORY** | There was insufficient memory available to complete the operation. |
| **ERROR_NOT_SUPPORTED** | This error is returned on versions of Windows where this function is not supported such as Windows 98/95 and Windows NT 4.0. |

## Remarks

The
**NotifyRouteChange** function may be called in two ways:

* Synchronous method
* Asynchronous method

If the caller specifies **NULL** for the *Handle* and *overlapped* parameters, the call to
**NotifyRouteChange** is synchronous and will block until an IPv4 routing table change occurs. In this case if a change occurs, the **NotifyRouteChange** function completes to indicate that a change has occurred.

If the **NotifyRouteChange** function is called synchronously, a notification will be sent on the next IPv4 routing change until the application terminates.

If the caller specifies a handle variable and an
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure, the caller can use the returned handle with the **OVERLAPPED** structure to receive asynchronous notification of IPv4 routing table changes. See the following topics for information about using the handle and
**OVERLAPPED** structure to receive notifications:

* [Synchronization and Overlapped Input and Output](https://learn.microsoft.com/windows/desktop/Sync/synchronization-and-overlapped-input-and-output)
* [GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus)
* [I/O Completion Ports](https://learn.microsoft.com/windows/desktop/FileIO/i-o-completion-ports)

If the application receives a notification and requires notification for the next change, then the **NotifyRouteChange** function must be called again.

The [CancelIPChangeNotify](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-cancelipchangenotify) function cancels notification of IP address and route changes previously requested with successful calls to the [NotifyAddrChange](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-notifyaddrchange) or **NotifyRouteChange** functions.

Once an application has been notified of a change, the application can then call the [GetIpForwardTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipforwardtable) or [GetIpForwardTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipforwardtable2) function to retrieve the IPv4 routing table to determine what has changed. If the application is notified and requires notification for the next change, then the **NotifyRouteChange** function must be called again.

If the **NotifyRouteChange** function is called asynchronously, a notification will be sent on the next IPv4 route change until either the application cancels the notification by calling the [CancelIPChangeNotify](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-cancelipchangenotify) function or the application terminates. If the application terminates, the system will automatically cancel the registration for the notification. It is still recommended that an application explicitly cancel any notification before it terminates.

Any registration for a notification does not persist across a system shut down or reboot.

On Windows Vista and later, the
[NotifyRouteChange2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifyroutechange2) function can be used to register to be notified for changes to the IPv6 routing table on the local computer.

#### Examples

The following example waits for a change to occur in the IP routing table.

```cpp
#include <winsock2.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <windows.h>

#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")

void main()
{
  OVERLAPPED overlap;
  DWORD ret;

  HANDLE hand = NULL;
  overlap.hEvent = WSACreateEvent();

  ret = NotifyRouteChange(&hand, &overlap);

  if (ret != NO_ERROR)
  {
    if (WSAGetLastError() != WSA_IO_PENDING)
    {
      printf("NotifyRouteChange error...%d\n", WSAGetLastError());
      return;
    }
  }

  if ( WaitForSingleObject(overlap.hEvent, INFINITE) == WAIT_OBJECT_0 )
    printf("Routing table changed..\n");
}

```

## See also

[CancelIPChangeNotify](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-cancelipchangenotify)

[GetIpForwardTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipforwardtable)

[GetIpForwardTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipforwardtable2)

[GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[NotifyAddrChange](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-notifyaddrchange)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)