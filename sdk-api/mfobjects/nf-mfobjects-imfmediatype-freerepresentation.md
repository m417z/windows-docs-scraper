# IMFMediaType::FreeRepresentation

## Description

Frees memory that was allocated by the [IMFMediaType::GetRepresentation](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediatype-getrepresentation) method.

## Parameters

### `guidRepresentation` [in]

GUID that was passed to the [GetRepresentation](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediatype-getrepresentation) method.

### `pvRepresentation` [in]

Pointer to the buffer that was returned by the [GetRepresentation](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediatype-getrepresentation) method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype)