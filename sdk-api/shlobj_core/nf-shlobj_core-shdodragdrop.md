# SHDoDragDrop function

## Description

Executes a drag-and-drop operation. Supports drag source creation on demand, as well as drag images.

## Parameters

### `hwnd` [in]

Type: **HWND**

The handle of the window used to obtain the drag image. This value can be **NULL**. See Remarks for more details.

### `pdata` [in]

Type: **[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)***

A pointer to the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface on a data object that contains the data being dragged.

### `pdsrc` [in]

Type: **[IDropSource](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idropsource)***

A pointer to an implementation of the [IDropSource](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idropsource) interface, which is used to communicate with the source during the drag operation.

As of Windows Vista, if this value is **NULL**, the Shell creates a drop source object for you.

### `dwEffect` [in]

Type: **DWORD**

The effects that the source allows in the drag-and-drop operation. The most significant effect is whether the drag-and-drop operation permits a move. For a list of possible values, see [DROPEFFECT](https://learn.microsoft.com/windows/desktop/com/dropeffect-constants).

### `pdwEffect` [out]

Type: **DWORD***

A pointer to a value that indicates how the drag-and-drop operation affected the source data. The *pdwEffect* parameter is set only if the operation is not canceled. For a list of possible values, see [DROPEFFECT](https://learn.microsoft.com/windows/desktop/com/dropeffect-constants).

## Return value

Type: **HRESULT**

This function supports the standard return value E_OUTOFMEMORY, as well as the following values:

| Return code | Description |
| --- | --- |
| **DRAGDROP_S_DROP** | The drag-and-drop operation was successful. |
| **DRAGDROP_S_CANCEL** | The drag-and-drop operation was canceled. |
| **E_UNSPEC** | Unexpected error occurred. |

## Remarks

As of Windows Vista, if a drag image is not already stored in the data object *pdtobj* and a drag image cannot be obtained from the window specified by *hwnd*, the Shell provides a generic drag image. A drag image can fail to be obtained from the specified window either because *hwnd* is **NULL** or the specified window does not support the DI_GETDRAGIMAGE message.