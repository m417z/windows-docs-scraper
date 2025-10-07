# JET_ENUMCOLUMNVALUE Structure

_**Applies to:** Windows | Windows Server_

## JET_ENUMCOLUMNVALUE Structure

The **JET_ENUMCOLUMNVALUE** structure enumerates the column values of a record using the [JetEnumerateColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetenumeratecolumns-function) function. [JetEnumerateColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetenumeratecolumns-function) returns an array of **JET_ENUMCOLUMNVALUE** structures. The array is returned in memory that was allocated using the [realloc](https://learn.microsoft.com/cpp/c-runtime-library/reference/realloc) compatible callback that was supplied to that function.

```cpp
    typedef struct {
      unsigned long itagSequence;
      JET_ERR err;
      unsigned long cbData;
      void* pvData;
    } JET_ENUMCOLUMNVALUE;
```

### Members

**itagSequence**

The column value (by one-based index) that was enumerated.

**err**

The column status code resulting from the enumeration of the column value.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_wrnColumnNull

|

The requested column value is NULL.

|
|

JET_wrnColumnSkipped

|

The *itagSequence* that is specified in the element of the *rgtagSequence* array in the [JET_ENUMCOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294138(v=exchg.10).md) struct corresponding to this **JET_ENUMCOLUMNVALUE** struct was zero.

|
|

JET_wrnColumnTruncated

|

The requested column value was truncated to the specified size before being returned.

This truncation occurs only for long text and long binary columns that contain large amounts of data.

|

**cbData**

The column value that was enumerated for the column.

The output buffer is returned in memory that was allocated using the [realloc](https://learn.microsoft.com/cpp/c-runtime-library/reference/realloc) compatible callback that was supplied to [JetEnumerateColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetenumeratecolumns-function).

**pvData**

The column value that was enumerated for the column.

The output buffer is returned in memory that was allocated using the [realloc](https://learn.microsoft.com/cpp/c-runtime-library/reference/realloc) compatible callback that was supplied to [JetEnumerateColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetenumeratecolumns-function).

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

[JET_ENUMCOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-enumcolumn-structure)
[JET_ENUMCOLUMNVALUE]()
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JetEnumerateColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetenumeratecolumns-function)
[realloc](https://learn.microsoft.com/cpp/c-runtime-library/reference/realloc)