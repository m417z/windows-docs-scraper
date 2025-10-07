# JetResetSessionContext Function

_**Applies to:** Windows | Windows Server_

## JetResetSessionContext Function

The **JetResetSessionContext** function disassociates a session from the current thread.

```cpp
    JET_ERR JET_API JetResetSessionContext(
      __in          JET_SESID sesid
    );
```

### Parameters

*sesid*

The session to use for this call.

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

JET_errInstanceUnavailable

|

It is not possible to complete the operation because the instance associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data.

This error will only be returned by Windows XP and later releases.

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

JET_errSessionContextNotSetByThisThread

|

The session could not be disassociated from the current thread because it is associated with a different thread.

|
|

JET_errTermInProgress

|

It is not possible to complete the operation because the instance associated with the session is being shut down.

|

On success, the session will be disassociated from the current thread. No change to the database state will occur.

On failure, the session state will remain unchanged. No change to the database state will occur.

#### Remarks

**JetResetSessionContext** must be called on the same thread that called [JetSetSessionContext](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsessioncontext-function) for a given session.

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

[JET_API_PTR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-api-ptr)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JetSetSessionContext](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsessioncontext-function)