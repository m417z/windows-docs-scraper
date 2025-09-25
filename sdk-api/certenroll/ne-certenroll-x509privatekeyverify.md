# X509PrivateKeyVerify enumeration

## Description

The **X509PrivateKeyVerify** enumeration specifies whether a user interface is displayed during [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) verification and whether verification can proceed if the cryptographic provider is a [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) provider. This enumeration is used by the [Verify](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-verify) method on the [IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey) interface.

## Constants

### `VerifyNone:0`

No option is identified.

### `VerifySilent:1`

The method does not display a user interface.

### `VerifySmartCardNone:2`

No verification occurs if the key is stored on a smart card (the CSP or KSP is a smart card provider).

### `VerifySmartCardSilent:3`

The method does not display a user interface if the key is stored on a smart card (the CSP or KSP is a smart card provider).

### `VerifyAllowUI:4`

The method displays a user interface.

## See also

[CertEnroll Enumerations](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-enumerations)

[CertEnroll Interfaces](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-interfaces)

[IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey)