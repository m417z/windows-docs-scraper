# SID_INFO_LIST structure

## Description

The **SID_INFO_LIST** structure contains a list of
[SID_INFO](https://learn.microsoft.com/windows/desktop/api/aclui/ns-aclui-sid_info) structures.

## Members

### `cItems`

The number of
[SID_INFO](https://learn.microsoft.com/windows/desktop/api/aclui/ns-aclui-sid_info) structures contained in the **aSidInfo** member.

### `aSidInfo`

A pointer to a list of [SID_INFO](https://learn.microsoft.com/windows/desktop/api/aclui/ns-aclui-sid_info) structures that is returned by the
[ISecurityInformation2::LookupSids](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation2-lookupsids) method.

## See also

[ISecurityInformation2::LookupSids](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation2-lookupsids)

[SID_INFO](https://learn.microsoft.com/windows/desktop/api/aclui/ns-aclui-sid_info)