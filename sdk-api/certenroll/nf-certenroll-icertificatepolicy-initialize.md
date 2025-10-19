# ICertificatePolicy::Initialize

## Description

The **Initialize** method initializes the object from an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID).

## Parameters

### `pValue` [in]

Pointer to an [IObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid) interface that represents the OID.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **CERTSRV_E_PROPERTY_EMPTY** | The pointer to the [IObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid) interface is **NULL**. |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)** | The object is already initialized. |

## Remarks

You must use an initialized [IObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid) object when calling this method. All of the **IObjectId** initialization methods search the registry and static memory on the local computer and Active Directory on the domain server for the first OID that matches the specified initialization parameters. You can retrieve the OID by calling the [ObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertificatepolicy-get_objectid) property.

When you call the **Initialize** method, an empty [IPolicyQualifiers](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ipolicyqualifiers) object is created. You can retrieve the object by calling the [PolicyQualifiers](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertificatepolicy-get_policyqualifiers) property. You can use the object to define policy qualifiers if you are creating a **CertificatePolicies** extension.

## See also

[ICertificatePolicies](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertificatepolicies)

[ICertificatePolicy](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertificatepolicy)