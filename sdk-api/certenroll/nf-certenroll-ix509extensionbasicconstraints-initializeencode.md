# IX509ExtensionBasicConstraints::InitializeEncode

## Description

The **InitializeEncode** method initializes the extension from a Boolean value that indicates whether the certificate subject is a certification authority (CA) and an integer that contains the depth of the subordinate CA chain.

## Parameters

### `IsCA` [in]

A **VARIANT_BOOL** variable that specifies whether the certificate subject is a CA.

### `PathLenConstraint` [in]

A **LONG** variable that contains the maximum number of certificates in the chain.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)** | The object is already initialized. |

## Remarks

 The method associates the name collection with the XCN_OID_BASIC_CONSTRAINTS2 (2.5.29.19) [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) and encodes it by using [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER).

You must call either **InitializeEncode** or [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensionbasicconstraints-initializedecode) before you can use an [IX509ExtensionBasicConstraints](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionbasicconstraints) object. The two methods complement each other. The **InitializeEncode** method enables you to construct a DER-encoded [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) extension object from raw data, and the **InitializeDecode** method enables you to initialize the raw data from an encoded object.

You can retrieve the following properties for this extension:

* The [Critical](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_critical) property identifies whether the extension is critical. You can also specify this property.
* The [ObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_objectid) property retrieves the OID.
* The [IsCA](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensionbasicconstraints-get_isca) property identifies whether the certificate subject can be a certification authority.
* The [PathLenConstraint](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensionbasicconstraints-get_pathlenconstraint) property identifies the depth of the subordinate certification authority chain.

## See also

[IX509ExtensionBasicConstraints](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionbasicconstraints)