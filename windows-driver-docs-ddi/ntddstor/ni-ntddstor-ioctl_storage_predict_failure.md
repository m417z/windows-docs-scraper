# IOCTL_STORAGE_PREDICT_FAILURE IOCTL

## Description

Polls for a prediction of device failure. This request works with the IDE disk drives that support self-monitoring analysis and reporting technology (SMART). If the drive is a SCSI drive, the class driver attempts to verify if the SCSI disk supports the equivalent IDE SMART technology by check the inquiry information on the Information Exception Control Page, X3T10/94-190 Rev 4.

If the device supports prediction failure, the disk class driver queries the device for failure prediction status and reports the results. If the disk class driver assigns a nonzero value to the **PredictFailure** member of [STORAGE_PREDICT_FAILURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_predict_failure) in the output buffer at **Irp->AssociatedIrp.SystemBuffer**, the disk has bad sectors and is predicting a failure. The storage stack returns 512 bytes of vendor-specific information about the failure prediction in the **VendorSpecific** member of STORAGE_PREDICT_FAILURE.

If the **PredictFailure** member contains a value of zero, the disk is not predicting a failure.

If the device does not support failure prediction, IOCTL_STORAGE_PREDICT_FAILURE fails with a status of STATUS_INVALID_DEVICE_REQUEST, and the data in the output buffer is undefined

Other means of checking for disk failure include monitoring the event log and registering to receive a WMI event with WMI_STORAGE_PREDICT_FAILURE_EVENT_GUID.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The driver returns a [STORAGE_PREDICT_FAILURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_predict_failure) structure containing failure prediction data in the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** indicates the size, in bytes, of the buffer at **Irp->AssociatedIrp.SystemBuffer,** which must be greater or equal to the **sizeof**(STORAGE_PREDICT_FAILURE).

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## See also

[STORAGE_PREDICT_FAILURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_predict_failure)