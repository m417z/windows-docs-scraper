# CatalogStatus enumeration

## Description

Used by [ISearchCatalogManager::GetCatalogStatus](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchcatalogmanager-getcatalogstatus) to determine the current state of the catalog.

## Constants

### `CATALOG_STATUS_IDLE:0`

Index is current; no indexing needed. Queries can be processed.

### `CATALOG_STATUS_PAUSED:1`

Indexer is paused. This can happen either because the user paused indexing or the indexer back-off criteria have been met. Queries can be processed.

### `CATALOG_STATUS_RECOVERING:2`

Index is recovering; queries and indexing are processed while in this state.

### `CATALOG_STATUS_FULL_CRAWL:3`

Indexer is currently executing a full crawl and will index everything it is configured to index. Queries can be processed while indexing.

### `CATALOG_STATUS_INCREMENTAL_CRAWL:4`

Indexer is preforming a crawl to see if anything has changed or requires indexing. Queries can be processed while indexing.

### `CATALOG_STATUS_PROCESSING_NOTIFICATIONS:5`

Indexer is processing the notification queue. This is done before resuming any crawl.

### `CATALOG_STATUS_SHUTTING_DOWN:6`

Indexer is shutting down and is not indexing. Indexer can't be queried.