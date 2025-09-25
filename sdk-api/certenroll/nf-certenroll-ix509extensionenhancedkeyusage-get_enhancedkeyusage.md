# IX509ExtensionEnhancedKeyUsage::get_EnhancedKeyUsage

## Description

The **EnhancedKeyUsage** property retrieves a collection of key usage [object identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OIDs).

This property is read-only.

## Parameters

## Remarks

Call the [InitializeEncode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensionenhancedkeyusage-initializeencode) method or the [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensionenhancedkeyusage-initializedecode) method to initialize the collection. You can also call the [Critical](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_critical) property to specify and retrieve a Boolean value that identifies whether the extension is critical, and you can call the [ObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_objectid) property to retrieve the OID associated with the extension.

## See also

[IX509ExtensionEnhancedKeyUsage](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionenhancedkeyusage)