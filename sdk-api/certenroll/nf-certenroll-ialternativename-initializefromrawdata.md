# IAlternativeName::InitializeFromRawData

## Description

The **InitializeFromRawData** method initializes the object from a [Digital Signature Algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DSA) GUID, an [X.500](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) directory name, or an Internet Protocol (IP) address contained in a [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) encoded byte array.

## Parameters

### `Type` [in]

An [AlternativeNameType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-alternativenametype) enumeration value that identifies the type of name represented by the input string. This must be one of the following values.

| Value | Meaning |
| --- | --- |
| **XCN_CERT_ALT_NAME_DIRECTORY_NAME** | The name is an X.500 directory name. |
| **XCN_CERT_ALT_NAME_IP_ADDRESS** | The name is an IP address. |
| **XCN_CERT_ALT_NAME_GUID** | The name is a GUID. |

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that identifies the type of Unicode encoding applied to the *strRawData* parameter.

### `strRawData` [in]

A **BSTR** variable that contains the DER-encoded data.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)** | The object is already initialized. |

## Remarks

The raw data is a byte array that has been encoded by using [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER). You must specify the byte array as a Unicode encoded string.

If you use this method to specify a DSA GUID (XCN_CERT_ALT_NAME_GUID), the GUID is associated with the XCN_OID_NTDS_REPLICATION (1.3.6.1.4.1.311.25.1) [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) and encoded as an octet string (byte array). You can retrieve the OID by calling the [ObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ialternativename-get_objectid) property. You can call the [RawData](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ialternativename-get_rawdata) property to retrieve the encoded byte array.

If you use this method to specify any of the following name types, the method returns **E_INVALIDARG**.

| Value | Description |
| --- | --- |
| XCN_CERT_ALT_NAME_UNKNOWN | The name type is not identified. |
| XCN_CERT_ALT_NAME_RFC822_NAME | The name is an email address. |
| XCN_CERT_ALT_NAME_DNS_NAME | The name is a DNS name. |
| XCN_CERT_ALT_NAME_URL | The name is a URL. |
| XCN_CERT_ALT_NAME_REGISTERED_ID | The name is a registered OID. |
| XCN_CERT_ALT_NAME_USER_PRINCIPLE_NAME | The name is a [user principal name](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) (UPN). |
| XCN_CERT_ALT_NAME_OTHER_NAME | The name consists of an OID and a byte array. |

You can use the [InitializeFromOtherName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ialternativename-initializefromothername) method to specify an OID and a corresponding name string, and you can use the [InitializeFromString](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ialternativename-initializefromstring) method to specify an email address, a DNS name, a URL, a registered OID, or a [user principal name](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) (UPN).

## See also

[IAlternativeName](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ialternativename)