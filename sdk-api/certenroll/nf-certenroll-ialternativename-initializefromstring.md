# IAlternativeName::InitializeFromString

## Description

The **InitializeFromString** method initializes the object from a string that contains an email address, a Domain Name System (DNS) name, a URL, a registered [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID), or a [user principal name](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) (UPN).

## Parameters

### `Type` [in]

An [AlternativeNameType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-alternativenametype) enumeration value that identifies the type of name represented by the input string contained in the *strValue* parameter. This must be one of the following values.

| Value | Meaning |
| --- | --- |
| **XCN_CERT_ALT_NAME_RFC822_NAME** | The name is an email address. |
| **XCN_CERT_ALT_NAME_DNS_NAME** | The name is a DNS name. |
| **XCN_CERT_ALT_NAME_URL** | The name is a URL. |
| **XCN_CERT_ALT_NAME_REGISTERED_ID** | The name is a registered OID. |
| **XCN_CERT_ALT_NAME_USER_PRINCIPLE_NAME** | The name is a UPN. |

### `strValue` [in]

A **BSTR** variable that contains the name.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

If you use this method to specify a UPN, the UPN is associated with the XCN_OID_NT_PRINCIPAL_NAME (1.3.6.1.4.1.311.20.2.3) OID and is [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) encoded. You can call the [RawData](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ialternativename-get_rawdata) property to retrieve the encoded byte array. You can retrieve the OID by calling the [ObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ialternativename-get_objectid) property.

If you use this method to specify any of the following name types, the method returns **E_INVALIDARG**.

| Value | Description |
| --- | --- |
| XCN_CERT_ALT_NAME_UNKNOWN | The name type is not identified. |
| XCN_CERT_ALT_NAME_OTHER_NAME | The name consists of an OID and a byte array. |
| XCN_CERT_ALT_NAME_DIRECTORY_NAME | The name is an [X.500](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) directory name. |
| XCN_CERT_ALT_NAME_IP_ADDRESS | The name is an IP address. |
| XCN_CERT_ALT_NAME_GUID | The name is a GUID. |

You can use the [InitializeFromOtherName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ialternativename-initializefromothername) method to specify an OID and a corresponding name string, and you can use the [InitializeFromRawData](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ialternativename-initializefromrawdata) method to specify a GUID, IP address, or X.500 directory name.

## See also

[IAlternativeName](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ialternativename)

[IAlternativeNames](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ialternativenames)

[IX509ExtensionAlternativeNames](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionalternativenames)