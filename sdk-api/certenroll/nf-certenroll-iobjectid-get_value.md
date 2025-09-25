# IObjectId::get_Value

## Description

The **Value** property retrieves a string that contains the dotted decimal [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID). This property is web enabled.

This property is read-only.

## Parameters

## Remarks

The dotted decimal format is discussed in the ASN.1 X.208 specification. For example, the string 1.2.840.10045.4.1. represents the iso(1)member-body(2)us(840)10045 signatures(4)sha1(1) object identifier.

You must call any of the following methods before you can retrieve this property value:

* [InitializeFromAlgorithmName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-iobjectid-initializefromalgorithmname)
* [InitializeFromName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-iobjectid-initializefromname)
* [InitializeFromValue](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-iobjectid-initializefromvalue)

You can also retrieve the following property values:

* [FriendlyName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-iobjectid-get_friendlyname)
* [Name](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-iobjectid-get_name)

## See also

[IObjectID](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid)