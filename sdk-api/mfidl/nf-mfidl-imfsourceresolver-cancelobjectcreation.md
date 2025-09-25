# IMFSourceResolver::CancelObjectCreation

## Description

Cancels an asynchronous request to create an object.

## Parameters

### `pIUnknownCancelCookie` [in]

Pointer to the **IUnknown** interface that was returned in the *ppIUnknownCancelCookie* parameter of the [IMFSourceResolver::BeginCreateObjectFromByteStream](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsourceresolver-begincreateobjectfrombytestream) or [IMFSourceResolver::BeginCreateObjectFromURL](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsourceresolver-begincreateobjectfromurl) method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You can use this method to cancel a previous call to [BeginCreateObjectFromByteStream](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsourceresolver-begincreateobjectfrombytestream) or [BeginCreateObjectFromURL](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsourceresolver-begincreateobjectfromurl). Because these methods are asynchronous, however, they might be completed before the operation can be canceled. Therefore, your callback might still be invoked after you call this method.

**Note** This method cannot be called remotely.

## See also

[IMFSourceResolver](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsourceresolver)

[Source Resolver](https://learn.microsoft.com/windows/desktop/medfound/source-resolver)