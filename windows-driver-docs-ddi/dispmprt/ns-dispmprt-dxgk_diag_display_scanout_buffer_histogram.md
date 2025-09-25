# DXGK_DIAG_DISPLAY_SCANOUT_BUFFER_HISTOGRAM structure

## Description

The **DXGK_DIAG_DISPLAY_SCANOUT_BUFFER_HISTOGRAM** structure provides histogram information for the current buffer being scanned out during diagnostic data collection.

## Members

### `MinPixelValue`

Minimum pixel value in the histogram for the currently scanned out buffer. A value of -1 specifies that no histograms are supported.

### `MaxPixelValue`

Maximum pixel value in the histogram for the currently scanned out buffer.

## Remarks

**DXGK_DIAG_DISPLAY_SCANOUT_BUFFER_HISTOGRAM** is a member of the [**DXGK_DIAG_SCANOUT_BUFFER_CONTENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_diag_scanout_buffer_content) structure, which is passed as a member of the [**DXGK_DISPLAYSTATE_INTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_displaystate_intrusive) structure in calls to [**DxgkDdiGetDisplayStateIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystateintrusive) during diagnostic data collection.

If the hardware doesn't support CRC calculation on the scanned out pixels and the driver/hardware maintains a histogram of the buffers being scanned out then it should return **MinPixelValue** and **MaxPixelValue** for the current buffer being scanned out. These values should be on the final scanned out pixels including all gamma and any other transformation applied. Since the minimum and maximum values will depend on the gamma values, and the operating system might not know the whole gamma curve being applied, the OS will only use these values for an overall decision of whether the pixels might be black or near black.

## See also

[**DXGK_DIAG_SCANOUT_BUFFER_CONTENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_diag_scanout_buffer_content)

[**DXGK_DIAG_DISPLAY_SCANOUT_BUFFER_CRC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-dxgk_diag_display_scanout_buffer_crc)

[**DXGK_DISPLAYSTATE_INTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_displaystate_intrusive)

[**DXGKARG_GETDISPLAYSTATEINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkarg_getdisplaystateintrusive)

[**DxgkDdiGetDisplayStateIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystateintrusive)