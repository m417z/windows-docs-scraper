# JetGetTableIndexInfo Function

_**Applies to:** Windows | Windows Server_

## JetGetTableIndexInfo Function

The **JetGetTableIndexInfo** function retrieves information about an index.

```cpp
    JET_ERR JET_API JetGetTableIndexInfo(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid,
      __in          const tchar* szIndexName,
      __out         void* pvResult,
      __in          unsigned long cbResult,
      __in          unsigned long InfoLevel
    );
```

### Parameters

*sesid*

The database session context to use for the API call.

*tableid*

The database table that contains the index that holds the needed information.

*szIndexName*

The name of the index that contains information that will be retrieved.

*pvResult*

Pointer to a buffer which will receive the information. The buffer should be aligned to hold the type required. The type of the buffer is dependent on the *InfoLevel* parameter.

*cbResult*

The size, in bytes, of the buffer passed in the *pvResult* parameter.

*InfoLevel*

Specifies which information will be stored in *pvResult*. The valid values are:

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

JET_IdxInfoLCID

|

*pvResult* is interpreted as an LCID. On success, the LCID holds the Locale Identifier of the index. On failure, the contents of *pvBuffer* are undefined.

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

JET_IdxInfoLangid

|

JET_IdxInfoLangid is deprecated. Use JET_IdxInfoLCID instead, and the [LANGIDFROMLCID](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-langidfromlcid) macro instead.

|
|

JET_IdxInfoCount

|

*pvResult* is interpreted as a ULONG. On success, the ULONG holds the count of indexes on the specified table. *szIndexName* is ignored. On failure, the contents of *pvBuffer* are undefined.

|
|

JET_IdxInfoVarSegMac

|

*pvResult* is interpreted as a USHORT. On success, the USHORT holds the value of *cbVarSegMac* used when the index was created. See [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) for a description of *cbVarSegMac*. On failure, the contents of *pvBuffer* are undefined.

|
|

JET_IdxInfoIndexId

|

*pvResult* is interpreted as a [JET_INDEXID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269327(v=exchg.10).md). On success, the [JET_INDEXID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269327(v=exchg.10).md) structure receives information about the index. On failure, the contents of *pvBuffer* are undefined.

|
|

JET_IdxInfoKeyMost

|

*pvResult* is interpreted as a USHORT. On success, the USHORT holds the value of cbKeyMost used when the index was created. See the [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) structure for a description of cbKeyMost. On failure, the contents of *pvBuffer* are undefined.

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

[JetGetIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetindexinfo-function) and **JetGetTableIndexInfo** retrieve identical information about an index. The difference is in how the table is specified. [JetGetIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetindexinfo-function) expects a database (*dbid*) and name of a table (*szTableName*), while **JetGetTableIndexInfo** expects a table identifier (*tableid*).

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

Implemented as **JetGetTableIndexInfoW** (Unicode) and **JetGetTableIndexInfoA** (ANSI).

|

#### See Also

[JET_COLUMNID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columnid)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexcreate-structure)
[JET_INDEXID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexid-structure)
[JetGetIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetindexinfo-function)