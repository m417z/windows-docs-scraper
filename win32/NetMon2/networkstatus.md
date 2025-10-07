# NETWORKSTATUS structure

The **NETWORKSTATUS** structure describes the current status of the NPP.

## Members

**State**

Indicates the current state of the NPP.

| Value | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------|
| **NETWORKSTATUS\_STATE\_VOID** | The NPP is not connected, or it is connected and the capture is not started.<br> |
| **NETWORKSTATUS\_STATE\_CAPTURING** | The NPP is capturing data.<br> |
| **NETWORKSTATUS\_STATE\_PAUSED** | The NPP has paused while capturing data.<br> |

**Flags**

Flags that describe the current state of the NPP.

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------|
| **NETWORKSTATUS\_FLAGS\_TRIGGER\_PENDING** | There is a trigger pending for the NPP.<br> |

## Remarks

When using this structure, you must allocate the memory for the structure before it can be used and free the memory when the structure is no longer needed.

The See Also list at the bottom of this topic lists all the methods that use this structure.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

## See also

[IDelaydC::QueryStatus](https://learn.microsoft.com/windows/win32/netmon2/idelaydc-querystatus)

[IESP::QueryStatus](https://learn.microsoft.com/windows/win32/netmon2/iesp-querystatus)

[IRTC::QueryStatus](https://learn.microsoft.com/windows/win32/netmon2/irtc-querystatus)

[IStats::QueryStatus](https://learn.microsoft.com/windows/win32/netmon2/istats-querystatus)

