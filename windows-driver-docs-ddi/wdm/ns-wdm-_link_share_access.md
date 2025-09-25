# _LINK_SHARE_ACCESS structure

## Description

The share access structure used by file systems for only link files.

## Members

### `OpenCount`

The number of open requests to the file.

### `Deleters`

File associated with the file object has been
opened for delete access.

### `SharedDelete`

File associated with the file object has been opened for delete sharing access.

## See also

[IoCheckLinkShareAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iochecklinkshareaccess)

[IoSetLinkShareAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetlinkshareaccess)