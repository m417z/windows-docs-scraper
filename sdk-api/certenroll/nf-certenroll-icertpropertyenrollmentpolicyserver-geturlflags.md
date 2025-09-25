# ICertPropertyEnrollmentPolicyServer::GetUrlFlags

## Description

The **GetUrlFlags** method retrieves a set of flags that contain miscellaneous policy information about the certificate enrollment policy (CEP) server. These flags are set by the [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyenrollmentpolicyserver-initialize) method.

## Parameters

### `pValue` [out, retval]

Pointer to a [PolicyServerUrlFlags](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-policyserverurlflags) enumeration value that specifies the policy server flags. This can be a bitwise **OR** of the following values.

| Value | Meaning |
| --- | --- |
| **PsfNone** | No flags are specified. |
| **PsfLocationGroupPolicy** | The policy server URL is specified in group policy by an administrator. |
| **PsfLocationRegistry** | The policy server URL is specified in the registry. |
| **PsfUseClientId** | Specifies that certificate enrollments and renewals include client specific data. Examples include the name of the cryptographic service provider, the Windows version number, the user name, the computer DNS name, and the domain controller DNS name. This flag is set when it is defined in group policy and is the default policy ID. |
| **PsfAutoEnrollmentEnabled** | Automatic certificate enrollment is enabled. |
| **PsfAllowUnTrustedCA** | Specifies that the certificate of the issuing CA need not be trusted by the client to install a certificate signed by the CA. |

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| ****E_POINTER**** | The *pValue* parameter cannot be **NULL**. |

## See also

[ICertPropertyEnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyenrollmentpolicyserver)