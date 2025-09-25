# IX509PolicyServerListManager::Initialize

## Description

The **Initialize** method initializes an [IX509PolicyServerListManager](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509policyserverlistmanager) object.

## Parameters

### `context` [in]

An [X509CertificateEnrollmentContext](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-x509certificateenrollmentcontext) enumeration value that specifies the nature of the end entity for which an issued certificate is intended. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **ContextUser** | The certificate is intended for an end user. |
| **ContextMachine** | The certificate is intended for a computer. |
| **ContextAdministratorForceMachine** | The certificate is being requested by an administrator acting on the behalf of a computer. |

### `Flags` [in]

A [PolicyServerUrlFlags](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-policyserverurlflags) enumeration value that specifies where policy information is located. This can be a bitwise **OR** of the following values.

| Value | Meaning |
| --- | --- |
| **PsfLocationGroupPolicy** | Policy information is specified in group policy by an administrator. |
| **PsfLocationRegistry** | Policy information is specified in the registry. |

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The *Flags* parameter must contain a bitwise OR of **PsfLocationGroupPolicy** and **PsfLocationRegistry**. |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)** | The [IX509PolicyServerListManager](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509policyserverlistmanager) has already been initialized. |

## See also

[IX509PolicyServerListManager](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509policyserverlistmanager)