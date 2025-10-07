# JET_INDEXID Structure

_**Applies to:** Windows | Windows Server_

## JET_INDEXID Structure

The **JET_INDEXID** structure holds an index ID. An index ID is a hint that is used to accelerate the selection of the current index using [JetSetCurrentIndex](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcurrentindex-function). It is most useful when there is a very large number of indexes over a table. The index ID can be retrieved using [JetGetIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetindexinfo-function) or [JetGetTableIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgettableindexinfo-function).

```cpp
    typedef struct tagJET_INDEXID {
      unsigned long cbStruct;
      char rgbIndexId[sizeof(JET_API_PRT) + sizeof(unsigned long) + sizeof(unsigned long)];
    } JET_INDEXID;
```

### Members

**cbStruct**

The size, in bytes, of the index ID.

This is the actual size of the index ID that is returned in the output buffer from [JetGetIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetindexinfo-function) or [JetGetTableIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgettableindexinfo-function).

**rgbIndexId**

An opaque BLOB of information that is used by the engine to quickly identify an index in its schema cache.

Do not attempt to interpret the BLOB of information. It is not a set size.

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

[JetGetIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetindexinfo-function)
[JetGetTableIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgettableindexinfo-function)
[JetGetTableInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgettableinfo-function)
[JetSetCurrentIndex](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcurrentindex-function)