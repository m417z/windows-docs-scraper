# WskDeregister function

## Description

The
**WskDeregister** function unregisters a WSK application's registration instance that was previously
created by
[WskRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskregister).

## Parameters

### `WskRegistration` [in]

A pointer to the memory location initialized by
[WskRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskregister) that identifies a WSK
application's registration instance.

## Remarks

For each call to
[WskRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskregister) that returns a success code, there
must be exactly one corresponding
**WskDeregister** call that uses the same
*WskRegistration* parameter that was passed to
**WskRegister**.

**WskDeregister** will wait to return until all of the following have completed:

* All captured instances of the provider NPI are released.
* Any outstanding calls to functions pointed to by
  [WSK_PROVIDER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_dispatch) members have
  returned.
* All sockets are closed.

For more information about attaching a WSK application to the WSK subsystem, see
[Registering a Winsock Kernel
Application](https://learn.microsoft.com/windows-hardware/drivers/network/registering-a-winsock-kernel-application).

## See also

[WSK_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_registration)

[WskRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskregister)