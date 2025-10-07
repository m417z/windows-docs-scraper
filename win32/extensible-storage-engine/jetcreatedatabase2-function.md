# JetCreateDatabase2 Function

_**Applies to:** Windows | Windows Server_

## JetCreateDatabase2 Function

The **JetCreateDatabase2** function creates and attaches a database file to be used with the ESE database engine with a maximum database size specified. Calling **JetCreateDatabase2** with *cpgDatabaseSizeMax* set to zero is identical to calling [JetCreateDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatedatabase-function) with *szConnect* set to NULL. Currently up to seven databases can be created per instance.

```cpp
    JET_ERR JET_API JetCreateDatabase2(
      __in          JET_SESID sesid,
      __in          const tchar* szFilename,
      __in          const unsigned long cpgDatabaseSizeMax,
      __out         JET_DBID* pdbid,
      __in          JET_GRBIT grbit
    );
```

### Parameters

*sesid*

The database session context to use for the API call.

*szFilename*

The name of the database to be created.

*cpgDatabaseSizeMax*

The maximum size, in database pages, for the database. The default database page size is 4 kilobytes, and can be changed with [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function) prior to creating a database.

Passing zero means that there is no maximum enforced by the database engine.

*pdbid*

Pointer to a buffer that, on a successful call, contains the identifier of the database. On failure, the value is undefined.

*grbit*

A group of bits specifying zero or more of the following options.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitDbOverwriteExisting

|

By default, if [JetCreateDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269212(v=exchg.10).md) or **JetCreateDatabase2** is called and the database already exists, the API call will fail and the original database will not be overwritten. JET_bitDbOverwriteExisting changes this behavior, and the old database will be overwritten with a new one. Windows XP and later.

|
|

JET_bitDbRecoveryOff

|

JET_bitDbRecoveryOff turns off logging. Setting this bit loses the ability to replay log files and recover the database to a consistent usable state after a catastrophic event.

|
|

JET_bitDbShadowingOff

|

Setting JET_bitDbShadowingOff will disable the duplication of some internal database structures (shadowing). The duplication of these structures is done for resiliency, so setting JET_bitDbShadowingOff will remove that resiliency.

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

JET_errDatabaseDuplicate

|

The database named in *szFilename* already exists. When this error is returned, the database does not get attached.

|
|

JET_errDatabaseInUse

|

Can be returned if exclusive access was requested, but could not be granted, or if another session has already opened the database exclusively.

|
|

JET_errDatabaseInvalidPages

|

Returned when *cpgDatabaseSizeMax* is larger than the maximum number of pages allowed in a database. The current maximum is 2147483646 (0x7ffffffe).

|
|

JET_errDatabaseInvalidPath

|

An invalid path was given in *szFilename*. *szFilename* must be non-NULL. By default, *szFilename* must point to a directory that exists. The path will be created if *JET_paramCreatePathIfNotExist* is set (See [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294044(v=exchg.10).md)).

|
|

JET_errDatabaseLocked

|

Indicates that another session has already opened the database exclusively (using JET_bitDbExclusive).

|
|

JET_errDatabaseNotFound

|

The database was not previously attached (See [JetAttachDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294074(v=exchg.10).md)).

|
|

JET_errDatabaseSharingViolation

|

The database file has already been attached by a different session.

|
|

JET_errInTransaction

|

An attempt was made to create a database while in a transaction.

|
|

JET_errInvalidDatabase

|

An attempt was made to open a file that is not a valid database file.

|
|

JET_errOneDatabasePerSession

|

An attempt was made to open more than one database, and JET_paramOneDatabasePerSession was set. See [System Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294139(v=exchg.10).md).

|
|

JET_errOutOfMemory

|

The system ran low on resources.

|
|

JET_errTooManyAttachedDatabases

|

Only a finite number of database can be attached per instance. The limit is currently seven databases per instance.

|
|

JET_wrnDatabaseAttached

|

A nonfatal warning indicating that the database file has already been attached by this session.

|
|

JET_wrnFileOpenReadOnly

|

JET_wrnFileOpenReadOnly indicates that the file was attached read-only, but [JetCreateDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269212(v=exchg.10).md) did not pass JET_bitDbReadOnly. The database is still opened with read-only access.

|

#### Remarks

If the database specified in *szFilename* exists and JET_bitDbOverwriteExisting was not passed in, the API call will fail. If JET_bitDbOverwriteExisting was passed in, the old database file will be deleted first.

If the API creates a database file and then hits another error, it will clean up and delete the file.

**JetCreateDatabase2** will implicitly open the database. It is not necessary to subsequently call [JetOpenDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopendatabase-function).

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

Implemented as **JetCreateDatabase2W** (Unicode) and **JetCreateDatabase2A** (ANSI).

|

#### See Also

[Extensible Storage Engine Files](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-files)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_DBID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-dbid)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JetAttachDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetattachdatabase-function)
[JetCloseDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosedatabase-function)
[JetCreateDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatedatabase-function)
[JetOpenDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopendatabase-function)
[JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function)
[System Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-system-parameters)