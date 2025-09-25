# IAzNameResolver::NameFromSid

## Description

The **NameFromSid** method gets the display name that corresponds to the specified [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID).

## Parameters

### `bstrSid` [in]

The string representation of the SID to translate.

### `pSidType` [out]

An element of the [SID_NAME_USE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-sid_name_use) enumeration that specifies the type of SID being translated.

### `pbstrName` [out]

A pointer to the display name of the principal that corresponds to the SID specified by the *bstrSid* parameter.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. In particular, if the method cannot find the display name of the principal, it returns **CO_E_NOMATCHINGNAMEFOUND**. For a list of other common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).