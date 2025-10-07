# JET_COLUMNBASE Structure

_**Applies to:** Windows | Windows Server_

## JET_COLUMNBASE Structure

The **JET_COLUMNBASE** structure describes the parameters of a base column. The [JetGetColumnInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetcolumninfo-function) and [JetGetTableColumnInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgettablecolumninfo-function) functions use the **JET_COLUMNBASE** structure.

```cpp
    typedef struct {
      unsigned long cbStruct;
      JET_COLUMNID columnid;
      JET_COLTYP coltyp;
      unsigned short wCountry;
      unsigned short langid;
      unsigned short cp;
      unsigned short wFiller;
      unsigned long cbMax;
      JET_GRBIT grbit;
      tchar szBaseTableName[256];
      tchar szBaseColumnName[256];
    } JET_COLUMNBASE;
```

### Members

**cbStruct**

The size of this structure, in bytes. Set **cbStruct** to sizeof( JET_COLUMNBASE ).

**columnid**

Reserved. Set **columnid** to 0 (zero).

**coltyp**

The type of the column (for example, text, binary, or numerical). For more information, see [JET_COLTYP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp).

**wCountry**

Reserved. Set to 0 (zero).

**langid**

Reserved. Set to 0 (zero).

**cp**

The code page for the column. The only valid values for text columns are English (1252) and Unicode (1200). A value of zero means the default will be used (English, 1252). If the column is not a text column, the code page is automatically set to zero.

**wFiller**

Reserved. Set to 0 (zero).

**cbMax**

The maximum length, in bytes, of a variable-length column, or the actual length, in bytes, of a fixed-length column.

**grbit**

Options for the column, including zero or more of the following values.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitColumnFixed

|

The column is fixed and occupies the same amount of space in a row regardless of how much data it contains. JET_bitColumnFixed cannot be combined with JET_bitColumnTagged, and cannot be used when the **coltyp** member is set to **JET_coltypLongText** or **JET_coltypLongBinary**.

|
|

JET_bitColumnTagged

|

The column is tagged and occupies space in the database only if it contains data. JET_bitColumnTagged cannot be combined with JET_bitColumnFixed, JET_bitColumnVersion, or JET_bitColumnEscrowUpdate.

|
|

JET_bitColumnNotNULL

|

The column must not be set to a **NULL** value.

JET_bitColumnNotNULL cannot be combined with JET_bitColumnUserDefinedDefault.

|
|

JET_bitColumnVersion

|

The column is a version column that specifies the version of the row. The value of this column starts at zero and is automatically incremented for each update of the row.

JET_bitColumnVersion can be used only when the **coltyp** member is set to **JET_coltypLong** and cannot be combined with JET_bitColumnAutoincrement, JET_bitColumnEscrowUpdate, JET_bitColumnTagged, or JET_bitColumnUserDefinedDefault.

|
|

JET_bitColumnAutoincrement

|

The column is automatically incremented. The number is an increasing number, and is guaranteed to be unique within a table. The numbers, however, may not be sequential. For example, if five rows are inserted into a table, the automatically incremented column could contain the values { 1, 2, 6, 7, 8 }.

JET_bitColumnAutoincrement can be used only when the **coltyp** member is set to **JET_coltypLong** or **JET_coltypCurrency** and cannot be combined with JET_bitColumnEscrowUpdate, JET_bitColumnUserDefinedDefault, or JET_bitColumnVersion.

**Windows 2000:** JET_bitColumnVersion can be used only when the **coltyp** member is set to **JET_coltypLong**.

|
|

JET_bitColumnUpdatable

|

Valid only for calls to [JetGetColumnInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269215(v=exchg.10).md). JET_bitColumnUpdatable cannot be combined with JET_bitColumnUserDefinedDefault.

|
|

JET_bitColumnTTKey

|

Valid only on calls to [JetOpenTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294118(v=exchg.10).md).

|
|

JET_bitColumnTTDescending

|

Valid only on calls to [JetOpenTempTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269211(v=exchg.10).md).

|
|

JET_bitColumnMultiValued

|

The column can be multi-valued. A multi-valued column can have zero, one, or more values associated with it. The various values in a multi-valued column are identified by a number in the **itagSequence** member of various structures, for example, [JET_RETINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294049(v=exchg.10).md), [JET_SETINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294090(v=exchg.10).md), [JET_SETCOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269233(v=exchg.10).md), [JET_RETRIEVECOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269334(v=exchg.10).md), [JET_ENUMCOLUMNVALUE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294052(v=exchg.10).md). Multi-valued columns must be tagged columns; that is, they may not be fixed-length or variable-length columns.

|
|

JET_bitColumnEscrowUpdate

|

Specifies that a column is an escrow update column that can be updated concurrently by different sessions with [JetEscrowUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294125(v=exchg.10).md) and will have transactional consistency.

* An escrow update column can be created only when the table is empty.

* For an escrow update column, the **coltyp** member must be set to **JET_coltypLong.**

* An escrow update column must have a default value (that is **cbDefault** must be positive).

* JET_bitColumnEscrowUpdate cannot be combined with JET_bitColumnTagged, JET_bitColumnVersion, or JET_bitColumnAutoincrement.

|
|

JET_bitColumnUnversioned

|

The column is created without a version number. This means that other transactions attempting to add a column with the same name will fail. JET_bitColumnUnversioned is used only with [JetAddColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294122(v=exchg.10).md). It cannot be used within a transaction.

|
|

JET_bitColumnMaybeNull

|

Reserved for future use.

JET_bitColumnMaybeNull cannot be combined with JET_bitColumnUserDefinedDefault.

|
|

JET_bitColumnFinalize

|

Do not use. Use JET_bitColumnDeleteOnZero instead.

The column can be finalized. A column that can be finalized is an escrow update column that causes the row to be deleted when the column reaches zero. Future versions may invoke a callback function instead (See [JET_CALLBACK](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294098(v=exchg.10).md)). A column that can be finalized must be an escrow update column. JET_bitColumnFinalize cannot be combined with JET_bitColumnUserDefinedDefault.

|
|

JET_bitColumnUserDefinedDefault

|

The default value for a column will be provided by a callback function. See [JET_CALLBACK](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294098(v=exchg.10).md). A column that has a user-defined default must be a tagged column. If JET_bitColumnUserDefinedDefault is specified, the **pvDefault** must point to a [JET_USERDEFINEDDEFAULT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269200(v=exchg.10).md) structure, and **cbDefault** must be set to sizeof( JET_USERDEFINEDDEFAULT ).

JET_bitColumnUserDefinedDefault cannot be combined with JET_bitColumnFixed, JET_bitColumnNotNULL, JET_bitColumnVersion, JET_bitColumnAutoincrement, JET_bitColumnUpdatable, JET_bitColumnEscrowUpdate, JET_bitColumnFinalize, JET_bitColumnDeleteOnZero, or JET_bitColumnMaybeNull.

|
|

JET_bitColumnDeleteOnZero

|

The column is an escrow update column and when it reaches zero, the record will be deleted. A common use for delete-on-zero columns is as reference count fields. When the number of references fall to zero, the record is deleted. A delete-on-zero column must be an escrow update column.

JET_bitColumnDeleteOnZero replaces JET_bitColumnFinalize.

JET_bitColumnDeleteOnZero cannot be combined with JET_bitColumnFinalize or JET_bitColumnUserDefinedDefault, and cannot be used with user-defined default columns.

|

**szBaseTableName**

The table from which the current table inherits its DDL.

**szBaseColumnName**

The name of the column in the template table.

### Remarks

**JET_COLUMNBASE** contains much of the same information as [JET_COLUMNDEF](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columndef-structure), but it adds string fields to describe the base table (if a hierarchical DDL was used).

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

Implemented as **JET_COLUMNBASE_W** (Unicode) and **JET_COLUMNBASE_A** (ANSI).

|

### See Also

[JET_CALLBACK](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-callback-callback-function)
[JET_COLTYP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp)
[JET_COLUMNDEF](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columndef-structure)
[JET_COLUMNID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columnid)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JET_USERDEFINEDDEFAULT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-userdefineddefault-structure)
[JetGetColumnInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetcolumninfo-function)
[JetGetTableColumnInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgettablecolumninfo-function)
[JetRenameColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetrenamecolumn-function)