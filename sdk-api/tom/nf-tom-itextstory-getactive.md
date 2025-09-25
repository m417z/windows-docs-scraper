# ITextStory::GetActive

## Description

Sets the active state of a story.

## Parameters

### `pValue` [out, retval]

Type: **long***

The active state. It can be one of the following values.

| Value | Meaning |
| --- | --- |
| **tomDisplayActive** | The story has no UI or display (fast and lightweight). |
| **tomDisplayUIActive** | The story is UI active; that is, gets keyboard and mouse interactions. |
| **tomInactive** | The story has display, but no UI. |
| **tomUIActive** | The story has display and UI activity. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextStory](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextstory)

[ITextStory::SetActive](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextstory-setactive)