# TEXT_SOURCE structure

## Description

Contains information about text that the word breaker will process.

## Members

### `pfnFillTextBuffer`

Type: **PFNFILLTEXTBUFFER**

Pointer to a function, **PFNFILLTEXTBUFFER** that refills the **awcBuffer** with text from the source document.

### `awcBuffer`

Type: **WCHAR***

Pointer to a buffer that contains text from the source document for the word breaker to parse.

### `iEnd`

Type: **ULONG**

Position of the last character in **awcBuffer**.

### `iCur`

Type: **ULONG**

Position of the first character in **awcBuffer**.

## Remarks

Windows Search populates the members of this structure when the word breaker is invoked and initialized. [IWordBreaker::BreakText](https://learn.microsoft.com/windows/desktop/api/indexsrv/nf-indexsrv-iwordbreaker-breaktext) gets a pointer to a **TEXT_SOURCE** structure and calls PFNFILLTEXTBUFFER, the function pointed to by the **pfnFillTextBuffer** member, to refill **awcBuffer** until all text from the source is processed. The **PFNFILLTEXTBUFFER** function returns an **HRESULT** that includes both filtering and word-breaking return values.

The filtering return values are the following:

* FILTER_E_NO_MORE_VALUES
* FILTER_E_NO_TEXT
* FILTER_E_NO_VALUES
* FILTER_E_NO_MORE_TEXT
* FILTER_E_END_OF_CHUNKS

For more information about these return values, see [Filter-Interface Values](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/filter-interface-values).

The word-breaking return value is WBREAK_E_END_OF_TEXT. For more information about word-breaking return values, see [Word-Breaking Values](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/word-breaking-values).

## See also

[IWordBreaker::BreakText](https://learn.microsoft.com/windows/desktop/api/indexsrv/nf-indexsrv-iwordbreaker-breaktext)