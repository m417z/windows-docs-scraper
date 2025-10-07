# JetSetColumnDefaultValue Function

_**Applies to:** Windows | Windows Server_

## JetSetColumnDefaultValue Function

The **JetSetColumnDefaultValue** function can be used to change the default value of an existing column.

```cpp
    JET_ERR JET_API JetSetColumnDefaultValue(
      __in          JET_SESID sesid,
      __in          JET_DBID dbid,
      __in          JET_PCSTR szTableName,
      __in          JET_PCSTR szColumnName,
      __in          const void* pvData,
      __in          const unsigned long cbData,
      __in          const JET_GRBIT grbit
    );
```

### Parameters

*sesid*

The session to use for this call.

*dbid*

The database to use for this call.

*szTableName*

The name of the table containing the column that will be affected.

*szColumnName*

The name of the column whose default value will be changed.

*pvData*

The input buffer containing the new default value.

*cbData*

The size of the input buffer containing the new default value.

*grbit*

Reserved for future use.

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

JET_errColumnIllegalNull

|

Same as JET_errNullInvalid.

|
|

JET_errColumnInUse

|

This specified column is currently in use by an index.

**JetSetColumnDefaultValue** cannot change the default value of a column that is referenced in the definition of an index. This is because doing so could change the contents of the index.

|
|

JET_errColumnNotFound

|

This specified column does not exist for this table.

|
|

JET_errInstanceUnavailable

|

It is not possible to complete the operation because the instance associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data. This error will only be returned by Windows XP and later releases.

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
* Object names may not contain an exclamation point (!), period (.), left bracket ([), or right bracket (]) character.
* Once validated, only the portion of the string up to the first space (if any) will be used for the object name. This means that object names may not contain a space either.

|
|

JET_errNotInitialized

|

It is not possible to complete the operation because the instance associated with the session has not been initialized yet.

|
|

JET_errNullInvalid

|

The column could not be set to NULL. This happens for **JetSetColumnDefaultValue** when:

* *cbData* is zero.
* **pvData** is NULL.

Therefore, it is not possible to set the default value of a column (back) to NULL or to a zero length value.

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

JET_errTableInUse

|

This specified table is in use by another session.

**JetSetColumnDefaultValue** requires exclusive access to a table in order to change the default value of the column for releases prior to Windows Server 2003.

|
|

JET_errTermInProgress

|

It is not possible to complete the operation because the instance associated with the session is being shut down.

|
|

JET_errTransReadOnly

|

It is illegal to attempt an update when inside the scope of a read only transaction. A read only transaction is a transaction that has been started using a call to [JetBeginTransaction2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269268(v=exchg.10).md) with JET_bitTransactionReadOnly. This error will only be returned by Windows XP and later releases.

|
|

JET_errWriteConflict

|

Another session has previously locked the record for update. The update attempted by this session will fail.

|

On success, the default value of the specified column in the given table in the given database is permanently changed to the new default value.

On failure, no change to the database state will occur.

#### Remarks

It is not possible to change the default value of a column in a template table.

The database engine will silently truncate the default value of a column to 255 bytes for long text and long binary columns.

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

Implemented as **JetSetColumnDefaultValueW** (Unicode) and **JetSetColumnDefaultValueA** (ANSI).

|

#### See Also

[JET_DBID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-dbid)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JetBeginTransaction2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbegintransaction2-function)
[JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopservice-function)