# JetCommitTransaction2 Function

_**Applies to:** Windows | Windows Server_

The **JetCommitTransaction2** function commits the changes made to the state of the database during the current save point and migrates them to the previous save point. If the outermost save point is committed, the changes made during that save point will be committed to the state of the database and the session will exit the transaction.

The **JetCommitTransaction2** function was introduced in the Windows 8 operating system.

``` c++
JET_ERR JET_API JetCommitTransaction2(
  __in          JET_SESID sesid,
  __in          JET_GRBIT grbit,
  __in          DWORD cmsecDurableCommit,
  __out         JET_COMMIT_ID pCommitID
);
```

### Parameters

*sesid*

The session to use for this call.

*grbit*

A group of bits that specify zero or more of the values listed in the following table.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitCommitLazyFlush

|

The transaction is committed normally but this API does not wait for the transaction to be flushed to the transaction log file before returning to the caller. This drastically reduces the duration of a commit operation at the cost of durability. Any transaction that is not flushed to the log before a crash will automatically be aborted during crash recovery during the next call to the [JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294068(v=exchg.10).md) function.

If JET_bitWaitLastLevel0Commit or JET_bitWaitAllLevel0Commit are specified, this option is ignored.

If this call to **JetCommitTransaction2** does not match the first call to the [JetBeginTransaction](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294083(v=exchg.10).md) function for this session, this option is ignored. This is because the final action that occurs on the outermost save point is the determining factor in whether the entire transaction is actually committed to disk.

|
|

JET_bitWaitAllLevel0Commit

|

All transactions previously committed by any session that have not yet been flushed to the transaction log file will be flushed immediately. This API will wait until the transactions have been flushed before returning to the caller.

This option may be used even if the session is not currently in a transaction.

This option cannot be used in combination with any other option.

This option is available in versions of the Windows Server operating system starting with Windows Server 2003.

|
|

JET_bitWaitLastLevel0Commit

|

If the session has previously committed any transactions and they have not yet been flushed to the transaction log file, they should be flushed immediately. This API will wait until the transactions have been flushed before returning to the caller. This is useful if the application has previously committed several transactions using JET_bitCommitLazyFlush and now wants to flush all of them to disk.

This option may be used even if the session is not currently in a transaction.

This option cannot be used in combination with any other option.

|

*cmsecDurableCommit*

The duration to commit a lazy transaction.

*pCommitID*

The Commit-ID associated with this commit record.

### Return value

This function returns the [JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err) data type with one of the return codes listed in the following table. For more information about the possible Extensible Storage Engine (ESE) errors, see [Extensible Storage Engine Errors](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-errors) and [Error Handling Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/error-handling-parameters).

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

It is not possible to complete the operation because all activity on the instance associated with the session has ceased as a result of a call to the [JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269240(v=exchg.10).md) function.

|
|

JET_errInstanceUnavailable

|

It is not possible to complete the operation because the instance associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data.

This error will only be returned by versions of the Windows operating system starting with Windows XP.

|
|

JET_errInvalidgrbit

|

One of the options requested was invalid or not implemented. This error will be returned by the **JetCommitTransaction2** function when the following occurs:

* An illegal *grbit* is specified.
* JET_bitWaitLastLevel0Commit was specified in combination with another *grbit*.
* JET_bitWaitAllLevel0Commit was specified in combination with another *grbit*.

|
|

JET_errNotInitialized

|

It is not possible to complete the operation because the instance associated with the session has not been initialized yet.

|
|

JET_errNotInTransaction

|

The operation failed because the given session is not in a transaction.

|
|

JET_errRestoreInProgress

|

It is not possible to complete the operation because a restore operation is in progress on the instance associated with the session.

|
|

JET_errSessionSharingViolation

|

The same session cannot be used for more than one thread at the same time.

This error will only be returned by versions of the Windows operating system starting with Windows XP.

|
|

JET_errTermInProgress

|

It is not possible to complete the operation because the instance associated with the session is being shut down.

|

On success, any changes made to the database during the current save point for the given session will be committed and that save point will be ended. If the last save point for the session was ended, the transaction will optionally be flushed to the transaction log file and the session will exit the transaction.

On failure, the transactional state of the session will remain unchanged. No change to the database state will occur. The application should call the [JetRollback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetrollback-function) function to abort the transaction.

#### Remarks

There must be one call to **JetCommitTransaction2** or [JetRollback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetrollback-function) to match every call to [JetBeginTransaction](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbegintransaction-function) for a given session.

#### Requirements

| Requirement | Value |
|------------|----------|
|

**Client**

|

Requires Windows 8.

|
|

**Server**

|

Requires Windows Server 2012.

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

#### See also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JetBeginTransaction](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbegintransaction-function)
[JetCommitTransaction](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcommittransaction-function)
[JetRollback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetrollback-function)
[JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopservice-function)