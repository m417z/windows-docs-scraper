# DBSETFUNC structure

## Description

> [!Note]
> Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.

The **DBSETFUNC** structure specifies the aggregation function to use in a select operation.

## Members

### `dwSetQuantifier`

which aggregation method to use

## Remarks

For valid values of the **dwSetQuantifier** member, see [Aggregate Function Constants](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/aggregate-function-constants).