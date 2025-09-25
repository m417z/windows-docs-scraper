# DXGKDDI_FORMATHISTORYBUFFER callback function

## Description

 Copies unformatted data from the history buffer into a buffer that's properly formatted to be submitted to the Event Tracing for Windows (ETW) facility.

## Parameters

### `hContext`

A handle to the device context for the DMA buffer that contains the unformatted history buffer.

### `pFormatData`

A pointer to a [DXGKARG_FORMATHISTORYBUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_formathistorybuffer) structure that contains data about how to format the history buffer.

## Return value

Returns **STATUS_SUCCESS** if it succeeds; otherwise, it returns one of the error codes defined in Ntstatus.h.

## See also

[DXGKARG_FORMATHISTORYBUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_formathistorybuffer)