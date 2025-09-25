# Pager_GetDropTarget macro

## Syntax

```cpp
void Pager_GetDropTarget(
   HWND        hwnd,
   IDropTarget **ppdt
);
```

## Description

Retrieves a pager control's [IDropTarget](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idroptarget) interface pointer. You can use this macro or send the [PGM_GETDROPTARGET](https://learn.microsoft.com/windows/desktop/Controls/pgm-getdroptarget) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the pager control.

### `ppdt`

Type: **[IDropTarget](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idroptarget)****

Pointer to an [IDropTarget](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idroptarget) pointer that receives the interface pointer. It is the caller's responsibility to call
[Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on this pointer when it is no longer needed.