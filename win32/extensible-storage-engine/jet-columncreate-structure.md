# JET_COLUMNCREATE Structure

_**Applies to:** Windows | Windows Server_

## JET_COLUMNCREATE Structure

The **JET_COLUMNCREATE** structure describes a column to create in a database.

```cpp
    typedef struct tag_JET_COLUMNCREATE {
      unsigned long cbStruct;
      tchar* szColumnName;
      JET_COLTYP coltyp;
      unsigned long cbMax;
      JET_GRBIT grbit;
      void* pvDefault;
      unsigned long cbDefault;
      unsigned long cp;
      JET_COLUMNID columnid;
      JET_ERR err;
    } JET_COLUMNCREATE;
```

### Members

**cbStruct**

The size of the structure, in bytes. This field must be initialized to **sizeof( JET_COLUMNCREATE )**.

**szColumnName**

The name of the column to create. The name must meet the following criteria:

  - It must be fewer than JET_cbNameMost characters in length, not including the terminating NULL.

<!-- end list -->

  - It must contain characters only from the following sets: 0 through 9, A through Z, a through z, and all other punctuation except for exclamation point (\!), comma (,), opening bracket (\[), and closing bracket (\]), that is, ASCII characters 0x20, 0x22 through 0x2d, 0x2f through 0x5a, 0x5c, 0x5d through 0x7f.

<!-- end list -->

  - It cannot begin with a space.

<!-- end list -->

  - It must contain at least one non-space character.

**coltyp**

The type of the column (for example, text, binary, or numerical). For more information, see [JET_COLTYP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp).

**cbMax**

The maximum length, in bytes, of a variable-length column. The length of the column for fixed-length columns.

**grbit**

A group of bits that contain the options for this structure, and which include zero or more of the following values.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitColumnFixed

|

The column is fixed. It will always use the same amount of space in a row, regardless of how much data is being stored in the column. JET_bitColumnFixed cannot be used with JET_bitColumnTagged. This bit cannot be used with long values such as **JET_coltypLongText** and **JET_coltypLongBinary**.

|
|

JET_bitColumnTagged

|

The column is tagged. Tagged columns do not take up any space in the database if they do not contain data. This bit cannot be used with JET_bitColumnFixed.

|
|

JET_bitColumnNotNULL

|

The column must never be set to a NULL value.

|
|

JET_bitColumnAutoincrement

|

The column is automatically incremented. The number is an increasing number, and is guaranteed to be unique within a table. The number, however, might not be continuous. For example, if five rows are inserted into a table, the autoincrement column could contain the values { 1, 2, 6, 7, 8 }.

**Windows 2000:** This bit can be used only on columns of type **JET_coltypLong**.

**Windows Server 2003 and later:** This bit can only be used on columns of type **JET_coltypLong** or **JET_coltypCurrency**.

|
|

JET_bitColumnUpdatable

|

This bit is valid only on calls to [JetGetColumnInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269215(v=exchg.10).md).

|
|

JET_bitColumnTTKey

|

This bit is valid only on calls to [JetOpenTempTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269211(v=exchg.10).md).

|
|

JET_bitColumnTTDescending

|

This bit is valid only on calls to [JetOpenTempTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269211(v=exchg.10).md).

|
|

JET_bitColumnMultiValued

|

The column can be multi-valued. A multi-valued column can have zero, one, or more values associated with it. The various values in a multi-valued column are identified by the **itagSequence** member of various structures, for example, [JET_RETINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294049(v=exchg.10).md), [JET_SETINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294090(v=exchg.10).md), [JET_SETCOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269233(v=exchg.10).md), [JET_RETRIEVECOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269334(v=exchg.10).md), [JET_ENUMCOLUMNVALUE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294052(v=exchg.10).md). Multi-valued columns must be tagged columns; that is, they cannot be fixed-length or variable-length columns.

|
|

JET_bitColumnEscrowUpdate

|

The column is an escrow update column. An escrow update column can be updated concurrently by different sessions with [JetEscrowUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294125(v=exchg.10).md) and maintain transactional consistency.

* An escrow update column can be created only when the table is empty.
* An escrow update column must be of type **JET_coltypLong.**
* An escrow update column must have a default value (that is **cbDefault** must be positive).
* JET_bitColumnEscrowUpdate cannot be used in conjunction with the following constants:

  + JET_bitColumnTagged
  + JET_bitColumnVersion
  + JET_bitColumnAutoincrement

|
|

JET_bitColumnUnversioned

|

The column is created without a version. Other transactions attempting to add a column with the same name will fail. This bit is only useful with [JetAddColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294122(v=exchg.10).md). It cannot be used within a transaction.

|
|

JET_bitColumnMaybeNull

|

Reserved for future use.

|
|

JET_bitColumnFinalize

|

Use JET_bitColumnDeleteOnZero instead of JET_bitColumnFinalize. JET_bitColumnFinalize specifies that a column can be finalized. When a column that can be finalized has an escrow update column that reaches zero, the row will be deleted. Future versions can invoke a callback function instead. For more information, see [JET_CALLBACK](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294098(v=exchg.10).md). A column that can be finalized must be an escrow update column. JET_bitColumnFinalize cannot be used with JET_bitColumnUserDefinedDefault.

|
|

JET_bitColumnUserDefinedDefault

|

The default value for a column is provided by the callback function, [JET_CALLBACK](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294098(v=exchg.10).md). A column that has a user-defined default must be a tagged column. **pvDefault** must point to a [JET_USERDEFINEDDEFAULT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269200(v=exchg.10).md) structure, and **cbDefault** must be set to sizeof([JET_USERDEFINEDDEFAULT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269200(v=exchg.10).md)).

JET_bitColumnUserDefinedDefault cannot be used in conjunction with the following constants:

* JET_bitColumnFixed
* JET_bitColumnNotNULL
* JET_bitColumnVersion
* JET_bitColumnAutoincrement
* JET_bitColumnUpdatable
* JET_bitColumnEscrowUpdate
* JET_bitColumnFinalize
* JET_bitColumnDeleteOnZero
* JET_bitColumnMaybeNull

|
|

JET_bitColumnDeleteOnZero

|

The column is an escrow update column, and when it reaches zero, the record will be deleted. A common use for a column that can be finalized is to use it as a reference count field, and when the field reaches zero the record gets deleted. JET_bitColumnDeleteOnZero is related to JET_bitColumnFinalize. A delete-on-zero column must be an escrow update column. JET_bitColumnDeleteOnZero cannot be used with JET_bitColumnFinalize. JET_bitColumnDeleteOnZero cannot be used with user defined default columns.

|

**pvDefault**

Points to a buffer which will be the default value for a column. The length of the buffer is **cbDefault**. If there is no default, **pvDefault** should be set to NULL and **cbDefault** should be set to zero. If *grbit* has JET_bitColumnUserDefinedDefault set, **pvDefault** will be interpreted as a pointer to a JET_USERDEFINEDDEFAULT structure. Default values cannot be larger than 255 bytes. If a default value is larger than 255 bytes, it will be silently truncated.

**cbDefault**

The size, in bytes, of the buffer specified by **pvDefault**.

**cp**

The code page for the column. The only valid values for text columns are English (1252) and Unicode (1200). A value of zero means the default will be used (English, 1252). If the column is not a text column, the code page automatically gets set to zero.

**columnid**

On success, the column identifier of the newly-created column will be passed back in this field. On failure, the value is undefined.

**err**

The **err** field will contain the status of creating this column. See [JetAddColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetaddcolumn-function) for a list of likely return values.

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

Implemented as **JET_COLUMNCREATE_W** (Unicode) and **JET_COLUMNCREATE_A** (ANSI).

|

### See Also

[JET_COLTYP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp)
[JET_COLUMNID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columnid)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_RETINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-retinfo-structure)
[JET_SETINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-setinfo-structure)
[JET_SETCOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-setcolumn-structure)
[JET_RETRIEVECOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-retrievecolumn-structure)
[JET_ENUMCOLUMNVALUE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-enumcolumnvalue-structure)
[JetAddColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetaddcolumn-function)
[JetCreateTableColumnIndex](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatetablecolumnindex-function)
[JetCreateTableColumnIndex2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatetablecolumnindex2-function)
[JetEscrowUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetescrowupdate-function)
[JetRenameColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetrenamecolumn-function)
[JetSetColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcolumns-function)