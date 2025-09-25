# IX509ExtensionBasicConstraints::get_PathLenConstraint

## Description

The **PathLenConstraint** property retrieves the depth of the subordinate certification authority chain.

This property is read-only.

## Parameters

## Remarks

Call the [InitializeEncode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensionbasicconstraints-initializeencode) method or the [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensionbasicconstraints-initializedecode) method to initialize the [IX509ExtensionBasicConstraints](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionbasicconstraints) object and specify the **PathLenConstraint** property. You can also call the [Critical](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_critical) property to specify and retrieve a Boolean value that identifies whether the extension is critical, and you can call the [ObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_objectid) property to retrieve the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) associated with the extension.

## See also

[IX509ExtensionBasicConstraints](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionbasicconstraints)