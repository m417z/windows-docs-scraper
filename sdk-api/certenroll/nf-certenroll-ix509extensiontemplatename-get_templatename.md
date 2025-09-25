# IX509ExtensionTemplateName::get_TemplateName

## Description

The **TemplateName** property retrieves the name of the template.

This property is read-only.

## Parameters

## Remarks

You must call either [InitializeEncode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensiontemplatename-initializeencode) or [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensiontemplatename-initializedecode) before you can use an [IX509ExtensionTemplateName](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensiontemplatename) object. You can retrieve the following additional properties for this extension:

* The [Critical](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_critical) property identifies whether the extension is critical. You can also specify this property.
* The [ObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_objectid) property retrieves the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID).

## See also

[IX509ExtensionTemplateName](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensiontemplatename)