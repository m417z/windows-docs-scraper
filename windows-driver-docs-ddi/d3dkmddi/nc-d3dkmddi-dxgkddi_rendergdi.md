# DXGKDDI_RENDERGDI callback function

## Description

**DxgkDdiRenderGdi** is used when submitting Windows Graphics Device Interface (GDI) commands for contexts that support virtual addressing.

## Parameters

### `hContext`

A handle to a context block that is associated with a display adapter.

### `pRenderGdi`

A pointer to a [DXGKARG_RENDERGDI](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_rendergdi) structure that describes operation.

## Return value

|Value|Description|
|--- |--- |
|STATUS_SUCCESS|The submitted command is well-formed.|
|(other)|All other return values will lead to the OS bugcheck.|

## See also

[DXGKARG_RENDERGDI](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_rendergdi)