# IPolicyQualifier::get_Type

## Description

The **Type** property retrieves the qualifier type.

This property is read-only.

## Parameters

## Remarks

You must call [InitializeEncode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ipolicyqualifier-initializeencode) to initialize the qualifier object before you can retrieve this property. The value retrieved is one of the following values of the [PolicyQualifierType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-policyqualifiertype) enumeration.

| Value | Description |
| --- | --- |
| **PolicyQualifierTypeUrl** | The qualifier is a URL that points to a Certification Practice Statement (CPS). |
| **PolicyQualifierTypeUserNotice** | The qualifier is a string to be displayed to users who rely on the certificate. |

You can also retrieve the following properties for this object:

* The [ObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ipolicyqualifier-get_objectid) property retrieves an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) that identifies whether the qualifier is a CPS or a user notice.
* The [Qualifier](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ipolicyqualifier-get_qualifier) property retrieves the string specified for the *strQualifier* parameter of the [InitializeEncode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ipolicyqualifier-initializeencode) method.
* The [RawData](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ipolicyqualifier-get_rawdata) property retrieves the [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) encoded qualifier.

## See also

[IPolicyQualifier](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ipolicyqualifier)