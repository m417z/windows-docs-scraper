# Netbios function

## Description

[[Netbios](https://learn.microsoft.com/previous-versions/windows/desktop/netbios/portal) is not supported on Windows Vista, Windows Server 2008, and subsequent versions of the operating system]

The **Netbios** function interprets and executes the specified network control block (NCB).

The **Netbios** function is provided primarily for applications that were written for the NetBIOS interface and need to be ported to Windows. Applications not requiring compatibility with NetBIOS should use other interfaces, such as Windows Sockets, mailslots, named pipes, RPC, or distributed COM to accomplish tasks similar to those supported by NetBIOS. These other interfaces are more flexible and portable.

## Parameters

### `pncb`

A pointer to an [NCB](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-ncb) structure that describes the network control block.

## Return value

For synchronous requests, the return value is the return code in the [NCB](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-ncb) structure. That value is also returned in the **ncb_retcode** member of the **NCB** structure.

For asynchronous requests, there are the following possibilities:

* If the asynchronous command has already completed when **Netbios** returns to its caller, the return value is the return code of the NCB structure, just as if it were a synchronous [NCB](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-ncb) structure.
* If the asynchronous command is still pending when **Netbios** returns to its caller, the return value is zero.

If the address specified by the pncb parameter is invalid, the return value is **NRC_BADNCB**.

If the buffer length specified in the **ncb_length** member of the [NCB](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-ncb) structure is incorrect, or if the buffer specified by the **ncb_retcode** member is protected from write operations, the return value is **NRC_BUFLEN**.

## Remarks

When an asynchronous network control block finishes and the **ncb_post** member is nonzero, the routine specified in **ncb_post** is called with a single parameter. This parameter contains a pointer to an [NCB](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-ncb) structure, the network control block.

The [NCB](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-ncb) structure contains a handle of an event (the **ncb_event** member). The system sets the event to the nonsignaled state when an asynchronous NetBIOS command is accepted, and sets the event to the signaled state when the asynchronous NetBIOS command is completed. Only manual reset events should be used for synchronization. A specified event should not be associated with more than one active asynchronous NetBIOS command.

Using **ncb_event** to submit asynchronous requests requires fewer system resources than using **ncb_post**. Also, when **ncb_event** is nonzero, the pending request is canceled if the thread terminates before the request is processed. This is not true for requests sent by using **ncb_post**.

## See also

[NCB](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-ncb)