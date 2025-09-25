# IEnroll::AddExtensionsToRequest

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **AddExtensionsToRequest** method adds extensions to the certificate request. This method was first defined in the [IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll) interface.

## Parameters

### `pCertExtensions` [in]

A pointer to a [CERT_EXTENSIONS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extensions) structure that represents the extensions to add to the request.

## Return value

The return value is an **HRESULT**, with S_OK returned if the call is successful.

## See also

[IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)