# PFND3D12DDI_OPENADAPTER callback function

## Description

The PFND3D12DDI_OPENADAPTER function creates a graphics adapter object that is referenced in subsequent calls.

## Parameters

### `unnamedParam1`

A pointer to a [D3D12DDIARG_OPENADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_openadapter) structure. On input, this structure contains information that the driver can use. On output, the driver specifies information that the Microsoft Direct3D runtime can use.

## Return value

PFND3D12DDI_OPENADAPTER returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The graphics adapter object was successfully created.|
|E_OUTOFMEMORY|PFND3D12DDI_OPENADAPTER could not allocate memory that was required for it to complete.|

## Remarks

The graphics adapter object that is created by the PFND3D12DDI_OPENADAPTER function represents the underlying graphics hardware. Before the Direct3D runtime can create a display device by calling [PFND3D12DDI_CREATEDEVICE_0003](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createdevice_0003), the user-mode display driver should call the [pfnQueryAdapterInfoCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryadapterinfocb) function to query for the graphics hardware capabilities from the display miniport driver.

The Direct3D runtime can open multiple graphics adapter objects from a single graphics adapter.