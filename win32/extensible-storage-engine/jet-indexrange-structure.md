# JET_INDEXRANGE Structure

_**Applies to:** Windows | Windows Server_

## JET_INDEXRANGE Structure

The **JET_INDEXRANGE** structure identifies an index range when it is used with the [JetIntersectIndexes](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetintersectindexes-function) function.

```cpp
    typedef struct {
      unsigned long cbStruct;
      JET_TABLEID tableid;
      JET_GRBIT grbit;
    } JET_INDEXRANGE;
```

### Members

**cbStruct**

The size, in bytes, of the **JET_INDEXRANGE**.

**tableid**

A cursor that has previously had an index range set with [JetSetIndexRange](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetindexrange-function).

**grbit**

A bitmask composed of exactly one of the following.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitRecordInIndex

|

Specifies that the index range should be treated normally.

|
|

JET_bitRecordNotInIndex

|

Reserved for future use. Do not use.

|

### Remarks

Each **JET_INDEXRANGE** structure that is passed to [JetIntersectIndexes](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetintersectindexes-function) represents an index range, which will be intersected by the API call. The cursor that is given in **JET_INDEXRANGE** must have a valid index range set on it already, with a successful call to [JetSetIndexRange](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetindexrange-function).

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
[JetSetIndexRange](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetindexrange-function)