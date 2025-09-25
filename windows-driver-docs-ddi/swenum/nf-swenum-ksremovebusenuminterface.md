# KsRemoveBusEnumInterface function

## Description

*This function is intended for internal use only.*

The **KsRemoveBusEnumInterface** function removes an interface to the demand-load bus enumerator object.

## Parameters

### `Irp` [in]

Pointer to an IRP that contains a SWENUM_INSTALL_INTERFACE structure that specifies the device ID, interface ID, and reference string of the specific device and interface to be removed. For information about this structure, see theRemarks section below.

## Return value

Returns STATUS_SUCCESS if successful. Otherwise, it returns an appropriate error code.

## Remarks

The **Irp->AssociatedIrp.SystemBuffer** is assumed to contain a SWENUM_INSTALL_INTERFACE structure. The *DeviceId*, *InterfaceId* and *ReferenceString* members of the structure specify the specific device and interface to be removed.

## See also

[KsInstallBusEnumInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/swenum/nf-swenum-ksinstallbusenuminterface)

[SWENUM_INSTALL_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/swenum/ns-swenum-_swenum_install_interface)