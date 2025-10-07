# JetSetDatabaseSize Function

_**Applies to:** Windows | Windows Server_

## JetSetDatabaseSize Function

The **JetSetDatabaseSize** function sets the size of an unopened database file.

```cpp
    JET_ERR JET_API JetSetDatabaseSize(
      __in          JET_SESID sesid,
      __in          JET_PCSTR szDatabaseName,
      __in          unsigned long cpg,
      __out         unsigned long* pcpgReal
    );
```

### Parameters

*sesid*

Identifies the database session context to use for the API call.

*szDatabaseName*

Identifies the name of the database file whose size is to be altered.

*cpg*

Specifies the desired size of the database, in pages.

*pcpgReal*

Pointer to a number that receives the size of the database, in pages, after the API call. If the API call was unsuccessful, the contents of *pcpgReal* are undefined.

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

JET_errDatabaseInconsistent\
JET_errDatabaseDirtyShutdown

|

JET_errDatabaseInconsistent and JET_errDatabaseDirtyShutdown are the same numeric value. The database whose size is to be adjusted must be in a clean shutdown, known as a consistent state. An inconsistent database is not corrupted, but it requires log files to be replayed.

|
|

JET_errDatabaseInvalidPath

|

*szDatabaseName* must not be an empty, non-NULL string.

|
|

JET_errDiskFull

|

There is insufficient free space on the volume to perform the grow operation. **JetSetDatabaseSize** may also return many file-related errors, including, but not limited to:

* JET_errDiskIO
* JET_errFileNotFound
* JET_errInvalidPath
* JET_errFileAccessDenied
* JET_errOutOfFileHandles

|
|

JET_errInvalidParameter

|

One of the reasons this error may be returned is if *cpg* does meet the minimum database size. The current minimum database size is 256 pages.

|
|

JET_errOutOfMemory

|

The system is low on memory resources.

|

#### Remarks

If **JetSetDatabaseSize** is called prior to inserting large amounts of data, the database file will be grown in one operation. This will reduce the likelihood of the database file becoming fragmented at the file system level, and also reduce the number of times the database file has to be grown. Growing the database file once can be faster than growing it several times.

Only growing the file is currently supported. To shrink a file, use the defragmentation feature of the esentutl.exe utility program.

If *cpg* is smaller than the current size of the database, the operation will be ignored. If *cpg* is less than the minimum database size (currently 256 pages), it will return JET_errInvalidParameter.

To set the size of a database that is opened, see [JetGrowDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgrowdatabase-function).

The file size may not match the number of pages returned in *pcpgReal*. There are two additional reserved pages that may not be counted in *pcpgReal*.

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

Implemented as **JetSetDatabaseSizeW** (Unicode) and **JetSetDatabaseSizeA** (ANSI).

|

#### See Also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JET_OBJECTINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-objectinfo-structure)
[JET_OBJECTLIST](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-objectlist-structure)
[JetGrowDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgrowdatabase-function)