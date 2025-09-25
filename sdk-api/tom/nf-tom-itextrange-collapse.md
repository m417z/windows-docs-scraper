# ITextRange::Collapse

## Description

Collapses the specified text range into a degenerate point at either the beginning or end of the range.

## Parameters

### `bStart` [in]

Type: **long**

Flag specifying the end to collapse at. It can be one of the following.

| Value | Meaning |
| --- | --- |
| **tomStart or tomTrue** | Range is collapsed to the start of the range. This is the default. |
| **tomEnd or tomFalse** | Range is collapsed to the end of the range. |

## Return value

Type: **HRESULT**

This method returns an
**HRESULT** value. If successful, it returns **S_OK**. Otherwise, it returns S_FALSE.

## See also

**Conceptual**

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)