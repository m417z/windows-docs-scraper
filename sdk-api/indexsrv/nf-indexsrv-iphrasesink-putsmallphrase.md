# IPhraseSink::PutSmallPhrase

## Description

Puts a small query-time phrase in the [IPhraseSink](https://learn.microsoft.com/windows/desktop/api/indexsrv/nn-indexsrv-iphrasesink) object for WordBreaker.

## Parameters

### `pwcNoun` [in]

A pointer to a buffer that contains a word being modified.

### `cwcNoun` [in]

The number of characters in *pwcNoun*. There is no limit on the size of a query-time phrase.

### `pwcModifier` [in]

A pointer to the word modifying *pwcNoun*.

### `cwcModifier` [in]

The number of characters in *pwcModifier*. There is no limit on the size of a query-time phrase.

### `ulAttachmentType` [in]

A wordbreaker-specific value which a
wordbreaker can use to store additional information about the method of composition.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**PutSmallPhrase** is called by the [IWordBreaker::BreakText](https://learn.microsoft.com/windows/desktop/api/indexsrv/nf-indexsrv-iwordbreaker-breaktext) method of the [IWordBreaker](https://learn.microsoft.com/windows/desktop/api/indexsrv/nn-indexsrv-iwordbreaker) implementation. Phrases that the [IPhraseSink](https://learn.microsoft.com/windows/desktop/api/indexsrv/nn-indexsrv-iphrasesink) object handles are used by Windows Search to expand the original query text.

## See also

[IPhraseSink](https://learn.microsoft.com/windows/desktop/api/indexsrv/nn-indexsrv-iphrasesink)