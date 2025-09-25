# WskRegister function

## Description

The
**WskRegister** function registers a WSK application, given the application's WSK client
[Network Programming Interface
(NPI)](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface).

## Parameters

### `WskClientNpi` [in]

A pointer to the client NPI implemented by the WSK application.

### `WskRegistration` [out]

A pointer to a memory location that identifies a WSK application's registration instance. This
memory location will be initialized by the
**WskRegister** call and will be used by the other
[WSK registration functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/). The
WSK application should never change the contents of this memory location directly.

## Return value

**WskRegister** returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The registration succeeded. |
| **Other status codes** | The registration failed. |

## Remarks

A WSK client object can call this function multiple times, but a different
*WskRegistration* parameter must be used for each call in order to create multiple registration
instances.

For each call to
**WskRegister** that returns a success code, there must be exactly one corresponding
[WskDeregister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskderegister) call that uses the same
*WskRegistration* parameter that was passed to
**WskRegister**.

The block of memory pointed to by
*WskRegistration* must be kept allocated (must not be freed or go out of scope) as long as there are
outstanding calls to other
[WSK registration functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/).
Using the
**WskRegister** and
[WskDeregister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskderegister) functions is the preferred
method for registering and unregistering WSK applications. The
[Network Module Registrar](https://learn.microsoft.com/windows-hardware/drivers/network/network-module-registrar2) remains
available for compatibility.

For more information about attaching a WSK application to the WSK subsystem, see
[Registering a Winsock Kernel
Application](https://learn.microsoft.com/windows-hardware/drivers/network/registering-a-winsock-kernel-application).

## See also

[WSK_CLIENT_NPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_npi)

[WSK_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_registration)

[WskDeregister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskderegister)