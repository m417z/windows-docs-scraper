# JetOSSnapshotEnd Function

_**Applies to:** Windows | Windows Server_

## JetOSSnapshotEnd Function

The **JetOSSnapshotEnd** function notifies the engine that the snapshot session finished.

**Windows Vista:** **JetOSSnapshotEnd** is introduced in Windows Vista:.

```cpp
    JET_ERR JET_API JetOSSnapshotEnd(
      __in          const JET_OSSNAPID snapId,
      __in          const JET_GRBIT grbit
    );
```

### Parameters

*snapId*

The identifier of the snapshot session.

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

The successful end of the snapshot session.

|
|

JET_bitAbortSnapshot

|

The snapshot session aborted.

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

One of the options requested is invalid, used incorrectly, or not implemented.

|
|

JET_errOSSnapshotInvalidSequence

|

A snapshot session is already in progress. This is not allowed.

|
|

JET_errOSSnapshotInvalidSnapId

|

The identifier for the snapshot session is not valid.

|
|

JET_errOSSnapshotTimeOut

|

The snapshot session had an internal timeout before this call occurred. As a result, the IO operations returned to normal before this call was made.

|

If this function succeeds, a snapshot session will complete and the normal engine behavior will resume. A new snapshot session can be started later.

If this function fails, the JET_errOSSnapshotTimeOut return code returns and the current snapshot session ends but the freeze of IOs during the snapshot period was not respected internally. For all other errors, the snapshot session state will not be changed.

#### Remarks

This function is called only if [JetOSSnapshotThaw](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotthaw-function) was called with JET_bitContinueAfterThaw.

The snapshot session must complete for the snapshot verification and log truncation to take place. Event log entries will be generated for the different steps of the snapshot.

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
[JetOSSnapshotThaw](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotthaw-function)