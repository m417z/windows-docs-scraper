# IEnroll::freeRequestInfoBlob

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **freeRequestInfoBlob** method deletes a certificate context. This method was first defined in the [IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll) interface.

## Parameters

### `pkcs7OrPkcs10` [in]

A [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that specifies the session information whose context is being deleted.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success.

## See also

[IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)