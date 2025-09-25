# IPreviewHandler::SetWindow

## Description

Sets the parent window of the previewer window, as well as the area within the parent to be used for the previewer window.

## Parameters

### `hwnd` [in]

Type: **HWND**

A handle to the parent window.

### `prc` [in]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to a **RECT** defining the area for the previewer.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The preview handler is responsible for painting the entire area defined by *prc*. If the previewer window has been created, the preview handler must associate the previewer window to the new parent *hwnd* and resize the previewer window to the area defined by *prc*. If the previewer window has not yet been created, the preview handler must remember this information for when the previewer window is created in [IPreviewHandler::DoPreview](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipreviewhandler-dopreview).

**Note** It is preferred that this information be stored prior to calling [IPreviewHandler::DoPreview](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipreviewhandler-dopreview). Doing so increases performance at setup time for any cases where the preview does not start.