# ID2D1Ink::RemoveSegmentsAtEnd

## Description

Removes the given number of segments from the end of this ink object.

## Parameters

### `segmentsCount`

Type: **UINT32**

The number of segments to be removed from the end of this ink object. Note that segmentsCount must be less or equal to the number of segments in the ink object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ID2D1Ink](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1ink)