# IEnroll2::GetKeyLen

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **GetKeyLen** method retrieves the minimum and maximum key lengths for the [signature](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) and [exchange keys](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly). This method was first defined in the [IEnroll2](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll2) interface. The values retrieved by this method are dependent upon the current [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

## Parameters

### `fMin` [in]

Boolean value indicating which key length (minimum or maximum) is retrieved. If *fMin* is **TRUE**, the minimum key length is retrieved; if it is **FALSE**, the maximum key length is retrieved.

### `fExchange` [in]

Boolean value indicating the type of key. If *fExchange* is **TRUE**, the exchange key length is retrieved; if it is **FALSE**, the signature key length is retrieved.

### `pdwKeySize` [out]

Pointer that receives the key's minimum or maximum length, in bits.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success, and **pdwKeySize* will be the value representing the length (in bits) for the key's minimum or maximum length.

## Remarks

Call this method to determine the minimum and maximum key lengths. If a CSP does not support this method, an error is returned.

## See also

[IEnroll2](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)