# _SWENUM_INSTALL_INTERFACE structure

## Description

The SWENUM_INSTALL_INTERFACE structure describes a specific demand-load bus enumerator object interface to install.

## Members

### `DeviceId`

GUID that specifies the demand-load bus enumerator object's device ID.

### `InterfaceId`

GUID that specifies the demand-load bus enumerator object's interface ID.

### `ReferenceString`

A reference string that a driver can use to uniquely identify multiple interface instances of the same type for a single device.

## Remarks

The *swenum* driver uses device interface instances as placeholders for software devices created on demand.

## See also

[KsInstallBusEnumInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/swenum/nf-swenum-ksinstallbusenuminterface)

[KsRemoveBusEnumInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/swenum/nf-swenum-ksremovebusenuminterface)