# JetInit2 Function

_**Applies to:** Windows | Windows Server_

## JetInit2 Function

The **JetInit2** function puts the database engine into a state where it can support application use of database files. The engine must already be properly configured for initialization using [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function). Database crash recovery is performed automatically as a part of the initialization process.

**Windows XP:** **JetInit2** is introduced in Windows XP.

This function is obsolete. Use [JetInit3](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit3-function) instead.

```cpp
JET_ERR JET_API JetInit2(
  __in_out_opt  JET_INSTANCE* pinstance,
  __in          JET_GRBIT grbit
);
```

### Parameters

*pinstance*

The instance to use for this call.

For Windows 2000, this parameter is ignored and should always be NULL.

For Windows XP and later releases, the use of this parameter depends on the operating mode of the engine. If the engine is operating in legacy mode (Windows 2000 compatibility mode) where only one instance is supported, this parameter may either be NULL or it may be set to a valid output buffer containing NULL or JET_instanceNil which returns the global instance handle created as a side effect of the initialization. This instance handle can then be passed to any other API that takes an instance. If the engine is operating in multi-instance mode, this parameter must be set to a valid input buffer that contains the instance handle returned by the [JetCreateInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateinstance-function) that is being initialized.

*grbit*

A group of bits specifying zero or more of the following options.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitReplayReplicatedLogFiles

|

Reserved for future use.

|
|

JET_bitCreateSFSVolumeIfNotExist

|

Reserved for future use.

|
|

JET_bitReplayIgnoreMissingDB

|

This option allows the user to run recovery on a set of log files, without all of the databases being present, that were attached at one point of the log set.

|
|

JET_bitRecoveryWithoutUndo

|

Perform recovery, but halt at the Undo phase. This allows additional transaction logs to copied in and applied.

|
|

JET_bitTruncateLogsAfterRecovery

|

On successful soft recovery, truncate log files.

|
|

JET_bitReplayMissingMapEntryDB

|

Missing database map entry default to same location.

|
|

JET_bitReplayIgnoreLostLogs

|

Ignore logs lost from the end of the log stream.

**Windows 7:JET_bitReplayIgnoreLostLogs** is introduced in Windows 7.

|

### Return Value

This function returns the [JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err) datatype with one of the following return codes. For more information about the possible ESE errors, see [Extensible Storage Engine Errors](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-errors) and [Error Handling Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/error-handling-parameters).

#### Remarks

An instance must be initialized with a call to **JetInit2** before it can be used by anything other than [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function).

An instance is destroyed by a call to the [JetTerm](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetterm-function) function, even if that instance was never initialized using [JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit-function). An instance is the unit of recoverability for the database engine. It controls the life cycle of all the files used to protect the integrity of the data in a set of database files. These files include the checkpoint file and the transaction log files.

If recovery is running on a set of logs, for which not all databases is present (which will return the error JET_errAttachedDatabaseMismatch under normal circumstances), and the client wishes recovery to continue despite missing databases, the JET_ bitReplayIgnoreMissingDB is used to continue recovery for the available databases.

See the Remarks section in [JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit-function) for more information.

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

[Extensible Storage Engine Files](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-files)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_INSTANCE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-instance)
[JetCreateInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateinstance-function)
[JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit-function)
[JetInit3](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit3-function)
[JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function)
[Resource Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/resource-parameters)