# _WSK_EXTENSION_CONTROL_OUT structure

## Description

The WSK_EXTENSION_CONTROL_OUT structure specifies the WSK subsystem's implementation of an extension
interface for a socket.

## Members

### `ProviderContext`

A pointer to a WSK subsystem-supplied context for the registration of the extension interface on a
socket. The WSK subsystem uses this context to track the state of the extension interface registration
for the socket. The contents of the WSK subsystem's registration context are opaque to the WSK
application. The WSK application passes this pointer to the WSK subsystem whenever it calls any of the
socket's extension interface functions that require the WSK subsystem's registration context.

### `ProviderDispatch`

A pointer to a structure that contains the WSK subsystem's dispatch table of functions for the
extension interface. The contents of the structure are specific to the extension interface.

## Remarks

The WSK subsystem fills in the contents of the WSK_EXTENSION_CONTROL_OUT structure when a WSK
application registers an extension interface. For more information about registering an extension
interface, see
[Registering an Extension
Interface](https://learn.microsoft.com/windows-hardware/drivers/network/registering-an-extension-interface).

## See also

[SIO_WSK_REGISTER_EXTENSION](https://learn.microsoft.com/windows-hardware/drivers/network/sio-wsk-register-extension)

[WSK_EXTENSION_CONTROL_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_extension_control_in)

[WskControlSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_socket)