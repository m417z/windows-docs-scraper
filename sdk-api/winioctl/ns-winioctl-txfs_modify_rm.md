# TXFS_MODIFY_RM structure

## Description

[Microsoft strongly recommends developers utilize alternative means to achieve your
application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily
available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more
information, and alternatives to TxF, please see
[Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).]

Contains the information required when modifying log parameters and logging mode for a secondary
resource manager.

## Members

### `Flags`

The log parameters to be set.

This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **TXFS_RM_FLAG_LOGGING_MODE**<br><br>0x00000001 | If this flag is set, the **LoggingMode** member of this structure is being used. If the flag is not set, the **LoggingMode** member is ignored. |
| **TXFS_RM_FLAG_RENAME_RM**<br><br>0x00000002 | If this flag is set, the RM is instructed to rename itself (creating a new **GUID**). |
| **TXFS_RM_FLAG_LOG_CONTAINER_COUNT_MAX**<br><br>0x00000004 | If this flag is set, the **LogContainerCountMax** member is being used. If the flag is not set, the **LogContainerCountMax** member is ignored. This flag is mutually exclusive with **TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MIN**. |
| **TXFS_RM_FLAG_LOG_CONTAINER_COUNT_MIN**<br><br>0x00000008 | If this flag is set, the **LogContainerCountMin** member is being used. If the flag is not set, the **LogContainerCountMin** member is ignored. This flag is mutually exclusive with **TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MAX**. |
| **TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_NUM_CONTAINERS**<br><br>0x00000010 | If this flag is set, the **LogGrowthIncrement** member is being used. If the flag is not set, the **LogGrowthIncrement** member is ignored. This flag indicates that the log should grow by the number of containers specified in the **LogGrowthIncrement** member. This flag is mutually exclusive with **TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_PERCENT**. |
| **TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_PERCENT**<br><br>0x00000020 | If this flag is set, the **LogGrowthIncrement** member is being used. If the flag is not set, the **LogGrowthIncrement** member is ignored. This flag indicates that the log should grow by the percentage of the log size specified in the **LogGrowthIncrement** member. This flag is mutually exclusive with **TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_NUM_CONTAINERS**. |
| **TXFS_RM_FLAG_LOG_AUTO_SHRINK_PERCENTAGE**<br><br>0x00000040 | If this flag is set, the **LogAutoShrinkPercentage** member is being used. If the flag is not set, the **LogAutoShrinkPercentage** is ignored. |
| **TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MAX**<br><br>0x00000080 | If this flag is set, the RM is instructed to allow its log to grow without bounds. This flag is mutually exclusive with **TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MIN**. |
| **TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MIN**<br><br>0x00000100 | If this flag is set, the RM is instructed to allow its log to shrink the log to only two containers. This flag is mutually exclusive with **TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MAX**. |
| **TXFS_RM_FLAG_GROW_LOG**<br><br>0x00000400 | If this flag is set, the log is instructed to immediately increase its size to the size specified in **LogContainerCount**. If the flag is not set, the **LogContainerCount** is ignored. |
| **TXFS_RM_FLAG_SHRINK_LOG**<br><br>0x00000800 | If this flag is set, the log is instructed to immediately decrease its size to the size specified in **LogContainerCount**. If this flag and **TXFS_RM_FLAG_ENFORCE_MINIMUM_SIZE** are set, the log is instructed to shrink to its minimum allowable size, and **LogContainerCount** is ignored. |
| **TXFS_RM_FLAG_ENFORCE_MINIMUM_SIZE**<br><br>0x00001000 | If this flag and **TXFS_RM_FLAG_SHRINK_LOG** are set, the log is instructed to shrink to its minimum allowable size, and **LogContainerCount** is ignored. If this flag is set, the **TXFS_RM_FLAG_SHRINK_LOG** must be set. |
| **TXFS_RM_FLAG_PRESERVE_CHANGES**<br><br>0x00002000 | If this flag is set, the log is instructed to preserve the changes on disk. If this flag is not set, any changes made are temporary (that is, until the RM is shut down and restarted). |
| **TXFS_RM_FLAG_RESET_RM_AT_NEXT_START**<br><br>0x00004000 | This flag is only valid for default RMs, not secondary RMs. If this flag is set, the RM is instructed to reset itself the next time it is started. The log and the associated metadata are deleted. |
| **TXFS_RM_FLAG_DO_NOT_RESET_RM_AT_NEXT_START**<br><br>0x00008000 | This flag is only valid for default RMs, not secondary RMs. If this flag is set, a previous call to [FSCTL_TXFS_MODIFY_RM](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_txfs_modify_rm) is canceled with the **TXFS_RM_FLAG_RESET_RM_AT_NEXT_START** flag set. |
| **TXFS_RM_FLAG_PREFER_CONSISTENCY**<br><br>0x00010000 | Indicates that the RM is to prefer transaction [consistency](https://learn.microsoft.com/windows/win32/fileio/glossary) over system [availability](https://learn.microsoft.com/windows/win32/fileio/glossary). This flag is mutually exclusive with **TXFS_RM_FLAG_PREFER_AVAILABILITY** and is not supported by the default RM on the system volume. |
| **TXFS_RM_FLAG_PREFER_AVAILABILITY**<br><br>0x00020000 | Indicates that the RM is to prefer system [availability](https://learn.microsoft.com/windows/win32/fileio/glossary) over transaction [consistency](https://learn.microsoft.com/windows/win32/fileio/glossary). This flag is mutually exclusive with **TXFS_RM_FLAG_PREFER_CONSISTENCY** and is forced by the default RM on the system volume. |

### `LogContainerCountMax`

The maximum size of the log, in containers.

### `LogContainerCountMin`

The minimum size of the log, in containers.

### `LogContainerCount`

The actual size of the log, in containers.

### `LogGrowthIncrement`

The number of containers or percentage of space that should be added to the log.

### `LogAutoShrinkPercentage`

The percentage of log space to keep free. This member is used when the
**TXFS_RM_FLAG_LOG_AUTO_SHRINK_PERCENTAGE** flag is used, and instructs the log to
automatically shrink itself, so no more than **LogAutoShrinkPercentage** of the log is
free at any given time.

### `Reserved`

Reserved.

### `LoggingMode`

The current logging mode.

| Value | Meaning |
| --- | --- |
| **TXFS_LOGGING_MODE_SIMPLE**<br><br>1 | Simple logging is used. |
| **TXFS_LOGGING_MODE_FULL**<br><br>2 | Full logging is used |

## See also

[FSCTL_TXFS_MODIFY_RM](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_txfs_modify_rm)