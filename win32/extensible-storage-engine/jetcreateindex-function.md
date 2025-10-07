# JetCreateIndex Function

_**Applies to:** Windows | Windows Server_

## JetCreateIndex Function

The **JetCreateIndex** function enables you to create an index of data in an Extensible Storage Engine (ESE) database, which you can use to locate specific data quickly.

```cpp
    JET_ERR JET_API JetCreateIndex(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid,
      __in          JET_PCSTR szIndexName,
      __in          JET_GRBIT grbit,
      __in          const tchar* szKey,
      __in          unsigned long cbKey,
      __in          unsigned long lDensity
    );
```

### Parameters

*sesid*

The database session context to use for a particular API call.

*tableid*

The table that an index will be created for.

*szIndexName*

A pointer to a null-terminated string that specifies the name of the index to be created.

The index name must conform to the following guidelines:

  - It must contain fewer characters than JET_cbNameMost, not including the terminating null character.

  - It must contain only characters from the following categories: 0 through 9, A through Z, a through z, and all punctuation characters except for "\!" (exclamation point), "," (comma), "\[" (opening bracket), and "\]" (closing bracket) — that is, the ASCII characters 0x20, 0x22 through 0x2d, 0x2f through 0x5a, 0x5c, and 0x5d through 0x7f.

  - It must not begin with a space.

  - It must contain at least one non-space character.

*grbit*

A group of bits that contains the options to be used for a particular call. This parameter can include zero or more of the options found in the [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexcreate-structure) structure.

*szKey*

A pointer to a double null-terminated string of null-delimited tokens.

For more information about this parameter, see the [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexcreate-structure) structure.

*cbKey*

The length, in bytes, of the *szKey* parameter, including the two terminating null characters.

*lDensity*

The percentage density of the initial index B+ tree.

For more information about this parameter, see the [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexcreate-structure) structure.

### Return Value

This function returns the [JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err) data type with one of the return codes listed in the following table. For more information about the possible ESE errors, see [Extensible Storage Engine Errors](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-errors) and [Error Handling Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/error-handling-parameters).

|

Return code

|

Meaning

|
|--------------------|----------------|
|

JET_errSuccess

|

The operation completed successfully.

|

For a list of additional errors that can be returned by the **JetCreateIndex** function, see [JetCreateIndex2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateindex2-function).

#### Remarks

Calling the **JetCreateIndex** function is identical to calling the [JetCreateIndex2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateindex2-function) function with a [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexcreate-structure) structure containing the same settings as the parameters of **JetCreateIndex**, and a *cIndexCreate* parameter equal to 1. For the fields of the [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexcreate-structure) structure that do not have corresponding parameters in **JetCreateIndex**, a value of 0 is assumed.

Note that **JetCreateIndex** has been superseded by [JetCreateIndex2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateindex2-function).

#### Requirements

| Requirement | Value |
|------------|----------|
|

Client

|

Requires Windows Vista, Windows XP, or Windows 2000 Professional.

|
|

Server

|

Requires Windows Server 2008, Windows Server 2003, or Windows 2000 Server.

|
|

Header

|

Is declared in Esent.h.

|
|

Library

|

Uses ESENT.lib.

|
|

DLL

|

Requires ESENT.dll.

|
|

Unicode

|

Is implemented as **JetCreateIndexW** (Unicode) and **JetCreateIndexA** (ANSI).

|

#### See Also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexcreate-structure)
[JetCreateIndex2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateindex2-function)
[JetCreateTableColumnIndex](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatetablecolumnindex-function)
[JetCreateTableColumnIndex2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatetablecolumnindex2-function)