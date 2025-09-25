# IEnroll::AddAuthenticatedAttributesToPKCS7Request

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **AddAuthenticatedAttributesToPKCS7Request** method adds authenticated attributes to a PKCS #7 certificate request. This method was first defined in the [IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll) interface.

## Parameters

### `pAttributes` [in]

A pointer to a [CRYPT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attributes) structure that represents the authenticated attributes to add to the PKCS #7 certificate request.

## Return value

The return value is an **HRESULT**, with S_OK returned if the call is successful.

## See also

[IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)