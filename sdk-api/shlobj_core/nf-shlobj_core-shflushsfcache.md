# SHFlushSFCache function

## Description

[**SHFlushSFCache** is available for use in the operating
systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Flushes the special folder cache.

## Remarks

**SHFlushSFCache** is called when the path to a special
folder is changed. This ensures that the updated path stored in the registry is used rather than the cached
value.

For more information on special folders, see the *Special Folders and CSIDLs* section
of [Getting a Folder's ID](https://learn.microsoft.com/windows/desktop/shell/folder-id).