# AUTHZ_ACCESS_REPLY structure

## Description

The **AUTHZ_ACCESS_REPLY** structure defines an access check reply.

## Members

### `ResultListLength`

The number of elements in the **GrantedAccessMask**, **SaclEvaluationResults**, and **Error** arrays. This number matches the number of entries in the object type list structure used in the access check.
If no object type is used to represent the object, then set **ResultListLength** to one.

### `GrantedAccessMask`

An array of granted access masks. Memory for this array is allocated by the application before calling [AccessCheck](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheck).

### `SaclEvaluationResults`

An array of [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL) evaluation results. Memory for this array is allocated by the application before calling [AccessCheck](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheck). SACL evaluation will only be performed if auditing is requested. Each element of this member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **AUTHZ_GENERATE_SUCCESS_AUDIT**<br><br>0x1 | An audit message that indicates success was generated. |
| **AUTHZ_GENERATE_FAILURE_AUDIT**<br><br>0x2 | An audit message that indicates failure was generated. |

### `Error`

An array of results for each element of the array. Memory for this array is allocated by the application before calling [AccessCheck](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheck).

The following table lists the possible error values.

| Value | Meaning |
| --- | --- |
| **ERROR_SUCCESS** | All the access bits, not including MAXIMUM_ALLOWED, are granted and the **GrantedAccessMask** member is not zero. |
| **ERROR_PRIVILEGE_NOT_HELD** | DesiredAccess includes ACCESS_SYSTEM_SECURITY and the client does not have SeSecurityPrivilege. |
| **ERROR_ACCESS_DENIED** | Includes each of the following: <br><br>* The requested bits are not granted.<br>* MaximumAllowed bit is on and granted access is zero.<br>* DesiredAccess is zero. |

## See also

[AccessCheck](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheck)