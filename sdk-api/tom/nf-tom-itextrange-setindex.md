# ITextRange::SetIndex

## Description

Changes this range to the specified unit of the story.

## Parameters

### `Unit` [in]

Type: **long**

Unit used to index the range. For a list of unit values, see [ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange).

### `Index` [in]

Type: **long**

Index for the *Unit*. This range is relocated to the *Unit* that has this index number. If positive, the numbering of *Unit*s begins at the start of the story and proceeds forward. If negative, the numbering begins at the end of the story and proceeds backward. The start of the story corresponds to an *Index* of 1 for all units that exist, and the last unit in the story corresponds to an *Index* of -1.

### `Extend` [in]

Type: **long**

Flag that indicates the extent of the range. If zero (the default), the range is collapsed to an insertion point at the start position of the specified *Unit*. If nonzero, the range is set to the entire *Unit*.

## Return value

Type: **HRESULT**

The method returns an **HRESULT** value. If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Index is not valid. |
| **E_NOTIMPL** | Unit is not supported. |
| **S_FALSE** | Failure for some other reason. |

## Remarks

This method allows an application to work with line-oriented text, such as programs, in a convenient way. For example, `SetIndex(tomLine, 10, 0)` converts a range to an insertion point at the start of the tenth line.

## See also

**Conceptual**

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)