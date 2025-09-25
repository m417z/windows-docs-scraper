## Description

An AVStream minidriver's *AVStrMiniPinHandshake* routine is called when AVStream receives a protocol handshake request that it does not handle.

## Parameters

### `Pin`

Describes the **PKSPIN** parameter Pin.

### `In`

Describes the **PKSHANDSHAKE** parameter *In*.

### `Out`

Describes the **PKSHANDSHAKE** parameter *Out*.

## Return value

Returns STATUS_SUCCESS if the pin supports the requested protocol. Otherwise, it should return STATUS_INVALID_DEVICE_REQUEST.

## Remarks

The minidriver specifies this routine's address in the *Handshake* parameter of a call to [**KsPinRegisterHandshakeCallback**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinregisterhandshakecallback).

## See also

[**KSHANDSHAKE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kshandshake)

[**KSIDENTIFIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksidentifier)

[**KsPinRegisterHandshakeCallback**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinregisterhandshakecallback)