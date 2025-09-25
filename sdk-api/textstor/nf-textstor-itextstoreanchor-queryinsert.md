# ITextStoreAnchor::QueryInsert

## Description

The **ITextStoreAnchor::QueryInsert** method determines whether the specified start and end anchors are valid. Use this method to adjust an edit to a document before you execute the edit. The method must not return values outside the range of the document.

## Parameters

### `paTestStart` [in]

Receives a pointer to a start anchor for the inserted text.

### `paTestEnd` [in]

Receives a pointer to an end anchor for the inserted text. This is the same as *paTestStart* if the text is inserted at a point instead of replacing selected text.

### `cch` [in]

Length of replacement text.

### `ppaResultStart` [out]

Pointer to the new anchor object at the starting location for the inserted text. If the value of this parameter is **NULL**, then text cannot be inserted at the specified position. This anchor cannot be outside the document.

### `ppaResultEnd` [out]

Pointer to the new anchor object at the ending location for the inserted text. If the value of this parameter is **NULL**, then text cannot be inserted at the specified position. This anchor cannot be outside the document.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | The *paTestStart* or *paTestEnd* parameters are invalid. |
| **E_OUTOFMEMORY** | The attempt to instantiate the *ppaResultStart* and/or *ppaResultEnd* anchors failed. |

## Remarks

The values of *ppaResultStart* and *ppaResultEnd* depend upon how the application inserts text into the document. If *ppaResultStart* and *ppaResultEnd* are the same as *paTestStart*, the cursor is at the beginning of the inserted text after insertion. If *ppaResultStart* and *ppaResultEnd* are the same as *paTextEnd*, the cursor is at the end of the inserted text after insertion.