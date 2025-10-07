# JetDefragment Function

_**Applies to:** Windows | Windows Server_

## JetDefragment Function

The **JetDefragment** function starts and stops database defragmentation tasks that improves data organization within a database. This is done to limit database growth by using existing disk allocation more efficiently within the database. It can also reduce working set by ensuring that data is more closely packed. Lastly, it can improve application performance by speeding common operations through better data organization.

Database defragmentation is an online operation and does not interrupt regular database activity, such as query operations or data updates. **JetDefragment** also does not make a copy of all existing data. Instead, it defragments a database in place. Lastly, **JetDefragment** recovers internal database space for re-use but does not release excess space to the operating system file system.

The resulting format of the data can be much more efficient but is not generally optimal. Defragmentation is limited to releasing database pages for re-use which contain data that has already been logically deleted. Defragmentation also makes database pages available for re-use in some cases by combining data from two pages when it can fit on a single page.

This operation is different from [JetCompact](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcompact-function) which makes a copy of a read-only database into a highly optimal form.

```cpp
    JET_ERR JET_API JetDefragment(
      __in          JET_SESID sesid,
      __in          JET_DBID dbid,
      __in          JET_PCSTR szTableName,
      __out_opt     unsigned long* pcPasses,
      __out_opt     unsigned long* pcSeconds,
      __in          JET_GRBIT grbit
    );
```

### Parameters

*sesid*

The session to use for this call.

*dbid*

The database that will be defragmented.

*szTableName*

Unused parameter. Defragmentation is performed for the entire database described by the given database ID.

*pcPasses*

When starting an online defragmentation task, this input parameter sets the maximum number of defragmentation passes. When stopping an online defragmentation task, this output buffer is set to the number of passes performed.

When this parameter is set to NULL, the number of online defragmentation passes is unlimited.

*pcSeconds*

When starting an online defragmentation task, this input parameter sets the maximum time for defragmentation. When stopping an online defragmentation task, this output buffer is set to the length of time used for defragmentation.

When this parameter is set to NULL or if *pcSeconds* points to a negative value, the maximum time for defragmentation is unlimited.

*grbit*

A group of bits specifying zero or more of the following options.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitDefragmentAvailSpaceTreesOnly

|

Defragments the available space portion of ESE database space allocation. Database space is divided into two types, owned space and available space. Owned space is allocated to a table or index while available space is ready for use within the table or index, respectively. Available space is much more dynamic in behavior and requires on-line defragmentation more so than owned space or table or index data.

|
|

JET_bitDefragmentBatchStart

|

Starts a new defragmentation task.

|
|

JET_bitDefragmentBatchStop

|

Stops a defragmentation task.

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

JET_errClientRequestToStopJetService

|

It is not possible to complete the operation because all activity on the instance associated with the session has ceased as a result of a call to [JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269240(v=exchg.10).md).

|
|

JET_errDatabaseFileReadOnly

|

The database chosen for defragmentation is read only and cannot be updated in any way, including defragmentation.

|
|

JET_errDistributedTransactionAlreadyPreparedToCommit

|

The given session is in the prepared to commit state, and cannot begin new updates until the current transaction is committed or rolled back.

|
|

JET_errInstanceUnavailable

|

It is not possible to complete the operation because the instance associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data. This error will only be returned by Windows XP and later releases.

|
|

JET_errInvalidDatabaseId

|

The given database ID does not match a known database in the instance.

|
|

JET_errNotInitialized

|

It is not possible to complete the operation because the instance associated with the session has not been initialized yet.

|
|

JET_errRestoreInProgress

|

It is not possible to complete the operation because a restore operation is in progress on the instance associated with the session.

|
|

JET_errSessionSharingViolation

|

The same session cannot be used for more than one thread at the same time. This error will only be returned by Windows XP and later releases.

|
|

JET_errTermInProgress

|

It is not possible to complete the operation because the instance associated with the session is being shut down.

|
|

JET_errTransReadOnly

|

The given session has read-only privileges only and cannot start a task that may perform an update, including defragmentation.

|
|

JET_errVersionStoreOutOfMemory

|

This error will occur when the configured size of the version store is insufficient to hold all outstanding updates.

|
|

JET_wrnDefragAlreadyRunning

|

The JET_bitDefragmentBatchStart option has been passed but a defragmentation task is already running defragmentation on the given database.

|
|

JET_wrnDefragNotRunning

|

The JET_bitDefragmentBatchStop option has been passed, but no defragmentation task is currently running.

|

On success, the requested action of either starting a defragmentation task for a given data with given options is performed, or the action of stopping an existing defragmentation task is performed.

On failure, the requested action of either starting or stopping an online defragmentation job is not done. No other side effects occur.

#### Remarks

Online defragmentation is controlled both by a parameter setting, as well as by this API. The default system parameter value is JET_OnlineDefragAll, which means defragmentation is enabled for all supported data structures. However, using [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function), it is possible to disable online defragmentation, or to selectively enable it for database space trees only, databases only, streaming files only or any combination of these options. If the system setting for online defragmentation is set to an obsolete setting, **JetDefragment** will treat the setting as JET_OnlineDefragAll.

There can at most be one task running for each database. The task runs as a thread in the process hosting ESE.

The session used to start the online defragmentation task can be subsequently used for database operations while the defragmentation task continues, because the defragmentation task allocates its own session. The given session is only used to check the permissions associated with the task starting session and is not actually used for the defragmentation operations themselves.

#### Requirements

| Requirement | Value |
|------------|----------|
|

**Client**

|

Requires Windows Vista, Windows XP, or Windows 2000 Professional.

|
|

**Server**

|

Requires Windows Server 2008, Windows Server 2003, or Windows 2000 Server.

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

Implemented as **JetDefragmentW** (Unicode) and **JetDefragmentA** (ANSI).

|

#### See Also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JetCompact](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcompact-function)
[JetDefragment2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdefragment2-function)
[JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function)
[JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopservice-function)