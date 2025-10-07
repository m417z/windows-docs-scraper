# MPDETECTION\_STATE enumeration

The state of the currently detected threat.

## Constants

**MPDETECTION\_STATE\_UNKNOWN**

In an error state.

**MPDETECTION\_STATE\_ACTIVE**

Active threat.

**MPDETECTION\_STATE\_FINISHED**

Pending 24 hours to a move to cleared.

**MPDETECTION\_STATE\_ADDITIONAL\_ACTIONS**

Additional actions required.

**MPDETECTION\_STATE\_FAILED**

Non-critical remediation failure.

**MPDETECTION\_STATE\_CRITICALLY\_FAILED**

Critical remediation failure.

**MPDETECTION\_STATE\_CLEARED**

Threat does not show up in the state query, only in history.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | MpClient.h |

