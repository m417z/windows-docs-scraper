# IDXGISurface2::GetResource

## Description

Gets the parent resource and subresource index that support a subresource surface.

## Parameters

### `riid` [in]

The globally unique identifier (GUID) of the requested interface type.

### `ppParentResource` [out]

A pointer to a buffer that receives a pointer to the parent resource object for the subresource surface.

### `pSubresourceIndex` [out]

A pointer to a variable that receives the index of the subresource surface.

## Return value

Returns S_OK if successful; otherwise, returns one of the following values:

* E_NOINTERFACE if the object does not implement the GUID that the *riid* parameter specifies.
* Possibly other error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

## Remarks

For subresource surface objects that the [IDXGIResource1::CreateSubresourceSurface](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgiresource1-createsubresourcesurface) method creates, **GetResource** simply returns the values that were used to create the subresource surface.

Current objects that implement [IDXGISurface](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgisurface) are either resources or views. **GetResource** for these objects returns “this” or the resource that supports the view respectively. In this situation, the subresource index is 0.

## See also

[IDXGISurface2](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgisurface2)