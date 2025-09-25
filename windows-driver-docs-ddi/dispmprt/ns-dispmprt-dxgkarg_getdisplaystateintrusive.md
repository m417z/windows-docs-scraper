# DXGKARG_GETDISPLAYSTATEINTRUSIVE structure

## Description

The **DXGKARG_GETDISPLAYSTATEINTRUSIVE** structure is passed to [**DxgkDdiGetDisplayStateIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystateintrusive) during diagnostic data collection.

## Members

### `NumOfTargets`

The number of targets on which the operating system believes there is a monitor connected with a corresponding VidPnTargetId filled in.

### `SizeOfDisplayStateIntrusiveElement`

Size of a [**DXGK_DISPLAYSTATE_INTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_displaystate_intrusive) structure, in bytes. Set to ```sizeof(DXGK_DISPLAYSTATE_INTRUSIVE)```.

### `ppDisplayStateIntrusive`

Pointer to an array of pointers to [**DXGK_DISPLAYSTATE_INTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_displaystate_intrusive) structures.

## Remarks

DXGKRNL passes **DXGKARG_GETDISPLAYSTATEINTRUSIVE** in calls to [**DxgkDdiGetDisplayStateIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystateintrusive) during diagnostic data collection.

## See also

[**DXGK_DISPLAYSTATE_INTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_displaystate_intrusive)

[**DxgkDdiGetDisplayStateIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystateintrusive)