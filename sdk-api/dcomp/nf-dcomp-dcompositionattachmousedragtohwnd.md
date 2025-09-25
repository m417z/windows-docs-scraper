# DCompositionAttachMouseDragToHwnd function

## Description

Creates an Interaction/InputSink to route mouse button down and any
subsequent move and up events to the given HWND. There is no move
thresholding; when enabled, all events including and following the down
are unconditionally redirected to the specified window. After calling this
API, the device owning the visual must be committed.

## Parameters

### `visual` [in]

Type: **[IDCompositionVisual](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvisual)***

The visual to route messages from.

### `hwnd` [in]

Type: **HWND**

The HWND to route messages to.

### `enable` [in]

Type: **BOOL**

Boolean value indicating whether to enable or disable routing.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.