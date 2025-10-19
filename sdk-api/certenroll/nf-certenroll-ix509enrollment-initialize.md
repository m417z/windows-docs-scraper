# IX509Enrollment::Initialize

## Description

The **Initialize** method initializes the enrollment object and creates a default PKCS #10 request. This method is web enabled.

## Parameters

### `Context` [in]

An [X509CertificateEnrollmentContext](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-x509certificateenrollmentcontext) enumeration value that specifies whether the requested enrollment is for a user, a computer, or an administrator acting on behalf of a computer.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)** | The enrollment object has already been initialized. |

## Remarks

The **Initialize** method creates a new key pair and initializes empty collections for the attributes, extensions and critical extensions associated with the request.

## See also

[IX509Enrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment)