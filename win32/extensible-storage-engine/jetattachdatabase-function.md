# JetAttachDatabase Function

_**Applies to:** Windows | Windows Server_

## JetAttachDatabase Function

The **JetAttachDatabase** function attaches a database file for use with a database instance. In order to use the database, it will need to be subsequently opened with [JetOpenDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopendatabase-function).

```cpp
    JET_ERR JET_API JetAttachDatabase(
      __in          JET_SESID sesid,
      __in          const tchar* szFilename,
      __in          JET_GRBIT grbit
    );
```

### Parameters

*sesid*

The database session context to use for the API call.

*szFilename*

The name of the database to attach.

*grbit*

A group of bits that specify zero or more of the following options.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitDbDeleteCorruptIndexes

|

If [JET_paramEnableIndexChecking](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269337(v=exchg.10).md) has been set, all indexes over Unicode data will be deleted. See the Remarks section for more details.

|
|

JET_bitDbDeleteUnicodeIndexes

|

All indexes over Unicode data will be deleted, regardless of the setting of [JET_paramEnableIndexChecking](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269337(v=exchg.10).md). See the Remarks section for more details.

|
|

JET_bitDbUpgrade

|

Obsolete. Do not use.

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

JET_errBackupInProgress

|

Attaching a database is not allowed during a backup.

|
|

JET_errDatabaseFileReadOnly

|

The database file specified by *szFilename* must be writable. The Read-Only attribute must not be set, and the running process must have sufficient privileges to write to the file.

|
|

JET_errDatabaseInUse

|

The database file is already opened by another process.

|
|

JET_errDatabaseInvalidPath

|

An invalid path was given in *szFilename*. *szFilename* must be non-NULL and refer to a valid path.

|
|

JET_errDatabaseSharingViolation

|

The database file has already been attached by a different session.

|
|

JET_errFileAccessDenied

|

The database engine cannot open the database file. The file may be in use by another process or the caller may not have sufficient privileges to open the file.

|
|

JET_errFileNotFound

|

The file given in *szFilename* does not exist.

|
|

JET_errPrimaryIndexCorrupted

|

There is an error with the primary index. This may be from physical corruption (such as disk or memory corruption). It may also be returned when attaching a database last modified on an older operating system and the primary index is over a column with Unicode data. See the remarks for more information on indexes over Unicode data.

|
|

JET_errSecondaryIndexCorrupted

|

There is an error with a secondary index. This may be from physical corruption (such as disk or memory corruption). It may also be returned when attaching a database last modified on an older operating system and a secondary index is over a column with Unicode data. See the remarks for more information on indexes over Unicode data. Secondary indexes are completely rebuilt when a database is defragmented with an offline utility using the following command: **esentutl -d**.

|
|

JET_errTooManyAttachedDatabases

|

Only a finite number of databases can be attached per instance. The limit is currently seven databases per instance.

|
|

JET_wrnDatabaseAttached

|

A nonfatal warning indicating that the database file has already been attached by this session.

|

#### Remarks

Calling **JetAttachDatabase** is equivalent to calling [JetAttachDatabase2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetattachdatabase2-function) and passing a value of zero, meaning there is no limit, for the *cpgDatabaseSizeMax* parameter.

Attaching a writable database (that is, if JET_bitDbReadOnly was not specified in the *grbit* parameter) will open the file exclusively at the operating system level. No other process will be able open the file. It is possible for multiple processes to attach a single database by opening them in read-only mode.

The database file is detached using [JetDetachDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdetachdatabase-function) or [JetDetachDatabase2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdetachdatabase2-function).

Index-checking parameters

Different versions of Windows normalize Unicode text in different ways. That means indexes built under one version of Windows may not work on other versions.

Prior to Windows Server 2003, when the operating system version changed (including installation of a Service Pack), every index over Unicode data was in a potentially corrupt state.

Indexes created in Windows Server 2003 and later are flagged with the version of Unicode normalization with which they were built. Older indexes contain no version information. Most Unicode normalization changes consist of adding new characters, code points which were previously undefined are now defined and normalize differently. Thus, if binary data is stored in a Unicode column, it will normalize differently as new code points are defined.

As of Windows Server 2003, the ESE database engine tracks Unicode index entries that contain undefined code points. These can be used to fix an index when the set of defined Unicode characters changes.

These parameters control what happens when the ESE database engine attaches to a database that was last used under a different build of the operating system. The operating system version is stamped in the database header.

If [JET_paramEnableIndexChecking](https://learn.microsoft.com/windows/win32/extensible-storage-engine/database-parameters) is set to **TRUE**, and the database contains potentially corrupt indexes:

  - **JetAttachDatabase** will delete the potentially corrupt indexes if *grbit* contains JET_bitDbDeleteCorruptIndexes

  - **JetAttachDatabase**will return an error if *grbit* does not contain JET_bitDbDeleteCorruptIndexes and there are indexes which need deletion.

If [JET_paramEnableIndexChecking](https://learn.microsoft.com/windows/win32/extensible-storage-engine/database-parameters) is set to **FALSE**:

  - **JetAttachDatabase** will ignore potentially corrupt indexes, and return JET_errSuccess (assuming there were no other errors).

Windows Server 2003 and later: If [JET_paramEnableIndexChecking](https://learn.microsoft.com/windows/win32/extensible-storage-engine/database-parameters) has not been reset, the internal fixup table will be used to fixup index entries. This may not fix all index corruptions but will be transparent to the application.

If the database was attached as read-only the index cannot be fixed or deleted. In this case, the API will instead return an error, such as JET_errSecondaryIndexCorrupted or JET_errPrimaryIndexCorrupted.

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

Implemented as **JetAddColumnW** (Unicode) and **JetAddColumnA** (ANSI).

|

#### See Also

[Extensible Storage Engine Files](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-files)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JetAttachDatabase2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetattachdatabase2-function)
[JetCreateDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatedatabase-function)
[JetDetachDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdetachdatabase-function)
[JetDetachDatabase2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdetachdatabase2-function)
[JetOpenDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopendatabase-function)
[JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function)