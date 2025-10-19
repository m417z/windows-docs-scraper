# TXFS_QUERY_RM_INFORMATION structure

## Description

[Microsoft strongly recommends developers utilize alternative means to achieve your
application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily
available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more
information, and alternatives to TxF, please see
[Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).]

Contains information about the resource manager (RM).

## Members

### `BytesRequired`

If [FSCTL_TXFS_QUERY_RM_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_txfs_query_rm_information)
returns **ERROR_BUFFER_TOO_SMALL**, this member specifies the minimum number of bytes
needed to return the information requested, including the **NULL** terminating
character.

### `TailLsn`

The oldest log sequence number (LSN) currently used by the RM.

### `CurrentLsn`

The LSN most recently used by the RM in its log.

### `ArchiveTailLsn`

The LSN of the archive tail of the log.

### `LogContainerSize`

The actual size of a log container, in bytes.

### `HighestVirtualClock`

The highest timestamp associated with a log record.

### `LogContainerCount`

The number of log containers.

### `LogContainerCountMax`

The maximum number of log containers.

### `LogContainerCountMin`

The minimum number of containers allowed in the log.

### `LogGrowthIncrement`

The amount the log will grow by, which is either a number of containers or percentage of the log size; the
growth type used is specified by the flags set in **Flags** member.

### `LogAutoShrinkPercentage`

If the auto-shrink policy is active, this member specifies the maximum allowable amount of free space in
the log. If this member is zero, the auto-shrink policy is not active.

### `Flags`

This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **TXFS_RM_FLAG_LOG_CONTAINER_COUNT_MIN**<br><br>0x00000008 | If the flag is set, the RM's log is allowed to shrink as far as possible. This flag is mutually exclusive with **TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MAX**. |
| **TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_NUM_CONTAINERS**<br><br>0x00000010 | Indicates the type of value in **LogGrowthIncrement**. If this flag is set, **LogGrowthIncrement** is a number of containers. This flag is mutually exclusive with **TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_PERCENT**. |
| **TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_PERCENT**<br><br>0x00000020 | Indicates the type of value in **LogGrowthIncrement**. If this flag is set, **LogGrowthIncrement** is a percentage. This flag is mutually exclusive with **TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_NUM_CONTAINERS**. |
| **TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MAX**<br><br>0x00000080 | Indicates that the RM's log can grow without bounds. This flag is mutually exclusive with **TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MIN**. |
| **TXFS_RM_FLAG_RESET_RM_AT_NEXT_START**<br><br>0x00004000 | Indicates the current state of the RM reset flag. If this is set, the RM will reset itself the next time it is started. This flag is only valid for default RMs, not secondary RMs. This flag is mutually exclusive with **TXFS_RM_FLAG_DO_NOT_RESET_RM_AT_NEXT_START**. |
| **TXFS_RM_FLAG_DO_NOT_RESET_RM_AT_NEXT_START**<br><br>0x00008000 | Indicates the current state of the RM reset flag. If this is set, the RM will not reset itself the next time it is started. This flag is only valid for default RMs, not secondary RMs. This flag is mutually exclusive with **TXFS_RM_FLAG_RESET_RM_AT_NEXT_START**. |
| **TXFS_RM_FLAG_PREFER_CONSISTENCY**<br><br>0x00010000 | Indicates that the RM is to prefer transaction [consistency](https://learn.microsoft.com/windows/win32/fileio/glossary) over system [availability](https://learn.microsoft.com/windows/win32/fileio/glossary). This flag is mutually exclusive with **TXFS_RM_FLAG_PREFER_AVAILABILITY** and is not supported by the default RM on the system volume. |
| **TXFS_RM_FLAG_PREFER_AVAILABILITY**<br><br>0x00020000 | Indicates that the RM is to prefer system [availability](https://learn.microsoft.com/windows/win32/fileio/glossary) over transaction [consistency](https://learn.microsoft.com/windows/win32/fileio/glossary). This flag is mutually exclusive with **TXFS_RM_FLAG_PREFER_CONSISTENCY** and is forced by the default RM on the system volume. |

### `LoggingMode`

The current logging mode.

| Value | Meaning |
| --- | --- |
| **TXFS_LOGGING_MODE_SIMPLE**<br><br>1 | Simple logging is used. |
| **TXFS_LOGGING_MODE_FULL**<br><br>2 | Full logging is used |

### `Reserved`

Reserved.

### `RmState`

The state of the RM. Valid values are as follows.

| Value | Meaning |
| --- | --- |
| **TXFS_RM_STATE_NOT_STARTED**<br><br>0 | The RM is not yet started. |
| **TXFS_RM_STATE_STARTING**<br><br>1 | The RM is starting. |
| **TXFS_RM_STATE_ACTIVE**<br><br>2 | The RM is active and ready to accept transactions. |
| **TXFS_RM_STATE_SHUTTING_DOWN**<br><br>3 | The RM is shutting down. |

### `LogCapacity`

The total capacity of the log, in bytes.

### `LogFree`

The number of bytes free in the log.

### `TopsSize`

The size of the $Tops file, in bytes.

### `TopsUsed`

The amount of the $Tops file that is in use, in bytes.

### `TransactionCount`

The number of active transactions, at the time the query was issued.

### `OnePCCount`

The number of single-phase commit operations that have occurred on this RM.

### `TwoPCCount`

The number of two-phase commit operations that have occurred on this RM.

### `NumberLogFileFull`

The number of times this RM's log has become full.

### `OldestTransactionAge`

The length of the oldest active transaction, in milliseconds.

### `RMName`

The **GUID** that indicates the name of this RM.

### `TmLogPathOffset`

The offset from the beginning of this structure to a **NULL**-terminated Unicode
string that contains the path to the TM's log.

## See also

[FSCTL_TXFS_QUERY_RM_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_txfs_query_rm_information)

[TxF Structures](https://learn.microsoft.com/windows/desktop/FileIO/transactional-ntfs-structures)