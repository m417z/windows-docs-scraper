# JetSetTableSequential Function

_**Applies to:** Windows | Windows Server_

## JetSetTableSequential Function

The **JetSetTableSequential** function notifies the database engine that the application is scanning the entire current index that contains a given cursor. Consequently, the methods that are used to access the index data will be tuned to make this scenario as fast as possible.

**Windows XP:** **JetSetTableSequential** is introduced in Windows XP.

```cpp
    JET_ERR JET_API JetSetTableSequential(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid,
      __in          JET_GRBIT grbit
    );
```

### Parameters

*sesid*

The session to use for this call.

*tableid*

The cursor to use for this call.

*grbit*

A group of bits that specify zero or more of the following options.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitPrereadForward

|

This option is used to index in the forward direction.

**Windows 7:** **JET_bitPrereadForward** is introduced in Windows 7.

|
|

JET_bitPrereadBackward

|

This option is used to index in the backward direction.

**Windows 7:** **JET_bitPrereadBackward** is introduced in Windows 7.

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

JET_errClientRequestToStopJetService

|

The operation cannot complete because all activity on the instance that is associated with the session has been quiesced as a result of a call to [JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269240(v=exchg.10).md).

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

JET_errTermInProgress

|

The operation cannot complete because the instance that is associated with the session is being shut down.

|

If this function succeeds, the current index of the cursor is optimized for a sequential scan of the entire index. No change to the database state will occur.

If this function fails, no change to the configuration of the cursor will occur. No change to the database state will occur.

#### Remarks

If the application needs to efficiently scan a known subset of an index, a similar optimization is also performed whenever an index range is established by using [JetSetIndexRange](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetindexrange-function). This optimization is only available on Windows XP and later releases.

If the application needs to efficiently scan an unknown subset of an index, no action should be taken. The engine can automatically detect scanning behavior and will fetch data ahead of time. This behavior is not as aggressive, however.

This optimization will make scanning the primary index efficient and will make scanning just the index entry data in a secondary index efficient. It will not make scanning a secondary index while retrieving record data efficient. This is because the engine does not perform a read-ahead on the record data.

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
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JetSetIndexRange](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetindexrange-function)
[JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopservice-function)