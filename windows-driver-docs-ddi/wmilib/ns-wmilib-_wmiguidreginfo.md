# _WMIGUIDREGINFO structure

## Description

The **WMIGUIDREGINFO** structure contains registration information for a given data block or event block exposed by a driver that uses the WMI library support routines.

## Members

### `Guid`

Pointer to the GUID that identifies the block. The memory that contains the GUID can be paged unless it is also used to call [WmiFireEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmifireevent).

### `InstanceCount`

Specifies the number of instances defined for the block.

### `Flags`

Flag bits that indicate characteristics of the block. These flag bits are defined in the Wmistr.h header file. WMI ORs the **Flags** parameter value with the flag bits set by the driver in the *RegFlags* parameter of its [DpWmiQueryReginfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nc-wmilib-wmi_query_reginfo_callback) routine, which apply to all of the data blocks and event blocks registered by the driver. **Flags** therefore supplements the driver's default settings for a given block.

A driver might set the following flag bit in **Flags**:

#### WMIREG_FLAG_INSTANCE_PDO

Requests WMI to generate static instance names from the device instance ID for the PDO. If this flag is set, the *Pdo* parameter of the driver's *DpWmiQueryReginfo* routine points to the PDO passed to the driver's [AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) routine. WMI generates instance names from the device instance path of the PDO. Using the device instance path as a base for static instance names is efficient because such names are guaranteed to be unique. WMI automatically supplies a "friendly" name for the instance as an item in a data block that can be queried by data consumers.

A driver might also set one or more of the following flag bits:

#### WMIREG_FLAG_EVENT_ONLY_GUID

The block can be enabled or disabled as an event only, and cannot be queried or set. If this flag is clear, the block can also be queried or set.

#### WMIREG_FLAG_EXPENSIVE

Requests WMI to send an [IRP_MN_ENABLE_COLLECTION](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-enable-collection) request the first time a data consumer opens the data block and an [IRP_MN_DISABLE_COLLECTION](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-disable-collection) request when the last data consumer closes the data block. This is recommended if collecting such data affects performance, because a driver need not collect the data until a data consumer explicitly requests it by opening the block.

#### WMIREG_FLAG_REMOVE_GUID

Requests WMI to remove support for this block. This flag is valid only in response to a request to update registration information ([IRP_MN_REGINFO](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo) or [IRP_MN_REGINFO_EX](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo-ex) with **Parameters.WMI.DataPath** set to WMIUPDATE).

## Remarks

A driver that handles WMI IRPs by calling WMI library support routines builds an array of **WMIGUIDREGINFO** structures, one for each data block and event block to be registered. The driver sets the **GuidList** member of its [WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmilib_context) structure to point to the first **WMIGUIDREGINFO** in the series.

Memory for this structure can be allocated from paged pool.

## See also

[DpWmiQueryReginfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nc-wmilib-wmi_query_reginfo_callback)

[IRP_MN_DISABLE_COLLECTION](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-disable-collection)

[IRP_MN_ENABLE_COLLECTION](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-enable-collection)

[IRP_MN_REGINFO](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo)

[IRP_MN_REGINFO_EX](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo-ex)

[WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmilib_context)

[WmiFireEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmifireevent)