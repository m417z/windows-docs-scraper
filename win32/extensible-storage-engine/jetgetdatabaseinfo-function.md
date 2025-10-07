# JetGetDatabaseInfo Function

_**Applies to:** Windows | Windows Server_

## JetGetDatabaseInfo Function

The **JetGetDatabaseInfo** function retrieves various types of information about the database. This API can be called while a database is attached or online (with **JetGetDatabaseInfo**) or while the database or database engine is offline (with [JetGetDatabaseFileInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetdatabasefileinfo-function)).

```cpp
    JET_ERR JET_API JetGetDatabaseInfo(
      __in          JET_SESID sesid,
      __in          JET_DBID dbid,
      __out         void* pvResult,
      __in          unsigned long cbMax,
      __in          unsigned long InfoLevel
    );
```

### Parameters

*sesid*

The session to use for this call.

*dbid*

The [JET_DBID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-dbid) for the database to retrieve the information from.

*pvResult*

Pointer to a buffer which will receive the specified information. The size of the buffer, in bytes, is passed in *cbMax*.

On failure the contents of *pvResult* are undefined.

The information stored in *pvResult* depends on *InfoLevel*.

*cbMax*

The size, in bytes, of the buffer that was passed in *pvResult*.

*InfoLevel*

*InfoLevel* specifies which type of information should be retrieved about the specified database. It affects how *pvResult* is interpreted. Some *InfoLevel* are available only in the offline ([JetGetDatabaseFileInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetdatabasefileinfo-function)) or online (**JetGetDatabaseInfo**) version of the API.

If the *pvResult* buffer provided is too small, either JET_errInvalidBufferSize or JET_errBufferTooSmall will be returned depending on the *InfoLevel*.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_DbInfoCollate

|

Not yet supported and return default values. Do not use.

|
|

JET_DbInfoConnect

|

These *InfoLevels* are deprecated and are not currently supported. Do not use.

|
|

JET_DbInfoCountry

|

Not yet supported and return default values. Do not use.

|
|

JET_DbInfoCp

|

Not yet supported and return default values. Do not use.

|
|

JET_DbInfoFilename

|

*pvResult* will be interpreted as a string buffer (char *). A MAX_PATH buffer is suggested, however not required. If the buffer is not long enough, JET_errBufferTooSmall will be returned. The string will be populated with the path of the database for this DBID.

|
|

JET_DbInfoFilesize

|

*pvResult* will be interpreted as a DWORD (4 bytes). Returns the size of the database in pages.

|
|

JET_DbInfoIsam

|

These *InfoLevels* are deprecated and are not currently supported. Do not use.

|
|

JET_DbInfoLCID

|

(Windows XP and later) This *InfoLevel* was originally specified as: JET_DbInfoLangid (Windows 2000)

*pvResult* will be interpreted as a long. This returns the Locale identifier (LCID) associate with this database.

|
|

JET_DbInfoMisc

|

*pvResult* will be interpreted as a [JET_DBINFOMISC](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294147(v=exchg.10).md). The [JET_DBINFOMISC](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294147(v=exchg.10).md) structure will be populated with information pertaining to the database specified.

|
|

JET_DbInfoOptions

|

*pvResult* will be interpreted as a [JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294066(v=exchg.10).md) (DWORD). This returns whether the database is opened in exclusive mode. If the database is in exclusive mode JET_bitDbExclusive will be set in the [JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294066(v=exchg.10).md) provided, otherwise zero is set. Note other database *grbit* options for [JetAttachDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294074(v=exchg.10).md) and [JetOpenDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269299(v=exchg.10).md) are not returned.

|
|

JET_DbInfoPageSize

|

Available only on Windows XP and later. *pvResult* will be interpreted as an unsigned long. This will return the page size of the database in bytes.

|
|

JET_DbInfoSpaceAvailable

|

*pvResult* will be interpreted as a DWORD. This returns the available space for the database in pages.

|
|

JET_DbInfoSpaceOwned

|

*pvResult* will be interpreted as a DWORD. This returns the owned space for the database in pages.

|
|

JET_DbInfoTransactions

|

*pvResult* will be interpreted as a long. This will return one greater than the maximum level to which transactions can be nested. If [JetBeginTransaction](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294083(v=exchg.10).md) is called (in a nesting fashion, that is, on the same session, without a commit or rollback) as many times as this value, on the last call JET_errTransTooDeep will be returned from [JetBeginTransaction](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294083(v=exchg.10).md). Note the value in Windows 2000, Windows XP, and Windows Server 2003 is 7.

|
|

JET_DbInfoVersion

|

*pvResult* will be interpreted as a long. This returns the database engine's native major version. This value is 0x620 for Windows 2000, Windows XP, and Windows Server 2003.

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

JET_errBufferTooSmall

|

The size of the buffer given in *cbMax* was too small (or not correct) to hold the desired information.

|
|

JET_errFeatureNotAvailable

|

The *InfoLevel* requested was JET_DbInfoIsam. This is not supported.

|
|

JET_errInvalidBufferSize

|

The size of the buffer given in *cbMax* was too small (or not correct) to hold the desired information.

|
|

JET_errInvalidParameter

|

One of the parameters provided contained an unexpected value or contained a value that did not make sense when combined with the value of another parameter. This error will be returned by **JetGetDatabaseInfo** when the [JET_DBID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269248(v=exchg.10).md) provided is not a valid (attached) database. This error will be returned by [JetGetDatabaseFileInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269239(v=exchg.10).md) and **JetGetDatabaseInfo** when an *InfoLevel* requested is not supported by that version of the function.

|

On success, the requested data will be returned in the output buffer.

On failure, the output buffer will be in an undefined state.

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

Implemented as **JetGetDatabaseInfoW** (Unicode) and **JetGetDatabaseInfoA** (ANSI).

|

#### See Also

[JET_DBID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-dbid)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_DBINFOMISC](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-dbinfomisc-structure)
[JET_DBINFOUPGRADE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-dbinfoupgrade-structure)
[JetGetDatabaseFileInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetdatabasefileinfo-function)