# PHW_STARTIO callback

## Description

The PHW_INITIALIZE routine prototype declares a routine that initializes the miniport driver after a reboot or power failure occurs.

## Parameters

### `DeviceExtension` [in]

Pointer to the miniport driver's per-HBA storage area.

### `Srb` [in]

Pointer to the SCSI request block to be started.

## Return value

The start I/O routine returns **TRUE** to acknowledge receipt of the SCSI request block (SRB). If the start I/O routine does not receive a well-formed SRB, it returns **FALSE**.

## Remarks

The start routine for both SCSI and StorPort miniport drivers are declared using this prototype.

For more information about the SCSI miniport driver's start I/O routine see [HwScsiStartIo](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557323(v=vs.85)).

For more information about the miniport driver's start I/O routine that is used with the StorPort driver see [HwStorStartIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_startio).

## See also

[HwScsiStartIo](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557323(v=vs.85))

[HwStorStartIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_startio)