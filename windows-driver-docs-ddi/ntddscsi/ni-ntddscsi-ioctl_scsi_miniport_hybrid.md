# IOCTL_SCSI_MINIPORT_HYBRID IOCTL

## Description

The
**IOCTL_SCSI_MINIPORT_HYBRID** control code sends a hybrid disk control request to an HBA-specific miniport driver. The **IOCTL_SCSI_MINIPORT_HYBRID** request is a sub-IOCTL of [IOCTL_SCSI_MINIPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_miniport). This IOCTL is received and reformatted by StorPort, then sent to the miniport as a [STORAGE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_storage_request_block) (SRB) with a function type of SRB_FUNCTION_IO_CONTROL. The input and output data is contained in the SRB data block.

**IOCTL_SCSI_MINIPORT_HYBRID** is intended for use by third-party applications or filter drives which manage security features such as encryption or write-through behavior.

**Warning** Use of **IOCTL_SCSI_MINIPORT_HYBRID** to modify hybrid cache behavior will conflict with the operation of Windows system components and is not supported.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver-overview) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### Major code

### Input buffer

The buffer specified in the **DataBuffer** member of the SRB must contain an [SRB_IO_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_srb_io_control) structure and a **HYBRID_REQUEST_BLOCK** structure. Depending on the **Function** member of **HYBRID_REQUEST_BLOCK**, additional data can be supplied.

### Input buffer length

**DataTransferLength** indicates the size, in bytes, of the buffer, which must be at least **sizeof** (SRB_IO_CONTROL) + **sizeof**(HYBRID_REQUEST_BLOCK), with additional storage for function data if the **DataBufferLength** member of the **HYBRID_REQUEST_BLOCK** is nonzero.

### Output buffer

An updated [SRB_IO_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_srb_io_control) structure is returned to the data buffer in the SRB.

### Output buffer length

The **DataBufferOffset** and **DataBufferLength** members of **HYBRID_REQUEST_BLOCK** are nonzero when data is returned for the specified **Function**. The **DataTransferLength** member of the SRB is updated when data is returned for the request function.

### Input/output buffer

### Input/output buffer length

### Status block

The resulting status of the function request is set in the **ReturnCode** member of [SRB_IO_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_srb_io_control). The following are the hybrid disk IOCTL status codes.

| Return Code | Description |
| --- | --- |
| HYBRID_STATUS_SUCCESS | The function completed successfully. |
| HYBRID_STATUS_ILLEGAL_REQUEST | The request contains an invalid function code. |
| HYBRID_STATUS_INVALID_PARAMETER | Either the input or output parameters are formatted incorrectly. |
| HYBRID_STATUS_OUTPUT_BUFFER_TOO_SMALL | The data length given in **DataBufferLength** is too small to contain the request output. |

## Remarks

A **HYBRID_REQUEST_BLOCK** structure immediately follows the [SRB_IO_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_srb_io_control) structure in the data buffer. **HYBRID_REQUEST_BLOCK** is defined in ntddscsi.h as the following.

```
typedef struct _HYBRID_REQUEST_BLOCK {
    ULONG   Version;
    ULONG   Size;
    ULONG   Function;
    ULONG   Flags;
    ULONG   DataBufferOffset;
    ULONG   DataBufferLength;
} HYBRID_REQUEST_BLOCK, *PHYBRID_REQUEST_BLOCK;
```

The parameter requirements depend on the function code of the hybrid disk request. The following table lists the parameters required for each function.

| Function | Input Parameters | Output Parameters |
| --- | --- | --- |
| HYBRID_FUNCTION_GET_INFO | [SRB_IO_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_srb_io_control) +<br><br>**HYBRID_REQUEST_BLOCK** | [SRB_IO_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_srb_io_control) +<br><br>**HYBRID_REQUEST_BLOCK** +<br><br>[HYBRID_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_hybrid_information) |
| HYBRID_FUNCTION_DISABLE_CACHING_MEDIUM | [SRB_IO_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_srb_io_control) +<br><br>**HYBRID_REQUEST_BLOCK** | [SRB_IO_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_srb_io_control) |
| HYBRID_FUNCTION_ENABLE_CACHING_MEDIUM | [SRB_IO_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_srb_io_control) +<br><br>**HYBRID_REQUEST_BLOCK** | [SRB_IO_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_srb_io_control) |
| HYBRID_FUNCTION_SET_DIRTY_THRESHOLD | [SRB_IO_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_srb_io_control) +<br><br>**HYBRID_REQUEST_BLOCK** +<br><br>**HYBRID_DIRTY_THRESHOLDS** | [SRB_IO_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_srb_io_control) |
| HYBRID_FUNCTION_DEMOTE_BY_SIZE | [SRB_IO_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_srb_io_control) +<br><br>**HYBRID_REQUEST_BLOCK** +<br><br>**HYBRID_DEMOTE_BY_SIZE** | [SRB_IO_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_srb_io_control) |

The **HYBRID_REQUEST_BLOCK** structure is located after the [SRB_IO_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_srb_io_control) structure in the **DataBuffer** of the SRB. Any function data included with the request is found at the offset in **DataBufferOffset** after the beginning of the **SRB_IO_CONTROL** structure.

The following example demonstrates retrieval of the function data for a HYBRID_FUNCTION_SET_DIRTY_THRESHOLD request.

```
    PSRB_IO_CONTROL srbIoCtl = (PSRB_IO_CONTROL)srb->DataBuffer;
    PHYBRID_REQUEST_BLOCK hybridRequest = (PHYBRID_REQUEST_BLOCK)(srbIoCtl + 1);
    PHYBRID_DIRTY_THRESHOLDS hybridDirtyThresholds = NULL;

    if (hybridRequest->DataBufferOffset >= sizeof(SRB_IO_CONTROL) + sizeof(HYBRID_REQUEST_BLOCK))
    {
        if (hybridRequest->DataBufferLength >= sizeof(HYBRID_FUNCTION_SET_DIRTY_THRESHOLD))
        {
            hybridDirtyThresholds = (PHYBRID_DIRTY_THRESHOLDS)((PUCHAR)srbIoCtl + hybridRequest->DataBufferOffset);
        }
        else
        {
            srbIoCtl->ReturnCode = HYBRID_STATUS_INVALID_PARAMETER;
        }
    }
```

**HYBRID_DIRTY_THRESHOLDS**

The HYBRID_FUNCTION_SET_DIRTY_THRESHOLD function uses the **HYBRID_DIRTY_THRESHOLDS** structure for its input parameters. **HYBRID_DIRTY_THRESHOLDS** is defined in ntddscsi.h as the following.
```
typedef struct _HYBRID_DIRTY_THRESHOLDS {
    ULONG   Version;
    ULONG   Size;
    ULONG   DirtyLowThreshold;
    ULONG   DirtyHighThreshold;
} HYBRID_DIRTY_THRESHOLDS, *PHYBRID_DIRTY_THRESHOLDS;
```

Version

The version of the structure. Set to HYBRID_REQUEST_INFO_STRUCTURE_VERSION.

Size

The size of the structure. Set to **sizeof**(HYBRID_DIRTY_THRESHOLDS).

DirtyLowThreshold

The fractional low threshold value for the hybrid disk cache to synchronize to disk.

DirtyHighThreshold

The fractional high threshold value for the hybrid disk cache to synchronize to disk.

The values of **DirtyLowThreshold** and **DirtyHighThreshold** are expressed as the smaller part of a ratio between the threshold value and a fraction base. The fraction base is determined by the **FractionBase** member of the [HYBRID_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_hybrid_information) structure.

**HYBRID_DEMOTE_BY_SIZE**

The HYBRID_FUNCTION_DEMOTE_BY_SIZE function uses the **HYBRID_DEMOTE_BY_SIZE** structure for its input parameters. **HYBRID_DEMOTE_BY_SIZE** is defined in ntddscsi.h as the following.
```
typedef struct _HYBRID_DEMOTE_BY_SIZE {
    ULONG       Version;
    ULONG       Size;
    UCHAR       SourcePriority;
    UCHAR       TargetPriority;
    USHORT      Reserved0;
    ULONG       Reserved1;
    ULONGLONG   LbaCount;
} HYBRID_DEMOTE_BY_SIZE, *PHYBRID_DEMOTE_BY_SIZE;
```

Version

The version of the structure. Set to HYBRID_REQUEST_INFO_STRUCTURE_VERSION.

Size

The size of the structure. Set to **sizeof**(HYBRID_DEMOTE_BY_SIZE).

SourcePriority

The original priority level of the data to demote. This value must be <= the value in the **MaximumHybridPriorityLevel** member of the **HYBRID_INFORMATION** structure returned by from a **HYBRID_FUNCTION_GET_INFO** function request. This value must be > 0.

TargetPriority

The target priority level of the data to demote from the *SourcePriority* level. This value must be < *SourcePriority*.

Reserved0

Reserved.

Reserved1

Reserved.

LbaCount

The number of LBAs to demote to the new priority level.

The [SRB_IO_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_srb_io_control) structure for this IOCTL contains IOCTL_MINIPORT_SIGNATURE_HYBRDISK in its **Signature** member and **IOCTL_SCSI_MINIPORT_HYBRID** in the **ControlCode** member.

## See also

[HYBRID_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_hybrid_information)

[IOCTL_SCSI_MINIPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_miniport)

[SRB_IO_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_srb_io_control)

[STORAGE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_storage_request_block)