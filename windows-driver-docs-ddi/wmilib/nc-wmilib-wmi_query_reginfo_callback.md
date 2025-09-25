# WMI_QUERY_REGINFO_CALLBACK callback function

## Description

The *DpWmiQueryReginfo* routine provides information about the data blocks and event blocks to be registered by a driver. This routine is required.

## Parameters

### `DeviceObject` [in]

A pointer to the driver's WDM [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure.

### `RegFlags` [out]

This parameter indicates common characteristics of all blocks being registered. Any flag set in *RegFlags* is applied to all blocks. A driver can supplement *RegFlags* for a given block by setting **Flags** in the block's [WMIGUIDREGINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmiguidreginfo) structure. For example, a driver might clear WMIREG_FLAG_EXPENSIVE in *RegFlags*, but set it in **Flags** to register a given block as expensive to collect.

The driver sets one of the following flags in *RegFlags*:

#### WMIREG_FLAG_INSTANCE_BASENAME

Requests WMI to generate static instance names from a base name provided by the driver at the *InstanceName*. WMI generates instance names by appending a counter to the base name.

#### WMIREG_FLAG_INSTANCE_PDO

Requests WMI to generate static instance names from the device instance ID for the PDO. If the driver sets this flag, it must also set *Pdo* to the PDO passed to the driver's [AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) routine. WMI generates instance names from the device instance path of the PDO. Using the device instance path as a base for static instance names is efficient because such names are guaranteed to be unique. WMI automatically supplies a "friendly" name for the instance as an item in a data block that can be queried by data consumers.

A driver might also set one or more of the following flags in *RegFlags*, but more typically would set them in **Flags** of a block's [WMIGUIDREGINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmiguidreginfo) structure:

#### WMIREG_FLAG_EVENT_ONLY_GUID

The blocks can be enabled or disabled as events only, and cannot be queried or set. If this flag is clear, the blocks can also be queried or set.

#### WMIREG_FLAG_EXPENSIVE

Requests WMI to send an [IRP_MN_ENABLE_COLLECTION](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-enable-collection) request the first time a data consumer opens a data block and an [IRP_MN_DISABLE_COLLECTION](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-disable-collection) request when the last data consumer closes the data block. This is recommended if collecting such data affects performance, because a driver need not collect the data until a data consumer explicitly requests it by opening the block.

#### WMIREG_FLAG_REMOVE_GUID

Requests WMI to remove support for the blocks. This flag is valid only in response to a request to update registration information ([IRP_MN_REGINFO](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo) or [IRP_MN_REGINFO_EX](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo-ex) with **Parameters.WMI.DataPath** set to WMIUPDATE).

### `InstanceName` [out]

A pointer to a single counted Unicode string that serves as the base name for all instances of all blocks to be registered by the driver. WMI frees the string with [ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool). If WMIREG_FLAG_INSTANCE_BASENAME is clear, *InstanceName* is ignored.

### `RegistryPath` [out]

A pointer to a pointer to a counted Unicode string that specifies the registry path passed to the driver's [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine.

### `MofResourceName` [out]

A pointer to a single counted Unicode string that indicates the name of the MOF resource attached to the driver's binary image file. Typically this string would be a static defined by the driver. WMI makes a copy of this string after the driver returns from this routine. This string can be dynamically allocated by the driver. In the case of an allocated string, the driver is responsible for freeing the string which should be done after [WmiSystemControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmisystemcontrol) returns. If the driver does not have a MOF resource attached, it can leave *MofResourceName* unchanged.

### `Pdo` [out]

A pointer to the physical device object (PDO) passed to the driver's [AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) routine. If WMIREG_FLAG_INSTANCE_PDO is set, WMI uses the device instance path of this PDO as a base from which to generate static instance names. If WMIREG_FLAG_INSTANCE_PDO is clear, WMI ignores *Pdo*.

## Return value

*DpWmiQueryReginfo* always returns STATUS_SUCCESS.

## Remarks

WMI calls a driver's *DpWmiQueryReginfo* routine after the driver calls [WmiSystemControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmisystemcontrol) in response to an [IRP_MN_REGINFO](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo) or [IRP_MN_REGINFO_EX](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo-ex) request. The driver must place the address of its *DpWmiQueryReginfo* routine in the [WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmilib_context) structure that it passes to **WmiSystemControl**.

WMI sends the IRP after a driver calls [IoWMIRegistrationControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiregistrationcontrol) with WMIREG_ACTION_REGISTER, WMIREG_ACTION_REREGISTER, or WMIREG_ACTION_UPDATE. WMI transparently handles the differences between **IRP_MN_REGINFO** and **IRP_MN_REGINFO_EX** on behalf of the driver.

WMI does not send an [IRP_MN_REGINFO](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo) or [IRP_MN_REGINFO_EX](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo-ex) request after a driver calls **IoWMIRegistrationControl** with WMIREG_ACTION_DEREGISTER, because WMI requires no further information from the driver. A driver typically deregisters its blocks in response to an [IRP_MN_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-remove-device) request.

The driver provides new or updated registration information about individual blocks, or indicates blocks to remove, in the [WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmilib_context) structure it passes to **WmiSystemControl**. After the initial call, which establishes the driver's registry path and MOF resource name, a driver's *DpWmiQueryReginfo* routine can change flags common to all of a driver's blocks, provide a different base name string used to generate instance names, or change the basis for instance names from a string to the device instance path of the PDO.

The driver must not return STATUS_PENDING or block the request. The driver must not complete the request by calling [WmiCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmicompleterequest) from its *DpWmiQueryReginfo* routine or by calling [IoCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest) after **WmiSystemControl** returns.

This routine can be pageable.

For more information about implementing this routine, see [Calling WmiSystemControl to Handle WMI IRPs](https://learn.microsoft.com/windows-hardware/drivers/kernel/calling-wmisystemcontrol-to-handle-wmi-irps).

## See also

[IRP_MN_REGINFO_EX](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo-ex)

[IoWMIRegistrationControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiregistrationcontrol)

[WMIGUIDREGINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmiguidreginfo)

[WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmilib_context)

[WmiSystemControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmisystemcontrol)