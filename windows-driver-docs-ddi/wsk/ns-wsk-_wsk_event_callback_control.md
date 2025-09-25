# _WSK_EVENT_CALLBACK_CONTROL structure

## Description

The WSK_EVENT_CALLBACK_CONTROL structure specifies the information for enabling and disabling a
socket's event callback functions.

## Members

### `NpiId`

A pointer to a
[Network Programming Interface
(NPI)](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) identifier that specifies the NPI for the event callback function that is being enabled or
disabled. For enabling or disabling any of the standard WSK event callback functions, this member is a
pointer to the WSK NPI identifier, NPI_WSK_INTERFACE_ID. For enabling or disabling any event callback
functions for an extension interface, this member is a pointer to the NPI identifier for the extension
interface.

### `EventMask`

A ULONG value that contains a bitwise OR of event flags for the event callback functions that are
being enabled or disabled. For information about the event flags for the standard WSK event callback
functions, see
[SO_WSK_EVENT_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/network/so-wsk-event-callback).

## Remarks

A WSK application can enable any combination of event callback functions for a socket simultaneously
by setting the
**EventMask** member to a bitwise OR of the event flags for all of the event callback functions that
are being enabled. However, a WSK application must disable event callback functions individually by
setting the
**EventMask** member to a bitwise OR of the event flag for the event callback function that is being
disabled and the WSK_EVENT_DISABLE flag.

For more information about statically enabling certain event callback functions for all of the sockets
that are created by a WSK application, see
[WSK_SET_STATIC_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/network/wsk-set-static-event-callbacks).

For more information about enabling and disabling a socket's event callback functions, see
[Enabling and
Disabling Event Callback Functions](https://learn.microsoft.com/windows-hardware/drivers/network/enabling-and-disabling-event-callback-functions).

## See also

[SO_WSK_EVENT_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/network/so-wsk-event-callback)

[WSK_SET_STATIC_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/network/wsk-set-static-event-callbacks)

[WskControlClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_client)

[WskControlSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_socket)