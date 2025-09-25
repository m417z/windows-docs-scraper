# IX509PrivateKey::get_Certificate

## Description

The **Certificate** property specifies or retrieves a byte array that contains the certificate associated with the private key. The byte array is represented by a Unicode-encoded string.

This property is read/write.

## Parameters

## Remarks

If the key is not open when you specify a certificate, the certificate will be set when the key is opened. For more information, see the [Open](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-open) method.

The **Certificate** property compares the public key associated with the [IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey) object to the public key included in the certificate. The two keys must match.

## See also

[IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey)