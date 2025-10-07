# JetInit3 Function

_**Applies to:** Windows | Windows Server_

## JetInit3 Function

The **JetInit3** function puts the database engine into a state in which it can support application use of database files. The engine must already be properly configured for initialization, which you accomplish by using the [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function) function. Note that database crash recovery occurs automatically as a part of the initialization process.

**Windows Vista:** **JetInit3** is introduced in Windows Vista.

```cpp
    JET_ERR JET_API JetInit3(
      __in_out_opt  JET_INSTANCE* pinstance,
      __in_opt      JET_RSTINFO* prstInfo,
      __in          JET_GRBIT grbit
    );
```

### Parameters

*pinstance*

The instance that you use for a particular call. The use of this parameter depends on the operating mode of the engine. If the engine is operating in legacy mode (Windows 2000 compatibility mode), in which only one instance is supported, you can set this parameter either to **NULL** or to a valid output buffer containing either **NULL** or JET_instanceNil, which returns the global instance handle created as a side-effect of the initialization. This instance handle can then be passed to any other API that takes an instance. If the engine is operating in multi-instance mode, you must set this parameter to a valid input buffer that contains the instance handle returned by the [JetCreateInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateinstance-function) function that is being initialized.

*prstInfo*

Additional recovery parameters used for remapping databases during recovery, for setting the position where recovery will stop, or for determining the current recovery status.

*grbit*

A group of bits that specifies zero or more of the options listed and defined in the following table.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitReplayReplicatedLogFiles

|

This value is reserved for future use.

|
|

JET_bitCreateSFSVolumeIfNotExist

|

This value is reserved for future use.

|
|

JET_bitReplayIgnoreMissingDB

|

This value enables the user to run recovery on a set of log files, even in the absence of the databases that were attached to the log file set at some point.

|
|

JET_bitRecoveryWithoutUndo

|

This value enables the user to perform recovery, but only up to (and not including) the Undo phase. Using this value, additional transaction logs can be copied in and applied.

|
|

JET_bitTruncateLogsAfterRecovery

|

This value causes log files to be truncated during a successful soft recovery.

|
|

JET_bitReplayMissingMapEntryDB

|

This value causes a missing database map entry to default to the same location.

|
|

JET_bitReplayIgnoreLostLogs

|

This value causes logs lost from the end of the log stream to be ignored during a recovery.

**Windows 7:JET_bitReplayIgnoreLostLogs** is introduced in Windows 7.

|

### Return Value

This function returns the [JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err) data type with one of the following return codes. For more information about the possible Extensible Storage Engine (ESE) errors, see [Extensible Storage Engine Errors](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-errors) and [Error Handling Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/error-handling-parameters).

#### Remarks

An instance must be initialized with a call to the **JetInit3** function before it can be used by anything other than the [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function) function.

An instance is destroyed by a call to the [JetTerm](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetterm-function) function, even if that instance was never initialized by using the [JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit-function) function. An instance is the unit of recoverability for the database engine. It controls the life cycle of all the files used to protect the integrity of the data in a set of database files. These files include the checkpoint file and the transaction log files. Note that [JetTerm](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetterm-function) should not be called if the **JetInit3** function fails. However, [JetTerm](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetterm-function) should still be called for all instances created by **JetCreateInstance2** if **JetInit3** was never called or if **JetInit3** succeeds.

If recovery is running on a set of logs for which not all of the related databases are present (which will return the error JET_errAttachedDatabaseMismatch under normal circumstances), and the client wants recovery to continue despite the missing databases, the JET_bitReplayIgnoreMissingDB error is used to continue recovery for the available databases.

Because crash recovery doesn't usually happen on the same machine (and with the same configuration) as at the time of the crash, a database typically doesn't change location. In certain scenarios, such as moving files to a different machine or restoring snapshot backup to different locations, this is no longer true. The **JetInit3** function enables you to specify a mapping (using the [JET_RSTINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-rstinfo-structure) and [JET_RSTMAP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-rstmap-structure) structures) between the old database location and its new location. In fact, you need only the new location as long as the database files are present at that location. As soon as you know the locations of the restored databases, the database signature will be used to identify the database through the restore process. You'll need the original database location only if you need to re-create a database, in which case the signature is known.

In addition, if you need to stop a recovery after an Undo operation, you can specify a particular log position at which recovery will stop. Note that this includes the ability to stop at the end of a particular log generation if the specified position is part of the generation but past the end of the actual log.

For more information, see the "Remarks" section in the [JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit-function) topic.

#### Requirements

| Requirement | Value |
|------------|----------|
|

Client

|

Requires Windows Vista.

|
|

Server

|

Requires Windows Server 2008.

|
|

Header

|

Declared in Esent.h.

|
|

Library

|

Uses ESENT.lib.

|
|

DLL

|

Requires ESENT.dll.

|
|

Unicode

|

Implemented as **JetInit3W** (Unicode) and **JetInit3A** (ANSI).

|

#### See Also

[Extensible Storage Engine Files](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-files)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_INSTANCE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-instance)
[JET_RSTINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-rstinfo-structure)
[JET_RSTMAP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-rstmap-structure)
[JetCreateInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateinstance-function)
[JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit-function)
[JetInit2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit2-function)
[JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function)
[Resource Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/resource-parameters)