# IAzApplicationGroup::DeleteNonMember

## Description

The **DeleteNonMember** method removes the specified [security identifier](https://learn.microsoft.com/windows/win32/SecGloss/s-gly) (SID) in text form from the list of accounts that are refused membership in the application group.

## Parameters

### `bstrProp` [in]

String that contains the text form of the SID to remove from the list of accounts that are refused membership in the application group.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

If the method succeeds, it will return `S_OK`. Any other **HRESULT** value indicates that the operation failed.

## Remarks

To view the list of SIDs of accounts that are refused membership in this application group in text form, use the [NonMembers](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplicationgroup-get_nonmembers) property.

## See also

[NonMembers](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplicationgroup-get_nonmembers)