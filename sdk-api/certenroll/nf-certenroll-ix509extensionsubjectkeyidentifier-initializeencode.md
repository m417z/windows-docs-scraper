# IX509ExtensionSubjectKeyIdentifier::InitializeEncode

## Description

The **InitializeEncode** method initializes the extension from a byte array that contains the key identifier. The byte array is represented by a Unicode-encoded string.

## Parameters

### `Encoding` [in]

An [EncodingType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-encodingtype) enumeration value that specifies the type of Unicode encoding applied to the *strKeyIdentifier* parameter.

### `strKeyIdentifier` [in]

A **BSTR** variable that contains the key identifier.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)** | The object is already initialized. |

## Remarks

Typically, the input value should be a SHA-1 hash of the [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) contained in the certification authority signing certificate. The method associates the value with the XCN_OID_SUBJECT_KEY_IDENTIFIER (2.5.29.14) [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) and encodes it by using [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER).

You must call either **InitializeEncode** or [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensionsubjectkeyidentifier-initializedecode) before you can use an [IX509ExtensionSubjectKeyIdentifier](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionsubjectkeyidentifier) object. The two methods complement each other. The **InitializeEncode** method enables you to construct a DER-encoded [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) extension object from raw data, and the **InitializeDecode** method enables you to initialize the raw data from an encoded object.

You can retrieve the following properties for this extension:

* The [Critical](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_critical) property identifies whether the extension is critical. You can also specify this property.
* The [ObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_objectid) property retrieves the OID.
* The [AuthorityKeyIdentifier](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensionauthoritykeyidentifier-get_authoritykeyidentifier) property retrieves the raw data.

## See also

[IX509ExtensionSubjectKeyIdentifier](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionsubjectkeyidentifier)