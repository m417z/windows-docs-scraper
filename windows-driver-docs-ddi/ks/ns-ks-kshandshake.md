# KSHANDSHAKE structure

## Description

The KSHANDSHAKE structure is used to pass information back and forth while pins are handshaking in an attempt to negotiate a private interface.

## Members

### `ProtocolId`

This member specifies the GUID that represents the interface or protocol being negotiated between two AVStream pins.

### `Argument1`

A pointer to an interface-dependent argument. Most often, this is used to pass back and forth COM-style interface pointers once a specific private interface or protocol has been agreed upon.

### `Argument2`

A pointer to an interface-dependent argument.

## Remarks

See [KsPinHandshake](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinhandshake) for more information about negotiating private interfaces between AVStream pins.

Pin handshaking is a concept that is usable only between two pins that support IOCTL_KS_HANDSHAKE. Currently, only AVStream pins support this interface; thus this is only useful for negotiating private interfaces between two AVStream pins. Currently, connections between AVStream pins are negotiated via this mechanism.

## See also

[IOCTL_KS_HANDSHAKE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ni-ks-ioctl_ks_handshake)

[KsPinHandshake](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinhandshake)