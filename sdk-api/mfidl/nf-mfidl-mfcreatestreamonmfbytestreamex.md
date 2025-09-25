# MFCreateStreamOnMFByteStreamEx function

## Description

Creates an [IRandomAccessStream](https://learn.microsoft.com/previous-versions/hh438400(v=vs.85)) object that wraps a Microsoft Media Foundation byte stream.

## Parameters

### `pByteStream` [in]

A pointer to the [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) interface of the Media Foundation byte stream.

### `riid` [in]

The interface identifier (IID) of the interface being requested.

### `ppv` [out]

Receives a pointer to the requested interface. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The returned byte stream object exposes the [IMFGetService](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfgetservice) interface. To get the original [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) pointer, call [IMFGetService::GetService](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfgetservice-getservice) using the service identifier **MF_WRAPPED_OBJECT**.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)