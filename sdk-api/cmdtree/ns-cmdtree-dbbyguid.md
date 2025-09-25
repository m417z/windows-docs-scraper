# DBBYGUID structure

## Description

> [!Note]
> Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.

The **DBBYGUID** structure supplies supplementary information for a node.

## Members

### `pbInfo`

extra node information, provider-specific

### `cbInfo`

size of the data in pbInfo

### `guid`

this node's GUID

## Remarks

The information stored in the **pbInfo** member is provider-specific, and provides for operation extensibility.