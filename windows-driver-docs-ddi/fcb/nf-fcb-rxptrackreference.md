# RxpTrackReference function

## Description

**RxpTrackReference** tracks requests to reference SRV_CALL, NET_ROOT, V_NET_ROOT, FOBX, FCB, and SRV_OPEN structures in checked builds. A log of these reference requests can be accessed by the logging system and WMI.

## Parameters

### `TraceType`

[in] The value that determines which reference request type is tracked. This value can be one of the following macros defined in *fcb.h*:

| Value | Meaning |
| ----- | ------- |
| RDBSS_REF_TRACK_SRVCALL | A reference request on a SRV_CALL structure. |
| RDBSS_REF_TRACK_NETROOT | A reference request on a NET_ROOT structure. |
| RDBSS_REF_TRACK_VNETROOT | A reference request on a V_NET_ROOT structure. |
| RDBSS_REF_TRACK_NETFOBX | A reference request on an FOBX structure. |
| RDBSS_REF_TRACK_NETFCB | A reference request on an FCB structure. |
| RDBSS_REF_TRACK_SRVOPEN | A reference request on a SRV_OPEN structure. |

### `FileName`

[in] The name of the source file where this routine was called.

### `Line`

[in] The line number in the source file where this routine was called.

### `Instance`

A pointer to the structure to be referenced.

## Remarks

In checked builds, **RxpTrackReference** is used to track requests to reference SRV_CALL, NET_ROOT, V_NET_ROOT, FOBX, FCB, and SRV_OPEN structures. For retail builds, this function does nothing.

If WMI is enabled, a log of these dereference operations is sent as a WMI event to user-mode WMI components that have requested notification. The deference request is also logged to the RDBSS logging system by calling the [_RxLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxlog/nf-rxlog-_rxlog) routine to record an I/O error log entry if logging is enabled.

Note that this routine does not actually reference the structure passed (increment the reference count on the structure).

A number of macros are defined in *fcb.h* for debugging that are the preferred way to call this routine. These macros provide a wrapper around the **RxReference** or **RxDereference** routines used for file structure management operations on SRV_CALL, NET_ROOT, V_NET_ROOT, FOBX, FCB, and SRV_OPEN structures. These macros first call the corresponding **RxpTrackReference** routine to log diagnostic information about the request before calling the corresponding **RxReference** routine.

For retail builds, this function does nothing.

## See also

[RxAssert](https://learn.microsoft.com/windows-hardware/drivers/ifs/rxassert)

[RxDbgBreakPoint](https://learn.microsoft.com/windows-hardware/drivers/ifs/rxdbgbreakpoint)

[RxDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxdereference)

[RxReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxreference)

[RxpTrackDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxptrackdereference)

[_RxLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxlog/nf-rxlog-_rxlog)