# KsPinHandshake function

## Description

The **KsPinHandshake** function attempts a protocol handshake with a connected pin.

## Parameters

### `Pin` [in]

A pointer to the [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure that is initiating the handshake. The handshake request is passed on to the pin connected to this object.

### `In` [in]

A pointer to the [KSHANDSHAKE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kshandshake) structure containing the handshake information to be passed to the connected pin.

### `Out` [out]

A pointer to a [KSHANDSHAKE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kshandshake) structure that is filled in with handshake information by the connected pin.

## Return value

**KsPinHandshake** returns STATUS_SUCCESS if the connected pin is accepting the negotiated connection. Otherwise, it returns an appropriate error code.

## Remarks

Protocol handshakes can be used to negotiate private interfaces between two pins that are both AVStream pins.

Connections between AVStream pins are performed using this type of handshake.

## See also

[IOCTL_KS_HANDSHAKE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ni-ks-ioctl_ks_handshake)

[KSHANDSHAKE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kshandshake)

[KsPinGetConnectedPinInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetconnectedpininterface)