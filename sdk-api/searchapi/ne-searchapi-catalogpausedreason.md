# CatalogPausedReason enumeration

## Description

Used by [ISearchCatalogManager::GetCatalogStatus](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchcatalogmanager-getcatalogstatus) to determine the reason the catalog is paused.

## Constants

### `CATALOG_PAUSED_REASON_NONE:0`

Not paused.

### `CATALOG_PAUSED_REASON_HIGH_IO:1`

Paused due to high I/O.

### `CATALOG_PAUSED_REASON_HIGH_CPU:2`

Paused due to high CPU usage.

### `CATALOG_PAUSED_REASON_HIGH_NTF_RATE:3`

Paused due to high NTF rate.

### `CATALOG_PAUSED_REASON_LOW_BATTERY:4`

Paused due to low battery.

### `CATALOG_PAUSED_REASON_LOW_MEMORY:5`

Paused due to low memory.

### `CATALOG_PAUSED_REASON_LOW_DISK:6`

Paused due to low disk space.

### `CATALOG_PAUSED_REASON_DELAYED_RECOVERY:7`

Paused due to need for delayed recovery.

### `CATALOG_PAUSED_REASON_USER_ACTIVE:8`

Paused due to user activity.

### `CATALOG_PAUSED_REASON_EXTERNAL:9`

Paused by external request.

### `CATALOG_PAUSED_REASON_UPGRADING:10`

Paused by upgrading.