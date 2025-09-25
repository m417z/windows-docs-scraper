# ID3D12Device3::EnqueueMakeResident

## Description

Asynchronously makes objects resident for the device.

## Parameters

### `Flags`

Type: **[D3D12_RESIDENCY_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_residency_flags)**

Controls whether the objects should be made resident if the application is over its memory budget.

### `NumObjects`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of objects in the *ppObjects* array to make resident for the device.

### `ppObjects` [in]

Type: **[ID3D12Pageable](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12pageable)***

A pointer to a memory block; contains an array of [ID3D12Pageable](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12pageable) interface pointers for the objects.

Even though most D3D12 objects inherit from [ID3D12Pageable](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12pageable), residency changes are only supported on the following:

* descriptor heaps
* heaps
* committed resources
* query heaps

### `pFenceToSignal` [in]

Type: **[ID3D12Fence](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12fence)***

A pointer to the fence used to signal when the work is done.

### `FenceValueToSignal`

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

An unsigned 64-bit value signaled to the fence when the work is done.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## Remarks

**EnqueueMakeResident** performs the same actions as [MakeResident](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-makeresident), but does not wait for the resources to be made resident. Instead, **EnqueueMakeResident** signals a fence when the work is done.

The system will not allow work that references the resources that are being made resident by using **EnqueueMakeResident** before its fence is signaled. Instead, calls to this API are guaranteed to signal their corresponding fence in order, so the same fence can be used from call to call.

## See also

[ID3D12Device](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device)

[ID3D12Device3](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device3)