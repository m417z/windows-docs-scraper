# IQueryParserManager::InitializeOptions

## Description

Sets the flags for Natural Query Syntax (NQS) and automatic wildcard characters for the specified query parser. If the query parser was created for the `SystemIndex` catalog, this method also sets up standard condition generators to be used later by the query parser object for recognizing named entities.

## Parameters

### `fUnderstandNQS` [in]

Type: **BOOL**

**BOOL** flag that controls whether NQS is supported by this instance of the query parser.

### `fAutoWildCard` [in]

Type: **BOOL**

**BOOL** flag that controls whether a wildcard character (*) is to be assumed after each word in the query (unless followed by punctuation other than a parenthesis).

### `pQueryParser` [in]

Type: **[IQueryParser](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iqueryparser)***

Pointer to the query parser object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.