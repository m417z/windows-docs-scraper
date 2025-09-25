# IX509ExtensionTemplate::get_TemplateOid

## Description

The **TemplateOid** property retrieves the template [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID).

This property is read-only.

## Parameters

## Remarks

You must call either [InitializeEncode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensiontemplate-initializeencode) or [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensiontemplate-initializedecode) before you can use an [IX509ExtensionTemplate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensiontemplate) object. You can retrieve the following additional properties for this extension:

* The [Critical](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_critical) property identifies whether the extension is critical. You can also specify this property.
* The [ObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_objectid) property retrieves the OID.
* The [MajorVersion](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensiontemplate-get_majorversion) and [MinorVersion](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensiontemplate-get_minorversion) properties retrieve the version information.

## See also

[IX509ExtensionTemplate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensiontemplate)