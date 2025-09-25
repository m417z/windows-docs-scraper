# DCompositionAttachMouseWheelToHwnd function

## Description

Creates an Interaction/InputSink to route mouse wheel messages to the
given HWND. This will fail if there is already an interaction attached
to this visual. After calling this API, the device that owns the visual must
be committed.

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