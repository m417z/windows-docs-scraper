# PHW_INITIALIZE callback

## Description

The PHW_INITIALIZE routine prototype declares a routine that initializes the miniport driver after a reboot or power failure occurs.

## Parameters

### `DeviceExtension` [in]

Pointer to the miniport driver's per-HBA storage area.

## Return value

If the operation succeeds, the initialization routine returns **TRUE**. Otherwise, the initialize routine returns **FALSE**.

## Remarks

The initialization routine for both SCSI and StorPort miniport drivers are declared using this prototype.

For more information about the SCSI miniport driver initialization routine see [HwScsiInitialize](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557302(v=vs.85)).

For more information about the miniport driver initialization routine that is used with the StorPort driver see [HwStorInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_initialize).

## See also

[HwScsiInitialize](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557302(v=vs.85))

[HwStorInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_initialize)