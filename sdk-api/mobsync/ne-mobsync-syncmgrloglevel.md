# SYNCMGRLOGLEVEL enumeration

## Description

The
**SYNCMGRLOGLEVEL** enumeration values specify an error level for use in the
[ISyncMgrSynchronizeCallback::LogError](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronizecallback-logerror) method.

## Constants

### `SYNCMGRLOGLEVEL_INFORMATION:0x1`

An information message was logged.

### `SYNCMGRLOGLEVEL_WARNING:0x2`

A warning message was logged.

### `SYNCMGRLOGLEVEL_ERROR:0x3`

An error message was logged.

### `SYNCMGRLOGLEVEL_LOGLEVELMAX:0x3`

The largest valid [SYNCMGRLOGLEVEL](https://learn.microsoft.com/windows/desktop/api/mobsync/ne-mobsync-syncmgrloglevel) value.

## See also

[ISyncMgrSynchronizeCallback::LogError](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronizecallback-logerror)