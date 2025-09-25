# KsInstallBusEnumInterface function

## Description

*This function is intended for internal use only.*

The **KsInstallBusEnumInterface** function installs an interface to the demand-load bus enumerator object.

## Parameters

### `Irp` [in]

Pointer to an IRP that contains a SWENUM_INSTALL_INTERFACE structure that specifies the demand-load bus enumerator object interface to install. For information about this structure, see the Remarks section below.

## Return value

Returns STATUS_SUCCESS if successful. Otherwise, it returns an error code.

## Remarks

The **Irp->AssociatedIrp.SystemBuffer** is assumed to contain a SWENUM_INSTALL_INTERFACE structure. The *DeviceId*, *InterfaceId* and *ReferenceString* members of the structure specify the specific device and interface with which to access this new interface. When the interface is registered with Plug and Play for the interface GUID and the associated reference string is accessed the first time through IRP_MJ_CREATE, the device will be enumerated using the format of *bus-identifier-prefix\device-id-GUID-string*. For example, SW\{xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx}.

## See also

[KsRemoveBusEnumInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/swenum/nf-swenum-ksremovebusenuminterface)

[SWENUM_INSTALL_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/swenum/ns-swenum-_swenum_install_interface)