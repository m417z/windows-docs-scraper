# JetOSSnapshotPrepareInstance Function

_**Applies to:** Windows | Windows Server_

## JetOSSnapshotPrepareInstance Function

The **JetOSSnapshotPrepareInstance** function selects a specific instance to be part of the snapshot session.

**Windows Vista:** **JetOSSnapshotPrepareInstance** was introduced in Windows Vista.

```cpp
JET_ERR JET_API JetOSSnapshotPrepareInstance(
  __in          JET_OSSNAPID snapId,
  __in          JET_INSTANCE instance,
  __in          const JET_GRBIT grbit
);
```

### Parameters

*snapId*

The identifier of the snapshot session.

*instance*

The instance that will be used for this call.

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

JET_errInvalidParameter

|

The snapshot id pointer is **NULL** or the *grbit* parameter is invalid.

|
|

JET_errOSSnapshotInvalidSequence

|

A snapshot session is already in progress.

|
|

JET_errOSSnapshotInvalidSnapId

|

The identifier for the snapshot session is not valid.

|

If this function succeeds, the specified instance will be part of the snapshot session.

If this function fails, no change in the engine state occurs.

#### Remarks

The normal API sequence call is: [JetOSSnapshotPrepare](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotprepare-function), optionally followed by one or more calls to **JetOSSnapshotPrepareInstance**, then followed by [JetOSSnapshotFreeze](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotfreeze-function). Once the freeze is started, it can be terminated using [JetOSSnapshotThaw](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotthaw-function). At any time after the prepare, the snapshot session can be abruptly terminated with [JetOSSnapshotAbort](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotabort-function). Event log entries will be generated for the different steps of the snapshot.

If **JetOSSnapshotPrepareInstance** is not called between the start of the session ([JetOSSnapshotPrepare](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotprepare-function)) and the freeze moment ([JetOSSnapshotFreeze](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotfreeze-function)), all the running instances in the engine will freeze and become part of the snapshot session. This occurs for two reasons:

  - It simplifies the code for users who want all instances.

  - It allows backward compatibility for the callers of the snapshot APIs.

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

#### See Also

[Error Handling Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/error-handling-parameters)
[Extensible Storage Engine Errors](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-errors)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JetOSSnapshotAbort](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotabort-function)
[JetOSSnapshotEnd](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotend-function)
[JetOSSnapshotFreeze](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotfreeze-function)
[JetOSSnapshotPrepare](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotprepare-function)
[JetOSSnapshotThaw](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotthaw-function)