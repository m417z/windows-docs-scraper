# TOKEN_PRIVILEGES structure

## Description

The **TOKEN_PRIVILEGES** structure contains information about a set of privileges for an access token.

## Members

### `PrivilegeCount`

Specifies the number of entries in the **Privileges** array.

### `Privileges`

Specifies an array of [**LUID_AND_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_luid_and_attributes) structures. Each structure contains the LUID and attributes of a privilege.

## See also

[**LUID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)

[**LUID_AND_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_luid_and_attributes)

[**SID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)

[**SeFilterToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sefiltertoken)

[**SeQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryinformationtoken)

[**TOKEN_INFORMATION_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_token_information_class)

[**ZwQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryinformationtoken)

[**ZwSetInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwsetinformationtoken)