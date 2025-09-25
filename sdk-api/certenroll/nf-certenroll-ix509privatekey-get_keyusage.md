# IX509PrivateKey::get_KeyUsage

## Description

The **KeyUsage** property specifies or retrieves a value that identifies the specific purpose for which a private key can be used. This property is web enabled for both input and output.

This property is read/write.

## Parameters

## Remarks

If you set the [KeySpec](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_keyspec) property for a legacy CSP to XCN_NCRYPT_ALLOW_SIGNING_FLAG, the **KeyUsage** property to XCN_NCRYPT_ALLOW_SIGNING_FLAG. If you specify XCN_AT_KEYEXCHANGE, the **KeyUsage** property is automatically set to XCN_NCRYPT_ALLOW_DECRYPT_FLAG |
XCN_NCRYPT_ALLOW_KEY_AGREEMENT_FLAG.

## See also

[IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey)