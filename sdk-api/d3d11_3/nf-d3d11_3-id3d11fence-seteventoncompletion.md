# ID3D11Fence::SetEventOnCompletion

## Description

Specifies an event that should be fired when the fence reaches a certain value.

This member function is equivalent to the Direct3D 12 [ID3D12Fence::SetEventOnCompletion](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12fence-seteventoncompletion) member function, and applies between Direct3D 11 and Direct3D 12 in interop scenarios.

## Parameters

### `Value`

Type: **[UINT64](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

The fence value when the event is to be signaled.

### `hEvent`

Type: **[HANDLE](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

A handle to the event object.

## Return value

Type: **HRESULT**

This method returns **E_OUTOFMEMORY** if the kernel components don’t have sufficient memory to store the event in a list. See [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-returnvalues) for other possible return values.

## See also

[ID3D11Fence](https://learn.microsoft.com/windows/win32/api/d3d11_3/nn-d3d11_3-id3d11fence)

[Multi-engine synchronization](https://learn.microsoft.com/windows/win32/direct3d12/user-mode-heap-synchronization)