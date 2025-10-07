# JetGetIndexInfo Function

_**Applies to:** Windows | Windows Server_

## JetGetIndexInfo Function

The **JetGetIndexInfo** function retrieves information about an index.

```cpp
    JET_ERR JET_API JetGetIndexInfo(
      __in          JET_SESID sesid,
      __in          JET_DBID dbid,
      __in          const tchar* szTableName,
      __in          const tchar* szIndexName,
      __out         void* pvResult,
      __in          unsigned long cbResult,
      __in          unsigned long InfoLevel
    );
```

### Parameters

*sesid*

The database session context to use for the API call.

*dbid*

The database identifier to use for the API call.

*szTableName*

The name of the table containing the index with the information to retrieve.

*szIndexName*

The name of the index with the information to retrieve.

*pvResult*

Pointer to a buffer that will receive the desired information. The buffer should be aligned to hold the type required. The type of the buffer is dependent on the *InfoLevel* parameter.

*cbResult*

The size, in bytes, of the buffer passed as *pvResult*.

*InfoLevel*

The information that will be stored in *pvResult*. The following options can be used for this parameter.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_IdxInfo

|

*pvResult* is interpreted as a [JET_INDEXLIST](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269185(v=exchg.10).md) structure. On success, the [JET_INDEXLIST](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269185(v=exchg.10).md) structure receives information about the index. On failure, the contents of *pvBuffer* are undefined.

|
|

JET_IdxInfoCount

|

*pvResult* is interpreted as a ULONG. On success, the ULONG holds the count of indexes on the specified table. *szIndexName* is ignored. On failure, the contents of *pvBuffer* are undefined.

|
|

JET_IdxInfoIndexId

|

*pvResult* is interpreted as a [JET_INDEXID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269327(v=exchg.10).md). On success, the [JET_INDEXID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269327(v=exchg.10).md) structure receives information about the index. On failure, the contents of *pvBuffer* are undefined.

|
|

JET_IdxInfoLangid

|

JET_IdxInfoLangid is deprecated. Use JET_IdxInfoLCID and the [LANGIDFROMLCID](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-langidfromlcid) macro instead.

|
|

JET_IdxInfoLCID

|

*pvResult* is interpreted as an LCID. On success, the LCID holds the Locale Identifier of the index. On failure, the contents of *pvBuffer* are undefined.

**Windows XP:** JET_IdxInfoLCID is introduced in Windows XP.

|
|

JET_IdxInfoList

|

*pvResult* is interpreted as a [JET_INDEXLIST](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269185(v=exchg.10).md) structure. On success, the [JET_INDEXLIST](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269185(v=exchg.10).md) structure receives information about the index. On failure, the contents of *pvBuffer* are undefined.

|
|

JET_IdxInfoOLC

|

JET_IdxInfoOLC is obsolete.

|
|

JET_IdxInfoResetOLC

|

JET_IdxInfoResetOLC is obsolete.

|
|

JET_IdxInfoSpaceAlloc

|

*pvResult* is interpreted as a ULONG. On success, the ULONG holds the space usage of the index. On failure, the contents of *pvBuffer* are undefined.

|
|

JET_IdxInfoSysTabCursor

|

JET_IdxInfoSysTabCursor is obsolete.

|
|

JET_IdxInfoVarSegMac

|

*pvResult* is interpreted as a USHORT. On success, the USHORT holds the value of *cbVarSegMac* used when the index was created. See [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) for a description of *cbVarSegMac*. On failure, the contents of *pvBuffer* are undefined.

|
|

JET_IdxInfoKeyMost

|

*pvResult* is interpreted as a USHORT. On success, the USHORT holds the value of *cbKeyMost* used when the index was created. See [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) for a description of *cbKeyMost*. On failure, the contents of *pvBuffer* are undefined.

**Windows Vista:** JET_IdxInfoKeyMost is introduced in Windows Vista.

|
|

JET_IdxInfoCreateIndex

|

*pvResult* is interpreted as a [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) structure. On failure, the contents of *pvBuffer* are undefined.

**Windows 7:** JET_IdxInfoCreateIndex is introduced in Windows 7.

|
|

JET_IdxInfoCreateIndex2

|

*pvResult* is interpreted as a [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) structure. On failure, the contents of *pvBuffer* are undefined.

**Windows 7:** JET_IdxInfoCreateIndex2 is introduced in Windows 7.

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

JET_errIndexNotFound

|

The specified index cannot be found in the specified table.

|
|

JET_wrnBufferTruncated

|

The buffer passed in as *pvResult* was too small. The contents of the buffer are undefined.

|

#### Remarks

**JetGetIndexInfo** and [JetGetTableIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgettableindexinfo-function) retrieve identical information about an index. The difference is in how the table is specified. **JetGetIndexInfo** expects a database (*dbid*) and name of a table (*szTableName*), while [JetGetTableIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgettableindexinfo-function) expects a table identifier (*tableid*).

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

Implemented as **JetGetIndexInfoW** (Unicode) and **JetGetIndexInfoA** (ANSI).

|

#### See Also

[JET_COLUMNID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columnid)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexcreate-structure)
[JET_INDEXID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexid-structure)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JetGetTableIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgettableindexinfo-function)