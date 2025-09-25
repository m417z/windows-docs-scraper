# IX509AttributeArchiveKey::get_EncryptionAlgorithm

## Description

The **EncryptionAlgorithm** property retrieves the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) of the symmetric encryption algorithm used to encrypt the [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

This property is read-only.

## Parameters

## Remarks

Call the [InitializeEncode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributearchivekey-initializeencode) method or the [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributearchivekey-initializedecode) method to initialize the **EncryptionAlgorithm** property. You can call the following properties to retrieve the raw data:

* [EncryptedKeyBlob](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributearchivekey-get_encryptedkeyblob)
* [EncryptionStrength](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributearchivekey-get_encryptionstrength)

## See also

[IX509AttributeArchiveKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributearchivekey)