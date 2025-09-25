# IX509ExtensionEnhancedKeyUsage::InitializeEncode

## Description

The **InitializeEncode** method initializes the extension from a collection of [IObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid) object identifiers (OIDs) that specify the intended uses of the [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). This method is web enabled.

## Parameters

### `pValue` [in]

Pointer to an [IObjectIds](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectids) interface.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| ****HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)**** | The object is already initialized. |

## Remarks

You must call either **InitializeEncode** or [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensionenhancedkeyusage-initializedecode) before you can use an [IX509ExtensionEnhancedKeyUsage](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionenhancedkeyusage) object. The two methods complement each other. The **InitializeEncode** method enables you to construct a [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) encoded [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) extension object from raw data, and the **InitializeDecode** method enables you to initialize the raw data from an encoded object.

You can retrieve the following properties for this extension:

* The [Critical](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_critical) property identifies whether the extension is critical. You can also specify this property.
* The [ObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_objectid) property retrieves the extension [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID).
* The [EnhancedKeyUsage](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensionenhancedkeyusage-get_enhancedkeyusage) property retrieves the collection of OIDs that identify the intended uses of the public key (the raw extension data).

## See also

[IX509ExtensionEnhancedKeyUsage](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionenhancedkeyusage)