# JetOSSnapshotGetFreezeInfo Function

_**Applies to:** Windows | Windows Server_

## JetOSSnapshotGetFreezeInfo Function

The **JetOSSnapshotGetFreezeInfo** function retrieves the list of instances and databases that are part of the snapshot session at any given moment.

**Windows Vista:** **JetOSSnapshotGetFreezeInfo** is introduced in Windows Vista.

```cpp
    JET_ERR JET_API JetOSSnapshotGetFreezeInfo(
      __in          const JET_OSSNAPID snapId,
      __out         unsigned long* pcInstanceInfo,
      __out         JET_INSTANCE_INFO** paInstanceInfo,
      __in          const JET_GRBIT grbit
    );
```

### Parameters

*snapId*

The identifier of the snapshot session to be started.

*pcInstanceInfo*

The number of instances currently running that are part of the snapshot session.

*paInstanceInfo*

An array of structures, one for each running instance, describing the instance and the databases that are part of it.

*grbit*

The options for this call. This parameter is reserved for future use. The only valid value is 0 (zero).

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

JET_errOutOfMemory

|

The function failed due to an out-of-memory condition.

|
|

JET_errInvalidParameter

|

*pcInstanceInfo* or *paInstanceInfo* is **NULL**.

|
|

JET_errOSSnapshotInvalidSnapId

|

The identifier for the snapshot session is not valid.

|
|

JET_errOSSnapshotInvalidSequence

|

A snapshot session is not in progress.

|

If this function succeeds, the instance information is properly filled and it must be freed later by calling [JetFreeBuffer](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetfreebuffer-function) with the pointer to the instance info array that was returned.

If this function fails, no change in the engine state occurs.

#### Requirements

| Requirement | Value |
|------------|----------|
|

**Client**

|

Requires Windows Vista.

|
|

**Server**

|

Requires Windows Server 2008.

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
|

**Unicode**

|

Implemented as **JetOSSnapshotGetFreezeInfoW** (Unicode) and **JetOSSnapshotGetFreezeInfoA** (ANSI).

|

#### See Also

[Error Handling Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/error-handling-parameters)
[Extensible Storage Engine Errors](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-errors)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JetFreeBuffer](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetfreebuffer-function)
[JetOSSnapshotAbort](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotabort-function)
[JetOSSnapshotFreeze](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotfreeze-function)
[JetOSSnapshotThaw](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotthaw-function)