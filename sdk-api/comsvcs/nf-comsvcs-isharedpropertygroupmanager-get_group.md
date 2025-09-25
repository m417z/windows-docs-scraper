# ISharedPropertyGroupManager::get_Group

## Description

Retrieves a reference to an existing shared property group.

## Parameters

### `Name` [in]

The name of the shared property group to be retrieved.

### `ppGroup` [out]

A reference to the shared property group specified in the *Name* parameter, or **NULL** if the property group does not exist.

## Return value

This method can return the standard return values E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The shared property group exists, and a reference to it is returned in the *ppGroup* parameter. |
| **E_INVALIDARG** | The shared property group with the name specified in the *Name* parameter does not exist. |

## See also

[ISharedPropertyGroupManager](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-isharedpropertygroupmanager)