# DXGKARG_GETDISPLAYSTATENONINTRUSIVE structure

## Description

The **DXGKARG_GETDISPLAYSTATENONINTRUSIVE** structure is passed to [**DxgkDdiGetDisplayStateNonIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystatenonintrusive) during diagnostic data collection.

## Members

### `NumOfTargets`

The number of targets on which the operating system believes there is a monitor connected with a corresponding VidPnTargetId filled in.

### `SizeOfDisplayStateNonIntrusiveElement`

Size of a [**DXGK_DISPLAYSTATE_NONINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_displaystate_nonintrusive) structure, in bytes. Set to ```sizeof(DXGK_DISPLAYSTATE_NONINTRUSIVE)```.

### `ppDisplayStateNonIntrusive`

Pointer to an array of pointers to [**DXGK_DISPLAYSTATE_NONINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_displaystate_nonintrusive) structures.

## Remarks

DXGKRNL passes **DXGKARG_GETDISPLAYSTATENONINTRUSIVE** in calls to [**DxgkDdiGetDisplayStateNonIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystatenonintrusive) during diagnostic data collection.

## See also

[**DXGK_DISPLAYSTATE_NONINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_displaystate_nonintrusive)

[**DxgkDdiGetDisplayStateNonIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystatenonintrusive)