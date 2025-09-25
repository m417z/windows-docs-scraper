# DS_REPL_QUEUE_STATISTICSW structure

## Description

The **DS_REPL_QUEUE_STATISTICSW** structure is used to contain replication queue statistics.

Reserved. Obtain this data using the [DS_REPL_QUEUE_STATISTICSW_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms676274(v=vs.85)) structure with the [Lightweight Directory Access Protocol API](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/lightweight-directory-access-protocol-ldap-api) functions to obtain binary data for the **msDS-ReplQueueStatistics** attribute.

## Members

### `ftimeCurrentOpStarted`

Contains a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the date and time that the currently running operation started.

### `cNumPendingOps`

Contains the number of currently pending operations.

### `ftimeOldestSync`

Contains a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the date and time of the oldest synchronization operation.

### `ftimeOldestAdd`

Contains a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the date and time of the oldest add operation.

### `ftimeOldestMod`

Contains a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the date and time of the oldest modification operation.

### `ftimeOldestDel`

Contains a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the date and time of the oldest delete operation.

### `ftimeOldestUpdRefs`

Contains a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the date and time of the oldest reference update operation.

## Remarks

[DS_REPL_QUEUE_STATISTICSW_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms676274(v=vs.85)) is an alias for this structure.

## See also

[DS_REPL_QUEUE_STATISTICSW_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms676274(v=vs.85))

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)