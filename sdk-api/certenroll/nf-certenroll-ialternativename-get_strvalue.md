# IAlternativeName::get_StrValue

## Description

The **StrValue** property retrieves a string that contains an email address, a Domain Name System (DNS) name, a URL, a registered [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID), or a [user principal name](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) (UPN).

This property is read-only.

## Parameters

## Remarks

You can call this property to retrieve a string if you initialized the [IAlternativeName](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ialternativename) object by calling the [InitializeFromString](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ialternativename-initializefromstring) method and specifying one of the following [AlternativeNameType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-alternativenametype) values.

| Value | Description |
| --- | --- |
| XCN_CERT_ALT_NAME_RFC822_NAME | The name is an email address. |
| XCN_CERT_ALT_NAME_DNS_NAME | The name is a DNS name. |
| XCN_CERT_ALT_NAME_URL | The name is a URL. |
| XCN_CERT_ALT_NAME_REGISTERED_ID | The name is a registered OID. |
| XCN_CERT_ALT_NAME_USER_PRINCIPLE_NAME | The name is a UPN. |

## See also

[IAlternativeName](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ialternativename)