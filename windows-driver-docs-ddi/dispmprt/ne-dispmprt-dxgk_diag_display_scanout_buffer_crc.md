# DXGK_DIAG_DISPLAY_SCANOUT_BUFFER_CRC enumeration

## Description

The **DXGK_DIAG_DISPLAY_SCANOUT_BUFFER_CRC** enum provides CRC information for the current buffer being scanned out during diagnostic data collection.

## Constants

### `DXGK_DIAG_DISPLAY_SCANOUT_BUFFER_CRC_UNINITIALIZED`

Reserved for OS use during diagnostic initialization.

### `DXGK_DIAG_DISPLAY_SCANOUT_BUFFER_CRC_BLACK`

Driver should return this value if based on the calculated CRC of the scanned out pixels they appear as all black.

### `DXGK_DIAG_DISPLAY_SCANOUT_BUFFER_CRC_NON_BLACK`

Driver should return this value if based on the calculated CRC of the scanned out pixels they do not appear as all black.

### `DXGK_DIAG_DISPLAY_SCANOUT_BUFFER_CRC_ERROR`

Driver should return this value if there was an error encountered while calculating the CRC or reference CRC was missing.

### `DXGK_DIAG_DISPLAY_SCANOUT_BUFFER_CRC_UNKNOWN`

Driver should return this value if the hardware doesn't support calculating the CRC on scanned out pixels.

## Remarks

The **DXGK_DIAG_DISPLAY_SCANOUT_BUFFER_CRC** enum is a member of the [**DXGK_DIAG_SCANOUT_BUFFER_CONTENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_diag_scanout_buffer_content) structure, which is passed as a member of the [**DXGK_DISPLAYSTATE_INTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_displaystate_intrusive) structure in calls to [**DxgkDdiGetDisplayStateIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystateintrusive) during diagnostic data collection.

If the hardware supports performing a CRC calculation on the final scanned out pixels then the driver should enable it. If the driver would need a reference black CRC to check against the current CRC then it should always cache the reference one. If the reference CRC depends on the current mode then it should change the reference on mode changes.

## See also

[**DXGK_DIAG_SCANOUT_BUFFER_CONTENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_diag_scanout_buffer_content)

[**DXGK_DIAG_DISPLAY_SCANOUT_BUFFER_HISTOGRAM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_diag_display_scanout_buffer_histogram)

[**DXGK_DISPLAYSTATE_INTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_displaystate_intrusive)

[**DXGKARG_GETDISPLAYSTATEINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkarg_getdisplaystateintrusive)

[**DxgkDdiGetDisplayStateIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystateintrusive)