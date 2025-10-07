# JET_TABLECREATE3 Structure

_**Applies to:** Windows | Windows Server_

The **JET_TABLECREATE3** structure contains the information that is needed to create a table populated with columns and indexes in an Extensible Storage Engine (ESE) database, and that designates a callback function. The **JET_TABLECREATE3** structure is used by the [JetCreateTableColumnIndex3](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatetablecolumnindex3-function) function.

The **JET_TABLECREATE3** structure was introduced in the Windows 7 operating system.

``` cpp
typedef struct tagJET_TABLECREATE3 {
  unsigned long cbStruct;
  tchar* szTableName;
  tchar* szTemplateTableName;
  unsigned long ulPages;
  unsigned long ulDensity;
  JET_COLUMNCREATE* rgcolumncreate;
  unsigned long cColumns;
    JET_INDEXCREATE2* rgindexcreate;
  unsigned long cIndexes;
  tchar* szCallback;
  JET_CBTYP cbtyp;
  JET_GRBIT grbit;
  JET_TABLEID tableid;
  un  JET_GRBIT grbit;
  JET_SPACEHINTS* pSeqSpacehints;
  JET_SPACEHINTS* pLVSpacehints;
  unsigned long cbSeparateLV;
  JET_TABLEID tableid;
  unsigned long cCreated;
} JET_TABLECREATE3;>
```

### Members

**cbStruct**

The size of this structure in bytes (for future expansion). It must be set to sizeof( JET_TABLECREATE3 ) in bytes.

**szTableName**

The name of the table to create.

The name must meet the following conditions:

  - It must have a value that is less than JET_cbNameMost, not including the terminating null.

  - It must consist of the following set of characters: 0 through 9, A through Z, a through z, and all other punctuation except for exclamation point (\!), comma (,), opening bracket (\[), and closing bracket (\]); that is, ASCII characters 0x20, 0x22 through 0x2d, 0x2f through 0x5a, 0x5c, and 0x5d through 0x7f.

  - It must not begin with a space.

  - It must consist of at least one non-space character.

**szTemplateTableName**

The name of an existing table from which to inherit the base data definition language (DDL). Use of a template table allows for the easy creation of many tables with identical columns and indexes.

**ulPages**

The initial number of database pages to allocate for the table. Specifying a number larger than one can reduce fragmentation if many rows are inserted into this table.

**ulDensity**

The table density, in percentage points. The number must be either 0 or in the range of 20 through 100. Passing 0 means that the default value should be used. The default value is 80.

**rgcolumncreate**

An array of [JET_COLUMNCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columncreate-structure) structures, each of which corresponds to a column to be created in the new table.

**cColumns**

The number of [JET_COLUMNCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columncreate-structure) elements in the *rgcolumncreate* parameter.

**rgindexcreate**

An array of [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexcreate2-structure) structures, each of which corresponds to an index to be created in the new table.

**cIndexes**

The number of [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexcreate2-structure) elements in the *rgindexcreate* parameter.

**szCallback**

The function that gets called during certain events. **cbtyp** determines when the callback function will be called.

The format of **szCallback** must be "module\!function" — for example, "alpha\!beta" refers to the beta function in the module named "alpha".

The prototype of the function must match the [JET_CALLBACK](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-callback-callback-function) callback function.

**cbtyp**

Describes the type of callback function designated by **szCallback**. For more information, see [JET_CBTYP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-cbtyp).

This bitfield is composed of one or more of the bit values listed in the following table.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_cbtypFinalize

|

The callback function will be called when a column that can be finalized has gone to zero.

|
|

JET_cbtypBeforeInsert

|

The callback function will be called prior to record insertion.

|
|

JET_cbtypAfterInsert

|

The callback function will be called after the database engine has finished inserting a record.

|
|

JET_cbtypBeforeReplace

|

The callback function will be called prior to the modification of a record.

|
|

JET_cbtypAfterReplace

|

The callback function will be called after finishing the modification of a record.

|
|

JET_cbtypBeforeDelete

|

The callback function will be called prior to the deletion of a record.

|
|

JET_cbtypAfterDelete

|

The callback function will be called after a record has been deleted.

|
|

JET_cbtypUserDefinedDefaultValue

|

The callback function will be called to calculate a user-defined default.

|
|

JET_cbtypFreeCursorLS

|

The callback function will be called when the local storage that is associated with a cursor must be freed.

|
|

JET_cbtypFreeTableLS

|

The callback function will be called when the local storage that is associated with a table must be freed.

|

**grbit**

A group of bits that contains zero or more of the call option values listed in the following table.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitTableCreateFixedDDL

|

Prevents DDL operations on the table (such as adding or removing columns).

|
|

JET_bitTableCreateTemplateTable

|

Causes the table to be a template table. New tables can then specify the name of this table as their template table. Setting JET_bitTableCreateTemplateTable implies JET_bitTableCreateFixedDDL.

|
|

JET_bitTableCreateNoFixedVarColumnsInDerivedTables

|

Must be used in conjunction with JET_bitTableCreateTemplateTable. Deprecated. Do not use.

|

**pSeqSpacehints**

A pointer to a [JET_SPACEHINTS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-spacehints-structure) structure for default sequential index.

**pSeqSpacehints** was introduced in Windows 7.

**pLVSpacehints**

A pointer to a [JET_SPACEHINTS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-spacehints-structure) structure for a Separated Long Value tree.

**pLVSpacehints** was introduced in Windows 7.

**cbSeparateLV**

The size to separate an intrinsic LV from the primary record. Any long-value c structure for a Separated LV tree. For more information, see ng-value in [JET_SPACEHINTS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-spacehints-structure). Long-value columns smaller than this value may be separated if the record becomes too large.

**cbSeparateLV** was introduced in Windows 7.

**tableid**

An output field that holds the [JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid) of the new table if the API call succeeds. If the API call fails, the value is undefined. This table is opened exclusively.

**cCreated**

An output field that contains the count of objects that are created if the API call succeeds. If the API call fails, the value is undefined.

The count of objects that are created is equal to the sum of columns, tables, and indexes that are successfully created.

### Requirements

| Requirement | Value |
|------------|----------|
|

**Client**

|

Requires Windows Vista or Windows XP.

|
|

**Server**

|

Requires Windows Server 2008 or Windows Server 2003.

|
|

**Header**

|

Declared in Esent.h.

|
|

**Unicode**

|

Implemented as **JET_TABLECREATE3_W** (Unicode) and **JET_TABLECREATE3_A** (ANSI).

|

### See also

[JET_CALLBACK](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-callback-callback-function)
[JET_CBTYP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-cbtyp)
[JET_CONDITIONALCOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-conditionalcolumn-structure)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexcreate-structure)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JetCreateTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatetable-function)
[JetCreateTableColumnIndex](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatetablecolumnindex-function)
[JetCreateTableColumnIndex2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatetablecolumnindex2-function)
[JetDefragment2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdefragment2-function)