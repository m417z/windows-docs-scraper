# ITextStrings::SetOpCp

## Description

Sets the character position in the source range's story that has desired character formatting attributes. The [ITextStrings::EncodeFunction](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextstrings-encodefunction) method applies those character formatting attributes to the operators specified by the *Char*, *Char1*, and *Char2* parameters.

## Parameters

### `iString` [in]

Type: **long**

The index of the string to associate with a character position.

### `cp` [in]

Type: **long**

The character position in source range's story that has the desired character formatting.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |

## See also

[ITextStrings](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextstrings)