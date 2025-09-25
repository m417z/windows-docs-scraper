# IOCSPAdmin::GetMyRoles

## Description

The **GetMyRoles** method gets the access mask of privilege roles for a user on a given Online Certificate Status Protocol (OCSP) responder server.

## Parameters

### `bstrServerName` [in]

A string that contains the responder-server name.

### `pRoles` [out]

A pointer to the 32-bit access mask.

## Return value

### C++

If the method succeeds, it returns **S_OK**.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The 32-bit access mask.

## Remarks

The OCSP responder server defines the following masks for access privilege roles.

| Constant | C++ value | VB Script value | Description |
| --- | --- | --- | --- |
| CA_ACCESS_ADMIN | 0x001 | &H1 | CA administrator |
| CA_ACCESS_READ | 0x100 | &H100 | Read-only access to a CA |
| CA_ACCESS_ENROLL | 0x200 | &H200 | Enroll access to a CA |

Examples of privileges a user might have, depending on the mask:

* Configure and upgrade an OCSP server.
* Assign existing signing certificate and key.
* Install and update Certificate Revocation Lists (CRLs).
* Configure a response format.

## See also

[IOCSPAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspadmin)