# IAzRole::DeleteMember

## Description

The **DeleteMember** method removes the specified [security identifier](https://learn.microsoft.com/windows/win32/SecGloss/s-gly) (SID) in text form from the list of Windows accounts that belong to the role.

## Parameters

### `bstrProp` [in]

String that contains the text form of the SID to remove from the list of Windows accounts that belong to the role.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

If the method succeeds, it will return `S_OK`. Any other **HRESULT** value indicates that the operation failed.

## Remarks

To view the list of SIDs of Windows accounts that belong to the role in text form, use the [Members](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazrole-get_members) property.

## See also

[Members](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazrole-get_members)