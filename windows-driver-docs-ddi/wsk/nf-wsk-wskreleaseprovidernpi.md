# WskReleaseProviderNPI function

## Description

The
**WskReleaseProviderNPI** function releases a
[Network Programming Interface
(NPI)](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) that was captured with
[WskCaptureProviderNPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskcaptureprovidernpi).

## Parameters

### `WskRegistration` [in]

A pointer to the memory location initialized by
[WskRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskregister) that identifies a WSK
application's registration instance.

## Remarks

For each call to
**WskCaptureProviderNPI** that returns a success code, there must be exactly one corresponding
**WskReleaseProviderNPI** call that uses
the same
*WskRegistration* parameter that was passed to
**WskCaptureProviderNPI**.

## See also

[WSK_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_registration)

[WskCaptureProviderNPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskcaptureprovidernpi)