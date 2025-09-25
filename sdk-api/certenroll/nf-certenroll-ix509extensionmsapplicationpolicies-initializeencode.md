# IX509ExtensionMSApplicationPolicies::InitializeEncode

## Description

The **InitializeEncode** method initializes the extension from an [ICertificatePolicies](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertificatepolicies) collection.

## Parameters

### `pValue` [in]

Pointer to the [ICertificatePolicies](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertificatepolicies) interface.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| ****HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)**** | The object is already initialized. |

## Remarks

You must call either **InitializeEncode** or [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensionmsapplicationpolicies-initializedecode) before you can use an [IX509ExtensionMSApplicationPolicies](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionmsapplicationpolicies) object. The two methods complement each other. The **InitializeEncode** method enables you to construct a [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) encoded ASN.1 extension object from raw data, and the **InitializeDecode** method enables you to initialize the raw data from an encoded object.

You can retrieve the following properties for this extension:

* The [Critical](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_critical) property identifies whether the extension is critical. You can also specify this property.
* The [ObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_objectid) property retrieves the extension [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID).
* The [Policies](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensionmsapplicationpolicies-get_policies) property retrieves the collection of [certificate policies](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (the raw extension data).

## See also

[IX509ExtensionMSApplicationPolicies](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionmsapplicationpolicies)

[InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensionmsapplicationpolicies-initializedecode)