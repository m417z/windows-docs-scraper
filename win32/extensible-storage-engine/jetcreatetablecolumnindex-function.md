# JetCreateTableColumnIndex Function

_**Applies to:** Windows | Windows Server_

## JetCreateTableColumnIndex Function

The **JetCreateTableColumnIndex** function creates a table in an ESE database with an initial set of indexes and an initial set of columns from an array of [JET_TABLECREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tablecreate-structure) structures. The name **JetCreateTableColumnIndex** comes from the order of creation of the objects. It first creates a table, columns, and then finally indexes.

```cpp
    JET_ERR JET_API JetCreateTableColumnIndex(
      __in          JET_SESID sesid,
      __in          JET_DBID dbid,
      __in_out      JET_TABLECREATE* ptablecreate
    );
```

### Parameters

*sesid*

The database session context to use for the API call.

*dbid*

The database identifier to use for the API call.

*ptablecreate*

A pointer to a [JET_TABLECREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tablecreate-structure) structure which defines the table to be created. See [JET_TABLECREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tablecreate-structure) for more details.

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

The operation completed successfully.

|
|

JET_errCallbackNotResolved

|

The callback function could not be resolved. The DLL might not have been found, or the function in the DLL might not have been found. With sufficient logging enabled, the event log will provide more details.

|
|

JET_errCannotIndex

|

An attempt was made to index over an escrow-update or SLV column (note that SLV columns are deprecated).

|
|

JET_errCannotNestDDL

|

If ptablecreate->grbit specifies JET_bitTableCreateTemplateTable, but ptablecreate->szTemplateTableName is set to NULL.

|
|

JET_errColumnDuplicate

|

A column already exists.

|
|

JET_errColumnNotFound

|

An attempt was made to index over a non-existent column. Attempting to conditionally index over a non-existent column can also produce this error.

|
|

JET_errColumnRedundant

|

An attempt was made to add a redundant column. There should be no more than one autoincrement column, and no more than one version column per table.

|
|

JET_errDensityInvalid

|

This error will be returned if the **ulDensity** member of the [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) structure is set to a number less than 20 or more than 100.

|
|

JET_errDDLNotInheritable

|

Signifies that the table named in the **szTemplateTableName** member of the [JET_TABLECREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294146(v=exchg.10).md) structure was not marked as a template table (that is, that table did not have JET_bitTableCreateTemplateTable set).

|
|

JET_errIndexDuplicate

|

An attempt to define two identical indexes was made.

|
|

JET_errIndexHasPrimary

|

An attempt was made to specify more than one primary index for a table. A table must have exactly one primary index. If no primary index is specified, the database engine will transparently create one.

|
|

JET_errIndexInvalidDef

|

An invalid index definition was specified. Some of the possible reasons for receiving this error are:

* A primary index is conditional (that is, the **grbit** member of the [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) structure has JET_bitIndexPrimary set, and **cConditionalColumn** member of the [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) structure is greater than zero).
* Windows Server 2003 and later. Attempting to create a tuple index with tuple limits, but without passing the **ptuplelimits** member in the [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) structure (that is, the **grbit** member of the [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) structure has JET_bitIndexTupleLimits set, but the **ptuplelimits** pointer is NULL).
* Passing in an invalid key definition in the **szKey** member of the [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) structure. See [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) for a discussion of valid definitions.
* Setting the **cbVarSegMac** member in [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) to be greater than JET_cbPrimaryKeyMost (for a primary index) or greater than JET_cbSecondaryKeyMost (for a secondary index).
* Passing an invalid combination for a user-defined Unicode index (one which has the JET_bitIndexUnicode bit set in the **grbit** member of [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md)). Some common causes include the **pidxunicode** member of the [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) structure is NULL, or the LCID specified in the **pidxunicode** structure is invalid.
* Specifying a multi-valued column for a primary index.
* Trying to index too many conditional columns. The **cConditionalColumn** member of the [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) structure must not be greater than JET_ccolKeyMost.

|
|

JET_errIndexTuplesInvalidLimits

|

Windows XP and later. A [JET_TUPLELIMITS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269207(v=exchg.10).md) structure was specified, and its limits are not supported. See the remarks section of the [JET_TUPLELIMITS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269207(v=exchg.10).md) structure.

|
|

JET_errIndexTuplesNonUniqueOnly

|

Windows XP and later. A tuple index cannot be unique (that is, the *grbit* member of the [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) structure must not have both JET_bitIndexPrimary and JET_bitIndexUnique set).

|
|

JET_errIndexTuplesOneColumnOnly

|

Windows XP and later. A tuple index can only be over a single column (that is, if the **grbit** member of the [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) structure has JET_bitIndexTuples set, and the **szKey** member of the [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) structure specifies more than one column).

|
|

JET_errIndexTuplesSecondaryIndexOnly

|

Windows XP and later. A tuple index cannot be a primary index (that is, the **grbit** member of the [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) structure must not have both JET_bitIndexPrimary and JET_bitIndexTuples set).

|
|

JET_errIndexTuplesTextColumnsOnly

|

Windows XP and later. A tuple index can only be on a text or Unicode column. An attempt to index other columns (such as binary columns) will result in JET_errIndexTuplesTextColumnsOnly.

|
|

JET_errIndexTuplesVarSegMacNotAllowed

|

Windows XP and later. A tuple index does not allow the **cbVarSegMac** member of the [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) structure to be set.

|
|

JET_errInTransaction

|

An attempt was made to create an index without version information while in a transaction.

|
|

JET_errInvalidCodePage

|

The **cp** member of the [JET_COLUMNCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269252(v=exchg.10).md) structure was not set to a valid code page. The only valid values for text columns are English (1252) and Unicode (1200). A value of 0 means the default will be used (English, 1252).

|
|

JET_errInvalidColumnType

|

The **coltyp** member of the [JET_COLUMNCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269252(v=exchg.10).md) structure was not set to a valid column type.

|
|

JET_errInvalidCreateIndex

|

Some of the reasons this error may occur:

* The **rgindexcreate** member of the [JET_TABLECREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269203(v=exchg.10).md) structure was set to NULL.
* The **rgcolumncreate** member of the [JET_TABLECREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269203(v=exchg.10).md) structure was set to NULL.
* The **cbStruct** member of a [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) structure was not set to a valid value.

|
|

JET_errInvalidgrbit

|

An invalid combination of **grbit** members was specified in [JET_TABLECREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294146(v=exchg.10).md) or [JET_TABLECREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269203(v=exchg.10).md).

The index definition is invalid because the **grbit** member contains inconsistent values. Some possible reasons are:

* A primary index had an ignore bit specified (that is, JET_bitIndexPrimary was passed with JET_bitIndexIgnoreNull, JET_bitIndexIgnoreAnyNull, or JET_bitIndexIgnoreFirstNull).
* An empty index does not ignore any NULL members (that is, the **grbit** member of the [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) structure has JET_bitIndexEmpty set, but does not have JET_bitIndexIgnoreAnyNull set).
* Passing in a [JET_CONDITIONALCOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269214(v=exchg.10).md) structure with an invalid **grbit** member.

|
|

JET_errInvalidLanguageId

|

An invalid Locale ID (LCID) was passed in (either through the **lcid** member of the [JET_UNICODEINDEX](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294097(v=exchg.10).md) structure which is pointed to by the **pidxunicode** member in the [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) structure, or through the **lcid** field of the [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) structure).

|
|

JET_errInvalidParameter

|

An invalid parameter was given. Some possible reasons are:

* The **rgcolumncreate** member of the [JET_TABLECREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269203(v=exchg.10).md) structure is NULL.
* The **cbStruct** member of one of the [JET_COLUMNCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269252(v=exchg.10).md) structures given in the **rgcolumncreate** member of the [JET_TABLECREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269203(v=exchg.10).md) structure was not set to sizeof( JET_COLUMNCREATE).
* The **cbKey** member of a [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) structure is set to zero.
* The **cbStruct** member of a [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) structure is not set to sizeof( JET_INDEXCREATE).

|
|

JET_errRecordTooBig

|

The record is too big. The sum of the **cbMax** member of the [JET_COLUMNCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269252(v=exchg.10).md) structure for all fixed columns must not exceed a certain value.

|
|

JET_errTableDuplicate

|

The table already exists.

|
|

JET_errTooManyColumns

|

An attempt was made to add too many columns to the table. A table can have no more than JET_ccolFixedMost fixed columns, no more than JET_ccolVarMost variable-length columns, and no more than JET_ccolTaggedMost tagged columns.

|
|

JET_errUnicodeTranslationFail

|

An error occurred attempting to normalize a Unicode column. This can be caused by running out of system resources.

|

#### Remarks

Calling **JetCreateTableColumnIndex** is identical to calling [JetCreateTableColumnIndex2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatetablecolumnindex2-function), with each field in the [JET_TABLECREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tablecreate2-structure) structure containing the value of the corresponding field of [JET_TABLECREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tablecreate-structure), with the following exceptions:

  - JET_TABLECREATE2.cbStruct set to sizeof( JET_TABLECREATE2)

  - JET_TABLECREATE2.szCallback set to NULL

  - JET_TABLECREATE2.cbtyp set to 0

See [JetCreateTableColumnIndex2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatetablecolumnindex2-function) for more details.

Like [JetOpenTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopentable-function), when the application is done using the returned *tableid*, it should usually be closed with [JetCloseTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosetable-function).

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

Implemented as **JetCreateTableColumnIndexW** (Unicode) and **JetCreateTableColumnIndexA** (ANSI).

|

#### See Also

[JET_DBID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-dbid)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JET_TABLECREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tablecreate-structure)
[JET_TABLECREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tablecreate2-structure)
[JetAddColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetaddcolumn-function)
[JetCreateTableColumnIndex]()
[JetCreateTableColumnIndex2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatetablecolumnindex2-function)