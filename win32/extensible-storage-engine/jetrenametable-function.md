# JetRenameTable Function

_**Applies to:** Windows | Windows Server_

## JetRenameTable Function

The **JetRenameTable** function can be used to change the name of an existing table.

```cpp
    JET_ERR JET_API JetRenameTable(
      __in          JET_SESID sesid,
      __in          JET_DBID dbid,
      __in          const tchar* szName,
      __in          const tchar* szNameNew
    );
```

### Parameters

*sesid*

The session to use for this call.

*dbid*

The database to use for this call.

*szName*

The current name of the table that will be renamed.

*szNameNew*

The new name for the table that will be renamed.

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

It is not possible to complete the operation because the instance associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data. This error will only be returned by Windows XP and later releases.

|
|

JET_errInvalidDatabase

|

The specified database was invalid.

This error is only returned in Windows 2000 when a table rename operation is attempted on the temporary database. JET_errInvalidDatabaseId is returned for this case in later releases.

|
|

JET_errInvalidDatabaseId

|

The specified database ID was invalid.

|
|

JET_errInvalidName

|

One of the specified object names was invalid. All object names must conform to the same set of rules. These rules are as follows:

* Object names must be composed of ASCII characters.
* Object names must be at least one character in length.
* Object names may not exceed JET_cbNameMost (64) characters in length.
* Object names may not begin with a space.
* Object names may not contain ASCII control characters (0x00 through 0x1F).
* Object names may not contain an exclamation point (!), period (.), left bracket ([), or right bracket (]) character - once validated, only the portion of the string up to the first space (if any) will be used for the object name. This effectively means that object names may not contain a space either.

|
|

JET_errInvalidParameter

|

One of the parameters provided contained an unexpected value or contained a value that did not make sense when combined with the value of another parameter. This can happen for **JetRenameTable** when:

* *szName* is NULL.
* *szNameNew* is NULL.

|
|

JET_errNotInitialized

|

It is not possible to complete the operation because the instance associated with the session has not been initialized yet.

|
|

JET_errObjectNotFound

|

This specified table does not exist for this database.

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

An update cannot be done while inside the scope of a read-only transaction. A read-only transaction is a transaction that has been started using a call to [JetBeginTransaction2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269268(v=exchg.10).md) with JET_bitTransactionReadOnly.

This error will only be returned by Windows XP and later releases.

|

On success, the name of the specified table in the given database is permanently changed to the new name.

On failure, no change to the database state will occur.

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

Implemented as **JetRenameTableW** (Unicode) and **JetRenameTableA** (ANSI).

|

#### See Also

[JET_DBID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-dbid)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JetBeginTransaction2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbegintransaction2-function)