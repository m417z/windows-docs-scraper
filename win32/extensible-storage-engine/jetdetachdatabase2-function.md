# JetDetachDatabase2 Function

_**Applies to:** Windows | Windows Server_

## JetDetachDatabase2 Function

The **JetDetachDatabase2** function releases a database file that was previously attached to a database session.

**Windows XP:** **JetDetachDatabase2** is introduced in Windows XP.

```cpp
    JET_ERR JET_API JetDetachDatabase2(
      __in          JET_SESID sesid,
      __in          const tchar* szFilename,
      __in          JET_GRBIT grbit
    );
```

### Parameters

*sesid*

The database session context to use for the API call.

*szFilename*

The name of the database to detach. If *szFilename* is **NULL** or an empty string, all databases attached to *sesid* will be detached.

*grbit*

A group of bits specifying zero or more of the following options.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitForceCloseAndDetach

|

Forces the database to be closed and detached. If JET_bitForceCloseAndDetach is not supported, JET_errForceDetachNotAllowed will be returned.

|
|

JET_bitForceDetach

|

Forces the database to be detached. If JET_bitForceDetach is not supported, JET_errForceDetachNotAllowed will be returned.

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

JET_errBackupInProgress

|

The database is being backed up, and cannot be detached.

|
|

JET_errDatabaseInUse

|

The database has been opened by [JetOpenDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269299(v=exchg.10).md). Databases must be closed prior to detaching.

|
|

JET_errDatabaseNotFound

|

The database was not previously attached (See [JetAttachDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294074(v=exchg.10).md) or [JetAttachDatabase2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269322(v=exchg.10).md)).

|
|

JET_errForceDetachNotAllowed

|

JET_bitForceDetach is not supported.

|
|

JET_errInTransaction

|

An attempt was made to detach a database while in a transaction.

|

#### Remarks

If an attached database was opened (with [JetAttachDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetattachdatabase-function)), it must be closed with [JetCloseDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosedatabase-function) prior to detaching.

Windows 2000 only: Databases which have not been detached prior to calling [JetTerm](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetterm-function) will automatically be re-attached when [JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit-function) is next called.

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

Implemented as **JetDetachDatabase2W** (Unicode) and **JetDetachDatabase2A** (ANSI).

|

#### See Also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JetAttachDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetattachdatabase-function)
[JetAttachDatabase2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetattachdatabase2-function)
[JetCloseDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosedatabase-function)
[JetCreateDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatedatabase-function)
[JetCreateDatabase2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatedatabase2-function)
[JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit-function)
[JetOpenDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopendatabase-function)
[JetTerm](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetterm-function)