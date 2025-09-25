# TOKEN_DEFAULT_DACL structure

## Description

The TOKEN_DEFAULT_DACL structure specifies a discretionary access-control list (DACL).

## Members

### `DefaultDacl`

Pointer to an access control list (ACL) structure assigned by default to any objects created by the user represented by the access token.

## Remarks

The **SeQueryInformationToken** support routine retrieves the default DACL for an access token, in the form of a TOKEN_DEFAULT_DACL structure.

## See also

[**ACL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)

[**SeQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryinformationtoken)

[**ZwQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryinformationtoken)

[**ZwSetInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwsetinformationtoken)