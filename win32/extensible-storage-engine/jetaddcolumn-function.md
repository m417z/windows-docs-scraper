# JetAddColumn Function

_**Applies to:** Windows | Windows Server_

## JetAddColumn Function

The **JetAddColumn** function adds a new column to an existing table in an ESE database.

```cpp
    JET_ERR JET_API JetAddColumn(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid,
      __in          JET_PCSTR szColumnName,
      __in          const JET_COLUMNDEF* pcolumndef,
      __in_opt      const void* pvDefault,
      __in          unsigned long cbDefault,
      __out_opt     JET_COLUMNID* pcolumnid
    );
```

### Parameters

*sesid*

The database session context to use for the API call.

*tableid*

The table to which to add the column.

*szColumnName*

The name of the column to add. The name must meet the following criteria:

  - It must be fewer than JET_cbNameMost characters in length, not including the terminating **NULL**.

  - It must contain characters only from the following sets: 0 through 9, A through Z, a through z, and all other punctuation except for exclamation point (\!), comma (,), opening bracket (\[), and closing bracket (\]) — that is, ASCII characters 0x20, 0x22 through 0x2d, 0x2f through 0x5a, 0x5c, and 0x5d through 0x7f.

  - It cannot begin with a space.

  - It must contain at least one non-space character.

*pcolumndef*

A pointer to a [JET_COLUMNDEF](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columndef-structure) structure, which defines the data that can be stored in a column.

*pvDefault*

A pointer to a buffer that contains the default value for the column. The length of the buffer is **cbDefault**. If there is no default, set **pvDefault** to **NULL** and **cbDefault** to zero. Default values cannot be larger than JET_cbColumnMost bytes for fixed columns or JET_cbLVDefaultValueMost bytes for long values. If a default value is larger than that, it will be silently truncated.

If *grbit* has JET_bitColumnUserDefinedDefault set, **pvDefault** will be interpreted as a pointer to a [JET_USERDEFINEDDEFAULT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-userdefineddefault-structure) structure.

*cbDefault*

The size, in bytes, of the buffer that is specified in **pvDefault**.

*pcolumnid*

A pointer to a [JET_COLUMNID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columnid) structure, which, on success, will receive the identifier of the newly created column. On failure, the value is undefined.

### Return Value

This function returns the [JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err) datatype with one of the following return codes. For more information about the possible ESE errors, see [Extensible Storage Engine Errors](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-errors) and [Error Handling Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/error-handling-parameters).

|

Return code

|

Description

|
|--------------------|--------------------|
|

JET_errSuccess

|

The operation was successful.

|
|

JET_errFixedDDL

|

An attempt was made to modify the data definition of a fixed DDL table. An example of a table with fixed DDL is a Template Table.

|
|

JET_errInvalidParameter

|

An invalid parameter was passed into the API. Some examples of invalid parameters are:

* Passing in the wrong size of the [JET_COLUMNDEF](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294130(v=exchg.10).md) structure in its *cbStruct* member.
* Passing in JET_bitColumnUserDefinedDefault, but not setting **cbDefault** to sizeof([JET_USERDEFINEDDEFAULT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269200(v=exchg.10).md)).

|
|

JET_errInTransaction

|

An attempt was made to add a column with the JET_bitColumnUnversioned bit set, but the session is currently in a transaction.

|
|

JET_errColumnDuplicate

|

A column already exists. An attempt was made to add a column without version information, and that column already exists.

|
|

JET_errTableNotEmpty

|

The table contains data. An Escrow Update column can only be added to an empty table.

|
|

JET_errRecordTooBig

|

The record is too big. The sum of the **cbMax** parameter for the fixed columns must not exceed a certain value.

|
|

JET_errTooManyColumns

|

An attempt was made to add too many columns to the table. A table can have no more than JET_ccolFixedMost fixed columns, no more than JET_ccolVarMost variable-length columns, and no more than JET_ccolTaggedMost tagged columns.

|
|

JET_errColumnRedundant

|

An attempt was made to add a redundant column. There should be no more than one autoincrement column, and no more than one version column per table.

|
|

JET_errCallbackNotResolved

|

The callback function could not be resolved. The DLL might not have been found, or the function in the DLL might not have been found. The event log will provide more details if sufficient logging is enabled.

|
|

JET_wrnColumnMaxTruncated

|

A warning indicating that the maximum length (**cbMax**) of a fixed or variable column was greater than JET_cbColumnMost. This limit does not apply to Long Values (that is [JET_coltypLongBinary](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269213(v=exchg.10).md) and [JET_coltypLongText](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269213(v=exchg.10).md)).

|
|

JET_errInvalidName

|

An invalid name was passed as **szColumnName**. For more information about the restrictions, see the criteria for **szColumnName**.

|
|

JET_errInvalidColumnType

|

The **coltyp** field was not set to a valid column type.

|
|

JET_errInvalidCodePage

|

The **cp** parameter of the [JET_COLUMNDEF](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294130(v=exchg.10).md) structure was not set to a valid code page. The only valid values for text columns are English (1252) and Unicode (1200). A value of 0 means the default will be used (English, 1252).

|
|

JET_errTaggedNotNULL

|

JET_bitColumnNotNULL cannot be used with tagged, Long Value, or SLV columns.

|
|

JET_errInvalidgrbit

|

An invalid combination of *grbits* was specified. Some of the reasons for this error are:

* JET_bitColumnFixed was used on a tagged, Long Value, or SLV column.
* JET_bitColumnEscrowUpdate was used on a column that was not of type [JET_coltypLong](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269213(v=exchg.10).md).
* JET_bitColumnEscrowUpdate was used on a Version column (JET_bitColumnVersion).
* JET_bitColumnEscrowUpdate was used on an AutoIncrememnt column (JET_bitColumnAutoincrement).
* JET_bitColumnEscrowUpdate was used on a column that did not have a default value (**cbDefault** was equal to zero).
* JET_bitColumnFinalize was used on a column that was not an Escrow Update column (JET_bitColumnEscrowUpdate was not set).
* JET_bitColumnDeleteOnZero was used on a column that was not an Escrow Update column (JET_bitColumnEscrowUpdate was not set).
* JET_bitColumnAutoincrement was used on a column that was not [JET_coltypLong](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269213(v=exchg.10).md).

  **Windows 2000:** This reason for the error code is used only in Windows 2000.

  JET_bitColumnAutoincrement was used on a column that was neither [JET_coltypLong](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269213(v=exchg.10).md) nor [JET_coltypCurrency](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269213(v=exchg.10).md).

  **Windows XP:** This reason for the error code is used in Windows XP and later operating systems.
* JET_bitColumnVersion was used on a column that was not [JET_coltypLong](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269213(v=exchg.10).md).
* JET_bitColumnVersion was used on an autoincrement column.
* JET_bitColumnUserDefinedDefault was used in conjunction with JET_bitColumnFixed.
* JET_bitColumnUserDefinedDefault was used in conjunction with JET_bitColumnNotNULL.
* JET_bitColumnUserDefinedDefault was used in conjunction with JET_bitColumnVersion.
* JET_bitColumnUserDefinedDefault was used in conjunction with JET_bitColumnAutoincrement.
* JET_bitColumnUserDefinedDefault was used in conjunction with JET_bitColumnUpdatable.
* JET_bitColumnUserDefinedDefault was used in conjunction with JET_bitColumnEscrowUpdate.
* JET_bitColumnUserDefinedDefault was used in conjunction with JET_bitColumnFinalize.
* JET_bitColumnUserDefinedDefault was used in conjunction with JET_bitColumnDeleteOnZero.
* JET_bitColumnUserDefinedDefault was used in conjunction with JET_bitColumnMaybeNull.
* JET_bitColumnUserDefinedDefault was used on a non-tagged column (that is fixed or variable).

|
|

JET_errMultiValuedColumnMustBeTagged

|

A multi-valued column (JET_bitColumnMultiValued) can only be used on a tagged or Long Value ([JET_coltypLongBinary](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269213(v=exchg.10).md) or [JET_coltypLongText](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269213(v=exchg.10).md)) column.

|
|

JET_errCannotBeTagged

|

An attempt was made to use a tagged column when the column might not be tagged. Some of the constraints for disallowing tagged columns are:

* An Escrow Update column (JET_bitColumnEscrowUpdate) cannot be used on a tagged or Long Value ([JET_coltypLongBinary](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269213(v=exchg.10).md) or [JET_coltypLongText](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269213(v=exchg.10).md)) column.
* An autoincrement column might not be tagged.
* A Version column might not be tagged.

|
|

JET_errExclusiveTableLockRequired

|

An exclusive lock on the table was required for this operation.

|
|

JET_wrnColumnMaxTruncated

|

A warning indicating that the maximum length (*cbMax*) of a fixed or variable column was greater than JET_cbColumnMost. This limit does not apply to Long Values (that is [JET_coltypLongBinary](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269213(v=exchg.10).md) and [JET_coltypLongText](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269213(v=exchg.10).md)).

|

#### Requirements

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

**Library**

|

Use ESENT.lib.

|
|

**DLL**

|

Requires ESENT.dll.

|
|

**Unicode**

|

Implemented as **JetAddColumnW** (Unicode) and **JetAddColumnA** (ANSI).

|

#### See Also

[JET_COLTYP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp)
[JET_COLUMNCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columncreate-structure)
[JET_COLUMNDEF](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columndef-structure)
[JET_COLUMNID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columnid)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JetCreateTableColumnIndex](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatetablecolumnindex-function)
[JetCreateTableColumnIndex2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatetablecolumnindex2-function)