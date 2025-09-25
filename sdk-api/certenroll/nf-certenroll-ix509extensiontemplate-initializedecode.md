# IX509ExtensionTemplate::InitializeDecode

## Description

The **InitializeDecode** method initializes the extension from a DER-encoded byte array that contains the extension value. The encoded byte array is represented by a Unicode encoded string.

## Parameters

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of Unicode encoding applied to the *strEncodedData* parameter.

### `strEncodedData` [in]

A **BSTR** variable that contains the DER-encoded extension.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| ****HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)**** | The object is already initialized. |

## Remarks

You can use this method if you have a [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) encoded [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) object that contains a **CertificateTemplate** extension. You must supply the DER-encoded object in a Unicode encoded string. For more information, see the [IBinaryConverter](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ibinaryconverter) interface.

You must call either [InitializeEncode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensiontemplate-initializeencode) or **InitializeDecode** before you can use an [IX509ExtensionTemplate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensiontemplate) object. The two methods complement each other. The **InitializeEncode** method enables you to construct a DER-encoded ASN.1 extension object from raw data, and the **InitializeDecode** method enables you to initialize the raw data from an encoded object.

You can retrieve the following properties for this extension:

* The [Critical](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_critical) property identifies whether the extension is critical. You can also specify this property.
* The [ObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_objectid) property retrieves the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID).
* The [MajorVersion](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensiontemplate-get_majorversion) and [MinorVersion](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensiontemplate-get_minorversion) properties retrieve the version information.
* The [TemplateOid](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensiontemplate-get_templateoid) property retrieves the OID of the template.

## See also

[IX509ExtensionTemplate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensiontemplate)