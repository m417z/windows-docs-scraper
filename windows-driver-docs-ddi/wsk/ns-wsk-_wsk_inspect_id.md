# _WSK_INSPECT_ID structure

## Description

The WSK_INSPECT_ID structure specifies an identifier for an incoming connection request on a
listening socket.

## Members

### `Key`

A key that is assigned to the incoming connection request.

### `SerialNumber`

A serial number that is assigned to the incoming connection request.

## Remarks

The WSK subsystem passes a pointer to a WSK_INSPECT_ID structure to a WSK application's
[WskInspectEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_inspect_event) event callback function
whenever an incoming connection request arrives on a listening socket that has conditional accept mode
enabled. The contents of the WSK_INSPECT_ID structure uniquely identify the incoming connection
request.

If the WSK application returns
**WskInspectPend** from a call to its
*WskInspectEvent* event callback function, the application must first copy the
contents of the WSK_INSPECT_ID structure that is provided by the WSK subsystem into its own
WSK_INSPECT_ID structure. The WSK application then passes a pointer to its WSK_INSPECT_ID structure to
the
[WskInspectComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_inspect_complete) function when it
completes the inspection.

If the incoming connection request is dropped by the remote system while an inspect operation is
pending, the WSK subsystem calls the WSK application's
[WskAbortEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_abort_event) event callback function with a
pointer to a WSK_INSPECT_ID structure that identifies the dropped request. The WSK application uses the
contents of this WSK_INSPECT_ID structure to determine which inspection of an incoming connection request
should be terminated. The WSK application should compare the contents of the WSK_INSPECT_ID structures to
check for a match. The actual values of the structure members are irrelevant.

A WSK application can enable conditional accept mode on a listening socket by enabling the
[SO_CONDITIONAL_ACCEPT](https://learn.microsoft.com/windows-hardware/drivers/network/so-conditional-accept) socket option.
For more information about conditionally accepting incoming connections, see
[Listening for and
Accepting Incoming Connections](https://learn.microsoft.com/windows-hardware/drivers/network/listening-for-and-accepting-incoming-connections).

## See also

[SO_CONDITIONAL_ACCEPT](https://learn.microsoft.com/windows-hardware/drivers/network/so-conditional-accept)

[WskAbortEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_abort_event)

[WskInspectComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_inspect_complete)

[WskInspectEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_inspect_event)