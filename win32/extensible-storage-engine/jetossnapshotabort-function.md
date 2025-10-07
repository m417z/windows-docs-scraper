# JetOSSnapshotAbort Function

_**Applies to:** Windows | Windows Server_

## JetOSSnapshotAbort Function

The **JetOSSnapshotAbort** function notifies the engine that it can resume normal IO operations after a freeze period ended with a failed snapshot.

**Windows Server 2003:** **JetOSSnapshotAbort** is introduced in Windows Server 2003.

```cpp
    JET_ERR JET_API JetOSSnapshotAbort(
      __in          const JET_OSSNAPID snapId,
      __in          const JET_GRBIT grbit
    );
```

### Parameters

*snapId*

The identifier of the snapshot session.

*grbit*

The options for this call. This parameter is reserved for future use and the only valid value supported is 0 (zero).

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

The snapshot session is invalid or the grbit parameter is invalid.

|
|

JET_errOSSnapshotInvalidSnapId

|

The identifier for the snapshot session is not valid.

|

If this function succeeds, the snapshot session will end and the normal engine behavior will resume. A new snapshot session can be started at a later point.

If this function fails, the snapshot session will not be aborted.

#### Remarks

This function should be called instead of [JetOSSnapshotThaw](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotthaw-function) to inform the engine that the snapshot was aborted for reasons that don't relate to the engine. This information can be used later to help issue event log messages about the snapshot session or to help determine other appropriate actions.

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
[JET_OSSNAPID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-ossnapid)
[JetOSSnapshotFreeze](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotfreeze-function)
[JetOSSnapshotPrepare](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotprepare-function)
[JetOSSnapshotThaw](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotthaw-function)