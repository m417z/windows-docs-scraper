# TOKEN_GROUPS structure

## Description

TOKEN_GROUPS contains information about the group security identifiers (SID) in an access token.

## Members

### `GroupCount`

Specifies the number of groups in the access token.

### `Groups[*]`

Specifies an array of [**SID_AND_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid_and_attributes) structures containing a set of SIDs and corresponding attributes.

### `Groups[ANYSIZE_ARRAY]`

Specifies an array of [**SID_AND_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid_and_attributes) structures containing a set of SIDs and corresponding attributes.

## Remarks

You can use [**SeFilterToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sefiltertoken) to designate one or more group SIDs as deny-only SIDs. Note that it is also possible to designate a user SID as a deny-only SID by specifying the user SID as one of the group SIDs in the **TOKEN_GROUPS** structure passed to **SeFilterToken**.

## See also

[**SID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)

[**SID_AND_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid_and_attributes)

[**SeFilterToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sefiltertoken)

[**SeQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryinformationtoken)

[**ZwQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryinformationtoken)

[**ZwSetInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwsetinformationtoken)