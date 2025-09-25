# DBCOMMANDREUSEENUM enumeration

## Description

> [!Note]
> Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.

The **DBCOMMANDREUSEENUM** enumerated type specifies whether a state from the previous command is retained.

## Constants

### `DBCOMMANDREUSE_NONE:0`

### `DBCOMMANDREUSE_PROPERTIES:0x1`

### `DBCOMMANDREUSE_PARAMETERS:0x2`

## Remarks

The [ICommandTree::SetCommandTree](https://learn.microsoft.com/previous-versions/windows/desktop/api/cmdtree/nf-cmdtree-icommandtree-setcommandtree) method uses a value from this enumerated type as a parameter.