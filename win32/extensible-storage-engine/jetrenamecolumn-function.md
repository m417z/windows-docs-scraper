# JetRenameColumn Function

_**Applies to:** Windows | Windows Server_

## JetRenameColumn Function

The **JetRenameColumn** function can be used to change the name of an existing column on a table.

**Windows XP:** **JetRenameColumn** is introduced in Windows XP.

```cpp
    JET_ERR JET_API JetRenameColumn(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid,
      __in          JET_PCSTR szName,
      __in          JET_PCSTR szNameNew,
      __in          JET_GRBIT grbit
    );
```

### Parameters

*sesid*

The session to use for this call.

*tableid*

The cursor to use for this call.

*szName*

The current name of the column that will be renamed.

*szNameNew*

The new name for the column that will be renamed.

*grbit*

This parameter must be 0.

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

JET_errColumnNotFound

|

This specified column does not exist for this table.

|
|

JET_errInvalidName

|

One of the specified object names was invalid. All object names must conform to the same set of rules. These rules are as follows:

* Object names must be composed of ASCII characters.
* Object names must be at least one character in length.
* Object names may not exceed JET_cbNameMost (64) characters in length.
* Object names may not begin with a space - object names may not contain ASCII control characters (0x00 through 0x1F).
* Object names may not contain an exclamation point (!), period (.), left bracket ([), or right bracket (]) character.
* Once validated, only the portion of the string up to the first space (if any) will be used for the object name. This effectively means that object names may not contain a space either.

|
|

JET_errInvalidParameter

|

One of the parameters provided contained an unexpected value or contained a value that did not make sense when combined with the value of another parameter. This can happen for **JetRenameColumn** when:

* *szName* is NULL.
* *szNameNew* is NULL.

|
|

JET_errInstanceUnavailable

|

It is not possible to complete the operation because the instance associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data. This error will only be returned by Windows XP and later releases.

|
|

JET_errInTransaction

|

This operation may only be performed when the session is not currently inside a transaction.

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

An update cannot be done while inside the scope of a read-only transaction. A read-only transaction is a transaction that has been started using a call to [JetBeginTransaction2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269268(v=exchg.10).md) with JET_bitTransactionReadOnly. This error will only be returned by Windows XP and later releases.

|

On success, the name of the specified column in the table associated with the cursor is permanently changed to the new name. Any indexes that reference that column will also be updated.

On failure, no change to the database state will occur.

#### Remarks

The column rename operation is unusual because, unlike other schema operations, it is not carried out as a transaction. When a column in a given table is renamed in one session then any other session using that table will see the change immediately, even if they are in a transaction that would prevent that session from seeing any other change made by the session doing the rename operation.

The column ID of a column is not affected by the rename operation.

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

Implemented as **JetRenameColumnW** (Unicode) and **JetRenameColumnA** (ANSI).

|

#### See Also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JetBeginTransaction2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbegintransaction2-function)