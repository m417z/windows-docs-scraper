# ICryptAttribute::get_ObjectId

## Description

The **ObjectId** property retrieves the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) for the attribute.

This property is read-only.

## Parameters

## Remarks

 You can initialize an [IObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid) object by calling [InitializeFromName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-iobjectid-initializefromname). This method initializes the object by using a value from the [CERTENROLL_OBJECTID](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-certenroll_objectid) enumeration. The enumeration value is associated with an ASN.1 object identifier. For example, the value **XCN_OID_COUNTRY_NAME** is associated with a string containing 2.5.4.6. This is the dotted decimal representation of the joint-iso-itu-t(2)ds(5)attributeType(4)countryName(6) object identifier.

## See also

[ICryptAttribute](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icryptattribute)

[ICryptAttributes](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icryptattributes)

[IX509Attribute](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attribute)

[IX509Attributes](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributes)