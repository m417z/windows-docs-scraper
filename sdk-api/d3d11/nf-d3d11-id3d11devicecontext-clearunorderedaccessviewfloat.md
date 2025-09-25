# ID3D11DeviceContext::ClearUnorderedAccessViewFloat

## Description

Clears an [unordered access](https://learn.microsoft.com/windows/desktop/direct3d11/direct3d-11-advanced-stages-cs-resources) resource with a float value.

## Parameters

### `pUnorderedAccessView` [in]

Type: **[ID3D11UnorderedAccessView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11unorderedaccessview)***

The [ID3D11UnorderedAccessView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11unorderedaccessview) to clear.

### `Values` [in]

Type: **const FLOAT[4]**

Values to copy to corresponding channels, see remarks.

## Remarks

This API works on FLOAT, UNORM, and SNORM unordered access views (UAVs), with format conversion from FLOAT to *NORM where appropriate. On other UAVs, the operation is invalid and the call will not reach the driver.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)