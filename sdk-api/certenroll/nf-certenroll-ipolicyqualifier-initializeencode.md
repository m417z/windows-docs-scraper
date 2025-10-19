# IPolicyQualifier::InitializeEncode

## Description

The **InitializeEncode** method initializes the object from a string and a value that identifies the qualifier type.

## Parameters

### `strQualifier` [in]

A **BSTR** variable that contains the qualifier.

### `Type` [in]

A [PolicyQualifierType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-policyqualifiertype) enumeration value that specifies the type of qualifier applied to a certificate policy. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PolicyQualifierTypeUnknown** | The qualifier type is not specified. |
| **PolicyQualifierTypeUrl** | The qualifier is a URL that points to a Certification Practice Statement (CPS) that has been defined by the certification authority to outline the policies under which the certificate was issued and the purposes for which the certificate can be used. |
| **PolicyQualifierTypeUserNotice** | The qualifier is a text statement to be displayed by the application to any user who relies on the certificate. The user notice identifies the permitted uses of the certificate. |

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)** | The object is already initialized. |

## Remarks

If you specify **PolicyQualifierTypeUrl** in the *Type* parameter, this method associates the string entered in the *strQualifier* parameter with the **XCN_OID_PKIX_POLICY_QUALIFIER_CPS** (1.3.6.1.5.5.7.2.1) [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) and encodes it by using [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER). The URL is encoded as an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) IA5 string.

If you specify **PolicyQualifierTypeUserNotice** in the *Type* parameter, this method associates the string entered in the *strQualifier* parameter with the **XCN_OID_PKIX_POLICY_QUALIFIER_USERNOTICE** (1.3.6.1.5.5.7.2.2) OID and encodes it by using DER.

You can retrieve the following properties for this object:

* The [ObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ipolicyqualifier-get_objectid) property retrieves an OID that identifies whether the qualifier is a CPS or a user notice.
* The [Qualifier](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ipolicyqualifier-get_qualifier) property retrieves the string specified for the *strQualifier* parameter of the **InitializeEncode** method.
* The [RawData](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ipolicyqualifier-get_rawdata) property retrieves the DER-encoded qualifier.
* The [Type](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ipolicyqualifier-get_type) property retrieves a value of the [PolicyQualifierType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-policyqualifiertype) enumeration that specifies the qualifier type.

## See also

[IPolicyQualifier](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ipolicyqualifier)