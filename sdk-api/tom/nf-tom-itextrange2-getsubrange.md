# ITextRange2::GetSubrange

## Description

Retrieves a subrange in a range.

## Parameters

### `iSubrange` [in]

Type: **long**

The subrange index.

### `pcpFirst` [out]

Type: **long***

The character position for the start of the subrange.

### `pcpLim` [out]

Type: **long***

The character position for the end of the subrange.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Subranges are selected as follows.

| iSubrange value | Subrange |
| --- | --- |
| Equals zero | Gets the current active subrange. |
| Greater than zero | Gets the subrange at the index specified by *iSubrange*, in the order in which the subranges were added. This requires extra calculation. |
| Less than zero | Gets the subrange at the index specified by *iSubrange*, in increasing character position order. |

See [ITextRange2::GetCount](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange2-getcount) for the count of subranges not including the active subrange.

## See also

[ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2)