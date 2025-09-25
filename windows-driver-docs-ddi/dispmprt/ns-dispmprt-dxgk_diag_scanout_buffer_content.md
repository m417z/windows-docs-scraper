# DXGK_DIAG_SCANOUT_BUFFER_CONTENT structure

## Description

The **DXGK_DIAG_SCANOUT_BUFFER_CONTENT** structure provides information about the current buffer being scanned out during diagnostic data collection.

## Members

### `ScanoutBufferCrc` [out]

A [**DXGK_DIAG_DISPLAY_SCANOUT_BUFFER_CRC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-dxgk_diag_display_scanout_buffer_crc) value.

### `ScanoutBufferHistogram` [out]

A [**DXGK_DIAG_DISPLAY_SCANOUT_BUFFER_HISTOGRAM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_diag_display_scanout_buffer_histogram) structure.

## Remarks

The **DXGK_DIAG_SCANOUT_BUFFER_CONTENT** structure is a member of the [**DXGK_DISPLAYSTATE_INTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_displaystate_intrusive) structure, which is passed in calls to [**DxgkDdiGetDisplayStateIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystateintrusive) during diagnostic data collection.

Drivers should use either **ScanoutBufferCrc** or **ScanoutBufferHistogram**, or both **ScanoutBufferCrc** and **ScanoutBufferHistogram**, to report to the operating system about the content of the current buffer being scanned out.

## See also

[**DXGK_DIAG_DISPLAY_SCANOUT_BUFFER_CRC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-dxgk_diag_display_scanout_buffer_crc)

[**DXGK_DIAG_DISPLAY_SCANOUT_BUFFER_HISTOGRAM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_diag_display_scanout_buffer_histogram)

[**DXGK_DISPLAYSTATE_INTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_displaystate_intrusive)

[**DXGKARG_GETDISPLAYSTATEINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkarg_getdisplaystateintrusive)

[**DxgkDdiGetDisplayStateIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystateintrusive)