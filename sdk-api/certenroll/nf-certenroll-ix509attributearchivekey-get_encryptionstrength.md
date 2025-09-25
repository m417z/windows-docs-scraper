# IX509AttributeArchiveKey::get_EncryptionStrength

## Description

The **EncryptionStrength** property retrieves an integer that contains the encryption strength of the symmetric algorithm used to encrypt the key.

This property is read-only.

## Parameters

## Remarks

You can specify this property by calling the [InitializeEncode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributearchivekey-initializeencode) method or the [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributearchivekey-initializedecode) method. However, the property is currently ignored and zero is returned because the Certificate Enrollment SDK does not support any algorithms for which the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) does not already imply the encryption strength (key length). For example, AES has multiple strengths, but each strength is already indicated by the OID.

You can call the following properties to retrieve the raw data:

* [EncryptionAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributearchivekey-get_encryptionalgorithm)
* [EncryptedKeyBlob](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributearchivekey-get_encryptedkeyblob)

## See also

[IX509AttributeArchiveKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributearchivekey)