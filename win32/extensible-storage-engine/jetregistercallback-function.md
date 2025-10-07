# JetRegisterCallback Function

_**Applies to:** Windows | Windows Server_

## JetRegisterCallback Function

The **JetRegisterCallback** function allows the application to configure the database engine to issue notifications to the application for specific events. These notifications are associated with a specific table and remain in effect only until the instance containing the table is shut down using [JetTerm](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetterm-function).

**Windows XP: JetRegisterCallback** is introduced in Windows XP.

```cpp
    JET_ERR JET_API JetRegisterCallback(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid,
      __in          JET_CBTYP cbtyp,
      __in          JET_CALLBACK pCallback,
      __in          void* pvContext,
      __out         JET_HANDLE* phCallbackId
    );
```

### Parameters

*sesid*

The session to use for this call.

*tableid*

The cursor to use for this call.

*cbtyp*

A bit mask composed of the callback reasons for which the application wishes to receive notifications.

To create this bit mask, simply or together valid callback reasons from the [JET_CBTYP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-cbtyp) enumeration.

*pCallback*

The function pointer to the callback function for the application.

*pvContext*

Specifies a context pointer that will be given to the callback function for the application.

*phCallbackId*

Returns a handle that can later be used to cancel the registration of the given callback function using [JetUnregisterCallback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetunregistercallback-function).

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

It is not possible to complete the operation because the instance associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data. This error will only be returned by Windows XP and later releases.

|
|

JET_errInvalidParameter

|

One of the parameters provided contained an unexpected value or contained a value that did not make sense when combined with the value of another parameter. This error will be returned by **JetRegisterCallback** when:

* *cbtyp* is zero,
* *pCallback* is NULL.
* *phCallbackId* is NULL.

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

JET_errSessionSharingViolation

|

The same session cannot be used for more than one thread at the same time. This error will only be returned by Windows XP and later releases.

|
|

JET_errTermInProgress

|

It is not possible to complete the operation because the instance associated with the session is being shut down.

|

On success, the specified callback will be registered for the given callback reasons with the table associated with the given cursor. No change to the database state will occur.

On failure, the callback will not be registered. No change to the database state will occur.

#### Remarks

This method provides a means for the application to associate volatile callbacks with a table in a database. If the application wishes to associate persisted callbacks with a table in the database then it should pass the callback to [JET_TABLECREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tablecreate-structure) using [JetCreateTableColumnIndex](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatetablecolumnindex-function).

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
[JET_CBTYP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-cbtyp)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_HANDLE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-handle)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JetCreateTableColumnIndex](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatetablecolumnindex-function)
[JetTerm](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetterm-function)
[JetUnregisterCallback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetunregistercallback-function)