# ResourcePolicy enumeration

## Description

Defines how folders are deleted when one of the disk resource limits is exceeded.

## Constants

### `plaDeleteLargest:0`

Delete folders from largest to smallest.

### `plaDeleteOldest:1`

Delete folders from oldest to newest.

## See also

[IDataManager::ResourcePolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatamanager-get_resourcepolicy)