# IPhraseSink::PutPhrase

## Description

Puts a query-time phrase in the [IPhraseSink](https://learn.microsoft.com/windows/desktop/api/indexsrv/nn-indexsrv-iphrasesink) object.

## Parameters

### `pwcPhrase` [in]

A pointer to a buffer that contains a phrase.

### `cwcPhrase` [in]

The number of characters in *pwcPhrase*. There is no limit on the size of a query-time phrase.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was completed successfully. |
| **PSINK_E_QUERY_ONLY** | [PutPhrase](https://learn.microsoft.com/windows/desktop/api/indexsrv/nf-indexsrv-iphrasesink-putphrase) was called at index time instead of query time. |

## Remarks

**PutPhrase** is called by the [IWordBreaker::BreakText](https://learn.microsoft.com/windows/desktop/api/indexsrv/nf-indexsrv-iwordbreaker-breaktext) method of the [IWordBreaker](https://learn.microsoft.com/windows/desktop/api/indexsrv/nn-indexsrv-iwordbreaker) implementation. Phrases that the [IPhraseSink](https://learn.microsoft.com/windows/desktop/api/indexsrv/nn-indexsrv-iphrasesink) object handles are used by Windows Search to expand the original query text.

## See also

[IPhraseSink](https://learn.microsoft.com/windows/desktop/api/indexsrv/nn-indexsrv-iphrasesink)