# JET_RECORDLIST Structure

_**Applies to:** Windows | Windows Server_

## JET_RECORDLIST Structure

The **JET_RECORDLIST** structure finds records that are in the intersection of specified index ranges when they are used with the [JetIntersectIndexes](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetintersectindexes-function) function.

```cpp
    typedef struct {
      unsigned long cbStruct;
      JET_TABLEID tableid;
      unsigned long cRecord;
      JET_COLUMNID columnidBookmark;
    } JET_RECORDLIST;
```

### Members

**cbStruct**

The size of the **JET_RECORDLIST** structure, in bytes.

**tableid**

The table identifier of a temporary table that contains the bookmarks for the results of the query. The table will automatically be closed if the current transaction is rolled back with [JetRollback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetrollback-function); otherwise, it must be closed with [JetCloseTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosetable-function).

**cRecord**

The number of rows in the temporary table.

**columnidBookmark**

The column identifier of the bookmark column in the temporary table.

### Remarks

The temporary table that is identified by **tableid** has a single column. That single column holds bookmarks, and each record should fit in a buffer of size JET_cbBookmarkMost bytes.

### Requirements

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

[JET_COLUMNID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columnid)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JetCloseTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosetable-function)
[JetIntersectIndexes](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetintersectindexes-function)
[JetRollback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetrollback-function)