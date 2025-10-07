# JetOSSnapshotPrepare Function

_**Applies to:** Windows | Windows Server_

## JetOSSnapshotPrepare Function

The **JetOSSnapshotPrepare** function begins the preparations for a snapshot session. A snapshot session is a short time interval in which the engine does not issue any write IOs to disk, so that the engine can participate in a volume snapshot session (when driven by a snapshot writer).

**Windows XP:** **JetOSSnapshotPrepare** is introduced in Windows XP.

```cpp
    JET_ERR JET_API JetOSSnapshotPrepare(
      __out         JET_OSSNAPID* psnapId,
      __in          const JET_GRBIT grbit
    );
```

### Parameters

*psnapId*

The identifier of the snapshot session to be started.

*grbit*

The options for this call. This parameter can have a combination of the following values.

|

Value

|

Meaning

|
|--------------|----------------|
|

0

|

Normal snapshot.

|
|

JET_bitIncrementalSnapshot

|

Only log files will be taken.

|
|

JET_bitCopySnapshot

|

A copy snapshot (normal or incremental) with no log truncation.

|
|

JET_bitContinueAfterThaw

|

The snapshot session occurs after [JetOSSnapshotThaw](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269229(v=exchg.10).md) and will require a [JetOSSnapshotEnd](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294136(v=exchg.10).md) function call.

|
|

JET_bitExplicitPrepare

|

No instances will be prepared by default.

**Windows 7:** JET_bitExplicitPrepare is introduced in Windows 7.

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

JET_errInvalidParameter

|

The snapshot ID pointer is NULL or the *grbit* parameter is invalid.

|
|

JET_errOSSnapshotInvalidSequence

|

A snapshot session is already in progress and the operation is not allowed to have more than one snapshot session at any given time.

|

If this function succeeds, a snapshot session will be able to start at any time with the IO freeze phase. The identifier for the session will be returned and must be used in the subsequent calls for the snapshot session.

The running instances of the engine will now be considered part of the snapshot session.

**Windows Vista:** To specify a different subset of instances, the [JetOSSnapshotPrepareInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotprepareinstance-function) can be called.

The normal API sequence call is: **JetOSSnapshotPrepare**, optionally followed by one or more calls to [JetOSSnapshotPrepareInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotprepareinstance-function), then followed by [JetOSSnapshotFreeze](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotfreeze-function). Once the freeze is started, it can be terminated using [JetOSSnapshotThaw](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotthaw-function). At any time after the prepare, the snapshot session can be abruptly terminated with [JetOSSnapshotAbort](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotabort-function).

If JET_bitContinueAfterThaw is specified after [JetOSSnapshotThaw](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotthaw-function), the snapshot session will remain (although the I/O will resume). This will enable a verification of the snapshot, and if needed, will enable log truncation using [JetOSSnapshotTruncateLog](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshottruncatelog-function) and will require a call to [JetOSSnapshotEnd](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotend-function).

If this function fails, no change in the engine state occurs.

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
[JetOSSnapshotEnd](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotend-function)
[JetOSSnapshotFreeze](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotfreeze-function)
[JetOSSnapshotPrepareInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotprepareinstance-function)
[JetOSSnapshotThaw](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotthaw-function)
[JetOSSnapshotTruncateLog](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshottruncatelog-function)