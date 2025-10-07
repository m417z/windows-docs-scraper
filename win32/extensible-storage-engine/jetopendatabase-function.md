# JetOpenDatabase Function

_**Applies to:** Windows | Windows Server_

## JetOpenDatabase Function

The **JetOpenDatabase** function opens a previously attached database, using the [JetAttachDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetattachdatabase-function) or [JetAttachDatabase2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetattachdatabase2-function) functions, for use with a database session. This function can be called multiple times for the same database.

```cpp
    JET_ERR JET_API JetOpenDatabase(
      __in          JET_SESID sesid,
      __in          const tchar* szFilename,
      __in_opt      const tchar* szConnect,
      __out         JET_DBID* pdbid,
      __in          JET_GRBIT grbit
    );
```

### Parameters

*sesid*

The database session context to use for the API call.

*szFilename*

The name of the database to open.

*szConnect*

Reserved. Set to NULL.

*pdbid*

Pointer to a buffer that, on a successful call, contains the identifier of the database. If the call fails, the value is undefined.

*grbit*

A group of bits that specify zero or more of the following options.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitDbExclusive

|

Allows only a single session to attach a database. Normally, several sessions can open a database.

|
|

JET_bitDbReadOnly

|

Prevents modifications to the database.

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

JET_errDatabaseInUse

|

Exclusive access was requested, but could not be granted.

|
|

JET_errDatabaseInvalidPath

|

An invalid path was given in *szFilename*. *szFilename* must be non-NULL and refer to a valid file.

|
|

JET_errDatabaseLocked

|

Another session has already opened the database exclusively (using JET_bitDbExclusive).

|
|

JET_errDatabaseNotFound

|

The database was not previously attached (See [JetAttachDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294074(v=exchg.10).md)).

|
|

JET_errInvalidDatabase

|

An attempt was made to open a file that is not a valid database file.

|
|

JET_errOneDatabasePerSession

|

An attempt was made to open more than one database, and [JET_paramOneDatabasePerSession](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269337(v=exchg.10).md) was set. For more information, see [System Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294139(v=exchg.10).md).

|
|

JET_wrnFileOpenReadOnly

|

The file was attached as read-only, but **JetOpenDatabase** did not pass JET_bitDbReadOnly. The database is still opened with read-only access.

|

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

Implemented as **JetOpenDatabaseW** (Unicode) and **JetOpenDatabaseA** (ANSI).

|

#### See Also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JetAttachDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetattachdatabase-function)
[JetAttachDatabase2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetattachdatabase2-function)
[JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function)
[System Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-system-parameters)