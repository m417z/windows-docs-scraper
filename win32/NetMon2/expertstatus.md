# EXPERTSTATUS structure

The **EXPERTSTATUS** structure indicates the current status of a running expert.

## Members

**Status**

Current expert status value defined by the [**EXPERTSTATUSENUMERATION**](https://learn.microsoft.com/windows/win32/netmon2/expertstatusenumeration) enumeration.

**SubStatus**

Sub-status value.

**PercentDone**

Percentage completion of the expert analysis of network data.

**Frame**

Frame number.

**szStatusText**

Text that describes the expert status.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

