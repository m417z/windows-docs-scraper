# JetCommitTransaction Function

_**Applies to:** Windows | Windows Server_

## JetCommitTransaction Function

The **JetCommitTransaction** function commits the changes made to the state of the database during the current save point and migrates them to the previous save point. If the outermost save point is committed then the changes made during that save point will be committed to the state of the database and the session will exit the transaction.

```cpp
    JET_ERR JET_API JetCommitTransaction(
      __in          JET_SESID sesid,
      __in          JET_GRBIT grbit
    );
```

### Parameters

*sesid*

The session to use for this call.

*grbit*

A group of bits specifying zero or more of the following options.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitCommitLazyFlush

|

The transaction is committed normally but this API does not wait for the transaction to be flushed to the transaction log file before returning to the caller. This drastically reduces the duration of a commit operation at the cost of durability. Any transaction that is not flushed to the log before a crash will be automatically aborted during crash recovery during the next call to [JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294068(v=exchg.10).md).

If JET_bitWaitLastLevel0Commit or JET_bitWaitAllLevel0Commit are specified, this option is ignored.

If this call to **JetCommitTransaction** does not match the first call to [JetBeginTransaction](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294083(v=exchg.10).md) for this session, this option is ignored. This is because the final action that occurs on the outermost save point is the determining factor in whether the entire transaction is actually committed to disk.

|
|

JET_bitWaitAllLevel0Commit

|

All transactions previously committed by any session that have not yet been flushed to the transaction log file will be flushed immediately. This API will wait until the transactions have been flushed before returning to the caller.

This option may be used even if the session is not currently in a transaction.

This option cannot be used in combination with any other option.

This option is only available as of Windows Server 2003.

|
|

JET_bitWaitLastLevel0Commit

|

If the session has previously committed any transactions and they have not yet been flushed to the transaction log file, they should be flushed immediately. This API will wait until the transactions have been flushed before returning to the caller. This is useful if the application has previously committed several transactions using JET_bitCommitLazyFlush and now wants to flush all of them to disk.

This option may be used even if the session is not currently in a transaction.

This option cannot be used in combination with any other option.

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

JET_errInstanceUnavailable

|

It is not possible to complete the operation because the instance associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data.

This error will only be returned by Windows XP and later releases.

|
|

JET_errInvalidgrbit

|

One of the options requested was invalid or not implemented. This error will be returned by **JetCommitTransaction** when:

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

This error will only be returned by Windows XP and later releases.

|
|

JET_errTermInProgress

|

It is not possible to complete the operation because the instance associated with the session is being shut down.

|

On success, any changes made to the database during the current save point for the given session will be committed and that save point will be ended. If the last save point for the session was ended then the transaction will optionally be flushed to the transaction log file and the session will exit the transaction.

On failure, the transactional state of the session will remain unchanged. No change to the database state will occur. The application should call [JetRollback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetrollback-function) to abort the transaction.

#### Remarks

There must be one call to **JetCommitTransaction** or [JetRollback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetrollback-function) to match every call to [JetBeginTransaction](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbegintransaction-function) for a given session.

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

#### See Also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JetBeginTransaction](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbegintransaction-function)
[JetCommitTransaction]()
[JetRollback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetrollback-function)
[JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopservice-function)