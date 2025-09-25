# ITextRange::InStory

## Description

Determines whether this range's story is the same as a specified range's story.

## Parameters

### `pRange`

Type: **[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)***

The [ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange) object whose story is compared to this range's story.

### `pValue`

Type: **long***

The comparison result. The pointer can be null. The *pB* parameter receives **tomTrue** if this range's story is the same as that of the *pRange*; otherwise it receives **tomFalse**.

## Return value

Type: **HRESULT**

The method returns an **HRESULT** value. If the two stories are the same, the method returns **S_OK**. Otherwise, it returns S_FALSE.

## See also

**Conceptual**

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)