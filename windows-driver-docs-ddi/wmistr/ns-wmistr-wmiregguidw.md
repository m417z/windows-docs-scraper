# WMIREGGUIDW structure

## Description

The **WMIREGGUID** structure contains new or updated registration information for a data block or event block.

## Members

### `Guid`

Specifies the GUID that represents the block to register or update.

### `Flags`

Indicates characteristics of the block to register or update.

If a block is being registered with static instance names, a driver sets one of the following flags:

#### WMIREG_FLAG_INSTANCE_LIST

Indicates that the driver provides static instance names for this block in a static list following the [WMIREGINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-wmireginfow) structure in the buffer at **IrpStack->Parameters.WMI.Buffer**. If this flag is set, **InstanceNameList** is the offset in bytes from the beginning of the **WMIREGINFO** structure that contains this **WMIREGGUID** to a contiguous series of **InstanceCount** counted Unicode strings.

#### WMIREG_FLAG_INSTANCE_BASENAME

Requests WMI to generate static instance names from a base name provided by the driver following the **WMIREGINFO** structure in the buffer at **IrpStack->Parameters.WMI.Buffer**. WMI generates instance names by appending a counter to the base name. If this flag is set, **BaseNameOffset** is the offset in bytes from the beginning of the **WMIREGINFO** structure that contains this **WMIREGGUID** to a single counted Unicode string that serves as the base name.

#### WMIREG_FLAG_INSTANCE_PDO

Requests WMI to generate static instance names from the device instance ID for the PDO. If this flag is set, **InstanceInfo** points to the PDO passed to the driver's [AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) routine. WMI generates instance names from the device instance path of the PDO. Using the device instance path as a base for static instance names is efficient because such names are guaranteed to be unique. WMI automatically supplies a "friendly" name for the instance as an item in a data block that can be queried by data consumers.

If a block is being registered with dynamic instance names, WMIREG_FLAG_INSTANCE_LIST, WMIREG_FLAG_INSTANCE_BASENAME, and WMIREG_FLAG_INSTANCE_PDO must be clear.

A driver might also set one or more of the following flags:

#### WMIREG_FLAG_EVENT_ONLY_GUID

The block can be enabled or disabled as an event only, and cannot be queried or set. If this flag is clear, the block can also be queried or set.

#### WMIREG_FLAG_EXPENSIVE

Requests WMI to send an [IRP_MN_ENABLE_COLLECTION](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-enable-collection) request the first time a data consumer opens the data block and an [IRP_MN_DISABLE_COLLECTION](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-disable-collection) request when the last data consumer closes the data block. This is recommended if collecting such data affects performance, because a driver need not collect the data until a data consumer explicitly requests it by opening the block.

#### WMIREG_FLAG_REMOVE_GUID

Requests WMI to remove support for this block. This flag is valid only in response to a request to update registration information ([IRP_MN_REGINFO](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo) or [IRP_MN_REGINFO_EX](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo-ex) with **Parameters.WMI.DataPath** set to WMIUPDATE).

#### WMIREG_FLAG_TRACED_GUID

The block can be written only to a log file and can be accessed only through user-mode routines declared in evntrace.h. Only NT kernel-mode data providers set this flag.

#### WMIREG_FLAG_TRACE_CONTROL_GUID

The GUID acts as the control GUID for enabling or disabling the trace GUIDs associated with it in the MOF file. This flag is valid only if WMIREG_FLAG_TRACED_GUID is also set. Only NT kernel-mode data providers set this flag.

### `InstanceCount`

Specifies the number of static instance names to be defined for this block. If the block is being registered with dynamic instance names, WMI ignores **InstanceCount**.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.InstanceNameList`

Indicates the offset in bytes from the beginning of the **WMIREGINFO** structure that contains this **WMIREGGUID** to a contiguous series of **InstanceCount** counted Unicode strings. This member is valid only if WMIREG_FLAG_INSTANCE_LIST is set in **Flags**. If the block is being registered with dynamic instance names, WMI ignores **InstanceNameList**.

### `DUMMYUNIONNAME.BaseNameOffset`

Indicates the offset in bytes from the beginning of the **WMIREGINFO** structure that contains this **WMIREGGUID** to a single counted Unicode string that serves as a base for WMI to generate static instance names. This member is valid only if WMIREG_FLAG_INSTANCE_BASENAME is set in **Flags**. If the block is being registered with dynamic instance names, WMI ignores **BaseNameOffset**.

### `DUMMYUNIONNAME.Pdo`

Pointer to the physical device object (PDO) passed to the driver's [AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) routine. WMI uses the device instance path of this PDO as a base from which to generate static instance names. This member is valid only if WMIREG_FLAG_INSTANCE_PDO is set in **Flags**. If the block is being registered with dynamic instance names, WMI ignores **Pdo**.

### `DUMMYUNIONNAME.InstanceInfo`

Reserved for use by WMI.

## Remarks

A driver builds one or more **WMIREGGUID** structures in response to an [IRP_MN_REGINFO](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo) or [IRP_MN_REGINFO_EX](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo-ex) request to register or update its blocks. The driver passes an array of such structures at the **WmiRegGuid** member of a **WMIREGINFO** structure, which the driver writes to the buffer at **IrpStack->Parameters.WMI.Buffer**.

A driver can register or update a block with either static or dynamic instance names. Static instance names provide best performance; however, dynamic instance names are preferred for data blocks if the number of instances or instance names change frequently. For more information about instance names, see [Defining WMI Instance Names](https://learn.microsoft.com/windows-hardware/drivers/kernel/defining-wmi-instance-names).

## See also

[IRP_MN_REGINFO](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo)

[IRP_MN_REGINFO_EX](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo-ex)

[WMIREGINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-wmireginfow)