# ITextStoreACP2::QueryInsert

## Description

Determines whether the specified start and end character positions are valid. Use this method to adjust an edit to a document before executing the edit. The method must not return values outside the range of the document.

## Parameters

### `acpTestStart` [in]

Starting application character position for inserted text.

### `acpTestEnd` [in]

Ending application character position for the inserted text. This value is equal to *acpTextStart* if the text is inserted at a point instead of replacing selected text.

### `cch` [in]

Length of replacement text.

### `pacpResultStart` [out]

Returns the new starting application character position of the inserted text. If this parameter is **NULL**, then text cannot be inserted at the specified position. This value cannot be outside the document range.

### `pacpResultEnd` [out]

Returns the new ending application character position of the inserted text. If this parameter is **NULL**, then *pacpResultStart* is set to **NULL** and text cannot be inserted at the specified position. This value cannot be outside the document range.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | The *acpTestStart* or *acpTestEnd* parameters are invalid. |

## Remarks

The values of *pacpResultStart* and *pacpResultEnd* depend upon how the application inserts text into the document. If *pacpResultStart* and *pacpResultEnd* are the same as *acpTextStart*, the cursor is at the beginning of the inserted text after insertion. If *pacpResultStart* and *pacpResultEnd* are the same as *acpTextEnd*, the cursor is at the end of the inserted text after insertion. If the difference between *pacpResultStart* and *pacpResultEnd* is equal to the length of the inserted text, the inserted text is highlighted after insertion.

## See also

[ITextStoreACP2](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp2)