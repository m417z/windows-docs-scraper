# IAlternativeName::get_ObjectId

## Description

The **ObjectId** property retrieves the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID), if any, associated with the name.

This property is read-only.

## Parameters

## Remarks

You can retrieve a value for this property if you initialized the [IAlternativeName](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ialternativename) object in any of the following ways:

* Call [InitializeFromOtherName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ialternativename-initializefromothername) and supply an OID.
* Call [InitializeFromRawData](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ialternativename-initializefromrawdata) and specify the XCN_CERT_ALT_NAME_GUID type.
* Call [InitializeFromString](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ialternativename-initializefromstring) and specify the XCN_CERT_ALT_NAME_USER_PRINCIPLE_NAME type.

## See also

[IAlternativeName](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ialternativename)