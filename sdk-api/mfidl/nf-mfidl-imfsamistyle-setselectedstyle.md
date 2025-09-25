# IMFSAMIStyle::SetSelectedStyle

## Description

Sets the current style on the SAMI media source.

## Parameters

### `pwszStyle` [in]

Pointer to a null-terminated string containing the name of the style. To clear the current style, pass an empty string (""). To get the list of style names, call [IMFSAMIStyle::GetStyles](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsamistyle-getstyles).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFSAMIStyle](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsamistyle)

[SAMI Media Source](https://learn.microsoft.com/windows/desktop/medfound/sami-media-source)