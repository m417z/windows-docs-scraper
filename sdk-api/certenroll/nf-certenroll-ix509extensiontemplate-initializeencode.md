# IX509ExtensionTemplate::InitializeEncode

## Description

The **InitializeEncode** method initializes the extension from a template [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) and from major and minor version numbers. This method is web enabled.

## Parameters

### `pTemplateOid` [in]

Pointer to an [IObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid) interface that represents the template OID.

### `MajorVersion` [in]

A **LONG** variable that contains the major version number of the template. The default value is zero (0).

### `MinorVersion` [in]

A **LONG** variable that contains the minor version number of the template. The default value is zero (0).

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)** | The object is already initialized. |

## Remarks

You must call either **InitializeEncode** or [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensiontemplate-initializedecode) before you can use an [IX509ExtensionTemplate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensiontemplate) object. The two methods complement each other. The **InitializeEncode** method enables you to construct a [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) encoded [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) extension object from raw data, and the **InitializeDecode** method enables you to initialize the raw data from an encoded object.

You can retrieve the following properties for this extension:

* The [Critical](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_critical) property identifies whether the extension is critical. You can also specify this property.
* The [ObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_objectid) property retrieves the OID.
* The [MajorVersion](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensiontemplate-get_majorversion) and [MinorVersion](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensiontemplate-get_minorversion) properties retrieve the version information.
* The [TemplateOid](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensiontemplate-get_templateoid) property retrieves the OID of the template.

You must call either **InitializeEncode** or [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensiontemplate-initializedecode) before you can use an [IX509ExtensionBasicConstraints](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionbasicconstraints) object. The two methods complement each other. The **InitializeEncode** method enables you to construct an encoded ASN.1 structure from raw data, and the **InitializeDecode** method enables you to initialize the raw data from an encoded ASN.1 structure. You can retrieve the raw data for the extension by calling the [MajorVersion](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensiontemplate-get_majorversion), [MinorVersion](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensiontemplate-get_minorversion), and [TemplateOid](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensiontemplate-get_templateoid) properties.

## See also

[IX509ExtensionTemplate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensiontemplate)