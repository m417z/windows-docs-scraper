# StorPortGetSystemAddress function

## Description

The **StorPortGetSystemAddress** routine returns a virtual address in system space for the data buffer of the specified SCSI request block (SRB).

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `Srb` [in]

A pointer to a [SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block) structure.

### `SystemAddress` [out]

A pointer to receive the virtual address of the data buffer.

## Return value

StorPortGetSystemAddress returns one of the following status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_SUCCESS** | Indicates that the system address was obtained successfully. |
| **STOR_STATUS_INVALID_PARAMETER** | This status code is caused by one of the following conditions:<br><br>The SRB does not have an associated data buffer.<br><br>The pointer to receive the virtual address is **NULL**. |
| **STOR_STATUS_INVALID_IRQL** | The call was made at an invalid IRQL. |
| **STOR_STATUS_INSUFFICIENT_RESOURCES** | The attempt to map the data buffer to system space failed. |

## Remarks

Starting in Windows 8, the *Srb* parameter may point to either [SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block) or [STORAGE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_storage_request_block). If the function identifier in the **Function** field of *Srb* is **SRB_FUNCTION_STORAGE_REQUEST_BLOCK**, the SRB is a **STORAGE_REQUEST_BLOCK** request structure.

## See also

[SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block)

[STORAGE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_storage_request_block)