# JET_CALLBACK Callback Function

_**Applies to:** Windows | Windows Server_

## JET_CALLBACK Callback Function

The **JET_CALLBACK** function is a multi-purpose callback function used by the database engine to inform the application of an event involving online defragmentation and cursor state notifications.

See [JET_CBTYP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-cbtyp) for specific settings to use for the parameters of this function, as these settings will differ depending upon the **JET_CBTYP** option that is selected for use in the *cbtyp* parameter.

```cpp
    JET_ERR JET_API* JET_CALLBACK(
      [in]                 JET_SESID sesid,
      [in]                 JET_DBID dbid,
      [in]                 JET_TABLEID tableid,
      [in]                 JET_CBTYP cbtyp,
      [in, out]            void* pvArg1,
      [in, out]            void* pvArg2,
      [in]                 void* pvContext,
      [in]                 JET_API_PTR ulUnused
    );
```

### Parameters

*sesid*

The session for which the callback is being made.

*dbid*

The database for which the callback is being made.

*tableid*

The cursor for which the callback is being made.

*cbtyp*

The point in the operation at which the callback is being made. See [JET_CBTYP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-cbtyp) for a list of values and the meaning of the following parameters in each case.

*pvArg1*

A parameter used to communicate with the application using the callback. See [JET_CBTYP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-cbtyp) for information on the use of this parameter for each callback supported by the database engine.

*pvArg2*

A parameter used to communicate with the application using the callback. See [JET_CBTYP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-cbtyp) for information on the use of this parameter for each callback supported by the database engine.

*pvContext*

A parameter used to communicate with the application using the callback. See [JET_CBTYP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-cbtyp) for information on the use of this parameter for each callback supported by the database engine.

*ulUnused*

A parameter used to communicate with the application using the callback. See [JET_CBTYP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-cbtyp) for information on the use of this parameter for each callback supported by the database engine.

#### Return Value

The function returns one of the [Extensible Storage Engine error codes](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-error-codes). For information about how to return these codes as HRESULTs, see [Extensible Storage Engine Errors](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-errors). On success, the operation that issued the callback can proceed normally. In some cases, the callback may return a warning that influences that operation. See [JET_CBTYP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-cbtyp) for information on the use of these warnings by the operation.

On failure, the operation that issued the callback may proceed normally or may fail. See [JET_CBTYP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-cbtyp) for information on the use of the error code by the operation.

#### Remarks

If the callback passes a cursor to the application then it is important to know that this cursor is intentionally limited to a smaller set of functionality to avoid recursion and other ugliness. The following operations are allowed:

  - [JetDupCursor](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdupcursor-function)

  - [JetEnumerateColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetenumeratecolumns-function)

  - [JetGetBookmark](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetbookmark-function)

  - [JetGetCurrentIndex](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetcurrentindex-function)

  - [JetGetCursorInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetcursorinfo-function)

  - [JetGetLS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetls-function)

  - [JetGetRecordPosition](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetrecordposition-function)

  - [JetGetSecondaryIndexBookmark](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetsecondaryindexbookmark-function)

  - [JetGetTableColumnInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgettablecolumninfo-function)

  - [JetGetTableIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgettableindexinfo-function)

  - [JetGetTableInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgettableinfo-function)

  - [JetRegisterCallback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetregistercallback-function)

  - [JetRetrieveColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievecolumn-function)

  - [JetRetrieveColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievecolumns-function)

  - [JetRetrieveKey](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievekey-function)

  - [JetSetColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcolumn-function)

  - [JetSetColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcolumns-function)

  - [JetSetLS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetls-function)

  - [JetUnregisterCallback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetunregistercallback-function)

When you design your callback, take into account that even with these restrictions, it is still possible for the callback to fail.

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

### See Also

[JET_API_PTR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-api-ptr)
[JET_DBID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-dbid)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JET_CBTYP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-cbtyp)