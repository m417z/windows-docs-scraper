# SID_INFO structure

## Description

The **SID_INFO** structure contains the list of common names corresponding to the
[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structures returned by
[ISecurityInformation2::LookupSids](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation2-lookupsids). It is a member of the
[SID_INFO_LIST](https://learn.microsoft.com/windows/desktop/api/aclui/ns-aclui-sid_info_list) structure.

## Members

### `pSid`

A pointer to a [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure that identifies one of the SIDs passed into
[ISecurityInformation2::LookupSids](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation2-lookupsids).

### `pwzCommonName`

A pointer to a string containing the common name corresponding to the
[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure specified in **pSid**.

### `pwzClass`

A pointer to a string describing the [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure as either a user or a group. The possible values of this string are as follows:

"Computer"

"Group"

"User"

### `pwzUPN`

A pointer to the user principal name (UPN) corresponding to the
[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure specified in **pSid**. If a UPN has not been designated for the **SID** structure, the value of this parameter is **NULL**.

## See also

[ISecurityInformation2::LookupSids](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation2-lookupsids)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)