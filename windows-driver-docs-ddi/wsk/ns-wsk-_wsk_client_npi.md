# _WSK_CLIENT_NPI structure

## Description

The WSK_CLIENT_NPI structure identifies a
[Network Programming Interface
(NPI)](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) implemented by a WSK client.

## Members

### `ClientContext`

A pointer to the context for the WSK application's binding to the WSK subsystem.

### `Dispatch`

A pointer to a constant
[WSK_CLIENT_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_dispatch) structure.

## Remarks

For more information about attaching a WSK application to the WSK subsystem, see
[Registering a Winsock Kernel
Application](https://learn.microsoft.com/windows-hardware/drivers/network/registering-a-winsock-kernel-application).

## See also

[WSK_CLIENT_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_dispatch)