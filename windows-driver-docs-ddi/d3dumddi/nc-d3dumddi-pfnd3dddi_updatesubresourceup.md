# PFND3DDDI_UPDATESUBRESOURCEUP callback function

## Description

Called by the Microsoft Direct3D runtime to update a destination subresource region from a source system-memory region. Must be implemented by Windows Display Driver Model (WDDM) 1.3 and later user-mode display drivers.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pCounterInfo* [in]

A pointer to a [D3DDDIARG_UPDATESUBRESOURCEUP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddiarg_updatesubresourceup) structure that describes how to update a destination subresource region from a source system-memory region.

## Return value

If this routine succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[D3DDDIARG_UPDATESUBRESOURCEUP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddiarg_updatesubresourceup)