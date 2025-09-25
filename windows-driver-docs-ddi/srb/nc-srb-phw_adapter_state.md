# PHW_ADAPTER_STATE callback

## Description

The PHW_INITIALIZE routine prototype declares a routine that saves or restores the state of the miniport driver's HBA.

## Parameters

### `DeviceExtension` [in]

Pointer to the miniport driver's per-HBA storage area.

### `Context` [in]

Reserved for system use.

### `SaveState` [in]

Indicates, when **TRUE**, that the miniport driver should save the current state of the HBA until the [HwScsiAdapterState](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557278(v=vs.85)) routine is called again with *SaveState* set to **FALSE** to restore the saved state.

## Return value

The routine declared by this prototype returns **TRUE** if it successfully saved or restored the HBA state, **FALSE** otherwise.

## Remarks

Only SCSI miniport drivers use this prototype. Miniport drivers that work with the StorPort driver do not use the routine that is declared by this prototype.

For more information about the routine declared by this prototype, see [HwScsiAdapterState](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557278(v=vs.85)).

## See also

[HwScsiAdapterState](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557278(v=vs.85))