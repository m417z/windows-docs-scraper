# ITextDocument::Save

## Description

Saves the document.

## Parameters

### `pVar` [in]

Type: **VARIANT***

The save target. This parameter is a **VARIANT**, which can be a file name, or **NULL**.

### `Flags` [in]

Type: **long**

File creation, open, share, and conversion flags. For a list of possible values, see [ITextDocument::Open](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument-open).

### `CodePage` [in]

Type: **long**

The specified code page. Common values are CP_ACP (zero: system ANSI code page), 1200 (Unicode), and 1208 (UTF-8).

## Return value

Type: **HRESULT**

The return value can be an
**HRESULT** value that corresponds to a system error code or a COM error code, including one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeds. |
| **E_INVALIDARG** | Invalid argument. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_NOTIMPL** | Feature not implemented. |

## Remarks

To use the parameters that were specified for opening the file, use zero values for the parameters.

If
*pVar* is null or missing, the file name given by this document's name is used. If both of these are missing or null, the method fails.

If
*pVar* specifies a file name, that name should replace the current Name property. Similarly, the
*Flags* and
*CodePage* arguments can overrule those supplied in the
[ITextDocument::Open](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument-open) method and define the values to use for files created with the
[ITextDocument::New](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument-new) method.

Unicode plain-text files should be saved with the Unicode byte-order mark (0xFEFF) as the first character. This character should be removed when the file is read in; that is, it is only used for import/export to identify the plain text as Unicode and to identify the byte order of that text. Microsoft Notepad adopted this convention, which is now recommended by the Unicode standard.

## See also

**Conceptual**

[ITextDocument](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument)

[New](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument-new)

[Open](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument-open)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)