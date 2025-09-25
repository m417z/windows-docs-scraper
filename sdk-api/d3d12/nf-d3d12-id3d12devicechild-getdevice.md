# ID3D12DeviceChild::GetDevice

## Description

Gets a pointer to the device that created this interface.

## Parameters

### `riid`

Type: **REFIID**

The globally unique identifier (**GUID**) for the device interface.
The **REFIID**, or **GUID**, of the interface to the device can be obtained by using the __uuidof() macro.
For example, __uuidof([ID3D12Device](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device)) will get the **GUID** of the interface to a device.

### `ppvDevice` [out, optional]

Type: **void****

A pointer to a memory block that receives a pointer to the [ID3D12Device](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device) interface for the device.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## Remarks

Any returned interfaces have their reference count incremented by one, so be sure to call ::release() on the returned pointers before they are freed or else you will have a memory leak.

#### Examples

The [D3D12Multithreading](https://learn.microsoft.com/windows/desktop/direct3d12/working-samples) sample uses **ID3D12DeviceChild::GetDevice** as follows:

```cpp
// Returns required size of a buffer to be used for data upload
inline UINT64 GetRequiredIntermediateSize(
    _In_ ID3D12Resource* pDestinationResource,
    _In_range_(0,D3D12_REQ_SUBRESOURCES) UINT FirstSubresource,
    _In_range_(0,D3D12_REQ_SUBRESOURCES-FirstSubresource) UINT NumSubresources)
{
    D3D12_RESOURCE_DESC Desc = pDestinationResource->GetDesc();
    UINT64 RequiredSize = 0;

    ID3D12Device* pDevice;
    pDestinationResource->GetDevice(__uuidof(*pDevice), reinterpret_cast<void**>(&pDevice));
    pDevice->GetCopyableFootprints(&Desc, FirstSubresource, NumSubresources, 0, nullptr, nullptr, nullptr, &RequiredSize);
    pDevice->Release();

    return RequiredSize;
}

```

Refer to the [Example Code in the D3D12 Reference](https://learn.microsoft.com/windows/desktop/direct3d12/notes-on-example-code).

## See also

[ID3D12DeviceChild](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12devicechild)