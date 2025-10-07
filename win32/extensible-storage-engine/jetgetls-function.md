# JetGetLS Function

_**Applies to:** Windows | Windows Server_

## JetGetLS Function

The **JetGetLS** function enables the application to retrieve the context handle known as Local Storage that is associated with a cursor or the table associated with that cursor. This context handle must have been previously set using [JetSetLS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetls-function). **JetGetLS** can also be used to simultaneously fetch the current context handle for a cursor or table and reset that context handle.

**Windows XP: JetGetLS** is introduced in Windows XP.

```cpp
    JET_ERR JET_API JetGetLS(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid,
      __out         JET_LS* pls,
      __in          JET_GRBIT grbit
    );
```

### Parameters

*sesid*

The session to use for this call.

*tableid*

The cursor to use for this call.

*pls*

The output buffer that receives the context handle currently associated with the cursor or table.

*grbit*

A group of bits specifying zero or more of the following options.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitLSCursor

|

Indicates that the context handle associated with the given cursor should be retrieved.

If neither JET_bitLSCursor nor JET_bitLSTable is specified then JET_bitLSCursor is presumed.

This option cannot be used with JET_bitLSTable. The operation will fail with JET_errInvalidgrbit if this is attempted.

|
|

JET_bitLSTable

|

Indicates that the context handle associated to the table that contains the given cursor should be retrieved. It is illegal to use this option with JET_bitLSCursor. The operation will fail with JET_errInvalidgrbit if this is attempted.

|
|

JET_bitLSReset

|

Indicates that the context handle for the chosen object should be reset to JET_LSNil. The current value of the context handle is returned in the output buffer.

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

JET_errInstanceUnavailable

|

It is not possible to complete the operation because the instance associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data.

This error will only be returned by Windows XP and later releases.

|
|

JET_errInvalidgrbit

|

One of the options requested was invalid, used in an illegal manner, or not implemented.

This can happen for **JetGetLS** when both JET_bitLSCursor and JET_bitLSTable are set.

|
|

JET_errLSNotSet

|

The context handle could not be returned because no context handle is currently associated with the requested object.

**Note**  This error is not returned if JET_bitLSReset is specified yet no context handle was associated with the requested object.

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

On success, the context handle was successfully retrieved from the requested object. If JET_bitLSReset was specified then that context handle was also successfully removed from the object. No change to the database state will occur.

On failure, no change to the state of the requested object has occurred. No change to the database state will occur.

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

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_LS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-ls)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JetSetLS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetls-function)