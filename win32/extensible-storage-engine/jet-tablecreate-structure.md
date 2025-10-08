# JET_TABLECREATE Structure

_**Applies to:** Windows | Windows Server_

## JET_TABLECREATE Structure

The **JET_TABLECREATE** structure contains the information that is necessary to create a table populated with columns and indexes in an ESE database. The **JET_TABLECREATE** structure is used by [JetCreateTableColumnIndex](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatetablecolumnindex-function)

```cpp
    typedef struct tagJET_TABLECREATE {
      unsigned long cbStruct;
      tchar* szTableName;
      tchar* szTemplateTableName;
      unsigned long ulPages;
      unsigned long ulDensity;
      JET_COLUMNCREATE* rgcolumncreate;
      unsigned long cColumns;
      JET_INDEXCREATE* rgindexcreate;
      unsigned long cIndexes;
      JET_GRBIT grbit;
      JET_TABLEID tableid;
      unsigned long cCreated;
    } JET_TABLECREATE;
```

### Members

**cbStruct**

The size of this structure in bytes (for future expansion). It must be set to sizeof( JET_TABLECREATE ) in bytes.

**szTableName**

The name of the table to create.

The name must use meet the following conditions:

  - Have a value less than JET_cbNameMost, not including the terminating NULL.

  - Consist of the following set of characters: 0 through 9, A through Z, a through z, and all other punctuation except for exclamation point (\!), comma (,), opening bracket (\[), and closing bracket (\]), that is, ASCII characters 0x20, 0x22 through 0x2d, 0x2f through 0x5a, 0x5c, and 0x5d through 0x7f.

  - Not begin with a space.

  - Consist of at least one non-space character.

**szTemplateTableName**

The name of an already-existing table from which to inherit base DDL (Data Definition Language). Use of a template table allows for the easy creation of many tables with identical columns and indexes.

**ulPages**

The initial number of database pages to allocate for the table. Specifying a number larger than one can reduce fragmentation if many rows are inserted into this table.

**ulDensity**

The table density, in percentage points. The number must be either 0 or in the range of 20 through 100. Passing 0 means that the default value should be used. The default is 80.

**rgcolumncreate**

An array of [JET_COLUMNCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columncreate-structure) structures, each of which corresponds to a column to be created in the new table.

**cColumns**

The number of [JET_COLUMNCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columncreate-structure) elements in **rgcolumncreate**.

**rgindexcreate**

An array of [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexcreate-structure) structures, each of which corresponds to an index to be created in the new table.

**cIndexes**

The number of [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexcreate-structure) elements in **rgindexcreate**.

**grbit**

A group of bits that contain the options for this call, which include zero or more of the following values.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitTableCreateFixedDDL

|

Setting JET_bitTableCreateFixedDDL prevents DDL operations on the table (such as adding or removing columns).

|
|

JET_bitTableCreateTemplateTable

|

Setting JET_bitTableCreateTemplateTable causes the table to be a template table. New tables can then specify the name of this table as their template table. Setting JET_bitTableCreateTemplateTable implies JET_bitTableCreateFixedDDL.

|
|

JET_bitTableCreateNoFixedVarColumnsInDerivedTables

|

Deprecated. Do not use.

|

**tableid**

An output field that holds the [JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid) of the new table if the API call succeeds. If the API call fails, the value is undefined.

**cCreated**

An output field that contains the count of objects created if the API call succeeds. If the API call fails, the value is undefined.

The count of objects that are created is equal to the sum of columns, tables, and indexes that are successfully created.

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

Implemented as **JET_TABLECREATE_W** (Unicode) and **JET_TABLECREATE_A** (ANSI).

|

### See Also

[JET_CALLBACK](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-callback-callback-function)
[JET_CBTYP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-cbtyp)
[JET_CONDITIONALCOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-conditionalcolumn-structure)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexcreate-structure)
[JetCreateTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatetable-function)
[JetCreateTableColumnIndex](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatetablecolumnindex-function)
[JetCreateTableColumnIndex2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatetablecolumnindex2-function)