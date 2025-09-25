## Description

The **UnacquireDirect3D12BufferResource** method relinquishes control of a Direct3D 12 buffer resource to the platform.

A resource that has been acquired, but not submitted, can be un-acquired to return control of the buffer back to the platform. A resource that has been un-acquired can be re-acquired at a later time.

## Parameters

### `pResourceToUnacquire`

Type: **[ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource)\***

The Direct3D 12 resource to relinquish control of.

## Return value

**S_OK** if successful, otherwise returns an [HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) error code indicating the reason for failure. Also see [COM Error Codes (UI, Audio, DirectX, Codec)](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

## See also