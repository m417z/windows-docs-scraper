# ChangerError function

## Description

**ChangerError** performs device-specific error handling.

## Parameters

### `DeviceObject`

Pointer to the device object that represents the changer.

### `Srb`

Pointer to the SCSI request block for the operation that failed.

### `Status`

Specifies the address of the STATUS_*XXX* code set by the system. The changer miniclass driver can change the status or leave it as is.

### `Retry`

Pointer to a flag that indicates whether to retry the request. The changer miniclass driver can set this flag or leave it as is.

## Remarks

This routine is required.

If an SRB fails with a SCSI status of CHECK CONDITION, the SCSI class driver calls the changer class driver's **ChangerClassError** routine. **ChangerClassError** performs device-independent error handling and calls the changer miniclass driver's **ChangerError** routine.

**ChangerError** first checks *Srb***->SrbStatus** with SRB_STATUS_AUTOSENSE_VALID to make sure the sense data buffer is valid. If so, it checks the sense data in *Srb***->SenseInfoBuffer** to determine whether to update **Status* with a more accurate STATUS_*XXX* code and/or set the *Retry* flag before returning to the changer class driver. The changer class driver's retry count determines whether the SRB is actually retried.