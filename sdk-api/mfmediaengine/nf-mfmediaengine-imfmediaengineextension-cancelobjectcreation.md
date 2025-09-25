# IMFMediaEngineExtension::CancelObjectCreation

## Description

Cancels the current request to create an object.

## Parameters

### `pIUnknownCancelCookie` [in]

The pointer that was returned in the *ppIUnknownCancelCookie* parameter of the [IMFMediaEngineExtension::BeginCreateObject](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengineextension-begincreateobject) method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method attempts to cancel a previous call to [BeginCreateObject](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengineextension-begincreateobject). Because that method is asynchronous, however, it might complete before the operation can be canceled.

## See also

[IMFMediaEngineExtension](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineextension)