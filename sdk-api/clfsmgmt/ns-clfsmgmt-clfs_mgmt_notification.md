# CLFS_MGMT_NOTIFICATION structure

## Description

The **CLFS_MGMT_NOTIFICATION** structure
specifies information about the notifications that the client receives.

## Members

### `Notification`

The type of notification to receive. The following values are valid.

| Value | Meaning |
| --- | --- |
| **ClfsMgmtAdvanceTailNotification**<br><br>0 | The notification to advance the log tail. For more information, see [LOG_TAIL_ADVANCE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/clfsmgmtw32/nc-clfsmgmtw32-plog_tail_advance_callback). |
| **ClfsMgmtLogFullHandlerNotification**<br><br>1 | The notification that a call to [HandleLogFull](https://learn.microsoft.com/windows/desktop/api/clfsmgmtw32/nf-clfsmgmtw32-handlelogfull) is complete. For more information, see [LOG_FULL_HANDLER_CALLBACK](https://learn.microsoft.com/windows/desktop/api/clfsmgmtw32/nc-clfsmgmtw32-plog_full_handler_callback). |
| **ClfsMgmtLogUnpinnedNotification**<br><br>2 | The notification that the log is unpinned. For more information, see [LOG_UNPINNED_CALLBACK](https://learn.microsoft.com/windows/desktop/api/clfsmgmtw32/nc-clfsmgmtw32-plog_unpinned_callback). |
| **ClfsMgmtLogWriteNotification**<br><br>3 | The notification that a nonzero number of bytes has been written to the log. For more information, see [RegisterForLogWriteNotification](https://learn.microsoft.com/windows/desktop/api/clfsmgmtw32/nf-clfsmgmtw32-registerforlogwritenotification).<br><br>**Windows Server 2003 R2 and Windows Vista before SP1:** This value is not supported. |

### `Lsn`

 If **Notification** is **ClfsMgmtAdvanceTailNotification**,
**Lsn** specifies the target log sequence number (LSN) the client should advance the log
tail to.

### `LogIsPinned`

If **Notification** is **ClfsMgmtLogUnpinnedNotification**,
**LogIsPinned** indicates that the log is pinned. This member is
**TRUE** if the log is pinned.

## See also

[CLFS Management Structures](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/clfs-management-structures)

[ReadLogNotification](https://learn.microsoft.com/windows/desktop/api/clfsmgmtw32/nf-clfsmgmtw32-readlognotification)