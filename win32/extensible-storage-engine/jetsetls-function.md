# JetSetLS Function

_**Applies to:** Windows | Windows Server_

## JetSetLS Function

The **JetSetLS** function enables the application to associate a context handle known as Local Storage with a cursor or the table associated with that cursor. This context handle can be used by the application to store auxiliary data that is associated with a cursor or table. The application is later notified using a runtime callback when the context handle must be released. This makes it possible to associate dynamically allocated state with a cursor or table.

**Windows XP:** **JetSetLS** is introduced in Windows XP.

```cpp
    JET_ERR JET_API JetSetLS(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid,
      __in          JET_LS ls,
      __in          JET_GRBIT grbit
    );
```

### Parameters

*sesid*

The session to use for this call.

*tableid*

The cursor to use for this call.

*ls*

The context handle to be associated with the cursor or table.

When JET_bitLSReset is specified then the actual value of this parameter is ignored and JET_LSNil is used.

*grbit*

A group of bits that contain the options to be used for this call, which include zero or more of the following.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitLSCursor

|

This option indicates that the context handle should be associated with the given cursor.

If neither JET_bitLSCursor nor JET_bitLSTable is specified then JET_bitLSCursor is presumed.

It is illegal to use this option with JET_bitLSTable. The operation will fail with JET_errInvalidgrbit if this is attempted.

|
|

JET_bitLSReset

|

This option indicates that the specified context handle should be ignored and that the context handle for the chosen object should be reset to JET_LSNil.

It is important to note that this action will not result in a callback to cleanup the previous value of the context handle for the chosen object. Proper cleanup of the previous context handle can be achieved using [JetGetLS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269234(v=exchg.10).md) with JET_bitLSReset. See [JetGetLS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269234(v=exchg.10).md) for more information.

|
|

JET_bitLSTable

|

This option indicates that the context handle should be associated with the table associated with the given cursor.

It is illegal to use this option with JET_bitLSCursor. The operation will fail with JET_errInvalidgrbit if this is attempted.

|

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

JET_errInvalidgrbit

|

One of the options requested was invalid, used incorrectly, or not implemented. This can happen for **JetSetLS** when JET_bitLSCursor and JET_bitLSTable are both specified.

|
|

JET_errInstanceUnavailable

|

It is not possible to complete the operation because the instance associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data. This error will only be returned by Windows XP and later releases.

|
|

JET_errLSAlreadySet

|

The given context handle could not be associated with the requested object because it already had a context handle associated with it.

|
|

JET_errLSCallbackNotSpecified

|

The given context handle could not be associated with the requested object because the runtime callback has not been configured for the instance associated with the session.

|
|

JET_errNotInitialized

|

It is not possible to complete the operation because the instance associated with the session has not been initialized yet.

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

On success, the given context handle was successfully associated with the requested object. No change to the database state will occur.

On failure, no change to the state of the requested object has occurred. No change to the database state will occur.

#### Remarks

The Local Storage for a cursor or table should be viewed as a volatile cache. The application should first try to retrieve the context handle using [JetGetLS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetls-function). If the value is not set (that is it is JET_LSNil) then the application should create a new context and load it into the cache using **JetSetLS**. The application can purge the cache using a call to [JetGetLS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetls-function) with JET_bitLSReset. If the database engine purges the cache then a runtime callback will be generated to give the application a chance to cleanup that context. The callback type will be JET_cbtypFreeCursorLS for a context handle associated with a cursor and JET_cbtypFreeTableLS for a context handle associated with a table. In either case, the context handle will be passed as pvArg1. See [JET_CALLBACK](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-callback-callback-function) for more information.

The runtime callback must be properly configured for the instance associated with the given session before Local Storage can be used. This callback can be set using [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function) with [JET_paramRuntimeCallback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/callback-parameters). See [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function) and [JET_paramRuntimeCallback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/callback-parameters) in System Parameters for more information.

#### Requirements

| Requirement | Value |
|------------|----------|
|

**Client**

|

Requires Windows Vista or Windows XP.

|
|

**Server**

|

Requires Windows Server 2008 or Windows Server 2003.

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

[JET_CALLBACK](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-callback-callback-function)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_LS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-ls)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JetGetLS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetls-function)
[JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function)
[System Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-system-parameters)