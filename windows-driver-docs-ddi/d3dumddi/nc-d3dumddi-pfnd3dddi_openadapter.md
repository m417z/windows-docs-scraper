# PFND3DDDI_OPENADAPTER callback function

## Description

The user-mode display driver's (UMD) **OpenAdapter** function creates a graphics adapter object that is referenced in subsequent calls.

## Parameters

### `unnamedParam1`

[in/out] *pOpenData* points to a [**D3DDDIARG_OPENADAPTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_openadapter) structure. On input, this structure contains information that the driver can use. On output, the driver specifies information that the Direct3D runtime can use.

## Return value

**OpenAdapter** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The graphics adapter object is successfully created.|
|E_OUTOFMEMORY|OpenAdapter could not allocate the required memory for it to complete.|

## Remarks

The graphics adapter object that is created by **OpenAdapter** represents the underlying graphics hardware. Before the Direct3D runtime can create a display device by calling [**CreateDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdevice), the UMD should call the [**pfnQueryAdapterInfoCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryadapterinfocb) function to query for the graphics hardware capabilities from the kernel-mode display miniport driver (KMD).

The Direct3D runtime can open multiple graphics adapter objects from a single graphics adapter.

## See also

[**CreateDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdevice)

[**D3DDDIARG_OPENADAPTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_openadapter)

[**pfnQueryAdapterInfoCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryadapterinfocb)