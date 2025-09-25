# DXGKDDI_QUERYADAPTERINFO callback function

## Description

*Dxgkrnl* calls the display miniport driver's (KMD's) **DxgkDdiQueryAdapterInfo** function to retrieve configuration information from the graphics adapter.

## Parameters

### `hAdapter` [in]

A handle to a context block that is associated with a display adapter. The KMD previously provided this handle to *Dxgkrnl* in the **MiniportDeviceContext** output parameter of the [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pQueryAdapterInfo` [in]

A pointer to a [**DXGKARG_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo) structure that the KMD fills with the configuration information for the graphics adapter.

## Return value

**DxgkDdiQueryAdapterInfo** returns STATUS_SUCCESS when it successfully retrieves the configuration information. Otherwise, it returns an NTSTATUS code such as one of the following values:

| Return code | Description |
| ----------- | ----------- |
| STATUS_INVALID_PARAMETER | One or more passed parameter contained errors that prevented it from completing.|
| STATUS_NO_MEMORY | **DxgkDdiQueryAdapterInfo** couldn't allocate memory that was required for it to complete.|
| STATUS_GRAPHICS_DRIVER_MISMATCH | The KMD isn't compatible with the user-mode display driver (UMD) that initiated the call to **DxgkDdiQueryAdapterInfo** (that is, supplied private data for a query to the KMD). |

## Remarks

When the UMD calls the Direct3D runtime's [**pfnQueryAdapterInfoCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryadapterinfocb) callback, a call to the **DxgkDdiQueryAdapterInfo** function is initiated.

* If *Dxgkrnl* specifies DXGKQAITYPE_UMDRIVERPRIVATE in [**DXGKARG_QUERYADAPTERINFO::Type**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo), **pOutputData** points to a proprietary structure that KMD fills with the configuration information that is necessary for the UMD to identify the adapter.

* If *Dxgkrnl* specifies DXGKQAITYPE_DRIVERCAPS in **DXGKARG_QUERYADAPTERINFO::Type**, the KMD should populate the provided [**DXGK_DRIVERCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps) structure with information that the subsystem can use.

* If *Dxgkrnl* specifies DXGKQAITYPE_QUERYSEGMENT in **DXGKARG_QUERYADAPTERINFO::Type**, the KMD should provide information about the memory segments that it supports. For more information about memory segments, see [Initializing Use of Memory Segments](https://learn.microsoft.com/windows-hardware/drivers/display/initializing-use-of-memory-segments).

**DxgkDdiQueryAdapterInfo** should be made pageable.

All drivers that support WDDM 2.6 and greater must implement the **DxgkDdiQueryAdapterInfo** callback.

## See also

[**DXGKARG_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo)

[**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[**pfnQueryAdapterInfoCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryadapterinfocb)