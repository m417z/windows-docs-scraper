# IX509ExtensionSubjectKeyIdentifier::get_SubjectKeyIdentifier

## Description

The **SubjectKeyIdentifier** property retrieves a byte array that contains the key identifier. The byte array is represented by a Unicode-encoded string.

This property is read-only.

## Parameters

## Remarks

Call the [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensionsubjectkeyidentifier-initializedecode) method or the [InitializeEncode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensionsubjectkeyidentifier-initializeencode) method to initialize the [IX509ExtensionSubjectKeyIdentifier](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionsubjectkeyidentifier) object. You can also call the [Critical](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_critical) property to specify and retrieve a Boolean value that identifies whether the extension is critical, and you can call the [ObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_objectid) property to retrieve the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) associated with the extension.

## See also

[IX509ExtensionSubjectKeyIdentifier](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionsubjectkeyidentifier)