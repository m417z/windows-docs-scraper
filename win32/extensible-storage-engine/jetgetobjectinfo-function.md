# JetGetObjectInfo Function

_**Applies to:** Windows | Windows Server_

## JetGetObjectInfo Function

The **JetGetObjectInfo** function retrieves information about database objects. Currently, only tables are supported. [JetGetTableInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgettableinfo-function) can be used to fetch more information than **JetGetObjectInfo**.

```cpp
    JET_ERR JET_API JetGetObjectInfo(
      __in          JET_SESID sesid,
      __in          JET_DBID dbid,
      __in          JET_OBJTYP objtyp,
      __in_opt      const tchar* szContainerName,
      __in_opt      const tchar* szObjectName,
      __out         void* pvResult,
      __in          unsigned long cbMax,
      __in          unsigned long InfoLevel
    );
```

### Parameters

*sesid*

The database session context to use.

*dbid*

The database from which the information is retrieved.

*objtyp*

The objects that contain information to be retrieved. Currently, only JET_objtypNil and JET_objtypTable are supported, both of which behave identically. Only tables will be retrieved.

*szContainerName*

This parameter is reserved for future use and passes **NULL**. The name of the types of objects about which to retrieve information.

*szObjectName*

The name of the object that contains information to retrieve. When *InfoLevel* uses the JET_ObjInfoList or JET_ObjInfoListNoStats options to retrieve a list of all objects, this value should be **NULL** or an empty string.

Only table names are currently supported.

*pvResult*

Pointer to a buffer which receives the specified information.

The size of the buffer, in bytes, is passed in *cbMax*. On failure the contents of *pvResult* are undefined.

The information that is stored in *pvResult* depends on *InfoLevel*.

*cbMax*

The size, in bytes, of the buffer passed in *pvResult*.

*InfoLevel*

Specifies which type of information to retrieve for the specified object. It affects how *pvResult* is interpreted.

The following options are available to set for this parameter.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_ObjInfo

|

*pvResult* is interpreted as a [JET_OBJECTINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269353(v=exchg.10).md) structure.

The [JET_OBJECTINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269353(v=exchg.10).md) structure is populated with information pertaining to the object that is named in *szObjectName*.

If the caller does not want to know the number of records and pages for the object, consider using JET_ObjInfoNoStats information level, which might be faster since statistics are not included.

|
|

JET_ObjInfoList

|

*pvResult* is interpreted as a [JET_OBJECTLIST](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269348(v=exchg.10).md) structure. Information about all objects is retrieved. A temporary table will be created, and the information that is necessary to traverse the temporary table is described in the [JET_OBJECTLIST](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269348(v=exchg.10).md) structure. For more information, see [JET_OBJECTLIST](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269348(v=exchg.10).md). If the caller does not want to know the number of records and pages for the object, consider using JET_ObjInfoListNoStats, which might be faster.

|
|

JET_ObjInfoListACM

|

Deprecated and not currently supported.

|
|

JET_ObjInfoListNoStats

|

*pvResult* is interpreted as a [JET_OBJECTLIST](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269348(v=exchg.10).md) structure. Information about all objects is retrieved. A temporary table will be created, and the information that is necessary to traverse the temporary table is described in the [JET_OBJECTLIST](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269348(v=exchg.10).md) structure. For more information, see [JET_OBJECTLIST](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269348(v=exchg.10).md). JET_ObjInfoListNoStats is identical to JET_ObjInfoList, except that the columns that report the number of records (*columnidcRecord*) and pages (*columnidcPage*) will not be updated.

|
|

JET_ObjInfoMax

|

*pvResult* is interpreted as a [JET_OBJECTINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269353(v=exchg.10).md). The maximum size of the object is in pages. Currently only tables will be returned.

|
|

JET_ObjInfoNoStats

|

*pvResult* is interpreted as a [JET_OBJECTINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269353(v=exchg.10).md). Information about only the object given in *szObjectName* will be retrieved.

The [JET_OBJECTINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269353(v=exchg.10).md) structure will be populated with information pertaining to the object that is named in *szObjectName*.

JET_ObjInfoNoStats is identical to JET_ObjInfo, except that the fields that report the number of records and pages are set to zero.

|
|

JET_ObjInfoRulesLoaded

|

Deprecated and not currently supported.

|
|

JET_ObjInfoSysTabCursor

|

Deprecated and not currently supported.

|
|

JET_ObjInfoSysTabReadOnly

|

Deprecated and not currently supported.

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

The size of the buffer given in *cbMax* was too small to hold the desired information.

|
|

JET_errInvalidName

|

An invalid name was given in *szObjectName* or *szContainerName*.

|
|

JET_errInvalidParameter

|

A bad parameter was given. It is possible that a bad level was passed in to *InfoLevel*.

|

#### Remarks

If **JetGetObjectInfo** successfully creates a temporary table (for example, JET_ObjInfoList or JET_ObjInfoNoStats), the caller is responsible for closing the temporary table with [JetCloseTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosetable-function).

**JetGetObjectInfo** currently only supports retrieving information about tables.

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

Implemented as **JetGetObjectInfoW** (Unicode) and **JetGetObjectInfoA** (ANSI).

|

#### See Also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_OBJTYP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-objtyp)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JET_OBJECTINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-objectinfo-structure)
[JET_OBJECTLIST](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-objectlist-structure)
[JetCloseTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosetable-function)
[JetGetTableInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgettableinfo-function)