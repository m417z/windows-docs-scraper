# PFND3D10_2DDI_GETCAPS callback function

## Description

The *GetCaps(D3D10_2)* function queries for capabilities of the graphics adapter.

## Parameters

### `unnamedParam1`

*hAdapter* [in]

A handle that identifies the graphics adapter.

### `unnamedParam2`

*pData* [in]

A pointer to a [D3D10_2DDIARG_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_2ddiarg_getcaps) structure that describes the capabilities to retrieve.

## Return value

*GetCaps(D3D10_2)* returns one of the following values:

|Return code|Description|
|---|---|
|S_OK|The capabilities are successfully retrieved.|
|E_OUTOFMEMORY|GetCaps(D3D10_2) could not allocate memory that is required for it to complete.|

## Remarks

The data that is returned by the *GetCaps(D3D10_2)* function in the **pData** member of the [D3D10_2DDIARG_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_2ddiarg_getcaps) structure depends on the type of data that is requested (that is, the data depends on the **Type** member of D3D10_2DDIARG_GETCAPS and sometimes on the **pInfo** member).

## See also

[D3D10_2DDIARG_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_2ddiarg_getcaps)

[D3D10_2DDI_ADAPTERFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_2ddi_adapterfuncs)