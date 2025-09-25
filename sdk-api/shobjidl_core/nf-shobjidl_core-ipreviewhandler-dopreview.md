# IPreviewHandler::DoPreview

## Description

Directs the preview handler to load data from the source specified in an earlier Initialize method call, and to begin rendering to the previewer window.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation completed successfully. |
| **E_PREVIEWHANDLER_DRM_FAIL** | Blocked by digital rights management. |
| **E_PREVIEWHANDLER_NOAUTH** | Blocked by file permissions. |
| **E_PREVIEWHANDLER_NOTFOUND** | Item was not found. |
| **E_PREVIEWHANDLER_CORRUPT** | Item was corrupt. |

## Remarks

If the previewer window has not yet been created, then it must be created after this method has been called. The preview handler is responsible for painting the area specified in [IPreviewHandler::SetWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipreviewhandler-setwindow) or [IPreviewHandler::SetRect](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipreviewhandler-setrect). If these methods are called while the preview handler is rendering, the window must be reparented/resized without stopping or restarting the rendering of the item.

This method should be called only after [IPreviewHandler::SetWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipreviewhandler-setwindow) has been called.

Additionally, this method should be called only after [IInitializeWithItem::Initialize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iinitializewithitem-initialize), [IInitializeWithStream::Initialize](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-iinitializewithstream-initialize), or [IInitializeWithFile::Initialize](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-iinitializewithfile-initialize) has been called.

**Note** Do not actually create the previewer window until this method has been called.