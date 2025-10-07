# JET_ENUMCOLUMN Structure

_**Applies to:** Windows | Windows Server_

## JET_ENUMCOLUMN Structure

The **JET_ENUMCOLUMN** structure enumerates the column values of a record when the [JetEnumerateColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetenumeratecolumns-function) function is used. [JetEnumerateColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetenumeratecolumns-function) returns an array of **JET_ENUMCOLUMN** structures. The array is returned in memory that is allocated using the [realloc](https://learn.microsoft.com/cpp/c-runtime-library/reference/realloc) compatible callback that was supplied to that API.

```cpp
    typedef struct {
      JET_COLUMNID columnid;
      JET_ERR err;
      union {
        struct {
          unsigned long cEnumColumnValue;
          JET_ENUMCOLUMNVALUE rgEnumColumnValue;
        };
        struct {
          unsigned long cbData;
          void* pvData;
        };
      };
    } JET_ENUMCOLUMN;
```

### Members

**columnid**

The column ID that was enumerated.

**err**

The column status code that results from the enumeration of the column.

|

Error Codes

|

Meaning

|
|--------------------|----------------|
|

JET_errBadColumnId

|

The column ID is outside the legal limits of a column ID.

|
|

JET_errColumnNotFound

|

The column described by the column ID does not exist in the table.

|
|

JET_wrnColumnNull

|

All values for this column are NULL.

|
|

JET_wrnColumnPresent

|

JET_bitEnumeratePresenceOnly was specified and at least one non-NULL column value would have been returned for this column.

|
|

JET_wrnColumnSingleValue

|

JET_bitEnumerateCompressOutput was specified and exactly one non-NULL column value has been returned for this column. As a result, the compressed form of **JET_ENUMCOLUMN** has been returned. See **JET_ENUMCOLUMN** for more information.

|
|

JET_wrnColumnSkipped

|

The column ID in the [JET_ENUMCOLUMNID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269251(v=exchg.10).md) struct corresponding to this **JET_ENUMCOLUMN** struct was zero.

|

**cEnumColumnValue**

The array of column values that was enumerated for the column. The output buffer is returned in memory that was allocated using the [realloc](https://learn.microsoft.com/cpp/c-runtime-library/reference/realloc) compatible callback that was supplied to [JetEnumerateColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetenumeratecolumns-function).

This output buffer is used when the column status code is not equal to JET_wrnColumnSingleValue. For more information, see [JetEnumerateColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetenumeratecolumns-function).

This is returned if "err \!= JET_wrnColumnSingleValue".

**rgEnumColumnValue**

The array of column values that was enumerated for the column. The output buffer is returned in memory that was allocated using the [realloc](https://learn.microsoft.com/cpp/c-runtime-library/reference/realloc) compatible callback that was supplied to [JetEnumerateColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetenumeratecolumns-function).

This output buffer is used when the column status code is not equal to JET_wrnColumnSingleValue. For more information, see [JetEnumerateColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetenumeratecolumns-function).

This is returned if "err \!= JET_wrnColumnSingleValue".

**cbData**

The column value that was enumerated for the column.

The output buffer is returned in memory that was allocated using the [realloc](https://learn.microsoft.com/cpp/c-runtime-library/reference/realloc) compatible callback that was supplied to [JetEnumerateColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetenumeratecolumns-function).

This output buffer is only used when the column status code is JET_wrnColumnSingleValue. For more information, see [JetEnumerateColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetenumeratecolumns-function).

This is returned if "err == JET_wrnColumnSingleValue".

**pvData**

The column value that was enumerated for the column.

The output buffer is returned in memory that was allocated using the [realloc](https://learn.microsoft.com/cpp/c-runtime-library/reference/realloc) compatible callback that was supplied to [JetEnumerateColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetenumeratecolumns-function).

This output buffer is only used when the column status code is JET_wrnColumnSingleValue. For more information, see [JetEnumerateColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetenumeratecolumns-function).

This is returned if "err == JET_wrnColumnSingleValue".

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
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_ENUMCOLUMNID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-enumcolumnid-structure)
[JET_ENUMCOLUMNVALUE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-enumcolumnvalue-structure)
[JetEnumerateColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetenumeratecolumns-function)
[realloc](https://learn.microsoft.com/cpp/c-runtime-library/reference/realloc)