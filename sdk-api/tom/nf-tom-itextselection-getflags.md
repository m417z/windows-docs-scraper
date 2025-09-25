# ITextSelection::GetFlags

## Description

Gets the text selection flags.

## Parameters

### `pFlags`

Type: **long***

Any combination of the following selection flags.

| Selection Flag | Value | Meaning |
| --- | --- | --- |
| **tomSelStartActive** | 1 | Start end is active. |
| **tomSelAtEOL** | 2 | For degenerate selections, the ambiguous character position corresponding to both the beginning of a line and the end of the preceding line should have the caret displayed at the end of the preceding line. |
| **tomSelOvertype** | 4 | Insert/Overtype mode is set to overtype. |
| **tomSelActive** | 8 | Selection is active. |
| **tomSelReplace** | 16 | Typing and pasting replaces selection. |

Each of the table values is binary. Thus, if any value is not set, the text selection has the opposite property.

## Return value

Type: **HRESULT**

The method returns an
**HRESULT** value. If the method succeeds, it returns **S_OK**. If *pFlags* is null, the method fails and it returns E_INVALIDARG.

## See also

**Conceptual**

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

[ITextSelection](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextselection)

**Reference**

[SetFlags](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-setflags)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)