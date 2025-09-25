# IFileDialogCustomize::GetEditBoxText

## Description

Gets the current text in an edit box control.

## Parameters

### `dwIDCtl` [in]

Type: **DWORD**

The ID of the edit box.

### `ppszText` [out]

Type: **WCHAR****

The address of a pointer to a buffer that receives the text as a null-terminated Unicode string.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

It is the responsibility of the calling application to free the buffer referenced by *ppszText* when it is no longer needed. Use [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to free the buffer.