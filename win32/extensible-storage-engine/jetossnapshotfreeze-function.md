# JetOSSnapshotFreeze Function

_**Applies to:** Windows | Windows Server_

## JetOSSnapshotFreeze Function

The **JetOSSnapshotFreeze** function starts a snapshot. While the snapshot is in progress, no write-to-disk activity by the engine can take place.

**Windows XP:** **JetOSSnapshotFreeze** is introduced in Windows XP.

```cpp
    JET_ERR JET_API JetOSSnapshotFreeze(
      __in          const JET_OSSNAPID snapId,
      __out         unsigned long* pcInstanceInfo,
      __out         JET_INSTANCE_INFO** paInstanceInfo,
      __in          const JET_GRBIT grbit
    );
```

### Parameters

*snapId*

The identifier of the snapshot session.

*pcInstanceInfo*

The number of instances currently running in the engine that are part of the snapshot session.

*paInstanceInfo*

An array of structures, one for each running instance that is part of the snapshot session, describing the instance and the databases that are part of it.

*grbit*

The options for this call. This parameter is reserved for future use and the only valid value supported is 0.

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

The pointers provided for the output parameters are NULL, the snapshot session is invalid, or the *grbit* parameter is invalid.

|
|

JET_errOSSnapshotInvalidSequence

|

The snapshot session is not in the appropriate state to start a freeze (for example, a previous freeze failed on this session before).

|
|

JET_errOSSnapshotNotAllowed

|

The engine is not in a state in which a snapshot can be performed. Either one or more streaming backups is already in progress, or one or more instances are going through recovery steps or terminating.

|
|

JET_errOSSnapshotInvalidSnapId

|

The identifier for the snapshot session is not valid.

|
|

JET_errOutOfMemory

|

The function failed due to an out-of-memory condition.

|
|

JET_errOutOfThreads

|

The function failed because a new thread doing the freeze failed to start.

|

If this function succeeds, there will not be any write IOs issued for the database files or for the log files that are part of instances that are frozen. Also, the instance information will be properly filled and it must be freed later on by calling [JetFreeBuffer](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetfreebuffer-function) with the pointer to the instance info array that was returned.

If this function fails, the engine will keep running normally with the IOs occurring as usual. There is no need to call [JetOSSnapshotThaw](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotthaw-function) if the freeze fails. Also, the instance information will not be filled so there is no need to free this resource.

#### Remarks

During the freeze period, there will not be any write IOs issued to the attached databases or the transaction logs, although there might be write IOs issued to the temporary databases or streaming files.

The state in which the databases and the log files will be during the freeze (the state in which the files would be in a Volume Snapshot image) will be such that a normal recovery will be possible if those files are restored later.

Because there are no write operations during the freeze period, normal API calls into the engine might be stalled for that interval. The client application must be able to handle API calls that might take longer then normal if a freeze occurs.

Due to the possible effects described above, there is an internal timeout after which the snapshot session will stop the freeze phase even if the APIs doing the thaw or abort were not called. The value of the timeout can be changed using the [JET_paramOSSnapshotTimeout](https://learn.microsoft.com/windows/win32/extensible-storage-engine/backup-and-restore-parameters) system parameter. Note that the typical freeze interval is in the range of 10 seconds with the default timeout somewhere around 60 seconds.

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
|

**Unicode**

|

Implemented as **JetOSSnapshotFreezeW** (Unicode) and **JetOSSnapshotFreezeA** (ANSI).

|

#### See Also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_INSTANCE_INFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-instance-info-structure)
[JET_OSSNAPID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-ossnapid)
[JetOSSnapshotAbort](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotabort-function)
[JetOSSnapshotPrepare](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotprepare-function)
[JetOSSnapshotPrepareInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotprepareinstance-function)
[JetOSSnapshotThaw](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotthaw-function)