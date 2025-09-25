# IOCTL_SCSI_PASS_THROUGH_DIRECT_EX IOCTL

## Description

The **IOCTL_SCSI_PASS_THROUGH_DIRECT_EX** control code request
is the extended version of the **IOCTL_SCSI_PASS_THROUGH_DIRECT** request. This request provides support for bidirectional data transfers and allows a command data block (CDB) > 16 bytes.

Allows an application to send almost any SCSI command to a target device, with the following restrictions:

* Multitarget commands, such as COPY, are not allowed.
* If a class driver for the target type of device exists, the request must be sent to that class driver. Thus, an application can send this request directly to the system port driver for a target logical unit only if there is no class driver for the type of device connected to that LU.
* This request *must* be made if the input CDB might require the underlying miniport driver to access memory directly.

The calling application creates the SCSI command descriptor block, which can include a request for request-sense data if a CHECK CONDITION occurs. If the CDB requests a data transfer operation, the caller must set up an adapter device aligned buffer from which or into which the miniport driver can transfer data directly. This request is typically used for transferring larger amounts of data (>16K).

Applications can send this request by means of an [IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-device-control) request.

Storage class drivers set the minor IRP number to IRP_MN_SCSI_CLASS to indicate that the request has been processed by a storage class driver.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver-overview) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### Major code

### Input buffer

*Parameters.DeviceIoControl.InputBufferLength* indicates the size, in bytes, of the buffer at *Irp->AssociatedIrp.SystemBuffer*, which must be at least (*sense data size* + **sizeof**(SCSI_PASS_THROUGH_DIRECT_EX)). The size of the [SCSI_PASS_THROUGH_DIRECT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_pass_through_direct_ex) structure is fixed.

This structure includes an SCSI CDB, which must be initialized by the caller except for the path, target ID, and LUN, which are filled in by the port driver. For a data-out command, the data to be transferred must be in an adapter device aligned buffer. The **DataInBuffer** member of [SCSI_PASS_THROUGH_DIRECT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_pass_through_direct_ex) is a pointer to this adapter device aligned buffer. The caller must allocate additional storage, following the **SCSI_PASS_THROUGH_DIRECT_EX** structure, if the caller asks for request-sense data.

### Input buffer length

*Parameters.DeviceIoControl.InputBufferLength* indicates the size, in bytes, of the buffer at *Irp->AssociatedIrp.SystemBuffer*, which must be at least (*sense data size* + **sizeof**(SCSI_PASS_THROUGH_DIRECT_EX)). The size of the [SCSI_PASS_THROUGH_DIRECT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_pass_through_direct_ex) structure is fixed.

### Output buffer

The port driver returns any request-sense data and the [SCSI_PASS_THROUGH_DIRECT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_pass_through_direct_ex) structure to the buffer at *Irp->AssociatedIrp.SystemBuffer*.

### Output buffer length

**SenseInfoLength** and **DataOutTransferLength** are updated to indicate the amount of data transferred. The port driver returns any data transferred from the device to the supplied cache-aligned buffer at **DataOutBuffer**.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes returned in the output buffer at *Irp->AssociatedIrp.SystemBuffer*. The **Status** field is set to **STATUS_SUCCESS**, or possibly to **STATUS_BUFFER_TOO_SMALL** or **STATUS_INVALID_PARAMETER** if the input **Length** value in [SCSI_PASS_THROUGH_DIRECT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_pass_through_direct_ex) is improperly set or the buffer specified in **DataInBuffer** is not properly device aligned.

## Remarks

For data transfer operations, a buffer with alignment matching the adapter device is required. Applications can retrieve the device alignment mask by issuing an [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) control code request with a query type of **PropertyStandardQuery** and property id of **StorageAdapterProperty**. The alignment mask is found in the **AlignmentMask** member of the [STORAGE_ADAPTER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_adapter_descriptor) structure that is returned. Drivers may also use the value in the **AlignmentMask** member of the adapter's *DeviceObject*.

In the following example function, a buffer is prepared as a device aligned data transfer buffer.

```cpp

PVOID AllocateAlignedBuffer(ULONG size, ULONG AlignmentMask, PVOID *pUnAlignedBuffer)
{
    PVOID AlignedBuffer;
    ULONG_PTR FullWordMask = (ULONG_PTR)AlignmentMask;

    if (AlignmentMask == 0)
    {
        AlignedBuffer = malloc(size);
        // return the original buffer to free later
        *pUnAlignedBuffer = AlignedBuffer;
    }
    else
    {
        // expand the size for the alignment window
        size += AlignmentMask;
        AlignedBuffer = malloc(size);
        // return the original buffer to free later
        *pUnAlignedBuffer = AlignedBuffer;
        // adjust buffer pointer for the desired alignment
        AlignedBuffer = (PVOID)(((ULONG_PTR)AlignedBuffer + FullWordMask) & ~FullWordMask);
    }

    return AlignedBuffer;
}
```

In order to issue an **IOCTL_SCSI_PASS_THROUGH_DIRECT_EX** request, the underlying storage device must support extended SRBs. This means that the supported SRB type is **SRB_TYPE_STORAGE_REQUEST_BLOCK**. An application can query for SRB support with the **IOCTL_STORAGE_QUERY_PROPERTY** request with a query type of **PropertyStandardQuery** and a property type of **StorageDeviceProperty**. The **SrbType** member returned in the [STORAGE_ADAPTER_DESCRIPTIOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_adapter_descriptor) structure will indicate either **SRB_TYPE_SCSI_REQUEST_BLOCK** or **SRB_TYPE_STORAGE_REQUEST_BLOCK**.

## See also

[IOCTL_SCSI_PASS_THROUGH_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_pass_through_ex)

[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)

[SCSI_PASS_THROUGH_DIRECT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_pass_through_direct_ex)