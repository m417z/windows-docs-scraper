# IMFByteStreamProxyClassFactory::CreateByteStreamProxy

## Description

Creates a proxy to a byte stream. The proxy enables a media source to read from a byte stream in another process.

## Parameters

### `pByteStream` [in]

A pointer to the [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) interface of the byte stream to proxy.

### `pAttributes` [in]

Reserved. Set to **NULL**.

### `riid` [in]

The interface identifier (IID) of the interface being requested.

### `ppvObject` [out]

Receives a pointer to the interface. The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFByteStreamProxyClassFactory](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestreamproxyclassfactory)