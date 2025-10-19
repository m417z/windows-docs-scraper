# IX509PrivateKey::Verify

## Description

The **Verify** method verifies that a private key exists and can be used by the client but does not open the key.

## Parameters

### `VerifyType` [in]

An [X509PrivateKeyVerify](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-x509privatekeyverify) enumeration value that specifies execution options for the method. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **VerifyNone** | Does not verify. |
| **VerifySilent** | Does not verify if a user interface is required to open the private key; otherwise verification occurs. For more information, see Remarks. |
| **VerifySmartCardNone** | Does not verify if the key is stored on a smart card; otherwise, this value is equivalent to **VerifyAllowUI**. |
| **VerifySmartCardSilent** | Does not verify if a user interface is required to open the private key and the key is stored on a smart card; otherwise, this value is equivalent to **VerifyAllowUI**. For more information, see Remarks. |
| **VerifyAllowUI** | The method allows a user interface to be displayed. |

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. Also, this method calls the [CryptGetUserKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetuserkey) and [CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) CryptoAPI functions and can return errors identified in that documentation. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **CERTSRV_E_PROPERTY_EMPTY** | Properties related to the CSP or KSP could not be found. |

## Remarks

If **VerifySilent** or **VerifySmartCardSilent** values are set and the cryptographic provider specifies that a user interface is necessary, the key will not be opened, but the method returns **S_OK**.

## See also

[IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey)