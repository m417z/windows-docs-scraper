# ITextStory::SetText

## Description

Replaces the text in a story with the specified text.

## Parameters

### `Flags` [in]

Type: **long**

Flags controlling how the text is inserted as defined in the following table:

#### tomCheckTextLimit

#### tomMathCFCheck

#### tomUnhide

#### tomUnicodeBiDi

#### tomUnlink

### `bstr` [in]

Type: **BSTR**

The new text for this story. If this parameter is **NULL**, the text in the story is deleted.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **E_ACCESSDENIED** | Write access is denied. |
| **E_OUTOFMEMORY** | Insufficient memory. |

## See also

[ITextStory](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextstory)

[ITextStory::GetText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextstory-gettext)