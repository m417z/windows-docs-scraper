# TOKEN_USER structure

## Description

The **TOKEN_USER** structure identifies the user associated with an access token.

## Members

### `User`

Specifies an [**SID_AND_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid_and_attributes) structure representing the user associated with the access token.

## Remarks

Unlike TOKEN_GROUPS structures, TOKEN_USER structures cannot be passed to **SeFilterToken**. Nevertheless, it is possible to designate a user SID as a deny-only SID by specifying the user SID as one of the group SIDs in the TOKEN_GROUPS structure passed to **SeFilterToken**.

## See also

[**SID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)

[**SID_AND_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid_and_attributes)

[**SeFilterToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sefiltertoken)

[**SeQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryinformationtoken)

[**TOKEN_GROUPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_groups)

[**TOKEN_INFORMATION_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_token_information_class)

[**ZwQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryinformationtoken)

[**ZwSetInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwsetinformationtoken)