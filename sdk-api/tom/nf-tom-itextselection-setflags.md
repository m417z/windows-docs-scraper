# ITextSelection::SetFlags

## Description

Sets the text selection flags.

## Parameters

### `Flags`

Type: **long**

New flag values. It can be any combination of the following.

| Selection flag | Value | Meaning |
| --- | --- | --- |
| **tomSelStartActive** | 1 | Start end is active. |
| **tomSelAtEOL** | 2 | For degenerate selections, the ambiguous character position corresponding to both the beginning of a line and the end of the preceding line should have the caret displayed at the end of the preceding line. |
| **tomSelOvertype** | 4 | Insert/Overtype mode is set to overtype. |
| **tomSelActive** | 8 | Selection is active. |
| **tomSelReplace** | 16 | Typing and pasting replaces selection. |

Each of the table values is binary. Thus, if any value is not set, the text selection has the opposite property.

## Return value

Type: **HRESULT**

The method returns **S_OK**.

## Remarks

To make sure that the start end is active and that the ambiguous
character position is displayed at the end of the line, execute the following code:

```
selection.Flags = tomSelStartActive + tomSelAtEOL
```

The
Flags property is useful because an [ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange) object can select itself. With **SetFlags**, you can change the active end from the default value of End, select the caret position for an ambiguous
character position, or change the Insert/Overtype mode.

## See also

**Conceptual**

[GetFlags](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextselection-getflags)

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

[ITextSelection](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextselection)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)