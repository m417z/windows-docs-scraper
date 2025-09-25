# IX509ExtensionAuthorityKeyIdentifier::get_AuthorityKeyIdentifier

## Description

The **AuthorityKeyIdentifier** property retrieves a byte array that contains the extension value. The byte array is represented by a Unicode-encoded string.

This property is read-only.

## Parameters

## Remarks

Call the [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensionauthoritykeyidentifier-initializedecode) method or the [InitializeEncode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensionauthoritykeyidentifier-initializeencode) method to initialize the [IX509ExtensionAuthorityKeyIdentifier](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionauthoritykeyidentifier) object. You can also call the [Critical](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_critical) property to specify and retrieve a Boolean value that identifies whether the extension is critical, and you can call the [ObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_objectid) property to retrieve the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) associated with the extension.

## See also

[IX509ExtensionAuthorityKeyIdentifier](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionauthoritykeyidentifier)