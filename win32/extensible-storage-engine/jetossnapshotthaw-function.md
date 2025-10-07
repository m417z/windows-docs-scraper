# JetOSSnapshotThaw Function

_**Applies to:** Windows | Windows Server_

## JetOSSnapshotThaw Function

The **JetOSSnapshotThaw** function notifies the engine that it can resume normal IO operations after a freeze period and a successful snapshot.

**Windows XP:** **JetOSSnapshotThaw** is introduced in Windows XP.

```cpp
    JET_ERR JET_API JetOSSnapshotThaw(
      __in          const JET_OSSNAPID snapId,
      __in          const JET_GRBIT grbit
    );
```

### Parameters

*snapId*

The identifier of the snapshot session.

*grbit*

This parameter is reserved for future use and the only valid value supported is 0.

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

The snapshot session is invalid or the *grbit* parameter is invalid.

|
|

JET_errOSSnapshotTimeOut

|

The snapshot session had an internal timeout before this call occurred. Consequently, IO operations returned to normal before this call was made.

|
|

JET_errOSSnapshotInvalidSnapId

|

The identifier for snapshot session is not valid.

|

If this function succeeds, a snapshot session ends and the normal engine behavior resumes. A new snapshot session can be started later.

If this function fails, the current snapshot session ends but the freeze of IOs during the snapshot period was not respected internally.

#### Remarks

Event log entries will be generated for the different steps of the snapshot.

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
[JET_OSSNAPID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-ossnapid)
[JetOSSnapshotAbort](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotabort-function)
[JetOSSnapshotFreeze](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotfreeze-function)
[JetOSSnapshotPrepare](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotprepare-function)