# JET_COLUMNDEF Structure

_**Applies to:** Windows | Windows Server_

## JET_COLUMNDEF Structure

The **JET_COLUMNDEF** structure defines the data that can be stored in a column.

```cpp
    typedef struct {
      unsigned long cbStruct;
      JET_COLUMNID columnid;
      JET_COLTYP coltyp;
      unsigned short wCountry;
      unsigned short langid;
      unsigned short cp;
      unsigned short wCollate;
      unsigned long cbMax;
      JET_GRBIT grbit;
    } JET_COLUMNDEF;
```

### Members

**cbStruct**

The size of the structure, in bytes. It must be set to sizeof( JET_COLUMNDEF).

**columnid**

Reserved. **columnid** must be set to 0 (zero).

**coltyp**

The type of the column (for example, text, binary, or numerical). For more information, see [JET_COLTYP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp).

**wCountry**

Reserved. **wCountry** must be set to 0 (zero).

**langid**

Obsolete. **langid** should be set to 0 (zero).

**cp**

The code page for the column. The only valid values for text columns are English (1252) and Unicode (1200). A value of zero means the default will be used (English, 1252). If the column is not a text column, the code page automatically gets set to zero.

**wCollate**

Reserved. **wCollate** must be set to 0 (zero).

**cbMax**

The maximum length, in bytes, of a variable-length column, or the length of a fixed-length column.

**grbit**

A group of bits that contain the options to be used for this call, which include zero or more of the following values.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitColumnFixed

|

The column will be fixed. It will always use the same amount of space in a row, regardless of how much data is being stored in the column. JET_bitColumnFixed cannot be used with JET_bitColumnTagged. This bit cannot be used with long values (that is **JET_coltypLongText** and **JET_coltypLongBinary**).

|
|

JET_bitColumnTagged

|

The column will be tagged. Tagged columns do not take up any space in the database if they do not contain data. This bit cannot be used with JET_bitColumnFixed.

|
|

JET_bitColumnNotNULL

|

The column must never be set to a NULL value.

|
|

JET_bitColumnVersion

|

The column is a version column that specifies the version of the row. The value of this column starts at zero and will be automatically incremented for each update on the row.

This bit can only be applied to **JET_coltypLong** columns. This bit cannot be used with JET_bitColumnAutoincrement, JET_bitColumnEscrowUpdate, or JET_bitColumnTagged.

|
|

JET_bitColumnAutoincrement

|

The column will automatically be incremented. The number is an increasing number, and is guaranteed to be unique within a table. The numbers, however, might not be continuous. For example, if five rows are inserted into a table, the "autoincrement" column could contain the values { 1, 2, 6, 7, 8 }. This bit can only be used on columns of type **JET_coltypLong** or **JET_coltypCurrency**.

**Windows 2000:** In Windows 2000, this bit can only be used on columns of type **JET_coltypLong**.

|
|

JET_bitColumnUpdatable

|

This bit is valid only on calls to [JetGetColumnInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269215(v=exchg.10).md).

|
|

JET_bitColumnTTKey

|

This bit is valid only on calls to [JetOpenTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294118(v=exchg.10).md).

|
|

JET_bitColumnTTDescending

|

This bit is valid only on calls to [JetOpenTempTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269211(v=exchg.10).md).

|
|

JET_bitColumnMultiValued

|

The column can be multi-valued. A multi-valued column can have zero, one, or more values associated with it. The various values in a multi-valued column are identified by a number called the **itagSequence** member, which belongs to various structures, including: [JET_RETINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294049(v=exchg.10).md), [JET_SETINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294090(v=exchg.10).md), [JET_SETCOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269233(v=exchg.10).md), [JET_RETRIEVECOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269334(v=exchg.10).md), and [JET_ENUMCOLUMNVALUE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294052(v=exchg.10).md). Multi-valued columns must be tagged columns; that is, they cannot be fixed-length or variable-length columns.

|
|

JET_bitColumnEscrowUpdate

|

Specifies that a column is an escrow update column. An escrow update column can be updated concurrently by different sessions with [JetEscrowUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294125(v=exchg.10).md) and will maintain transactional consistency. An escrow update column must also meet the following conditions:

* An escrow update column can be created only when the table is empty.

* An escrow update column must be of type **JET_coltypLong**.

* An escrow update column must have a default value (that is **cbDefault** must be positive).

* JET_bitColumnEscrowUpdate cannot be used in conjunction with JET_bitColumnTagged, JET_bitColumnVersion, or JET_bitColumnAutoincrement.

|
|

JET_bitColumnUnversioned

|

The column will be created in an without version information. This means that other transactions that attempt to add a column with the same name will fail. This bit is only useful with [JetAddColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294122(v=exchg.10).md). It cannot be used within a transaction.

|
|

JET_bitColumnMaybeNull

|

Reserved for future use.

|
|

JET_bitColumnFinalize

|

Use JET_bitColumnDeleteOnZero instead of JET_bitColumnFinalize. JET_bitColumnFinalize that a column can be finalized. When a column that can be finalized has an escrow update column that reaches zero, the row will be deleted. Future versions might invoke a callback function instead (For more information, see [JET_CALLBACK](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294098(v=exchg.10).md)). A column that can be finalized must be an escrow update column. JET_bitColumnFinalize cannot be used with JET_bitColumnUserDefinedDefault.

|
|

JET_bitColumnUserDefinedDefault

|

The default value for a column will be provided by a callback function. See [JET_CALLBACK](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294098(v=exchg.10).md). A column that has a user-defined default must be a tagged column. Specifying JET_bitColumnUserDefinedDefault means that **pvDefault** must point to a [JET_USERDEFINEDDEFAULT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269200(v=exchg.10).md) structure, and **cbDefault** must be set to sizeof( [JET_USERDEFINEDDEFAULT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269200(v=exchg.10).md) ).

* JET_bitColumnUserDefinedDefault cannot be used in conjunction with JET_bitColumnFixed, JET_bitColumnNotNULL, JET_bitColumnVersion, JET_bitColumnAutoincrement, JET_bitColumnUpdatable, JET_bitColumnEscrowUpdate, JET_bitColumnFinalize, JET_bitColumnDeleteOnZero, or JET_bitColumnMaybeNull.

|
|

JET_bitColumnDeleteOnZero

|

The column is an escrow update column, and when it reaches zero, the record will be deleted. A common use for a column that can be finalized is to use it as a reference count field, and when the field reaches zero the record gets deleted. JET_bitColumnDeleteOnZero is related to JET_bitColumnFinalize. A Delete-on-zero column must be an escrow update column. JET_bitColumnDeleteOnZero cannot be used with JET_bitColumnFinalize. JET_bitColumnDeleteOnZero cannot be used with user defined default columns.

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

[JET_CALLBACK](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-callback-callback-function)
[JET_COLTYP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp)
[JET_COLUMNCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columncreate-structure)
[JET_COLUMNID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columnid)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_USERDEFINEDDEFAULT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-userdefineddefault-structure)
[JetAddColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetaddcolumn-function)
[JetEscrowUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetescrowupdate-function)
[JetGetTableColumnInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgettablecolumninfo-function)
[JetOpenTempTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopentemptable-function)
[JetOpenTempTable2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopentemptable2-function)
[JetOpenTempTable3](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopentemptable3-function)
[JetRenameColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetrenamecolumn-function)