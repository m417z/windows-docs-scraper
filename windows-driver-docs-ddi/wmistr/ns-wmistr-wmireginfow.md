# WMIREGINFOW structure

## Description

The **WMIREGINFO** structure contains information provided by a driver to register or update its data blocks and event blocks.

## Members

### `BufferSize`

Indicates the total size of the WMI registration data associated with this **WMIREGINFO** structure, calculated as follows: (**sizeof**(**WMIREGINFO**) + (**GuidCount** * **sizeof**(**WMIREGGUID**) + *additionaldata*). Additional data might include items such as the MOF resource name, registry path, and static instance names for blocks.

### `NextWmiRegInfo`

If a driver handles WMI requests on behalf of another driver, as a class driver might on behalf of a miniclass driver, **NextWmiRegInfo** indicates the offset in bytes from the beginning of this **WMIREGINFO** to the next **WMIREGINFO** structure that contains WMI registration information for the other driver. Otherwise, **NextWmiRegInfo** is zero.

### `RegistryPath`

Indicates the offset in bytes from the beginning of this structure to a counted Unicode string that specifies the registry path passed to the driver's [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine. The string must be aligned on a USHORT boundary. This member should be set only in response to a WMI registration request ([IRP_MN_REGINFO](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo) or [IRP_MN_REGINFO_EX](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo-ex) with **Parameters.WMI.DataPath** set to WMIREGISTER).

### `MofResourceName`

Indicates the offset in bytes from the beginning of this structure to a counted Unicode string that specifies the name of the MOF resource in the driver's image file. The string must be aligned on a USHORT boundary. This member should be set only in response to a WMI registration request ([IRP_MN_REGINFO](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo) or [IRP_MN_REGINFO_EX](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo-ex) with **Parameters.WMI.DataPath** set to WMIREGISTER).

### `GuidCount`

Indicates the number of [WMIREGGUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-wmiregguidw) structures in the array at **WmiRegGuid**.

### `WmiRegGuid`

Is an array of **GuidCount** [WMIREGGUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-wmiregguidw) structures.

## Remarks

In response to a registration request ([IRP_MN_REGINFO](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo) or [IRP_MN_REGINFO_EX](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo-ex) with **Parameters.WMI.DataPath** set to WMIREGISTER), a driver builds at least one **WMIREGINFO** structure and writes the **WMIREGINFO** structure to the buffer at **IrpStack->Parameters.WMI.Buffer**. The **WMIREGINFO** structure contains an array of **WMIREGGUID** structures, one for each data block or event block exposed by the driver.

If the driver handles WMI requests on behalf of another driver, it builds another **WMIREGINFO** containing an array of **WMIREGGUID** structures for each block exposed by the other driver, sets the **NextWmiRegInfo** member of the first **WMIREGINFO** to an offset in bytes from the beginning of the first **WMIREGINFO** to the beginning of the next **WMIREGINFO** in the buffer, and writes both structures to the buffer. The driver indicates the total size of both **WMIREGINFO** structures and associated data when calls **IoCompleteRequest** to complete the IRP.

A driver can use the same **WMIREGINFO** structure(s) to remove or update blocks in response to an update request ([IRP_MN_REGINFO](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo) or [IRP_MN_REGINFO_EX](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo-ex) with **Parameters.WMI.DataPath** set to WMIUPDATE). If WMIREG_FLAG_REMOVE_GUID is set in the **Flags** member of a **WMIREGGUID**, WMI removes that block from the list of blocks previously registered by the driver. If WMIREG_FLAG_REMOVE_GUID is clear, WMI updates registration information for that block only if other **WMIREGGUID** members have changed—otherwise, WMI does not change to its registration information for that block.

## See also

[IRP_MN_REGINFO](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo)

[IRP_MN_REGINFO_EX](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo-ex)

[IoCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest)

[WMIREGGUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-wmiregguidw)