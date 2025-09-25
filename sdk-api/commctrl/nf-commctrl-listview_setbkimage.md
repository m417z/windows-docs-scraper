# ListView_SetBkImage macro

## Syntax

```cpp
BOOL ListView_SetBkImage(
   HWND        hwnd,
   LPLVBKIMAGE plvbki
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns nonzero if successful, or zero otherwise. Returns zero if the ulFlags member of the **LVBKIMAGE** structure is LVBKIF_SOURCE_NONE.

## Description

Sets the background image in a list-view control. You can use this macro or send the [LVM_SETBKIMAGE](https://learn.microsoft.com/windows/desktop/Controls/lvm-setbkimage) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `plvbki`

Type: **LPLVBKIMAGE**

A pointer to an [LVBKIMAGE](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvbkimagea) structure that contains the new background image information.

## Remarks

Because the list-view control uses OLE COM to manipulate the background images, the calling application must call [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize) or [OleInitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleinitialize) before using this macro. It is best to call one of these functions when the application is initialized and call either [CoUninitialize](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-couninitialize) or [OleUninitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleuninitialize) when the application is terminating.

## See also

[ListView_GetBkImage](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-listview_getbkimage)