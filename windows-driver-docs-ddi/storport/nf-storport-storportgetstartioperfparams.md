# StorPortGetStartIoPerfParams function

## Description

The **StorPortGetStartIoPerfParams** routine places the performance parameters for a given I/O request in a [STARTIO_PERFORMANCE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_startio_performance_parameters) structure.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `Srb` [in]

The SRB pointer that was passed in to the [HwStorStartIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_startio) routine that was supplied by the miniport driver. This parameter must not be **NULL**.

### `StartIoPerfParams` [in, out]

A pointer to a STARTIO_PERFORMANCE_PARAMETERS structure that the miniport driver supplies. The miniport driver needs to set only the size of the allocated structure, as Storport will set the other members. This parameter must not be **NULL**.

## Return value

StorPortGetStartIoPerfParams returns one of the following status values:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_SUCCESS** | Indicates that the performance parameters have been stored in *StartIoPerfParams*. |
| **STOR_STATUS_INVALID_PARAMETER** | Either the *Srb* parameter or the *StartIoPerfParams* parameter is **NULL**.<br><br>-or-<br><br>The *HwDeviceExtension* parameter is NULL or not valid.<br><br>-or-<br><br>The *Srb* parameter is not pointing to an SRB sent by Storport<br><br>-or-<br><br>The structure pointed to by *StartIoPerfParams* is not valid because the value of its **Size** member indicates that structure is too small to contain the returned data. |

## Remarks

Starting in Windows 8, the *Srb* parameter may point to either [SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block) or [STORAGE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_storage_request_block). If the function identifier in the **Function** field of *Srb* is **SRB_FUNCTION_STORAGE_REQUEST_BLOCK**, the SRB is a **STORAGE_REQUEST_BLOCK** request structure.

## See also

[SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block)

[STARTIO_PERFORMANCE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_startio_performance_parameters)

[STORAGE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_storage_request_block)