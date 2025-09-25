# IPolicyQualifier::get_ObjectId

## Description

The **ObjectId** property retrieves the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) for the qualifier.

This property is read-only.

## Parameters

## Remarks

If you specified **PolicyQualifierTypeUrl** in the *Type* parameter of the [InitializeEncode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ipolicyqualifier-initializeencode) method, **XCN_OID_PKIX_POLICY_QUALIFIER_CPS** (1.3.6.1.5.5.7.2.1) is returned. If you specified **PolicyQualifierTypeUserNotice**, **XCN_OID_PKIX_POLICY_QUALIFIER_USERNOTICE** (1.3.6.1.5.5.7.2.2) is returned.

You must call [InitializeEncode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ipolicyqualifier-initializeencode) to initialize the qualifier object before you can retrieve this property. You can also retrieve the following properties for this object:

* The [Qualifier](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ipolicyqualifier-get_qualifier) property retrieves the string specified for the *strQualifier* parameter of the [InitializeEncode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ipolicyqualifier-initializeencode) method.
* The [RawData](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ipolicyqualifier-get_rawdata) property retrieves the [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) encoded qualifier.
* The [Type](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ipolicyqualifier-get_type) property retrieves a value of the [PolicyQualifierType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-policyqualifiertype) enumeration that specifies the qualifier type.

## See also

[IPolicyQualifier](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ipolicyqualifier)