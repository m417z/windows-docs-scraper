# IPreviewHandler::Unload

## Description

Directs the preview handler to cease rendering a preview and to release all resources that have been allocated based on the item passed in during the initialization.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When called, the preview window will be destroyed.

This method should be called only after [IInitializeWithItem::Initialize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iinitializewithitem-initialize), [IInitializeWithStream::Initialize](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-iinitializewithstream-initialize), or [IInitializeWithFile::Initialize](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-iinitializewithfile-initialize) has been called. All resources associated with this initialization will be released. Prior to calling [IPreviewHandler::DoPreview](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipreviewhandler-dopreview), this preview handler will be re-initialized with a call to one of the initialization interfaces and a call to [IPreviewHandler::SetWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipreviewhandler-setwindow).