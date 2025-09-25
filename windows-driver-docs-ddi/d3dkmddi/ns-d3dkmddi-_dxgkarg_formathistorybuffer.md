# _DXGKARG_FORMATHISTORYBUFFER structure

## Description

Contains info for the display miniport driver to format a history buffer.

## Members

### `pHistoryBuffer`

A pointer to the unformatted [DXGK_HISTORY_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_history_buffer) history buffer that was populated by the GPU.

### `HistoryBufferSize`

The size, in bytes, of the buffer pointed to by **pHistoryBuffer**.

### `pFormattedBuffer`

A pointer to a segment of non-paged system memory that the driver uses to store time stamp info that it derives from the provided unformatted history buffer.

The buffer pointed to by **pFormattedBuffer** should be managed as a large array of time stamps of precision specified by **Precision**. The buffer should not contain any header info that already exists in the original history buffer.

### `FormattedBufferSize`

The size, in bytes, of the buffer pointed to by **pFormattedBuffer**. The driver should ensure that it doesn't write data beyond this buffer size.

### `NumTimestamps`

The number of time stamps. On completion of a call to the [DxgkDdiFormatHistoryBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_formathistorybuffer) function, the driver should set this value to the number of time stamps that are written to the formatted buffer pointed to by **pFormattedBuffer**.

Note that the number of time stamps that will be in the formatted output buffer won't be known until the driver completes the formatted buffer pointed to by **pFormattedBuffer**.

### `Precision`

A [DXGKARG_HISTORYBUFFERPRECISION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_historybufferprecision) structure that the driver fills with info on the precision of the time stamps that will be logged to the Event Tracing for Windows (ETW) facility.

The value of the [DXGKARG_HISTORYBUFFERPRECISION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_historybufferprecision).**PrecisionBits** member cannot be zero.

### `Offset`

On input to a call to the [DxgkDdiFormatHistoryBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_formathistorybuffer) function, the value of this member is the offset to the first time stamp at which formatting should start. On completion of the function call, the driver should set the value to zero if it successfully formatted all the time stamps in the history buffer.

If nonzero, the driver could not format all the time stamps in the history buffer without filling the formatted buffer. In this case, the value represents the offset that should be continued from in the next function call.

## Remarks

The driver should obtain time stamp entries and the number of usable time stamps from the header of the provided history buffer. Any additional data that the driver needs for calculations should be stored in private data.

## See also

[DXGKARG_HISTORYBUFFERPRECISION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_historybufferprecision)

[DXGK_HISTORY_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_history_buffer)

[DxgkDdiFormatHistoryBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_formathistorybuffer)