# IIdentityStore::ConvertToSid

## Description

The **ConvertToSid** method retrieves the [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) associated with the specified identity and identity provider.

## Parameters

### `lpszUniqueID` [in]

The identity for which to retrieve the SID.

### `ProviderGUID` [in]

The GUID of the identity provider.

### `cbSid` [in]

The size, in bytes, of the buffer pointed to by the *pSid* parameter.

### `pSid` [in, out]

A pointer to the SID this method retrieves.

### `pcbRequiredSid` [out]

The required length, in bytes, of the *pSid* buffer.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IIdentityStore](https://learn.microsoft.com/windows/desktop/api/identitystore/nn-identitystore-iidentitystore)