# ID3D12Device::MakeResident

## Description

Makes objects resident for the device.

## Parameters

### `NumObjects`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of objects in the *ppObjects* array to make resident for the device.

### `ppObjects` [in]

Type: **[ID3D12Pageable](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12pageable)***

A pointer to a memory block that contains an array of [ID3D12Pageable](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12pageable) interface pointers for the objects.

Even though most D3D12 objects inherit from [ID3D12Pageable](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12pageable), residency changes are only supported on the following objects:
Descriptor Heaps, Heaps, Committed Resources, and Query Heaps

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## Remarks

**MakeResident** loads the data associated with a resource from disk, and re-allocates the memory from the resource's appropriate memory pool. This method should be called on the object which owns the physical memory.

Use this method, and [Evict](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-evict), to manage GPU video memory, noting that this was done automatically in D3D11, but now has to be done by the app in D3D12.

**MakeResident** and [Evict](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-evict) can help applications manage the residency budget on many adapters. **MakeResident** explicitly pages-in data and, then, precludes page-out so the GPU can access the data. **Evict** enables page-out.

Some GPU architectures do not benefit from residency manipulation, due to the lack of sufficient GPU virtual address space. Use [D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_feature_data_gpu_virtual_address_support) and [IDXGIAdapter3::QueryVideoMemoryInfo](https://learn.microsoft.com/windows/desktop/api/dxgi1_4/nf-dxgi1_4-idxgiadapter3-queryvideomemoryinfo) to recognize when the maximum GPU VA space per-process is too small or roughly the same size as the residency budget. For such architectures, the residency budget will always be constrained by the amount of GPU virtual address space. [Evict](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-evict) will not free-up any residency budget on such systems.

Applications must handle **MakeResident** failures, even if there appears to be enough residency budget available. Physical memory fragmentation and adapter architecture quirks can preclude the utilization of large contiguous ranges. Applications should free up more residency budget before trying again.

**MakeResident** is ref-counted, such that [Evict](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-evict) must be called the same amount of times as **MakeResident** before **Evict** takes effect. Objects that support residency are made resident during creation, so a single **Evict** call will actually evict the object.

Applications must use fences to ensure the GPU doesn't use non-resident objects. **MakeResident** must return before the GPU executes a command list that references the object. [Evict](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-evict) must be called after the GPU finishes executing a command list that references the object.

Evicted objects still consume the same GPU virtual address and same amount of GPU virtual address space. Therefore, resource descriptors and other GPU virtual address references are not invalidated after [Evict](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-evict).

## See also

[ID3D12Device](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device)