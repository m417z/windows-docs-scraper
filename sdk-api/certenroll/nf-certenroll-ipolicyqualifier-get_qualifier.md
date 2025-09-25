# IPolicyQualifier::get_Qualifier

## Description

The **Qualifier** property retrieves a string that contains the qualifier used to initialize the object.

This property is read-only.

## Parameters

## Remarks

You must call [InitializeEncode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ipolicyqualifier-initializeencode) to initialize the qualifier object before you can retrieve this property. The value retrieved is the string entered in the *strQualifier* parameter of that method. You can also retrieve the following properties for this object:

* The [ObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ipolicyqualifier-get_objectid) property retrieves an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) that identifies whether the qualifier is a CPS or a user notice.
* The [RawData](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ipolicyqualifier-get_rawdata) property retrieves the [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) encoded qualifier.
* The [Type](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ipolicyqualifier-get_type) property retrieves a value of the [PolicyQualifierType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-policyqualifiertype) enumeration that specifies the qualifier type.

## See also

[IPolicyQualifier](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ipolicyqualifier)