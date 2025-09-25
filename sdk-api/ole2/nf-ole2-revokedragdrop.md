# RevokeDragDrop function

## Description

Revokes the registration of the specified application window as a potential target for OLE drag-and-drop operations.

## Parameters

### `hwnd` [in]

Handle to a window previously registered as a target for an OLE drag-and-drop operation.

## Return value

This function returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **DRAGDROP_E_NOTREGISTERED** | An attempt was made to revoke a drop target that has not been registered. |
| **DRAGDROP_E_INVALIDHWND** | Invalid handle returned in the *hwnd* parameter. |
| **E_OUTOFMEMORY** | There is insufficient memory for the operation. |

## Remarks

When your application window is no longer available as a potential target for an OLE drag-and-drop operation, you must call **RevokeDragDrop**.

This function calls the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method for your drop target interface.

## See also

[RegisterDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-registerdragdrop)