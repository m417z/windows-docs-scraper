# IX509EnrollmentPolicyServer::Export

## Description

The **Export** method exports templates and object identifiers associated with the certificate enrollment policy (CEP) server to a buffer.

## Parameters

### `exportFlags` [in]

An [X509EnrollmentPolicyExportFlags](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-x509enrollmentpolicyexportflags) enumeration value that specifies what to export. This can be a bitwise OR of the following values.

| Value | Meaning |
| --- | --- |
| **ExportTemplates** | Export templates. |
| **ExportOIDs** | Export custom object identifiers. |

### `pVal` [out, retval]

Pointer to a **VARIANT** of type **VT_ARRAY|VT_UI1** that receives the templates and object identifiers.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_POINTER** | The *pVal* parameter must not be **NULL**. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | The *exportFlags* parameter must contain **ExportTemplates** or **ExportOIDs**. |
| **OLE_E_BLANK** | The [IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver) has not been initialized. |

## Remarks

To prevent memory leaks, you must free the **VARIANT** returned by this function.

You must call [LoadPolicy](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentpolicyserver-loadpolicy) before calling this function and after calling [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentpolicyserver-initialize) for the exported data to be meaningful.

## See also

[IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver)