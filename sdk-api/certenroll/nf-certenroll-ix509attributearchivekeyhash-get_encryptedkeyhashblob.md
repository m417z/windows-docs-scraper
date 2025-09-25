# IX509AttributeArchiveKeyHash::get_EncryptedKeyHashBlob

## Description

The **EncryptedKeyHashBlob** property retrieves a string that contains a [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) of the encrypted [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

This property is read-only.

## Parameters

## Remarks

Call the [InitializeEncodeFromEncryptedKeyBlob](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributearchivekeyhash-initializeencodefromencryptedkeyblob) method or the [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributearchivekeyhash-initializedecode) method to initialize the **EncryptedKeyHashBlob** property.

## See also

[IX509AttributeArchiveKeyHash](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributearchivekeyhash)