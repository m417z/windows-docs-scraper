# DsInheritSecurityIdentityW function

## Description

The **DsInheritSecurityIdentity** function appends the **objectSid** and **sidHistory** attributes of *SrcPrincipal* to the **sidHistory** of *DstPrincipal* and then deletes *SrcPrincipal*, all in a single transaction. To ensure that this operation is atomic, *SrcPrincipal* and *DstPrincipal* must be in the same domain and *hDS* must be bound to a domain controller that the correct permissions within that domain.

## Parameters

### `hDS` [in]

Contains a directory service handle obtained from either the
[DSBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda) or
[DSBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda) function.

### `Flags` [in]

Reserved for future use. Must be zero.

### `SrcPrincipal` [in]

Pointer to a null-terminated string that specifies the name of a security principal (user or group) in the source domain. This name is a domain-relative SAM name.

### `DstPrincipal` [in]

Pointer to a null-terminated string that specifies the name of a security principal (user or group) in the destination domain. This domain-relative SAM name identifies the principal whose **sidHistory** attribute will be updated with the SID of *SrcPrincipal*.

## Return value

Returns a system or RPC error code including the following.

## Remarks

With an operating system upgrade domain applications, which span both upgraded and non-upgraded domains, may have security principals inside and outside the forest for the same logical entity at the same time.

When all upgraded domains have joined the same forest, **DsInheritSecurityIdentity** eliminates the duplicate objects while ensuring that the remaining objects have all the security rights and privileges belonging to their respective deleted object.

A **DsInheritSecurityIdentity** implementation:

* Verifies that *SrcPrincipal* and *DstPrincipal* are in the same domain.
* Verifies that the domain is writable at the bind to the server.
* Verifies that auditing is enabled for the domain.
* Verifies that the caller is a member of the domain administrators for the domain.
* Verifies that the domain is in the native mode.
* Verifies that *SrcPrincipal* exists, that it is a security principal and has read its **objectSid** and **sidHistory** properties.
* Verifies that *DstPrincipal* exists, that it is a security principal, and has read certain properties required for auditing and verification.
* Deletes *SrcPrincipal* in the database only if the entire operation is committed at completion. This operation fails if the caller does not have delete rights or if *SrcPrincipal* has children.
* Fails the operation if the **objectSid** of *SrcPrincipal* or *DstPrincipal* is a well-known SID.
* Adds the **objectSid** and the **sidHistory** (if present) of *SrcPrincipal* to the **sidHistory** of *DstPrincipal*.
* Forces an audit event and fails the operation if the audit fails.
* Enters events into the Directory Service Log. Do not confuse this with the Security Audit Log.

> [!NOTE]
> The ntdsapi.h header defines DsInheritSecurityIdentity as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DSBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda)

[DSBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda)

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)