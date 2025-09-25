# IProgressDialog::SetAnimation

## Description

[This method is not supported in Windows Vista or later versions.]

Specifies an Audio-Video Interleaved (AVI) clip that runs in the dialog box.

## Parameters

### `hInstAnimation` [in, optional]

Type: **HINSTANCE**

An instance handle to the module from which the AVI resource should be loaded.

### `idAnimation`

Type: **UINT**

An AVI resource identifier. To create this value, use the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro. The control loads the AVI resource from the module specified by *hInstAnimation*.

## Return value

Type: **HRESULT**

Returns **S_OK** if successful, or an error value otherwise. In Windows Vista and later versions, always returns **S_OK**.

## Remarks

**IProgressDialog::SetAnimation** cannot be called before the progress dialog is visible. Until it is displayed, the progress dialog does not have a valid HWND. The existence of that HWND can be used to determine whether **IProgressDialog::SetAnimation** can be called.

This method takes the instance handle specified by *hInstAnimation* and uses an [animation control](https://learn.microsoft.com/windows/desktop/Controls/animation-control-overview) to open and run a silent AVI clip. There are several restrictions as to what types of AVI clips can be used, including the following:

* Clips cannot include sound.
* The size of the AVI clip cannot exceed 272 by 60 pixels. Smaller rectangles can be used, but they might not be properly centered.
* AVI clips must either be uncompressed or compressed with run-length (BI_RLE8) encoding. If you attempt to use an unsupported compression type, no animation is displayed.

## See also

[IProgressDialog](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iprogressdialog)