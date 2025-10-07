# MPNOTIFY enumeration

Possible callback notifications.

## Constants

**MPNOTIFY\_NONE**

**MPNOTIFY\_CALL\_START**

Notification call start.

**MPNOTIFY\_CALL\_COMPLETE**

Notification call completed.

**MPNOTIFY\_INTERNAL\_FAILURE**

Generic internal failure.

**MPNOTIFY\_STATUS\_SERVICE\_START**

Malware protection service has started.

**MPNOTIFY\_STATUS\_SERVICE\_RUNNING**

Malware protection service is running.

**MPNOTIFY\_STATUS\_SERVICE\_STOP**

Malware protection service has stopped.

**MPNOTIFY\_STATUS\_COMPONENT**

Particular component enable/disable status.

**MPNOTIFY\_STATUS\_CHANGE**

Overall product status has changed. Call [**MpManagerStatusQueryEx**](https://learn.microsoft.com/windows/win32/lwef/mpmanagerstatusqueryex) to obtain the current status.

**MPNOTIFY\_STATUS\_COMPONENT\_CONFIGURATION**

A particular component has changed configuration.

**MPNOTIFY\_STATUS\_EXPIRATION\_CHANGE**

Product expiration status has changed.

**MPNOTIFY\_STATUS\_OFFLINE\_SCAN\_CHANGE**

Offline scan required state changed.

**MPNOTIFY\_SCAN\_START**

Scan started.

**MPNOTIFY\_SCAN\_PAUSED**

Scan paused.

**MPNOTIFY\_SCAN\_RESUMED**

scan resumed.

**MPNOTIFY\_SCAN\_CANCEL**

Scan cancelled.

**MPNOTIFY\_SCAN\_COMPLETE**

Scan completed.

**MPNOTIFY\_SCAN\_PROGRESS**

Progress notification for the specific resource being scanned.

**MPNOTIFY\_SCAN\_ERROR**

Failure to scan a particular resource. Scan will still continue.

**MPNOTIFY\_SCAN\_INFECTED**

Scan found an infected resource.

**MPNOTIFY\_SCAN\_MEMORYSTART**

Scan progress to notify memory scan portion of the system scan has started.

**MPNOTIFY\_SCAN\_MEMORYCOMPLETE**

Scan progress to notify memory scan portion of the system scan has completed.

**MPNOTIFY\_SCAN\_SFC\_BUILD\_START**

Scan progress to notify sfc build portion has started.

**MPNOTIFY\_SCAN\_SFC\_BUILD\_COMPLETE**

Scan progress to notify sfc build portion has completed.

**MPNOTIFY\_SCAN\_FASTPATH\_START**

Scan fastpath spynet has begun.

**MPNOTIFY\_SCAN\_FASTPATH\_COMPLETE**

Scan fastpath spynet has ended.

**MPNOTIFY\_SCAN\_FASTPATH\_PROGRESS**

Progress notification for fastpath rescans, used internally and converted to **MPNOTIFY\_SCAN\_PROGRESS** for external.

**MPNOTIFY\_CLEAN\_START**

Cleaning started.

**MPNOTIFY\_CLEAN\_COMPLETE**

Cleaning completed.

**MPNOTIFY\_CLEAN\_RESTOREPOINT\_START**

Started to create a system restore point.

**MPNOTIFY\_CLEAN\_RESTOREPOINT\_SUCCEEDED**

System restore point successfully created.

**MPNOTIFY\_CLEAN\_RESTOREPOINT\_FAILED**

System restore point creation failed.

**MPNOTIFY\_CLEAN\_THREAT\_START**

Cleaning is started for a particular threat.

**MPNOTIFY\_CLEAN\_THREAT\_SUCCEEDED**

Cleaning is succeeded for a particular threat.

**MPNOTIFY\_CLEAN\_THREAT\_FAILED**

Cleaning has failed for a particular threat. **ERROR\_MP\_THREAT\_NOT\_FOUND** error code indicates that the threat was not found (and was not a failure to clean).

**MPNOTIFY\_CLEAN\_RESOURCE\_SUCCEEDED**

Cleaning is succeeded for a particular resource.

**MPNOTIFY\_CLEAN\_RESOURCE\_FAILED**

Cleaning has failed for a particular resource.

**MPNOTIFY\_CLEAN\_THREAT\_COMPLETE**

Cleaning has completed for a particular threat.

**MPNOTIFY\_PRECHECK\_START**

Clean precheck started.

**MPNOTIFY\_PRECHECK\_COMPLETE**

Clean precheck completed.

**MPNOTIFY\_PRECHECK\_RESOURCE\_BLOCKED**

Clean precheck detected blocked resource.

**MPNOTIFY\_THREAT\_DETECTED**

New threat detected in system.

**MPNOTIFY\_THREAT\_MODIFIED**

Threat information modified. For example, a new resource was added.

**MPNOTIFY\_THREAT\_CLEAN\_SUCCEEDED**

Cleaning action succeeded for a threat.

**MPNOTIFY\_THREAT\_CLEAN\_FAILED**

Cleaning action failed for a threat. **ERROR\_MP\_THREAT\_NOT\_FOUND** error code indicates that the threat was not found (and was not a failure to clean).

**MPNOTIFY\_THREAT\_ABANDONED**

No remediation occurred before the service was stopped.

**MPNOTIFY\_THREAT\_CLEAN\_EVENT\_START**

A cleaning action has been started.

**MPNOTIFY\_THREAT\_CLEAN\_EVENT\_COMPLETE**

A cleaning action has ended.

**MPNOTIFY\_SIGUPDATE\_START**

Signature update started.

**MPNOTIFY\_SIGUPDATE\_SEARCH\_START**

Search for updates started.

**MPNOTIFY\_SIGUPDATE\_SEARCH\_COMPLETE**

Search for updates completed.

**MPNOTIFY\_SIGUPDATE\_SOFTWARE\_UPDATE\_AVAILABLE**

Software update available.

**MPNOTIFY\_SIGUPDATE\_DOWNLOAD\_START**

Download started.

**MPNOTIFY\_SIGUPDATE\_DOWNLOAD\_PROGRESS**

Download in progress. Callback data contains progress.

**MPNOTIFY\_SIGUPDATE\_DOWNLOAD\_COMPLETE**

Download completed.

**MPNOTIFY\_SIGUPDATE\_INSTALL\_START**

Installation started.

**MPNOTIFY\_SIGUPDATE\_INSTALL\_PROGRESS**

Installation in progress. Callback data contains progress.

**MPNOTIFY\_SIGUPDATE\_INSTALL\_COMPLETE**

Installation complete.

**MPNOTIFY\_SIGUPDATE\_REBOOT\_REQUIRED**

Update requires reboot.

**MPNOTIFY\_SIGUPDATE\_REQUEST\_PROCESSED**

Service processed a signature update request. Failure or success is indicated by **hResult** in the callback data.

**MPNOTIFY\_SIGUPDATE\_COMPLETE**

Update complete. **S\_FALSE** status indicates that no updates were needed.

**MPNOTIFY\_SAMPLE\_START**

Sample submission started.

**MPNOTIFY\_SAMPLE\_COMPLETE**

Sample submission completed.

**MPNOTIFY\_SAMPLE\_ITEM\_START**

Specific sample item submission started. Sample item index is available in [**MPSAMPLE\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpsample-data).

**MPNOTIFY\_SAMPLE\_ITEM\_SUCCEEDED**

Specific sample item submission succeeded.

**MPNOTIFY\_SAMPLE\_ITEM\_FAILED**

Specific sample item submission failed. Error code is available in [**MPCALLBACK\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpcallback-data).

**MPNOTIFY\_RESERVED\_DATA**

Internal reserved data.

**MPNOTIFY\_FASTPATH\_SIG\_ADDED**

A Fastpath signature has either added or disabled a signature.

**MPNOTIFY\_FASTPATH\_SIG\_REMOVED**

A FastPath signature has been removed.

**MPNOTIFY\_NIS\_PRIVATE**

NIS private notifications. No partners should register for this.

**MPNOTIFY\_HEALTH\_CHANGE**

The AM service has entered a new state.

**MPNOTIFY\_HEALTH\_RECOVERY**

The AM service has recovered from a state.

**MPNOTIFY\_HEALTH\_START**

The AM service has initialized the health of the system.

**MPNOTIFY\_ENDOFLIFE\_CHANGE**

The "End Of Life" expiry dates for the AM service have changed.

**MPNOTIFY\_MALWARETOAST\_DATA**

The AM service has encountered malware that might have caused critical settings change in the machine.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | MpClient.h |

## See also

[**MpManagerStatusQueryEx**](https://learn.microsoft.com/windows/win32/lwef/mpmanagerstatusqueryex)

[**MPCALLBACK\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpcallback-data)

[**MPSAMPLE\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpsample-data)

