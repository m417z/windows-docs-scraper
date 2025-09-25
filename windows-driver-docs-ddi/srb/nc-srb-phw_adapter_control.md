# PHW_ADAPTER_CONTROL callback

## Description

The PHW_INITIALIZE routine prototype declares a routine that initializes the miniport driver after a reboot or power failure occurs.

## Parameters

### `DeviceExtension` [in]

Pointer to the miniport driver's per-HBA storage area.

### `ControlType` [in]

Specifies an adapter-control operation. For a list of the allowed operations, see [HwScsiAdapterControl](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557274(v=vs.85)).

### `Parameters` [in]

Contains information related to the *ControlType*. For an explanation of the meaning of these values, see the discussion accompanying the *Parameters* parameter of the [HwScsiAdapterControl](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557274(v=vs.85)).

## Return value

The routine declared by this prototype returns different sets of values depending on the control type. For a complete description of the return values, see [HwScsiAdapterControl](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557274(v=vs.85)).

## Remarks

The adapter control routine for both SCSI and StorPort miniport drivers are declared using this prototype.

For more information about the SCSI miniport driver's adapter control routine, see [HwScsiAdapterControl](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557274(v=vs.85)).

For more information about the adapter control routine that is used with the StorPort driver's miniport driver, see [HwStorAdapterControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control).

## See also

[HwScsiAdapterControl](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557274(v=vs.85))

[HwStorAdapterControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control)