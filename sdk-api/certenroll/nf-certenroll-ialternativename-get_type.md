# IAlternativeName::get_Type

## Description

The **Type** property retrieves the alternative name type.

This property is read-only.

## Parameters

## Remarks

The following values from the [AlternativeNameType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-alternativenametype) enumeration can be returned. The **XCN_CERT_ALT_NAME_UNKNOWN** value is never returned.

| Value | Description |
| --- | --- |
| **XCN_CERT_ALT_NAME_OTHER_NAME** | The name consists of an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) and a byte array. |
| **XCN_CERT_ALT_NAME_RFC822_NAME** | The name is an email address. |
| **XCN_CERT_ALT_NAME_DNS_NAME** | The name is a DNS name. |
| **XCN_CERT_ALT_NAME_DIRECTORY_NAME** | The name is an [X.500](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) directory name. |
| **XCN_CERT_ALT_NAME_URL** | The name is a URL. |
| **XCN_CERT_ALT_NAME_IP_ADDRESS** | The name is an IP address. |
| **XCN_CERT_ALT_NAME_REGISTERED_ID** | The name is a registered OID. |
| **XCN_CERT_ALT_NAME_GUID** | The name is a GUID. |
| **XCN_CERT_ALT_NAME_USER_PRINCIPLE_NAME** | The name is a [user principal name](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) (UPN). |

## See also

[IAlternativeName](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ialternativename)