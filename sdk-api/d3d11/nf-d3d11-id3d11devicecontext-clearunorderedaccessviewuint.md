# ID3D11DeviceContext::ClearUnorderedAccessViewUint

## Description

Clears an [unordered access](https://learn.microsoft.com/windows/desktop/direct3d11/direct3d-11-advanced-stages-cs-resources) resource with bit-precise values.

## Parameters

### `pUnorderedAccessView` [in]

Type: **[ID3D11UnorderedAccessView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11unorderedaccessview)***

The [ID3D11UnorderedAccessView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11unorderedaccessview) to clear.

### `Values` [in]

Type: **const [UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)[4]**

Values to copy to corresponding channels, see remarks.

## Remarks

This API copies the lower ni bits from each array element i to the corresponding channel, where ni is the number of bits in
the ith channel of the resource format (for example, R8G8B8_FLOAT has 8 bits for the first 3 channels). This works on any UAV with no format conversion.
For a raw or structured buffer view, only the first array element value is used.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)