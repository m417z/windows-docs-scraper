# IOCTL_EHSTOR_DRIVER_UPDATE_LBA_FILTER_TABLE IOCTL

## Description

This IOCTL is used to inform the enhanced storage (EHSTOR) class driver of changes to the LBA filter table. Bands managed by the silo driver are composed of LBA ranges. The silo driver notifies the EHSTOR class driver of updates to the set of bands it controls with this IOCTL.

## Parameters

### Major code

### Input buffer

The input buffer at **Irp->AssociatedIrp.SystemBuffer** must contain a structure of type [LBA_FILTER_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ns-ehstorioctl-_lba_filter_table). This structure contains the filter table and the total entries it contains. An array [LBA_FILTER_TABLE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ns-ehstorioctl-_lba_filter_table_entry) structure follows **LBA_FILTER_TABLE**.

### Input buffer length

The length of the buffer.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

One of the following values can be returned in the **Status** field.

| Status Value | Description |
| --- | --- |
| STATUS_SUCCESS | The LBA filter table was successfully updated. |
| STATUS_INVALID_BUFFER_SIZE | The input buffer length supplied is of incorrect size. |
| STATUS_INVALID_PARAMETER | The LBA filter count or an LBA range is specified incorrectly. |
| STATUS_INSUFFICIENT_RESOURCES | The IOCTL redirection list cannot be copied. |
| STATUS_NOT_SUPPORTED | The sending device is not a silo device or banding is not supported. |

## Remarks

The LBA filters cannot overlap or be empty. The LBA filters do not have to be sorted in any way.

If an LBA range is being unlocked, an **IOCTL_EHSTOR_DRIVER_UPDATE_LBA_FILTER_TABLE** request should be sent after the LBA range is unlocked on the storage device. Also,
if an LBA range is currently being locked, **IOCTL_EHSTOR_DRIVER_UPDATE_LBA_FILTER_TABLE** must be sent before the LBA range has been locked on the storage device.

## See also

[LBA_FILTER_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ns-ehstorioctl-_lba_filter_table)

[LBA_FILTER_TABLE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ns-ehstorioctl-_lba_filter_table_entry)