# EXPERTSTATUSENUMERATION enumeration

The **EXPERTSTATUSENUMERATION** enumeration contains status values. It is used by the **Status** member of [EXPERTSTATUS](https://learn.microsoft.com/windows/win32/netmon2/expertstatus) structure and the *Status* parameter in [ExpertIndicateStatus](https://learn.microsoft.com/windows/win32/netmon2/expertindicatestatus).

## Constants

**EXPERTSTATUS\_INACTIVE**

The expert never started.

**EXPERTSTATUS\_STARTING**

The expert is starting.

**EXPERTSTATUS\_RUNNING**

The expert is running normally.

**EXPERTSTATUS\_PROBLEM**

A problem specified in *SubStatus* stopped the expert.

**EXPERTSTATUS\_ABORTED**

Network Monitor stopped the expert.

**EXPERTSTATUS\_DONE**

The expert finished successfully.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

