# THDTYPE enumeration

## Description

Indicates whether a particular thread supports a message loop.

## Constants

### `THDTYPE_BLOCKMESSAGES:0`

The thread does not support a message loop. This behavior is associated with multithreaded apartments.

### `THDTYPE_PROCESSMESSAGES:1`

The thread supports a message loop. This behavior is associated with single-threaded apartments.

## See also

[IComThreadingInfo::GetCurrentThreadType](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-icomthreadinginfo-getcurrentthreadtype)