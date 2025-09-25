# IFileDialog::GetFileName

## Description

Retrieves the text currently entered in the dialog's **File name** edit box.

## Parameters

### `pszName` [out]

Type: **WCHAR****

The address of a pointer to a buffer that, when this method returns successfully, receives the text.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The text in the **File name** edit box does not necessarily reflect the item the user chose. To get the item the user chose, use [IFileDialog::GetResult](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialog-getresult).

The calling application is responsible for releasing the retrieved buffer by using the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.