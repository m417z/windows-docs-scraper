# JetCloseDatabase Function

_**Applies to:** Windows | Windows Server_

## JetCloseDatabase Function

The **JetCloseDatabase** function closes a database file that was previously opened with [JetOpenDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopendatabase-function).

```cpp
    JET_ERR JET_API JetCloseDatabase(
      __in          JET_SESID sesid,
      __in          JET_DBID dbid,
      __in          JET_GRBIT grbit
    );
```

### Parameters

*sesid*

The database session context that will be used for the API call.

*dbid*

The database to be closed.

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

JET_errDatabaseNotFound

|

The database was not previously opened.

|
|

JET_errInvalidDatabaseId

|

The *dbid* parameter was not a valid database identifier.

|
|

JET_errSuccess

|

The operation completed successfully.

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

#### See Also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JetCreateDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatedatabase-function)
[JetCreateDatabase2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatedatabase2-function)
[JetOpenDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopendatabase-function)