# SYNCMGRHANDLERFLAGS enumeration

## Description

Used in the [SYNCMGRHANDLERINFO](https://learn.microsoft.com/windows/desktop/api/mobsync/ns-mobsync-syncmgrhandlerinfo) structure as flags that apply to the current handler.

## Constants

### `SYNCMGRHANDLER_HASPROPERTIES:0x1`

The current handler provides a property sheet dialog.

### `SYNCMGRHANDLER_MAYESTABLISHCONNECTION:0x2`

May call back the [ISyncMgrSynchronizeCallback::EstablishConnection](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronizecallback-establishconnection) method. This value is ignored in **Windows Vista and later**.

### `SYNCMGRHANDLER_ALWAYSLISTHANDLER:0x4`

Indicates Show Handler in Choice even if items are not shown. This value is ignored in **Windows Vista and later**.

### `SYNCMGRHANDLER_HIDDEN:0x8`

**Windows Vista and later**. Do not display handler or item. This value is ignored by **Windows Vista**.

## Remarks

Only the ****SYNCMGRHANDLER_HASPROPERTIES**** and ****SYNCMGRHANDLER_HIDDEN**** flags are recognized by Windows Vista. Although Windows Vista recognizes the ****SYNCMGRHANDLER_HIDDEN**** flag, it does not currently use it.

All flags are still valid for previous versions of Windows.

## See also

[SYNCMGRHANDLERINFO](https://learn.microsoft.com/windows/desktop/api/mobsync/ns-mobsync-syncmgrhandlerinfo)