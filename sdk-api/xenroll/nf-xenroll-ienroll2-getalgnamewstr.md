# IEnroll2::GetAlgNameWStr

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **GetAlgNameWStr** method retrieves the name of a cryptographic algorithm given its ID. The values retrieved by this method depend on the current [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP). This method was first defined in the [IEnroll2](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll2) interface.

## Parameters

### `algID` [in]

Value representing a cryptographic algorithm, as defined in Wincrypt.h. For example, CALG_MD2 is a defined algorithm identifier. For this method to be successful, the current CSP must support the *algID* algorithm.

### `ppwsz` [out]

Upon success, pointer to a **LPWSTR** that represents the name of the algorithm specified by *algID*.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success. If a CSP does not support this method or does not support the *algID* cryptographic algorithm, an error is returned.

## Remarks

This method may be used to display the names of algorithms whose IDs are retrieved by calling
[EnumAlgs](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll2-enumalgs).

Constants for the cryptographic algorithms are defined in Wincrypt.h.

## See also

[IEnroll2](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)