# IX509ExtensionCertificatePolicies::InitializeEncode

## Description

The **InitializeEncode** method initializes the object from an [ICertificatePolicies](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertificatepolicies) collection.

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

 The method associates the name collection with the XCN_OID_CERT_POLICIES (2.5.29.32) [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) and encodes it by using [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER).

You must call either **InitializeEncode** or [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensioncertificatepolicies-initializedecode) before you can use an [IX509ExtensionCertificatePolicies](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensioncertificatepolicies) object. The two methods complement each other. The **InitializeEncode** method enables you to construct a DER-encoded [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) extension object from raw data, and the **InitializeDecode** method enables you to initialize the raw data from an encoded object. You can retrieve the collection of policies (the raw data) by calling the [Policies](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensioncertificatepolicies-get_policies) property.

You can retrieve the following properties for this extension:

* The [Critical](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_critical) property identifies whether the extension is critical. You can also specify this property.
* The [ObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_objectid) property retrieves the extension OID.
* The [Policies](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensioncertificatepolicies-get_policies) property retrieves the collection of [certificate policies](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (the raw extension data).

## See also

[IX509ExtensionCertificatePolicies](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensioncertificatepolicies)