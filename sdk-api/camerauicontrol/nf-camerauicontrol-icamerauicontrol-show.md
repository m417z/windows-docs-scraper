# ICameraUIControl::Show

## Description

Displays the user interface control for the camera.

## Parameters

### `pWindow` [in]

Pointer to the user interface window.

### `mode` [in]

Specifies whether the user interface will be presented in a browseable or linear manner.

### `selectionMode`

Specifies the selection mode.

### `captureMode` [in]

Specifies whether the user interface that will be shown allows the user to capture a photo, capture a video, or either.

### `photoFormat` [in]

Provides the format for capturing photos. The available formats include JPEG, PNG, and JPEG XR.

### `videoFormat` [in]

Provides the format for capturing videos. The available formats include MP4 and WMV.

### `bHasCloseButton` [in]

TRUE if the user interface has a close button, otherwise, FALSE.

### `pEventCallback` [in]

Pointer to an event callback for the dialog. The callback is invoked if an item is captured or deleted, and when the dialog starts, or is closed or suspended.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ICameraUIControl](https://learn.microsoft.com/windows/desktop/api/camerauicontrol/nn-camerauicontrol-icamerauicontrol)