# ITextStory::GetRange

## Description

Gets a text range object for the story.

## Parameters

### `cpActive` [in]

Type: **long**

The active end of the range.

### `cpAnchor` [in]

Type: **long**

The anchor end of the range.

### `ppRange` [out, retval]

Type: **[ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2)****

The text range object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **E_OUTOFMEMORY** | Insufficient memory. |

## See also

[ITextStory](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextstory)