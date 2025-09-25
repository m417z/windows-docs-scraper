# LSA_TOKEN_INFORMATION_V1 structure

## Description

The **LSA_TOKEN_INFORMATION_V2** structure contains information an [authentication package](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) can place in a Version 2 Windows token object and has superceded [LSA_TOKEN_INFORMATION_V1](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa378721(v=vs.85)).

The version 2 token information is used in most logons. The structure is identical to the [LSA_TOKEN_INFORMATION_V1](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa378721(v=vs.85)) structure, with the exception that the memory allocation is handled differently. The **LSA_TOKEN_INFORMATION_V2** structure is intended to be allocated monolithically with the privileges, DACL, SIDs, and group array either part of the same allocation, or allocated and freed externally.

A Version 2 Windows token object stores all the information needed to build a token from the authentication package to the [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA). The LSA passes this information into the kernel to create a token object and to return a handle to that token object to the caller of [LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser).

## Members

### `ExpirationTime`

Time at which the [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) becomes not valid. Use a value in the distant future if the context never expires. The current version of the operating system kernel does not enforce this expiration time.

### `User`

[TOKEN_USER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_user) structure that contains the SID of the user logging on. The [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) SID value is in a separately allocated block of memory.

### `Groups`

[TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups) structure that contains the SIDs of groups the user is a member of. This should not include WORLD or other system-defined and system-assigned SIDs. These will be added automatically by the LSA.

Each SID is expected to be in a separately allocated block of memory. The [TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups) structure is also expected to be in a separately allocated block of memory. All of these memory blocks should be allocated by calling the [AllocatePrivateHeap](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_allocate_private_heap) function.

### `PrimaryGroup`

[TOKEN_PRIMARY_GROUP](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_primary_group) structure that is used to establish the primary group of the user. This value does not have to correspond to one of the SIDs assigned to the user.

The SID pointed to by this structure is expected to be in a separately allocated block of memory.

This member is mandatory and must be filled in.

### `Privileges`

[TOKEN_PRIVILEGES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_privileges) structure that contains the [privileges](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) assigned to the user. This list of privileges will be augmented or overridden by any local security policy assigned privileges.

Each privilege is expected to be in a separately allocated block of memory. The [TOKEN_PRIVILEGES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_privileges) structure is also expected to be in a separately allocated block of memory.

If there are no privileges to assign to the user, this member may be set to **NULL**.

### `Owner`

[TOKEN_OWNER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_owner) structure. This member may be used to establish an explicit default owner. Normally, the user ID is used as the default owner. If another value is desired, it must be specified here.

The **Owner.Sid** member may be set to **NULL** to indicate there is no alternate default owner value.

### `DefaultDacl`

[TOKEN_DEFAULT_DACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_default_dacl) structure. This member may be used to establish a default protection for the user. If no value is provided, a default protection that grants everyone all access will be established.

The **DefaultDacl.DefaultDacl** member may be set to **NULL** to indicate there is no default protection.