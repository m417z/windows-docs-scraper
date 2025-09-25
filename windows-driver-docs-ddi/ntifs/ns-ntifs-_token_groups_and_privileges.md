# TOKEN_GROUPS_AND_PRIVILEGES structure

## Description

TOKEN_GROUPS_AND_PRIVILEGES contains information about the group security identifiers (SIDs) and privileges in an access token.

## Members

### `SidCount`

Specifies the number of SIDs in the access token.

### `SidLength`

Specifies the length, in bytes, required to hold all of the user SIDs and the account SID for the group.

### `Sids`

A pointer to SID_AND_ATTRIBUTES structures that contain a set of SIDs and corresponding attributes.

### `RestrictedSidCount`

Specifies the number of the restricted SIDs included in the access token.

### `RestrictedSidLength`

Specifies the length, in bytes, required to hold all of the restricted SIDs.

### `RestrictedSids`

A pointer to [**SID_AND_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid_and_attributes) structures that contain a set of restricted SIDs and corresponding attributes.

### `PrivilegeCount`

Specifies the number of privileges included in the access token.

### `PrivilegeLength`

Specifies the length, in bytes, needed to hold all of the privileges.

### `Privileges`

A pointer to [**LUID_AND_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_luid_and_attributes) structures that contain a set of privileges.

### `AuthenticationId`

The locally unique identifier (LUID) of the authenticator of the token.

## See also

[**ACL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)

[**LUID_AND_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_luid_and_attributes)

[**SECURITY_IMPERSONATION_LEVEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_security_impersonation_level)

[**SID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)

[**SID_AND_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid_and_attributes)

[**SeFilterToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sefiltertoken)

[**SeQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryinformationtoken)

[**SeTokenIsRestricted**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-setokenisrestricted)

[**TOKEN_DEFAULT_DACL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_default_dacl)

[**TOKEN_INFORMATION_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_token_information_class)

[**TOKEN_OWNER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_owner)

[**TOKEN_PRIMARY_GROUP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_primary_group)

[**TOKEN_PRIVILEGES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_privileges)

[**TOKEN_SOURCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_source)

[**TOKEN_STATISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_statistics)

[**TOKEN_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_token_type)

[**TOKEN_USER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_user)

[**ZwQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryinformationtoken)

[**ZwSetInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwsetinformationtoken)