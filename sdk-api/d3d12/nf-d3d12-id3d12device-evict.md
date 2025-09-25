# ID3D12Device::Evict

## Description

Enables the page-out of data, which precludes GPU access of that data.

## Parameters

### `NumObjects`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of objects in the *ppObjects* array to evict from the device.

### `ppObjects` [in]

Type: **[ID3D12Pageable](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12pageable)***

A pointer to a memory block that contains an array of [ID3D12Pageable](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12pageable) interface pointers for the objects.

Even though most D3D12 objects inherit from [ID3D12Pageable](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12pageable), residency changes are only supported on the following objects:
Descriptor Heaps, Heaps, Committed Resources, and Query Heaps

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## Remarks

**Evict** persists the data associated with a resource to disk, and then removes the resource from the memory pool where it was located. This method should be called on the object which owns the physical memory: either a committed resource (which owns both virtual and physical memory assignments) or a heap - noting that reserved resources do not have physical memory, and placed resources are borrowing memory from a heap.

Refer to the remarks for [MakeResident](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-makeresident).

## See also

[ID3D12Device](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device)