# TOKEN_OWNER structure

## Description

The **TOKEN_OWNER** structure contains the default owner security identifier (SID) that will be applied to newly created objects.

## Members

### `Owner`

Pointer to a SID structure representing a user that will become the default owner of any objects created by a process using this access token. The SID must be one of the user or group SIDs already in the token.

## Remarks

Whenever the process using this access token creates a new object, the object is owned by the **Owner**, unless the process provides a security descriptor for the object.

The **Owner** must be a legally formed SID and must match one of the user or group SIDs already in the token.

If it is a group SID, the **Owner** must match a group SID in the token, where the attributes on the group must include SE_GROUP_OWNER and must not include SE_GROUP_USE_FOR_DENY_ONLY.

## See also

[**SID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)

[**SeQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryinformationtoken)

[**TOKEN_INFORMATION_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_token_information_class)

[**ZwQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryinformationtoken)

[**ZwSetInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwsetinformationtoken)