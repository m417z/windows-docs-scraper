# IAzApplicationGroup::AddMember

## Description

The **AddMember** method adds the specified [security identifier](https://learn.microsoft.com/windows/win32/SecGloss/s-gly) (SID) in text form to the list of accounts that belong to the application group.

## Parameters

### `bstrProp` [in]

String that contains the text form of the SID to add to the list of accounts that belong to the application group.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

If the method succeeds, it will return `S_OK`. Any other **HRESULT** value indicates that the operation failed.

## Remarks

To view the list of SIDs of accounts that belong to this application group in text form, use the [Members](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplicationgroup-get_members) property.

You must call the [Submit](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplicationgroup-submit) method to persist any changes made by this method.

## See also

[Members](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplicationgroup-get_members)

[Submit](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplicationgroup-submit)