# ITextRange::Expand

## Description

Expands this range so that any partial units it contains are completely contained.

## Parameters

### `Unit`

Type: **long**

Unit to include, if it is partially within the range. The default value is `tomWord`. For a list of the other *Unit* values, see the discussion under [ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange).

### `pDelta`

Type: **long***

The count of characters added to the range. The value can be null.

## Return value

Type: **HRESULT**

The method returns an **HRESULT** value. If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | Unit is not supported. |
| **S_FALSE** | Failure for some other reason. |

## Remarks

For example, if an insertion point is at the beginning, the end, or within a word, **ITextRange::Expand** expands the range to include that word. If the range already includes one word and part of another, **ITextRange::Expand** expands the range to include both words. **ITextRange::Expand** expands the range to include the visible portion of the range's story.

## See also

**Conceptual**

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)