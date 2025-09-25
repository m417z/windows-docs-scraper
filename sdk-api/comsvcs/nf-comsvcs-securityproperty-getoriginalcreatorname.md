# SecurityProperty::GetOriginalCreatorName

## Description

[Do not use this method in COM+ applications because it was designed to be used only in MTS 2.0 applications.]

Retrieves the user name associated with the original base process that initiated the activity in which the current object is executing.

## Parameters

### `bstrUserName` [out]

A reference to the user name associated with the original base process that initiated the activity in which the current object is executing.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[SecurityProperty](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-securityproperty)