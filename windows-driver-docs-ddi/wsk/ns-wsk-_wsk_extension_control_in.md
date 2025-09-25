# _WSK_EXTENSION_CONTROL_IN structure

## Description

The WSK_EXTENSION_CONTROL_IN structure specifies a WSK application's implementation of an extension
interface for a socket.

## Members

### `NpiId`

A pointer to the
[Network Programming Interface
(NPI)](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) identifier that identifies the extension interface.

### `ClientContext`

A pointer to a WSK application-supplied context for the registration of the extension interface on
a socket. A WSK application uses this context to track the state of the extension interface registration
for the socket. The contents of the WSK application's registration context are opaque to the WSK
subsystem. The WSK subsystem passes this pointer to the WSK application whenever it calls any of the
socket's extension interface event callback functions that require the WSK application's registration
context.

### `ClientDispatch`

A pointer to a structure that contains the WSK application's dispatch table of event callback
functions for the extension interface. The contents of the structure are specific to the extension
interface.

## Remarks

A WSK application passes a pointer to a WSK_EXTENSION_CONTROL_IN structure to the WSK subsystem when
registering an extension interface. For more information about registering an extension interface, see
[Registering an Extension
Interface](https://learn.microsoft.com/windows-hardware/drivers/network/registering-an-extension-interface).

## See also

[SIO_WSK_REGISTER_EXTENSION](https://learn.microsoft.com/windows-hardware/drivers/network/sio-wsk-register-extension)

[WSK_EXTENSION_CONTROL_OUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_extension_control_out)

[WskControlSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_socket)