# ITextStoryRanges2::Item2

## Description

Gets an [ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2) object for a story, by index, in a stories collection.

## Parameters

### `Index` [in]

Type: **long**

The index of the story range. The default value is 1.

### `ppRange` [out, retval]

Type: **ITextRange2****

The range.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The first story has an index of 1, and the last story has an index equal to the count retrieved by the [ITextStoryRanges::GetCount](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextstoryranges-getcount) method. Negative index values count from the last story to the first; that is, an index of –1 gets the last story in the collection, and an index of –*count* gets the first story.

## See also

[ITextStoryRanges2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextstoryranges2)