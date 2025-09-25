# DBLIKE structure

## Description

> [!Note]
> Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.

The **DBLIKE** structure represents specific information required by the DBOP_like operator.

## Members

### `lWeight`

weight on the dbop_like node

### `guidDialect`

system to use for "likeness". E.g. Reg. Ex.

## Remarks

For more information about the DBOP_like operator, see [Operators for Scalars](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/operators-for-scalars).