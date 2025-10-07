# JetAttachDatabase2 Function

_**Applies to:** Windows | Windows Server_

## JetAttachDatabase2 Function

The **JetAttachDatabase2** function attaches a database file for use with a database instance and specifies a maximum size for that database. In order to use the database, it will need to be subsequently opened with [JetOpenDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopendatabase-function).

```cpp
    JET_ERR JET_API JetAttachDatabase2(
      __in          JET_SESID sesid,
      __in          const tchar* szFilename,
      __in          const unsigned long cpgDatabaseSizeMax,
      __in          JET_GRBIT grbit
    );
```

### Parameters

*sesid*

The database session context that will be used for the API call.

*szFilename*

The name of the database to attach.

*cpgDatabaseSizeMax*

The maximum size, in database pages, for database. The default database page size is 4 kilobytes, which can be changed using the [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function) function prior to creating a database.

Passing zero means that there is no maximum enforced by the database engine.

*grbit*

A group of bits that contain the options to be used for this call, which include zero or more of the following:

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

JET_bitDbReadOnly

|

Prevents modifications to the database.

|
|

JET_bitDbUpgrade

|

Reserved for future use.

|

### Return Value

The function returns one of the [JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err) error codes. The following are the most commonly returned. (For a complete list of errors for this API, see [Extensible Storage Engine Error Codes](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-error-codes).)

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

The database file is detached using [JetDetachDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdetachdatabase-function) or [JetDetachDatabase2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdetachdatabase2-function).

See [JetAttachDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetattachdatabase-function) for remarks.

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

Implemented as **JetAttachDatabase2W** (Unicode) and **JetAttachDatabase2A** (ANSI).

|

#### See Also

[Extensible Storage Engine Files](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-files)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JetAttachDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetattachdatabase-function)
[JetCreateDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatedatabase-function)
[JetOpenDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopendatabase-function)
[JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function)