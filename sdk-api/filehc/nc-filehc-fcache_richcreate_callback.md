# FCACHE_RICHCREATE_CALLBACK callback function

## Description

A callback function that is used to create items in the cache. It is called by [CacheRichCreateFile](https://learn.microsoft.com/windows/desktop/api/filehc/nf-filehc-cacherichcreatefile).

## Parameters

### `lpstrName` [in]

The name of the file.

### `lpvData` [in]

User-provided data to [CacheRichCreateFile](https://learn.microsoft.com/windows/desktop/api/filehc/nf-filehc-cacherichcreatefile).

### `cbFileSize` [out]

The size of the low **DWORD**.

### `cbFileSizeHigh` [out]

The size of the high **DWORD**.

### `pfDidWeScanIt` [out]

Set to **TRUE** if the file has been scanned; otherwise, it is set to **FALSE**.

### `pfIsStuffed` [out]

Set to **TRUE** if the file is dot stuffed; otherwise, it is set to **FALSE**.

### `pfStoredWithDots` [out]

If set to **TRUE**, this parameter indicates that any dots that appear at the beginning of a line are stored with an extra dot as required in NNTP, SMTP, and POP3 protocols. If this is **FALSE**, the message is stored without dot stuffing.

### `pfStoredWithTerminatingDot` [out]

If set to **TRUE**, the file has been stored with a terminating dot; otherwise, it is **FALSE**.

## Return value

Returns a handle to the file that was created in the cache.

## See also

[CacheRichCreateFile](https://learn.microsoft.com/windows/desktop/api/filehc/nf-filehc-cacherichcreatefile)