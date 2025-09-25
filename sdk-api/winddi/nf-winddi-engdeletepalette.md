# EngDeletePalette function

## Description

The **EngDeletePalette** function sends a request to GDI to delete the specified palette.

## Parameters

### `hpal` [in]

Handle to the palette to be deleted. This handle is supplied by [EngCreatePalette](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatepalette).

## Return value

The return value is **TRUE** if the function is successful; otherwise, it returns **FALSE**.