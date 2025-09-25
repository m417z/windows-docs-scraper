# DBTEXT structure

## Description

> [!Note]
> Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.

The **DBTEXT** structure is used by the DBOP_text_command node. It stores the dialect to use to interpret the string stored in the **pwszText** member. The error locator is filled in by the provider, that is, the first offending token is indicated as the index into the text array, together with its length.

## Members

### `pwszText`

### `ulErrorLocator`

set by validation routines

### `ulTokenLength`

length of offending token

### `guidDialect`

lGUID of the language and dialect

## Remarks

For additional information about the *guidDialect* parameter, see the description of DBOP_text_command in [Special Operators](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/special-operators).