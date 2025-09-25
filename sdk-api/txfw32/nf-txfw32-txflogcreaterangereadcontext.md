## Description

[Microsoft strongly recommends developers utilize alternative means to achieve your
application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily
available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more
information, and alternatives to TxF, please see
[Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).]

Creates a context that is required to read any replication records. In order to recover resources, the context must later be closed by calling TxfLogDestroyReadContext. Since the resources are allocated by a user-mode process, if that routine is not called, the resources will be recovered automatically when the process hosting the DLL terminates.

## Parameters

### `LogPath`

Location of the RM's CLFS BLF.

### `BeginningLsn`

Start of LSN range to search. (inclusive)

### `EndingLsn`

End of LSN range to search. (inclusive)

### `BeginningVirtualClock`

Start of the virtual clock.

### `EndingVirtualClock`

End of the virtual clock.

### `RecordTypeMask`

A mask value indicating the type of records.

### `TxfLogContext`

The returned context object.

## Return value

Returns S_OK on success.

## Remarks

## See also