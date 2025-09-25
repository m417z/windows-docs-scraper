# IX509EnrollmentPolicyServer::GetUseClientId

## Description

The **GetUseClientId** method retrieves a value that specifies whether the **ClientId** attribute is set in the policy server flags of the certificate enrollment policy (CEP) server.

## Parameters

### `pValue` [out, retval]

Pointer to a Boolean value that specifies whether the **PsfUseClientId** bit is set on the [PolicyServerUrlFlags](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-policyserverurlflags) enumeration for this certificate enrollment policy (CEP) server.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_POINTER** | The *pValue* parameter cannot be **NULL**. |

## Remarks

This method returns **VARIANT_TRUE** if the **PsfUseClientId** bit is set on the [PolicyServerUrlFlags](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-policyserverurlflags) enumeration for this CEP server. If this flag is set, the **ClientID** attribute is included in certificate requests during the enrollment process and can be used by the certification authority for diagnostic or auditing purposes. Examples of the type of information included in this attribute include the name of the cryptographic service provider, the Windows version number, the user name, the computer DNS name, and the domain controller DNS name.

## See also

[IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver)