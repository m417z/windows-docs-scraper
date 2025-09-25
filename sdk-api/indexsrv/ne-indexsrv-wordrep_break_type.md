# WORDREP_BREAK_TYPE enumeration

## Description

> [!Note]
> Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.

Describes the type of break that separates the current word from the previous word.

## Constants

### `WORDREP_BREAK_EOW:0`

A word break is placed between this word and the previous word that was placed in the **WordSink**. This break is the default used by the [PutWord](https://learn.microsoft.com/windows/desktop/search/iwordsink-putword) method.

### `WORDREP_BREAK_EOS:1`

A sentence break is placed between this word and the previous word.

### `WORDREP_BREAK_EOP:2`

A paragraph break is placed between this word and the previous word.

### `WORDREP_BREAK_EOC:3`

A chapter break is placed between this word and the previous word.

## See also

[IWordSink::PutAltWord](https://learn.microsoft.com/windows/desktop/search/iwordsink-putaltword)

[IWordSink::PutWord](https://learn.microsoft.com/windows/desktop/search/iwordsink-putword)