# IX509AttributeArchiveKey::get_EncryptedKeyBlob

## Description

The **EncryptedKeyBlob** property retrieves a byte array that contains the encrypted key. The byte array is represented by a Unicode-encoded string.

This property is read-only.

## Parameters

## Remarks

Call the [InitializeEncode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributearchivekey-initializeencode) method or the [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributearchivekey-initializedecode) method to initialize the **EncryptedKeyBlob** property. You can call the following properties to retrieve the raw data:

* [EncryptionAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributearchivekey-get_encryptionalgorithm)
* [EncryptionStrength](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributearchivekey-get_encryptionstrength)

## See also

[IX509AttributeArchiveKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributearchivekey)