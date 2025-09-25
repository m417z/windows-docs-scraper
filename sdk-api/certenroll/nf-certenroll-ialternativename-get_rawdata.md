# IAlternativeName::get_RawData

## Description

The **RawData** property retrieves the [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) encoded byte array that contains the name. The byte array is contained in a Unicode encoded string.

This property is read-only.

## Parameters

## Remarks

You can retrieve a value for this property if you initialized the [IAlternativeName](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ialternativename) object in any of the following ways:

* Call [InitializeFromOtherName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ialternativename-initializefromothername) and supply an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID).
* Call [InitializeFromRawData](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ialternativename-initializefromrawdata) and specify the XCN_CERT_ALT_NAME_GUID, XCN_CERT_ALT_NAME_DIRECTORY_NAME, or XCN_CERT_ALT_NAME_IP_ADDRESS types.
* Call [InitializeFromString](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ialternativename-initializefromstring) and specify the XCN_CERT_ALT_NAME_USER_PRINCIPLE_NAME type.

## See also

[IAlternativeName](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ialternativename)