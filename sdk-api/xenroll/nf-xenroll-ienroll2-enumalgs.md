# IEnroll2::EnumAlgs

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **EnumAlgs** method retrieves the IDs of cryptographic algorithms in a given algorithm class that are supported by the current [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP). This method was first defined in the [IEnroll2](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll2) interface.

## Parameters

### `dwIndex` [in]

Specifies the ordinal position of the algorithm whose ID will be retrieved. Specify zero for the first algorithm.

### `algClass` [in]

A cryptographic algorithm class. The IDs returned by this method will be in the specified class. Specify one of the following:

* ALG_CLASS_HASH
* ALG_CLASS_KEY_EXCHANGE
* ALG_CLASS_MSG_ENCRYPT
* ALG_CLASS_DATA_ENCRYPT
* ALG_CLASS_SIGNATURE

### `pdwAlgID` [out]

A pointer to LONG which receives a cryptographic algorithm ID which is supported by the current CSP.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success. When there are no more algorithms to enumerate, the value ERROR_NO_MORE_ITEMS is returned.

## Remarks

For algorithm ID and class constants used by this method, see Wincrypt.h.

## See also

[ALG_ID](https://learn.microsoft.com/windows/desktop/SecCrypto/alg-id)

[IEnroll2](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)