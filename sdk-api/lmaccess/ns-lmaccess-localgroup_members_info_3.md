# LOCALGROUP_MEMBERS_INFO_3 structure

## Description

The
**LOCALGROUP_MEMBERS_INFO_3** structure contains the account name and domain name associated with a local group member.

## Members

### `lgrmi3_domainandname`

Pointer to a null-terminated Unicode string specifying the account name of the local group member prefixed by the domain name and the "\" separator character. For example:

``` syntax
<DomainName>\<AccountName>

```

## Remarks

User account names are limited to 20 characters and group names are limited to 256 characters. In addition, account names cannot be terminated by a period and they cannot include commas or any of the following printable characters: ", /, \, [, ], :, |, <, >, +, =, ;, ?, *. Names also cannot include characters in the range 1-31, which are nonprintable.

## See also

[LOCALGROUP_MEMBERS_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_members_info_0)

[LOCALGROUP_MEMBERS_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_members_info_1)

[LOCALGROUP_MEMBERS_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_members_info_2)

[Local Group Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/local-group-functions)

[NetLocalGroupAddMembers](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netlocalgroupaddmembers)

[NetLocalGroupDelMembers](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netlocalgroupdelmembers)

[NetLocalGroupGetMembers](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netlocalgroupgetmembers)

[NetLocalGroupSetMembers](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netlocalgroupsetmembers)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)