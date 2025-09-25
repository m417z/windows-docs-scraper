# SEARCH_INDEXING_PHASE enumeration

## Description

Specifies the status of the current search indexing phase.

## Constants

### `SEARCH_INDEXING_PHASE_GATHERER:0`

Sent in the event that an error occurs while a notification is in the gatherer. For instance, if the notification fails the exclusion-rule tests, a status update will be sent with the error.

### `SEARCH_INDEXING_PHASE_QUERYABLE:1`

The document will be returned in queries. It is currently only in the volatile indexes.

### `SEARCH_INDEXING_PHASE_PERSISTED:2`

The document has moved from the volatile index to the persisted-file-based index.