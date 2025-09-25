# PFND3D10DDI_OPENADAPTER callback function

## Description

The *OpenAdapter10* function creates a graphics adapter object that is referenced in subsequent calls.

## Parameters

### `unnamedParam1`

*pOpenData* [in, out]

A pointer to a [D3D10DDIARG_OPENADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_openadapter) structure. On input, this structure contains information that the driver can use. On output, the driver specifies information that the Microsoft Direct3D runtime can use.

## Return value

*OpenAdapter10* returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The graphics adapter object was successfully created. |
| **E_OUTOFMEMORY** | OpenAdapter10 could not allocate memory that was required for it to complete. |

## Remarks

The graphics adapter object that is created by the *OpenAdapter10* function represents the underlying graphics hardware. Before the Direct3D runtime can create a display device by calling [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice), the user-mode display driver should call the [pfnQueryAdapterInfoCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryadapterinfocb) function to query for the graphics hardware capabilities from the display miniport driver.

The Direct3D runtime can open multiple graphics adapter objects from a single graphics adapter.

## See also

[CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[D3D10DDIARG_OPENADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_openadapter)

[pfnQueryAdapterInfoCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryadapterinfocb)