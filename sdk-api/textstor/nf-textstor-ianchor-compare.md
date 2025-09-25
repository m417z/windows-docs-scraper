# IAnchor::Compare

## Description

The **IAnchor::Compare** method compares the relative position of two anchors within a text stream.

## Parameters

### `paWith` [in]

An anchor object to compare to the primary anchor. Used to determine the relative position of the two anchors.

### `plResult` [out]

Result of the comparison of the positions of the two anchors.

| Value | Meaning |
| --- | --- |
| **-1** | The primary anchor is positioned earlier in the text stream than *paWith.* |
| **0** | The primary anchor is positioned at the same location as *paWith.* |
| **+1** | The primary anchor is positioned later in the text stream than *paWith.* |

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | *paWith* is invalid. |
| **E_INVALIDARG** | *plResult* is invalid. |

## Remarks

The value 0 is returned for **plResult* only when the two anchors are in a single region. Anchor positions include the spaces between regions. If you only need to determine if the two anchors are positioned at the same location, [IAnchor::IsEqual](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-ianchor-isequal) is more efficient.

## See also

[Anchors](https://learn.microsoft.com/windows/desktop/TSF/ranges)

[IAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-ianchor)

[IAnchor::IsEqual](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-ianchor-isequal)

[Regions](https://learn.microsoft.com/windows/desktop/TSF/ranges)