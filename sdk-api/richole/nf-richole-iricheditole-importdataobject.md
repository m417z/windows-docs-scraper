# IRichEditOle::ImportDataObject

## Description

Imports a clipboard object into a rich edit control, replacing the current selection.

## Parameters

### `lpdataobj`

Type: **LPDATAOBJECT**

The clipboard object to import.

### `cf`

Type: **CLIPFORMAT**

Clipboard format to use. A value of zero will use the best available format.

### `hMetaPict`

Type: **[HGLOBAL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a metafile containing the icon view of an object. The handle is used only if the **DVASPECT_ICON** display aspect is required by a [Paste Special](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuipastespeciala) operation.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns **S_OK** on success. If the method fails, it can return one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | There was an invalid argument. |
| **E_OUTOFMEMORY** | There was not enough memory to do the operation. |

## See also

[IRichEditOle](https://learn.microsoft.com/windows/desktop/api/richole/nn-richole-iricheditole)