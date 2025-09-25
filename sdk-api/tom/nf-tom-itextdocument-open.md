# ITextDocument::Open

## Description

Opens a specified document. There are parameters to specify access and sharing privileges, creation and conversion of the file, as well as the code page for the file.

## Parameters

### `pVar` [in]

Type: **VARIANT***

A **VARIANT** that specifies the name of the file to open.

### `Flags`

Type: **long**

The file creation, open, share, and conversion flags. Default value is zero, which gives read/write access and read/write sharing, open always, and automatic recognition of the file format (unrecognized file formats are treated as text). Other values are defined in the following groups.

Any combination of these values may be used.

#### tomReadOnly

#### tomShareDenyRead

#### tomShareDenyWrite

#### tomPasteFile

These values are mutually exclusive.

#### tomCreateNew

#### tomCreateAlways

#### tomOpenExisting

#### tomOpenAlways

#### tomTruncateExisting

#### tomRTF

#### tomText

#### tomHTML

#### tomWordDocument

### `CodePage`

Type: **long**

The code page to use for the file. Zero (the default value) means **CP_ACP** (ANSI code page) unless the file begins with a Unicode BOM 0xfeff, in which case the file is considered to be Unicode. Note that code page 1200 is Unicode, **CP_UTF8** is UTF-8.

## Return value

Type: **HRESULT**

The return value can be an **HRESULT** value that corresponds to a system error or COM error code, including one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeds |
| **E_INVALIDARG** | Invalid argument. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_NOTIMPL** | Feature not implemented. |

## Remarks

If a document is created with the [ITextDocument::New](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument-new) method and the zero values are used, then the Text Object Model (TOM) engine has to choose which flags and code page to use. UTF-8 Rich Text Format (RTF) (defined below) is an attractive default.

Microsoft Rich Edit 3.0 defines a control word, \urtf8, which should be used instead of \rtf1. This means the file is encoded in UTF-8. On input, RTF files contain the relevant code-page information, but this can be changed for saving purposes, thereby allowing one version to be translated to another.

If the tomPasteFile flag is not set in the *Flags* parameter, the method first closes the current document after saving any unsaved changes.

A file is recognized as a Unicode text file if it starts with the Unicode BOM 0xfeff. The **ITextDocument::Open** method strips off this Unicode BOM on input and [ITextDocument::Save](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument-save) applies it on output. See the comments on the **ITextDocument::Save** method, which discuss putting the Unicode BOM at the beginning of Unicode plain-text files. The conversion values **tomRTF**, **tomHTML**, and **tomWordDocument** are used primarily for the **ITextDocument::Save** method, since these formats are easily recognized on input.

Errors are reported by negative values, but because file operations have many kinds of errors, you may not need all of the error information provided. In particular, you may not care (or you may already know) which file facility is used, namely Windows (`pVar.vt = VT_BSTR`) or OLE storage for [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage). By masking off bit 18 of an **HRESULT** value, you can ignore the difference and compare to its **STG_E_xxx** value. For example:

```
HRESULT hr;
VARIANT Var;
VariantInit(&Var)

Var.vt = VT_BSTR;
Var.bstrVal = SysAllocString(L"test.txt"); // Use file command
hr = pDoc->Open(&Var, tomOpenExisting, 0);
hr &= ~0x40000; // Mask off bit 18
if(hr == STG_E_FILENOTFOUND)
{
...// the rest of the code
}
```

## See also

**Conceptual**

[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage)

[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)

[ITextDocument](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument)

**Other Resources**

**Reference**

[Save](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument-save)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)