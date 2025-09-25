# CI_STATE structure

## Description

> [!Note]
> Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.

Represents the current state of an Indexing Service catalog.

## Members

### `cbStruct`

The size of this structure, in bytes.

### `cWordList`

The number of current word lists.

### `cPersistentIndex`

The number of persistent indexes.

### `cQueries`

The number of actively running queries.

### `cDocuments`

The number of documents waiting to be filtered.

### `cFreshTest`

The number of unique documents in word lists and shadow indexes.

### `dwMergeProgress`

The completion percentage of current merge, if one is running.

### `eState`

The state of content indexing. This can be one or more of the [CI_STATE_*](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/ci-state-constants) constants.

### `cFilteredDocuments`

The number of documents filtered since content indexing began.

### `cTotalDocuments`

The total number of documents in the system.

### `cPendingScans`

The number of pending scans, possibly one for each scope in the directories list. The value is usually zero, except immediately after content indexing has been started or after a notification queue overflows.

### `dwIndexSize`

The size, in megabytes, of the index (excluding the property cache).

### `cUniqueKeys`

The number of unique keys in the master index.

### `cSecQDocuments`

The number of documents in the secondary queue, which contains documents that failed filtering due to a sharing violation.

### `dwPropCacheSize`

The size of the property cache, in megabytes.

## Remarks

When using this structure, all members are output values. The **cbStruct** member is both an input value and an output value.

## See also

[CIState]()

[CI_STATE_* Constants](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/ci-state-constants)