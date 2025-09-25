# _WSK_PROVIDER_NPI structure

## Description

The WSK_PROVIDER_NPI structure identifies a provider
[Network Programming Interface
(NPI)](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) implemented by the WSK subsystem.

## Members

### `Client`

A pointer to a
[WSK_CLIENT](https://learn.microsoft.com/windows-hardware/drivers/network/wsk-client) structure that was returned through
the
*WskProviderNpi* parameter of the
[WskCaptureProviderNPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskcaptureprovidernpi) function.

### `Dispatch`

A pointer to a constant
[WSK_PROVIDER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_dispatch) structure.

## See also

[WSK_CLIENT](https://learn.microsoft.com/windows-hardware/drivers/network/wsk-client)

[WSK_PROVIDER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_dispatch)

[WskCaptureProviderNPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskcaptureprovidernpi)