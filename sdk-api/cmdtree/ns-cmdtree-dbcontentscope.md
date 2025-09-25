# DBCONTENTSCOPE structure

## Description

> [!Note]
> Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.

The **DBCONTENTSCOPE** structure is used to pass a scope argument in a command tree.

## Members

### `dwFlags`

flags from DBPROP_CI_SCOPE_FLAGS

### `rgpwszTagName`

reserved for future use.

### `pwszElementValue`

DBPROP_CI_INCLUDE_SCOPES property for the path