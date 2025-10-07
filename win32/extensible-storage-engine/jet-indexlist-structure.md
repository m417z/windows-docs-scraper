# JET_INDEXLIST Structure

_**Applies to:** Windows | Windows Server_

## JET_INDEXLIST Structure

The **JET_INDEXLIST** structure contains the necessary information to traverse a temporary table that is created by the [JetGetIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetindexinfo-function) or [JetGetTableIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgettableindexinfo-function) functions. Each row in the temporary table describes a column of an index.

```cpp
    typedef struct {
      unsigned long cbStruct;
      JET_TABLEID tableid;
      gned long cRecord;
      JET_COLUMNID columnidindexname;
      JET_COLUMNID columnidgrbitIndex;
      JET_COLUMNID columnidcKey;
      JET_COLUMNID columnidcEntry;
      JET_COLUMNID columnidcPage;
      JET_COLUMNID columnidcColumn;
      JET_COLUMNID columnidiColumn;
      JET_COLUMNID columnidcolumnid;
      JET_COLUMNID columnidcoltyp;
      JET_COLUMNID columnidCountry;
      JET_COLUMNID columnidLangid;
      JET_COLUMNID columnidCp;
      JET_COLUMNID columnidCollate;
      JET_COLUMNID columnidgrbitColumn;
      JET_COLUMNID columnidcolumnname;
      JET_COLUMNID columnidLCMapFlags;
    } JET_INDEXLIST;
```

### Members

**cbStruct**

The size of the structure in bytes. The API call will update this field, so the caller should ensure that this value matches sizeof( JET_INDEXLIST ).

**tableid**

The table identifier of the temporary table that was created. It is the responsibility of the caller to close the table.

**cRecord**

The number of records in the temporary table that was created.

**columnidindexname**

The column identifier of the name of the index.

This column is a [JET_coltypText](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp).

**columnidgrbitIndex**

The column identifier of the *grbits* used on the index. See [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexcreate-structure) for a list of valid bits.

This column is a [JET_coltypLong](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp).

**columnidcKey**

The column identifier of the number of keys in the index.

This column is a [JET_coltypLong](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp).

**columnidcEntry**

The column identifier of the number of entries in the index.

This column is a [JET_coltypLong](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp).

**columnidcPage**

The column identifier of the number of pages the index uses.This column is a [JET_coltypLong](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp).

**columnidcColumn**

The column identifier of the total number of columns that the index spans.

This column is a [JET_coltypLong](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp).

**columnidiColumn**

The column identifier of the number of the columns in the index. For more information, see the Remarks section of this topic.

This column is a [JET_coltypLong](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp).

|

Value

|

Meaning

|
|--------------|----------------|
|

cIndexInfoCols\
15

|

Specifies that 15 columns are allowed.

|
|

cColumnInfoCols\
14

|

Specifies that 14 columns are allowed.

|
|

cObjectInfoCols\
9

|

Specifies that 9 columns are allowed.

|

**columnidcolumnid**

The column identifier of the column that is indexed.For more information, see the Remarks section of this topic. This column is a [JET_coltypLong](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp).

**columnidcoltyp**

The column identifier of the coltyp of the column which is indexed. For more information, see the Remarks section of this topic. This column is a [JET_coltypLong](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp).

**columnidCountry**

The column identifier of the country code of the column that is indexed. The country code is deprecated.

This column is a [JET_coltypShort](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp).

**columnidLangid**

The column identifier of the language identifier (LCID) under which the index was created. For more information, see [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexcreate-structure).

This column is a [JET_coltypShort](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp).

**columnidCp**

The column identifier of the code page under which the index was created. For more information, see [JET_COLUMNCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columncreate-structure).

This column is a [JET_coltypShort](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp).

**columnidCollate**

The column identifier of the collation sequence under which the index was created. The collation sequence is deprecated.

This column is a [JET_coltypShort](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp).

**columnidgrbitColumn**

The column identifier of the *grbits* that apply to the order of the column in the index.

The data for this column can be ordered as JET_bitKeyAscending or JET_bitKeyDescending. This column is a [JET_coltypLong](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp). For example, an index defined as "-column1\\0+column2\\0" will have JET_bitKeyDescending for "column1", and JET_bitKeyAscending for "column2".

The following options are valid for this member.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitKeyAscending

|

An index segment in ascending order.

|
|

JET_bitKeyDescending

|

An index segment in descending order.

|

**columnidcolumnname**

The column identifier of the name of the column.

This column is a [JET_coltypText](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp).

**columnidLCMapFlags**

The column identifier of the flags that are used to create the index. For more information, see the **dwMapFlags** section of [JET_UNICODEINDEX](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-unicodeindex-structure).

This column is a [JET_coltypLong](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp).

### Remarks

Each row in the temporary table corresponds to a column in a particular index.

For example, the index "+A\\0+B\\0+C\\0+D\\0+E\\0" is more than five columns, and it will occupy five rows in the temporary table. Each of these five rows will have a value of 5 in the column that is identified by columnid column. But each row will have a different value for columnid column, ranging from 0 to 4.

The number of keys in a particular index corresponds to the number of unique values for which a caller can seek and get an exact match. The number of entries is the number of rows that an index matches. If an index has a uniqueness constraint, then the number of keys is equal to the number of entries. For example, if a table contains the following information and an index is created over the column named "key", then there are three keys (100, 200, and 500), but there are four entries ("this", "is", "an", and "example").

|

Key

|

Entry

|
|------------|--------------|
|

100

|

"this"

|
|

100

|

"is"

|
|

200

|

"an"

|
|

500

|

"example"

|

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

[JET_COLTYP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp)
[JET_COLUMNCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columncreate-structure)
[JET_COLUMNID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columnid)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexcreate-structure)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JET_UNICODEINDEX](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-unicodeindex-structure)
[JetGetIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetindexinfo-function)
[JetGetTableIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgettableindexinfo-function)