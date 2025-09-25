# IWICColorContext::InitializeFromFilename

## Description

Initializes the color context from the given file.

## Parameters

### `wzFilename` [in]

Type: **LPCWSTR**

The name of the file.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Once a color context has been initialized, it can't be re-initialized.

## See also

* [GetColorDirectoryW](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-getcolordirectoryw)
* [IWICColorContext](https://learn.microsoft.com/windows/win32/api/wincodec/nn-wincodec-iwiccolorcontext)