# ISearchProtocol::CloseAccessor

## Description

Closes a previously created [IUrlAccessor](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-iurlaccessor) object.

## Parameters

### `pAccessor` [in]

Type: **[IUrlAccessor](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-iurlaccessor)***

Pointer to the [IUrlAccessor](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-iurlaccessor) object that was used to process the current URL item.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The protocol host will release the *pAccessor* pointer passed to this method when this method returns. Use this method to release any resources associated with the [IUrlAccessor](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-iurlaccessor) object, freeing it for reuse by the protocol handler.

Accessors can be created and maintained in a pool, as resources to be used by protocol handlers when needed, and this might improve performance. If you are implementing a pool of [IUrlAccessor](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-iurlaccessor) objects, use [IUnknown::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) to add an **IUrlAccessor** to your pool.