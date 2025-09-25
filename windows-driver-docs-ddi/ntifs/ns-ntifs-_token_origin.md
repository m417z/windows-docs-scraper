# TOKEN_ORIGIN structure

## Description

The **TOKEN_ORIGIN** structure contains information about the origin of the logon session.

## Members

### `OriginatingLogonSession`

The locally unique identifier (LUID) for the logon session. If the token resulted from a logon using explicit credentials, such as passing name, domain, and password to the user-mode **LogonUser** function, then this member will contain the ID of the logon session that created it. If the token resulted from network authentication, such as a call to the user-mode **AcceptSecurityContext**, or a call to the user-mode **LogonUser** function with dwLogonType set to LOGON32_LOGON_NETWORK or LOGON32_LOGON_NETWORK_CLEARTEXT, then this member will be zero.

## See also

[**ACL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)

[**LUID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)

[**LUID_AND_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_luid_and_attributes)

[**SECURITY_IMPERSONATION_LEVEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_security_impersonation_level)

[**SID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)

[**SeFilterToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sefiltertoken)

[**SeQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryinformationtoken)

[**SeTokenIsRestricted**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-setokenisrestricted)

[**TOKEN_INFORMATION_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_token_information_class)

[**ZwQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryinformationtoken)

[**ZwSetInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwsetinformationtoken)