# JET_ENUMCOLUMNID Structure

_**Applies to:** Windows | Windows Server_

## JET_ENUMCOLUMNID Structure

The **JET_ENUMCOLUMNID** structure enumerates a specific set of columns and, optionally, a specific set of multiple values for those columns when the [JetEnumerateColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetenumeratecolumns-function) function is used. [JetEnumerateColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetenumeratecolumns-function) returns an array of **JET_ENUMCOLUMNID** structures.

```cpp
    typedef struct {
      JET_COLUMNID columnid;
      unsigned long ctagSequence;
      unsigned long* rgtagSequence;
    } JET_ENUMCOLUMNID;
```

### Members

**columnid**

The column ID to enumerate.

If the column ID is 0 (zero) then the enumeration of this column is skipped and a corresponding slot in the output array of [JET_ENUMCOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-enumcolumn-structure) structures will be generated with a column state of JET_wrnColumnSkipped.

**ctagSequence**

Optionally identifies an array of column values (by one-based index) to enumerate for the specified column ID.

If **ctagSequence** is 0 (zero) then **rgtagSequence** is ignored and all column values for the specified column ID will be enumerated.

If an element of **rgtagSequence** is 0 (zero), then the enumeration of that column value (by one-based index) will be skipped. A corresponding slot in the output array of the **JET_ENUMCOLUMNID** structure will be generated with a column status value of JET_wrnColumnSkipped.

**rgtagSequence**

An array of one-based indices into the array of column values for a given column. A single element is an **itagSequence** which is defined in [JET_RETRIEVECOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-retrievecolumn-structure). An **itagSequence** of 0 (zero) means "skip". An **itagSequence** of 1 means return the first column value of the column, 2 means the second, and so on.

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
[JET_ENUMCOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-enumcolumn-structure)
[JET_ENUMCOLUMNID]()
[JET_RETRIEVECOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-retrievecolumn-structure)
[JetEnumerateColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetenumeratecolumns-function)