# JetOSSnapshotTruncateLogInstance Function

_**Applies to:** Windows | Windows Server_

## JetOSSnapshotTruncateLogInstance Function

The **JetOSSnapshotTruncateLogInstance** function truncates the log for a specified instance during a snapshot session.

**Windows Vista:** **JetOSSnapshotTruncateLogInstance** is introduced in Windows Vista.

```cpp
    JET_ERR JET_API JetOSSnapshotTruncateLogInstance(
      __in          const JET_OSSNAPID snapId,
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

The options for this call. This parameter can have a combination of the following values.

*grbit* can be one of the following values:

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitAllDatabasesSnapshot

|

All the databases are attached so the storage engine can compute and do the log truncation.

|
|

0 (zero)

|

No truncation will occur.

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

JET_errInvalidGrbit

|

The *grbit* parameter is invalid.

|
|

JET_errOSSnapshotInvalidSequence

|

The snapshot session is not in the state in which a truncation can occur. Possible causes are:

* The call completes after the snapshot session timed out.
* The session was specified as a copy snapshot.

|

If this function succeeds, the log files for one or all of the instances that are part of the snapshot session will be truncated, if possible.

#### Remarks

This function should be called only if the snapshot was created with the JET_bitContinueAfterThaw option. Otherwise, the snapshot session ends after the call to [JetOSSnapshotThaw](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotthaw-function).

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
[JetOSSnapshotEnd](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotend-function)
[JetOSSnapshotFreeze](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotfreeze-function)
[JetOSSnapshotPrepare](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotprepare-function)
[JetOSSnapshotThaw](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotthaw-function)