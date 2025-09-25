## Description

The **DXGKARGCB_RELEASEHANDLEDATA** structure contains the information used by the [**DXGKCB_RELEASEHANDLEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_releasehandledata) callback function to release a reference to an allocation.

## Members

### `ReleaseHandle` [in]

The release handle obtained from a prior call to [**DXGKCB_ACQUIREHANDLEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_acquirehandledata).

### `Type` [in]

A [**DXGK_HANDLE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-dxgk_handle_type) value that identifies the handle type of the allocation.

## See also

[**DXGK_HANDLE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-dxgk_handle_type)

[**DXGKCB_RELEASEHANDLEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_releasehandledata)