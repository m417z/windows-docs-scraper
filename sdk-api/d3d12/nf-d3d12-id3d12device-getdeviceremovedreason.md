## Description

Gets the reason that the device was removed, or **S_OK** if the device isn't removed. To be called back when a device is removed, consider using [ID3D12Fence::SetEventOnCompletion](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12fence-seteventoncompletion) with a value of **UINT64_MAX**. That's because device removal causes all fences to be signaled to that value (which also implies completing all events waited on, because they'll all be less than **UINT64_MAX**).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns the reason that the device was removed.

## See also

[ID3D12Device](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device)