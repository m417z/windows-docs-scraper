# KsPinRegisterHandshakeCallback function

## Description

The **KsPinRegisterHandshakeCallback** function registers a minidriver-provided callback routine for a given pin. AVStream calls the callback routine when it receives a handshake request for the pin that specifies a protocol that AVStream does not handle by default.

## Parameters

### `Pin` [in]

A pointer to the [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure for which to register a handshake callback.

### `Handshake` [in]

A pointer to a minidriver-supplied [AVStrMiniPinHandshake](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkspinhandshake) routine to be called when AVStream receives a protocol handshake request on *Pin* that it does not handle.

## Remarks

Pins that support private protocol connections with other AVStream pins should register a handshake callback.

Minidrivers that support private protocols between a given pin and another AVStream pin should call this routine as soon as possible to register a callback. Then if another pin requests a handshake, the minidriver can return the request.

## See also

[AVStrMiniPinHandshake](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkspinhandshake)

[KSHANDSHAKE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kshandshake)

[KsFilterRegisterPowerCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterregisterpowercallbacks)

[KsPinHandshake](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinhandshake)

[KsPinRegisterPowerCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinregisterpowercallbacks)

[KsRegisterAggregatedClientUnknown](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksregisteraggregatedclientunknown)