# TxfLogCreateFileReadContext function

## Description

[Microsoft strongly recommends developers utilize alternative means to achieve your
application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily
available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more
information, and alternatives to TxF, please see
[Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).]

Creates a context to be used to read replication records.

## Parameters

### `LogPath` [in]

The path that identifies the Resource Manager's .blf file.

### `BeginningLsn` [in]

The first LSN in the range to be read.

### `EndingLsn` [in]

The last LSN in the range to be read.

### `TxfFileId` [in]

The TxF identifier to search for in the LSN range. For more information, see [TXF_ID](https://learn.microsoft.com/windows/desktop/api/txfw32/ns-txfw32-txf_id).

### `TxfLogContext` [out]

A pointer to the context created.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[TXF_ID](https://learn.microsoft.com/windows/desktop/api/txfw32/ns-txfw32-txf_id)

[TxfLogDestroyReadContext](https://learn.microsoft.com/windows/desktop/api/txfw32/nf-txfw32-txflogdestroyreadcontext)