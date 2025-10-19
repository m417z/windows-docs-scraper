# IX509ExtensionAlternativeNames::InitializeEncode

## Description

The **InitializeEncode** method initializes the extension from an [IAlternativeNames](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ialternativenames) collection.

## Parameters

### `pValue` [in]

Pointer to an [IAlternativeNames](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ialternativenames) interface.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)** | The object is already initialized. |

## Remarks

 The method associates the name collection with the XCN_OID_SUBJECT_ALT_NAME2 (2.5.29.17) [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) and encodes it by using [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER).

You must call either **InitializeEncode** or [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensionalternativenames-initializedecode) before you can use an [IX509ExtensionAlternativeNames](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionalternativenames) object. The two methods complement each other. The **InitializeEncode** method enables you to construct a DER-encoded [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) extension object from raw data, and the **InitializeDecode** method enables you to initialize the raw data from an encoded object.

 You can retrieve the following properties for this extension:

* The [Critical](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_critical) property identifies whether the extension is critical. You can also specify this property.
* The [ObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_objectid) property retrieves the OID.
* The [AlternativeNames](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensionalternativenames-get_alternativenames) property retrieves the collection of names (the raw extension data).

## See also

[IX509ExtensionAlternativeNames](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionalternativenames)