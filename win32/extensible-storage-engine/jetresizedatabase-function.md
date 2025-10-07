# JetResizeDatabase Function

_**Applies to:** Windows | Windows Server_

The **JetResizeDatabase** function extends or shrinks the size of a database that is currently open.

The **JetResizeDatabase** function was introduced in the Windows 8 operating system.

``` c++
JET_ERR JET_API JetResizeDatabase(
  __in          JET_SESID sesid,
  __in          JET_DBID dbid,
  __in          unsigned long cpg,
  __out         unsigned long* pcpgActual,
  __in          const JET_GRBIT grbit
);
```

### Parameters

*sesid*

The database session context to use for the API call.

*dbid*

The database that will be extended.

*cpg*

The requested size of the database, in pages.

*pcpgActual*

A pointer to a number that receives the size of the database, in pages, after the API call. If the API call fails, the contents of *pcpgActual* parameter are undefined.

*grbit*

A group of bits that specifies zero or more of the values listed in the following table.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitResizeDatabaseOnlyGrow

|

Only grow the database. If the resize call would shrink the database, do nothing.

|

### Return value

This function returns the [JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err) datatype with one of the return codes listed in the following table. For more information about the possible Extensible Storage Engine (ESE) errors, see [Extensible Storage Engine Errors](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-errors) and [Error Handling Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/error-handling-parameters).

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

A file-related error was returned by the [JetSetDatabaseSize](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269242(v=exchg.10).md) function. For more information about other file-related errors that might be returned, see [JetSetDatabaseSize](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269242(v=exchg.10).md).

|

#### Remarks

If the **JetResizeDatabase** function is called prior to inserting large amounts of data, the database file will be grown in one operation. This will reduce the likelihood of the database file becoming fragmented at the file system level, and also reduce the number of times the database file has to be grown. Growing the database file once can be faster than growing it several times.

To set the size of a database that is not opened, see [JetSetDatabaseSize](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetdatabasesize-function).

The file size might not match the number of pages that are returned in the *pcpgReal* parameter. Two additional reserved pages might not be counted in the *pcpgReal* parameter.

#### Requirements

| Requirement | Value |
|------------|----------|
|

**Client**

|

Requires Windows 8.

|
|

**Server**

|

Requires Windows Server 2012.

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

#### See also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JET_OBJECTINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-objectinfo-structure)
[JET_OBJECTLIST](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-objectlist-structure)
[JetSetDatabaseSize](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetdatabasesize-function)