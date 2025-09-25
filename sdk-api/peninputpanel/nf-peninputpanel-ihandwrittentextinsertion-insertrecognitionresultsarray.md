# IHandwrittenTextInsertion::InsertRecognitionResultsArray

## Description

Insert recognition results array.

## Parameters

### `psaAlternates` [in]

A two-dimensional array of strings, where each entry in the first array is a list of alternates for a single word. The first entry in the sub arrays of alternates is the text to insert (the top alternate).

### `locale` [in]

A specific culture for the input language of the recognizer used to produce alternates.

### `fAlternateContainsAutoSpacingInformation` [in]

Specifies whether the recognized text is generated with auto-spacing enabled. When **FALSE**, a space at the start/end of the lattice will always be inserted. When **TRUE**, a space exists, and is added where necessary. If no space exists, a space is consumed.

## Return value

This method can return one of these values.

## Remarks

This element is declared in Peninputpanel.h.

## See also

[IHandWrittenTextInsertion](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-ihandwrittentextinsertion)