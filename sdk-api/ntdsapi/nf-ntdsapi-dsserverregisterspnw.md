# DsServerRegisterSpnW function

## Description

The **DsServerRegisterSpn** function composes two SPNs for a host-based service. The names are based on the DNS and NetBIOS names of the local computer. The function modifies the **servicePrincipalName** attribute of either a specified account or of the account associated with the calling thread. The function either registers or unregisters the SPNs.

A host-based service is a service instance that provides services identified with its host computer, as distinguished from a replicable service where clients have no preference which host computer a service instance runs on.

## Parameters

### `Operation` [in]

Specifies what operation **DsServerRegisterSpn** should perform. This parameter can have one of the following values.

#### DS_SPN_ADD_SPN_OP

Adds the SPNs to the user or computer account.

#### DS_SPN_DELETE_SPN_OP

Deletes the specified SPNs from the account.

#### DS_SPN_REPLACE_SPN_OP

Removes all SPNs currently registered on the user or computer account and replaces them with the new SPNs.

### `ServiceClass` [in]

Pointer to a constant null-terminated string specifying the class of the service. This parameter may be any string unique to that service; either the protocol name (for example, ldap) or the string form of a GUID will work.

### `UserObjectDN` [in, optional]

Pointer to a constant null-terminated string specifying the distinguished name of a user or computer account object to write the SPNs to. If this parameter is **NULL**, **DsServerRegisterSpn** writes to the account object of the primary or impersonated user associated with the calling thread. If the thread is running in the security context of the LocalSystem account, the function writes to the account object of the local computer.

##### - Operation.DS_SPN_ADD_SPN_OP

Adds the SPNs to the user or computer account.

##### - Operation.DS_SPN_DELETE_SPN_OP

Deletes the specified SPNs from the account.

##### - Operation.DS_SPN_REPLACE_SPN_OP

Removes all SPNs currently registered on the user or computer account and replaces them with the new SPNs.

## Return value

If the function successfully registers one or more SPNs, it returns **ERROR_SUCCESS**. Modification is performed permissively, so that adding a value that already exists does not return an error.

## Remarks

The two SPNs composed by the **DsServerRegisterSpn** function have the following format:

```cpp
<ServiceClass>/<host>
```

In one SPN, the host computer is the fully qualified DNS name of the local computer. In the other SPN, the host component is the NetBIOS name of the local computer.

In most cases, the **DsServerRegisterSpn** caller must have domain administrator privileges to successfully modify the **servicePrincipalName** attribute of an account object. The exception to this rule is if the calling thread is running under the LocalSystem account, **DsServerRegisterSpn** is allowed if the *UserObjectDN* parameter is either **NULL** or specifies the distinguished name of the local computer account.

> [!NOTE]
> The ntdsapi.h header defines DsServerRegisterSpn as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsGetSpn](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsgetspna)

[DsWriteAccountSpn](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dswriteaccountspna)