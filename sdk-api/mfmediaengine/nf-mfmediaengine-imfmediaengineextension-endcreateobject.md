# IMFMediaEngineExtension::EndCreateObject

## Description

Completes an asynchronous request to create a byte stream or media source.

## Parameters

### `pResult` [in]

A pointer to the [IMFAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasyncresult) interface.

### `ppObject` [out]

Receives a pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of the byte stream or media source. The caller must release the interface

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The Media Engine calls this method to complete the [IMFMediaEngineExtension::BeginCreateObject](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengineextension-begincreateobject) method.

## See also

[IMFMediaEngineExtension](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineextension)