# ISimilarityTraitsMappedView::GetView

## Description

Returns the beginning and ending addresses for the mapped view of a similarity traits table file.

## Parameters

### `mappedPageBegin` [out]

Pointer to a location that receives the start of the data that is mapped for this view.

### `mappedPageEnd` [out]

Pointer to a location that receives the end of the data that is mapped for this view, plus one.

## Remarks

If there is no mapped view, then `*mappedPageBegin` must be set to zero. Otherwise, `*mappedPageBegin` is set to a valid pointer, and `*mappedPageBegin - *mappedPageEnd` equals the size, in bytes, of the mapped area.

## See also

[ISimilarityTraitsMappedView](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-isimilaritytraitsmappedview)