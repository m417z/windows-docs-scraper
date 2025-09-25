# IX509PolicyServerUrl::RemoveFromRegistry

## Description

The **RemoveFromRegistry** method unregisters a certificate enrollment policy (CEP) server.

## Parameters

### `context` [in]

An [X509CertificateEnrollmentContext](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-x509certificateenrollmentcontext) enumeration value that specifies the nature of the end entity. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **ContextUser** | An end user. |
| **ContextMachine** | A computer. |
| **ContextAdministratorForceMachine** | An administrator acting on the behalf of a computer. |

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_ACCESS_DISABLED_BY_POLICY)** | You do not have sufficient access rights to unregister the CEP. |

## See also

[IX509PolicyServerUrl](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509policyserverurl)