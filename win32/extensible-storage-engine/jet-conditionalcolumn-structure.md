# JET_CONDITIONALCOLUMN Structure

_**Applies to:** Windows | Windows Server_

## JET_CONDITIONALCOLUMN Structure

The **JET_CONDITIONALCOLUMN** structure defines how conditional indexing is performed for a given index. A conditional index contains an index entry for only those rows that match the specified condition. However, the conditional column is not part of the index's key, it only controls the presence of the index entry.

```cpp
    typedef struct tagJET_CONDITIONALCOLUMN {
      unsigned long cbStruct;
      tchar* szColumnName;
      JET_GRBIT grbit;
    } JET_CONDITIONALCOLUMN;
```

### Members

**cbStruct**

This field must be initialized to sizeof( JET_CONDITIONALCOLUMN ), in bytes.

**szColumnName**

The name of the column that contains the data on which the database engine is conditionally indexing the row.

**grbit** A group of bits that gives the options for the conditional index. Passing in zero or logically-**OR**ed values is not valid for **JET_CONDITIONALCOLUMN**. The bit field must be exactly one of the following:

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitIndexColumnMustBeNull

|

The column specified by the *szColumnName* parameter must be NULL for an index entry for a given row to appear in this index.

|
|

JET_bitIndexColumnMustBeNonNull

|

The column specified by the *szColumnName* parameter must be non-NULL for an index entry in order for a given row to appear in this index.

|

### Remarks

A conditional index contains an index entry for only those rows that match the specified condition. For example, a column could be named "Marked", and when a row is marked, the column is set to a non-NULL value. A JET_bitIndexColumnMustBeNonNull conditional index on this column will show all rows that are marked, and a JET_bitIndexColumnMustBeNull conditional index will show rows that are not marked. This is also a convenient way to perform a flag deletion and garbage collecting index.

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
|

**Unicode**

|

Implemented as **JET_CONDITIONALCOLUMN_W** (Unicode) and **JET_CONDITIONALCOLUMN_A** (ANSI).

|

### See Also

[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexcreate-structure)