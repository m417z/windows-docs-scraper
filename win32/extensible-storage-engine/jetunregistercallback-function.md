# JetUnregisterCallback Function

_**Applies to:** Windows | Windows Server_

## JetUnregisterCallback Function

The **JetUnregisterCallback** function enables the application to configure the database engine to stop issuing notifications to the application as previously requested through [JetRegisterCallback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetregistercallback-function).

**Windows XP:** **JetUnregisterCallback** is introduced in Windows XP.

```cpp
    JET_ERR JET_API JetUnregisterCallback(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid,
      __in          JET_CBTYP cbtyp,
      __in          JET_HANDLE hCallbackId
    );
```

### Parameters

*sesid*

The session to use for this call.

*tableid*

The cursor to use for this call.

*cbtyp*

A bitmask composed of the callback reasons that the application no longer wishes to receive notifications.

To create this bitmask, simply or together valid callback reasons from the [JET_CBTYP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-cbtyp) enumeration.

*hCallbackId*

The handle of the registered callback that was returned by [JetRegisterCallback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetregistercallback-function).

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

The operation cannot complete because all activity on the instance that is associated with the session has ceased as a result of a call to [JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269240(v=exchg.10).md).

|
|

JET_errInstanceUnavailable

|

The operation cannot complete because the instance that is associated with the session encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data.

**Windows XP:** This return value is introduced in Windows XP.

|
|

JET_errNotInitialized

|

The operation cannot complete because the instance that is associated with the session has not yet been initialized.

|
|

JET_errRestoreInProgress

|

The operation cannot complete because a restore operation is in progress on the instance that is associated with the session.

|
|

JET_errSessionSharingViolation

|

The same session cannot be used for more than one thread at the same time.

**Windows XP:** This return value is introduced in Windows XP.

|
|

JET_errTermInProgress

|

The operation cannot complete because the instance that is associated with the session is being shut down.

|

If this function succeeds, the specified callback will be unregistered for the given callback reasons with the table that is associated with the given cursor. No change to the database state will occur.

If this function fails, the specified callback will not be unregistered. No change to the database state will occur.

#### Remarks

The given bitmask should exactly match the bitmask that is specified when registering the callback. The database engine does not currently support removing a subset of these notifications and it does not return an error when this is attempted.

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

[JET_CBTYP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-cbtyp)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_HANDLE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-handle)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JetRegisterCallback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetregistercallback-function)
[JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopservice-function)