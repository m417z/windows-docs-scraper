# ITextPara::AddTab

## Description

Adds a tab at the displacement
*tbPos*, with type
*tbAlign*, and leader style,
*tbLeader*.

## Parameters

### `tbPos` [in]

Type: **float**

New tab displacement, in floating-point points.

### `tbAlign` [in]

Type: **long**

Alignment options for the tab position. It can be one of the following.

| Value | Meaning |
| --- | --- |
| **tomAlignLeft** | Text is left justified from the tab position. This is the default. |
| **tomAlignCenter** | Text is centered on the tab position. |
| **tomAlignRight** | Text is right justified from the tab position. |
| **tomAlignDecimal** | The decimal point is set at the tab position. This is useful for aligning a column of decimal numbers. |
| **tomAlignBar** | A vertical bar is positioned at the tab position. Text is not affected. Alignment bars on nearby lines at the same position form a continuous vertical line. |

### `tbLeader` [in]

Type: **long**

Leader character style. A leader character is the character that is used to fill the space taken by a tab character. It can be one of the following.

| Value | Meaning |
| --- | --- |
| **tomSpaces** | Spaces are used. This is the default. |
| **tomDots** | Dots are used. |
| **tomDashes** | A dashed line is used. |
| **tomLines** | A solid line is used. |

## Return value

Type: **HRESULT**

If **ITextPara::AddTab** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_ACCESSDENIED** | Write access is denied. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **CO_E_RELEASED** | The paragraph format object is attached to a range that has been deleted. |

## Remarks

It is assumed that there is never a tab at position zero. If multiple paragraphs are described, the common subset of tabs will be returned with 0x8000 in the upper word of the tab type.

## See also

[ClearAllTabs](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-clearalltabs)

**Conceptual**

[DeleteTab](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-deletetab)

[GetListTab](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-getlisttab)

[GetTab](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-gettab)

[GetTabCount](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-gettabcount)

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

**Reference**

[SetListTab](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-setlisttab)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)