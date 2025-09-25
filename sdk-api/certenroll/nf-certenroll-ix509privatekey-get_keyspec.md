# IX509PrivateKey::get_KeySpec

## Description

The **KeySpec** property specifies or retrieves a value that identifies whether a private key can be used for signing, or encryption, or both. This property is web enabled for both input and output.

This property is read/write.

## Parameters

## Remarks

If you specify a value of XCN_AT_SIGNATURE, the **KeySpec** property automatically sets the [KeyUsage](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_keyusage) property to XCN_NCRYPT_ALLOW_SIGNING_FLAG. If you specify XCN_AT_KEYEXCHANGE, the **KeyUsage** property is set to XCN_NCRYPT_ALLOW_DECRYPT_FLAG |
XCN_NCRYPT_ALLOW_KEY_AGREEMENT_FLAG. The **KeySpec** property only applies to [legacy] providers created by using CryptoAPI.

## See also

[IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey)