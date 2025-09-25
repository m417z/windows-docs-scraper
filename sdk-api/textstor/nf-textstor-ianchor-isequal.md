# IAnchor::IsEqual

## Description

The **IAnchor::IsEqual** method evaluates two anchors within a text stream and returns a Boolean value that specifies the equality or inequality of the anchor positions.

## Parameters

### `paWith` [in]

Specifies an anchor to compare to the primary anchor. Used to determine the equality of the two anchor positions.

### `pfEqual` [out]

A Boolean value that specifies whether the two anchors are positioned at the same location. If set to **TRUE**, the two anchors occupy the same location. If set to **FALSE**, the two anchors do not occupy the same location.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *pfEqual* is invalid. |

## Remarks

Anchors are always positioned between characters or regions. When two anchors are between the same characters, being at the same offset within the text stream, and within the same region, **IAnchor::IsEqual** returns **TRUE**. Otherwise it returns **FALSE**.

[IAnchor::Compare](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-ianchor-compare) incorporates the same functionality as **IAnchor::IsEqual**. However, because **IAnchor::IsEqual** is more specific, it can have a more efficient implementation on the server.

## See also

[Anchors](https://learn.microsoft.com/windows/desktop/TSF/ranges)

[IAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-ianchor)

[IAnchor::Compare](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-ianchor-compare)