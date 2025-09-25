## Description

Allows the caller to specify the [IMFContentEnabler](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfcontentenabler) interface that shall be used by the Content Decryption Module (CDM).

## Parameters

### `contentEnabler`

The [IMFContentEnabler](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfcontentenabler) interface to be used by the CDM.

### `result`

An [IMFAsyncResult](https://learn.microsoft.com/windows/win32/api/mfobjects/nn-mfobjects-imfasyncresult) that provides information about the result of the operation.

## Return value

Returns S_OK on success.

## Remarks

The IMFContentEnabler is typically obtained by calling [IMFInputTrustAuthority::RequestAccess](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfinputtrustauthority-requestaccess).

## See also