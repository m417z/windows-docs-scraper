# JetGetDatabaseFileInfo Function

_**Applies to:** Windows | Windows Server_

## JetGetDatabaseFileInfo Function

The **JetGetDatabaseFileInfo** function retrieves various types of information about the database. This API can be called while a database is attached or online (with [JetGetDatabaseInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetdatabaseinfo-function)) or while the database or database engine is offline (with **JetGetDatabaseFileInfo**).

```cpp
    JET_ERR JET_API JetGetDatabaseFileInfo(
      __in          const tchar* szDatabaseName,
      __out         void* pvResult,
      __in          unsigned long cbMax,
      __in          unsigned long InfoLevel
    );
```

### Parameters

*szDatabaseName*

The path of the database from which to retrieve the information.

*pvResult*

Pointer to a buffer that will receive the specified information. The size of the buffer, in bytes, is passed in *cbMax*.

If this function fails, the contents of *pvResult* are undefined.

The information stored in *pvResult* depends on *InfoLevel*.

*cbMax*

The size, in bytes, of the buffer passed in *pvResult*.

*InfoLevel*

*InfoLevel* specifies which type of information should be retrieved about the specified database. It affects how *pvResult* is interpreted. Some *InfoLevel* objects are available only in the offline (**JetGetDatabaseFileInfo**) or online ([JetGetDatabaseInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetdatabaseinfo-function)) version of the API.

If the *pvResult* buffer provided is too small, either JET_errInvalidBufferSize or JET_errBufferTooSmall will be returned, depending on the *InfoLevel*.

| Value | Meaning |
| --- | --- |
| JET_DbInfoFilesize | *pvResult* will be interpreted as a QWORD (8 bytes). Returns the size of the database in bytes. |
| JET_DbInfoUpgrade | *pvResult* will be interpreted as a [JET_DBINFOUPGRADE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294114(v=exchg.10).md). The [JET_DBINFOUPGRADE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294114(v=exchg.10).md) structure will be populated with information pertaining to the specified database. |
| JET_DbInfoMisc | *pvResult* will be interpreted as a [JET_DBINFOMISC](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294147(v=exchg.10).md). The [JET_DBINFOMISC](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294147(v=exchg.10).md) structure will be populated with information pertaining to the specified database. |
| JET_DbInfoDBInUse | *pvResult* will be interpreted as a BOOL (4 bytes). This will return whether the database engine currently has any open or attached databases.<br><br>**Windows XP:** This value is introduced in Windows XP. |
| JET_DbInfoPageSize | *pvResult* will be interpreted as an unsigned long. This will return the page size of the database in bytes.<br><br>**Windows XP:** This value is introduced in Windows XP. |
| JET_DbInfoCp | These *InfoLevels* are not yet supported and return default values. Do not use these *InfoLevels*. |
| JET_DbInfoCountry | These *InfoLevels* are not yet supported and return default values. Do not use these *InfoLevels*. |
| JET_DbInfoCollate | Same as JET_DbInfoCp. |
| JET_DbInfoIsam | These *InfoLevels* are deprecated and are not currently supported. Do not use these *InfoLevels*. |
| JET_DbInfoConnect | Same as JET_DbInfoIsam. |
| JET_DbInfoFileType | **Windows Vista:** This *InfoLevel* value is introduced in Windows Vista.<br><br>*pvResult* will be treated as a pointer to a DWORD. Returns an enumeration value, indicating what kind of file the engine considers this to be. File types are listed in the following table. For more information about these types of files and their usage to the engine, see [Extensible Storage Engine Files](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294069(v=exchg.10).md).<br><br>\| Value \| Meaning \| \| --- \| --- \| \| JET_filetypeUnknown \| The type of file is unknown, or not an ESE file type. \| \| JET_filetypeDatabase \| The file is a database file. \| \| JET_filetypeLog \| The file is a transaction log file. \| \| JET_filetypeCheckpoint \| The file is a checkpoint file. \| \| JET_filetypeTempDatabase \| The file is a temporary database file. \| |

### Return Value

This function returns the [JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err) datatype with one of the following return codes. For more information about the possible ESE errors, see [Extensible Storage Engine Errors](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-errors) and [Error Handling Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/error-handling-parameters).

| Return code | Description |
| --- | --- |
| JET_errSuccess | The operation completed successfully. |
| JET_errFeatureNotAvailable | The *InfoLevel* requested was JET_DbInfoIsam. This is not supported. |
| JET_errBufferTooSmall | The buffer that is given in *cbMax* is too small for the desired information. |
| JET_errInvalidBufferSize | The buffer that is given in *cbMax* is not the correct size for the desired information. |
| JET_errInvalidParameter | One of the parameters that was provided contained an unexpected value, or the combination of several parameter values yielded an unexpected result. This error will be returned by [JetGetDatabaseInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294076(v=exchg.10).md) when the DBID provided is not a valid (attached) database. This error will be returned by **JetGetDatabaseFileInfo** and [JetGetDatabaseInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294076(v=exchg.10).md) when an *InfoLevel* requested is not supported by that version of the function. |

If this function succeeds, the requested data will be returned in the output buffer.

If this function fails, the output buffer will be in an undefined state.

#### Requirements

|  |  |
| --- | --- |
| **Client** | Requires Windows Vista, Windows XP, or Windows 2000 Professional. |
| **Server** | Requires Windows Server 2008, Windows Server 2003, or Windows 2000 Server. |
| **Header** | Declared in Esent.h. |
| **Library** | Use ESENT.lib. |
| **DLL** | Requires ESENT.dll. |
| **Unicode** | Implemented as **JetGetDatabaseFileInfoW** (Unicode) and **JetGetDatabaseFileInfoA** (ANSI). |

#### See Also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_DBINFOMISC](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-dbinfomisc-structure)
[JET_DBINFOUPGRADE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-dbinfoupgrade-structure)
[JetGetDatabaseInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetdatabaseinfo-function)