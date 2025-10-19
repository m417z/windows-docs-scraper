# IX509CertificateTemplateWritable::Initialize

## Description

The **Initialize** method initializes an [IX509CertificateTemplateWritable](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificatetemplatewritable) object from a template.

## Parameters

### `pValue` [in]

Pointer to an [IX509CertificateTemplate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificatetemplate) interface that represents a certificate request template.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **E_POINTER** | The *pValue* parameter cannot be **NULL**. |
| **E_NOINTERFACE** | The *pValue* parameter does not point to an [IX509CertificateTemplate](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificatetemplate) interface. |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)** | The [IX509CertificateTemplateWritable](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificatetemplatewritable) has already been initialized. |

## See also

[IX509CertificateTemplateWritable](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificatetemplatewritable)