# ITextPara::SetIndents

## Description

Sets the first-line indent, the left indent, and the right indent for a paragraph.

## Parameters

### `First` [in]

Type: **float**

Indent of the first line in a paragraph, relative to the left indent. The value is in floating-point points and can be positive or negative.

### `Left` [in]

Type: **float**

Left indent of all lines except the first line in a paragraph, relative to left margin. The value is in floating-point points and can be positive or negative.

### `Right` [in]

Type: **float**

Right indent of all lines in paragraph, relative to the right margin. The value is in floating-point points and can be positive or negative. This value is optional.

## Return value

Type: **HRESULT**

If **ITextPara::SetIndents** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_INVALIDARG** | Invalid argument. |
| **E_ACCESSDENIED** | Write access is denied. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **CO_E_RELEASED** | The paragraph formatting object is attached to a range that has been deleted. |

## Remarks

Line indents are not allowed to position text in the margins. If the first-line indent is set to a negative value (for an outdented paragraph) while the left indent is zero, the first-line indent is reset to zero. To avoid this problem while retaining property sets, set the first-line indent value equal to zero either explicitly or by calling the [ITextPara::Reset](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-reset) method. Then, call **ITextPara::SetIndents** to set a nonnegative, left-indent value and set the desired first-line indent.

## See also

**Conceptual**

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

**Reference**

[Reset](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-reset)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)