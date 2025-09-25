# _STORAGE_PREDICT_FAILURE structure (minitape.h)

## Description

The STORAGE_PREDICT_FAILURE structure is used in conjunction with [IOCTL_STORAGE_PREDICT_FAILURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_predict_failure) to report whether a device is currently predicting a failure.

## Members

### `PredictFailure`

Indicates when nonzero that the device is currently predicting an imminent failure.

### `VendorSpecific`

Contains an array that holds 512 bytes of vendor-specific information if the device supports failure prediction.

## Remarks

Upon receiving an [IOCTL_STORAGE_PREDICT_FAILURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_predict_failure) device control request, the disk class driver attempts to verify if an IDE drive supports SMART. If the drive is a SCSI drive, the class driver attempts to verify if the SCSI disk supports the equivalent IDE SMART technology: Information Exception Control Page, X3T10/94-190 Rev 4.

If the device does not support failure prediction, the disk class driver fails the IRP with a status of STATUS_INVALID_DEVICE_REQUEST.

If the device supports failure prediction, the disk class driver queries the device for failure prediction status. If the device has bad sectors and predicts a failure, the disk class driver returns a nonzero value in **PredictFailure**. If status indicates that the device does not predict any failures at this time, the disk class driver returns a value of 0 in **PredictFailure**.

## See also

[IOCTL_STORAGE_PREDICT_FAILURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_predict_failure)