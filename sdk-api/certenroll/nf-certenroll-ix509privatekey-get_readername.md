# IX509PrivateKey::get_ReaderName

## Description

The **ReaderName** property specifies or retrieves the name of a smart card reader.

This property is read/write.

## Parameters

## Remarks

If you set this property before opening a key, the reader name is concatenated to the name of the key container. The format is \\.\*Reader_Name*\*Container_Name*. Prepending the reader name to the key container name enables the name to be disambiguated in subsequent calls to a cryptographic provider. The private key is typically stored in the smart card key container when a smart card is used.

## See also

[IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey)