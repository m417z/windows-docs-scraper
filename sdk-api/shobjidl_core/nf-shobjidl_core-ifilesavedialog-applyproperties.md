# IFileSaveDialog::ApplyProperties

## Description

Applies a set of properties to an item using the Shell's copy engine.

## Parameters

### `psi` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

Pointer to the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) that represents the file being saved. This is usually the item retrieved by [GetResult](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialog-getresult).

### `pStore` [in]

Type: **[IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore)***

Pointer to the [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) that represents the property values to be applied to the file. This can be the property store returned by [IFileSaveDialog::GetProperties](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifilesavedialog-getproperties).

### `hwnd` [in]

Type: **HWND**

The handle of the application window.

### `pSink` [in]

Type: **[IFileOperationProgressSink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperationprogresssink)***

Pointer to an optional **IFileOperationProgressSink** that the calling application can use if they want to be notified of the progress of the property stamping. This value may be **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method should be used when the application has turned on property collection ([IFileSaveDialog::SetCollectedProperties](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifilesavedialog-setcollectedproperties)), but does not persist the properties themselves into the saved file.

**Note** The file represented by the item specified in *psi* must exist in physical storage before making the call to **IFileSaveDialog::ApplyProperties**, so it must have been previously saved at some point.