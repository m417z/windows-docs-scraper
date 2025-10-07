# JetGrowDatabase Function

_**Applies to:** Windows | Windows Server_

## JetGrowDatabase Function

The **JetGrowDatabase** function extends the size of a database that is currently open.

```cpp
    JET_ERR JET_API JetGrowDatabase(
      __in          JET_SESID sesid,
      __in          JET_DBID dbid,
      __in          unsigned long cpg,
      __in          unsigned long* pcpgReal
    );
```

### Parameters

*sesid*

The database session context to use for the API call.

*dbid*

The database that will be extended.

*cpg*

The desired size of the database, in pages.

*pcpgReal*

Pointer to a number that receives the size of the database, in pages, after the API call. If the API call fails, the contents of *pcpgReal* are undefined.

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

JET_errDiskFull

|

There is insufficient free space on the volume to perform the grow operation.

|
|

JET_errDiskIO

|

A file-related error was returned by [JetSetDatabaseSize](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269242(v=exchg.10).md). For more information about other file-related errors that might be returned, see [JetSetDatabaseSize](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269242(v=exchg.10).md).

|

#### Remarks

If **JetGrowDatabase** is called prior to inserting large amounts of data, the database file will be grown in one operation. This will reduce the likelihood of the database file becoming fragmented at the file system level, and also reduce the number of times the database file has to be grown. Growing the database file once can be faster than growing it several times.

Only growing the file is currently supported. To shrink a file, use the defragmentation feature of the **esentutl.exe** utility program.

To set the size of a database that is not opened, see [JetSetDatabaseSize](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetdatabasesize-function).

The file size might not match the number of pages that are returned in *pcpgReal*. There are two additional reserved pages that might not be counted in *pcpgReal*.

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
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JET_OBJECTINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-objectinfo-structure)
[JET_OBJECTLIST](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-objectlist-structure)
[JetSetDatabaseSize](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetdatabasesize-function)