# JetEndSession Function

_**Applies to:** Windows | Windows Server_

## JetEndSession Function

The **JetEndSession** function ends the session, and cleans up and deallocates any resources associated with the specified session.

```cpp
    JET_ERR JET_API JetEndSession(
      __in          JET_SESID sesid,
      __in          JET_GRBIT grbit
    );
```

### Parameters

*sesid*

The session to end. Associated resources are released when the session ends.

*grbit*

Reserved. This parameter can contain the JET_bitForceSessionClosed flag, but this flag is reserved and setting it has no effect.

### Return Value

This function returns the [JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err) datatype with one of the following return codes. For more information about the possible ESE errors, see [Extensible Storage Engine Errors](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-errors) and [Error Handling Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/error-handling-parameters).

|

Return code

|

Description

|
|--------------------|--------------------|
|

JET_errSuccess

|

The operation completed successfully.

|
|

JET_errClientRequestToStopJetService

|

It is not possible to complete the operation because all activity on the instance associated with the session has ceased as a result of a call to [JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269240(v=exchg.10).md).

|
|

JET_errInvalidParameter

|

One of the parameters that was provided contained an unexpected value, or the combination of several parameter values yielded an unexpected result.

|
|

JET_errInvalidSesid

|

The session was not a valid JET session.

|
|

JET_errNotInitialized

|

It is not possible to complete the operation because the instance associated with the session has not been initialized yet.

|
|

JET_errOutOfMemory

|

The operation failed because memory could not be allocated.

|
|

JET_errSessionInUse

|

This means the session was in use on another thread, or the session was not set or reset properly.

|
|

JET_errInstanceUnavailable

|

It is not possible to complete the operation because the instance associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data.

This error will only be returned by Windows XP and later releases.

|
|

JET_errOutOfBuffers

|

System error that indicates that there are no more buffers.

|
|

JET_errRestoreInProgress

|

It is not possible to complete the operation because a restore operation is in progress on the instance associated with the session.

|
|

JET_errTermInProgress

|

It is not possible to complete the operation because the instance associated with the session is being shut down.

|

On success, the session handle is closed, and unavailable, and all resources related to this session are cleaned up.

On failure, there are several additional errors that could occur as part of sort table close, cursor close, and transaction rollback. These errors are fairly unlikely, and extremely unlikely if your sessions are completely not in use when **JetEndSession** is called. These errors will be returned if some part of the session was unable to be cleaned up properly.

#### Remarks

This API will rollback any open transactions (not committed to level 0). Also all cursors associated with this session, and any sort tables that have been created or opened will be cleaned up.

#### Requirements

| Requirement | Value |
|------------|----------|
|

**Client**

|

Requires Windows Vista, Windows XP, or Windows 2000 Professional.

|
|

**Server**

|

Requires Windows Server 2008, Windows Server 2003, or Windows 2000 Server.

|
|

**Header**

|

Declared in Esent.h.

|
|

**Library**

|

Use ESENT.lib.

|
|

**DLL**

|

Requires ESENT.dll.

|

#### See Also

[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JetBeginSession](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbeginsession-function)
[JetRollback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetrollback-function)
[JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function)
[JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopservice-function)