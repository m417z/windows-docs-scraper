# WskCaptureProviderNPI function

## Description

The
**WskCaptureProviderNPI** function captures a provider
[Network Programming Interface
(NPI)](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) when it becomes available from the WSK subsystem.

## Parameters

### `WskRegistration` [in]

A pointer to the memory location initialized by
[WskRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskregister) that identifies a WSK
application's registration instance. For more information, see
[WSK_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_registration).

### `WaitTimeout` [in]

The time, in milliseconds, that the
**WskCaptureProviderNPI** function can wait until the WSK provider NPI becomes available. Alternately,
the following can be specified:

#### WSK_NO_WAIT

Return from this function immediately if the provider NPI is not available.

#### WSK_INFINITE_WAIT

Wait until the provider NPI is available from the WSK subsystem.

For more information about how this parameter is used, see
[Registering a Winsock
Kernel Application](https://learn.microsoft.com/windows-hardware/drivers/network/registering-a-winsock-kernel-application).

### `WskProviderNpi` [out]

A pointer to the NPI returned by the WSK provider. This
[WSK_PROVIDER_NPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_npi) structure contains a
pointer to the WSK provider dispatch table of WSK functions that the WSK application can call.

## Return value

**WskCaptureProviderNPI** returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The provider NPI capture completed successfully. |
| **STATUS_DEVICE_NOT_READY** | The provider NPI was not yet available. |
| **STATUS_NOINTERFACE** | The version requested by the WSK client is not supported by the WSK subsystem. |
| **Other status codes** | The provider NPI capture failed. |

## Remarks

For each call to
**WskCaptureProviderNPI** that returns a success code, there must be exactly one corresponding
[WskReleaseProviderNPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskreleaseprovidernpi) call that uses
the same
*WskRegistration* parameter that was passed to
**WskCaptureProviderNPI**.

**WskCaptureProviderNPI** can be called after a call is made to
[WskDeregister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskderegister) only if the
*WskRegistration* block is not freed or overwritten. After
**WskDeregister** is called, any further calls to
**WskCaptureProviderNPI** will fail with status code STATUS_DEVICE_NOT_READY, and, unless the provider
NPI becomes available concurrently, any existing
**WskCaptureProviderNPI** calls that are blocked in other threads waiting for the WSK provider NPI to
become available will also return immediately with status code STATUS_DEVICE_NOT_READY.

For more information about attaching a WSK application to the WSK subsystem, see
[Registering a Winsock Kernel
Application](https://learn.microsoft.com/windows-hardware/drivers/network/registering-a-winsock-kernel-application).

Callers of the
**WskCaptureProviderNPI** function must be running at IRQL = PASSIVE_LEVEL if
*WaitTimeout* is not set to WSK_NO_WAIT; otherwise, callers must be running at IRQL <=
DISPATCH_LEVEL.

## See also

[WskDeregister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskderegister)

[WskRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskregister)

[WskReleaseProviderNPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskreleaseprovidernpi)