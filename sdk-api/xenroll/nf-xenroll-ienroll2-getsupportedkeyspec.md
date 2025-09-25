# IEnroll2::GetSupportedKeySpec

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **GetSupportedKeySpec** method retrieves information regarding the current [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) support for signature and/or exchange operations. This method was first defined in the [IEnroll2](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll2) interface.

The values retrieved by this method are dependent upon the current CSP.

## Parameters

### `pdwKeySpec` [out]

A pointer to a **LONG** that receives a bit flag indicating whether the current CSP supports [exchange](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly) and/or [signature keys](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success. If a CSP does not support this method, an error is returned.

## Remarks

Call this method to determine whether the current CSP supports exchange keys, signature keys, or both. The *pdwKeySpec* parameter will contain one or more of the following constants (defined in Wincrypt.h):

* AT_KEYEXCHANGE
* AT_SIGNATURE.

## See also

[IEnroll2](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)