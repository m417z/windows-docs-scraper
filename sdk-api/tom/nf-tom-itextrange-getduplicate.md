# ITextRange::GetDuplicate

## Description

Gets a duplicate of this range object.

## Parameters

### `ppRange`

Type: **[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)****

The duplicate of the range.

## Return value

Type: **HRESULT**

The method returns an **HRESULT** value. If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | ppRange is null. |
| **E_FAIL** | Failure for some other reason. |

## Remarks

To create an insertion point in order to traverse a range, first duplicate the range and then collapse the duplicate at its start character position. Note, a range is characterized by start and end character positions, and the story it belongs to.

Even if the range is actually an [ITextSelection](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextselection), the duplicate returned is an [ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange). For an example, see the [ITextRange::FindText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-findtext) method.

## See also

**Conceptual**

[FindText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-findtext)

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)