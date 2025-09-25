# IPolicyQualifier::get_RawData

## Description

The **RawData** property retrieves the [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) encoded qualifier object.

This property is read-only.

## Parameters

## Remarks

You must call [InitializeEncode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ipolicyqualifier-initializeencode) to initialize the qualifier object before you can retrieve this property. The value retrieved is the DER-encoded byte array that contains the qualifier. The byte array is represented as a string. You can use the [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration to apply Unicode encoding to the string.

You can also retrieve the following properties for this object:

* The [ObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ipolicyqualifier-get_objectid) property retrieves an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) that identifies whether the qualifier is a CPS or a user notice.
* The [Qualifier](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ipolicyqualifier-get_qualifier) property retrieves the string specified for the *strQualifier* parameter of the [InitializeEncode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ipolicyqualifier-initializeencode) method.
* The [Type](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ipolicyqualifier-get_type) property retrieves a value of the [PolicyQualifierType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-policyqualifiertype) enumeration that specifies the qualifier type.

## See also

[IPolicyQualifier](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ipolicyqualifier)