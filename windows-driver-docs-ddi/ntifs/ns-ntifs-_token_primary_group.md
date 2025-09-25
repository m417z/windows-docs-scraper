# TOKEN_PRIMARY_GROUP structure

## Description

The **TOKEN_PRIMARY_GROUP** structure specifies a group security identifier (SID) for an access token.

## Members

### `PrimaryGroup`

Pointer to a SID structure representing a group that will become the primary group of any objects created by a process using this access token. The SID must be one of the group SIDs already in the token.

## See also

[**SID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)

[**SeQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryinformationtoken)

[**TOKEN_INFORMATION_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_token_information_class)

[**ZwQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryinformationtoken)

[**ZwSetInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwsetinformationtoken)