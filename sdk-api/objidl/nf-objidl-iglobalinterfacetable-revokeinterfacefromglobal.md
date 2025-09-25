# IGlobalInterfaceTable::RevokeInterfaceFromGlobal

## Description

Revokes the registration of an interface in the global interface table.

## Parameters

### `dwCookie` [in]

Identifies the interface whose global registration is to be revoked.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | The parameter is invalid. |

## Remarks

Call this method when an interface registered in the global interface table object no longer needs to be accessed by other apartments in the same process. This method can be called by any apartment in the process, including apartments other than the one that registered the interface in the global interface table.

## See also

[IGlobalInterfaceTable](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iglobalinterfacetable)