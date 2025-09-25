# PFND3DDDI_LOGUMDMARKERCB callback function

## Description

Called by the user-mode display driver to log a custom Event Tracing for Windows (ETW) marker event.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pLogUMDMarker* [in]

A pointer to a [D3DDDICB_LOGUMDMARKER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddicb_logumdmarker) structure that indicates the location of an ETW marker event that is defined by the user-mode display driver.

## Return value

Returns **S_OK** or an appropriate error result if the function does not complete successfully.