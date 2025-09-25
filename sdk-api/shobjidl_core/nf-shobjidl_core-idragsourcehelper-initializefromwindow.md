# IDragSourceHelper::InitializeFromWindow

## Description

Initializes the drag-image manager for a control with a window.

## Parameters

### `hwnd` [in]

Type: **HWND**

A handle to the window that receives the **DI_GETDRAGIMAGE** message. This value can be **NULL**.

### `ppt` [in]

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)***

A pointer to a [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that specifies the location of the cursor within the drag image. The structure should contain the offset from the upper-left corner of the drag image to the location of the cursor. This value can be **NULL**.

### `pDataObject` [in]

Type: **[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)***

A pointer to the data object's [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **DI_GETDRAGIMAGE** message allows you to source a drag image from a custom control. It is defined in Shlobj.h and must be registered with [RegisterWindowMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerwindowmessagea). When the window specified by *hwnd* receives the **DI_GETDRAGIMAGE** message, the *lParam* value holds a pointer to an [SHDRAGIMAGE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-shdragimage) structure. The handler should fill the structure with the drag image bitmap information.

## See also

[IDragSourceHelper](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idragsourcehelper)