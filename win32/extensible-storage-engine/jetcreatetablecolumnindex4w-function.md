# JetCreateTableColumnIndex4W Function

_**Applies to:** Windows | Windows Server_

The **JetCreateTableColumnIndex4W** function creates a table in an Extensible Storage Engine (ESE( database with an initial set of indexes and an initial set of columns from an array of [JET_TABLECREATE3](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tablecreate3-structure) structures. The [JET_TABLECREATE3](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tablecreate3-structure) structure allows a callback function to be specified.

The **JetCreateTableColumnIndex4W** function was introduced in the Windows 8 operating system.

``` c++
JET_ERR JET_API JetCreateTableColumnIndex4W(
  __in          JET_SESID sesid,
  __in          JET_DBID dbid,
  __in_out      JET_TABLECREATE3* ptablecreate
);
```

### Parameters

*sesid*

The database session context to use for the API call.

*dbid*

The database identifier to use for the API call.

*ptablecreate*

A pointer to a [JET_TABLECREATE3](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tablecreate3-structure) structure that defines the table to be created. See [JET_TABLECREATE3](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tablecreate3-structure) for more details.

### Return value

This function returns the [JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err) datatype with one of the return codes listed in the following table. For more information about the possible Extensible Storage Enginge (ESE) errors, see [Extensible Storage Engine Errors](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-errors) and [Error Handling Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/error-handling-parameters).

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

Returned if the *ptablecreate->grbit* parameter specifies the JET_bitTableCreateTemplateTable value, but the *ptablecreate->szTemplateTableName* parameter is set to null.

|
|

JET_errColumnDuplicate

|

A column already exists.

|
|

JET_errColumnNotFound

|

An attempt was made to index over a nonexistent column. An attempt to conditionally index over a nonexistent column can also produce this error.

|
|

JET_errColumnRedundant

|

An attempt was made to add a redundant column. No more than one autoincrement column should exist, and no more than one version column should exist per table.

|
|

JET_errDensityInvalid

|

This error will be returned if the **ulDensity** member of the [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) structure is set to a number less than 20 or more than 100.

|
|

JET_errDDLNotInheritable

|

Signifies that the table named in the **szTemplateTableName** member of the [JET_TABLECREATE3](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269264(v=exchg.10).md) structure was not marked as a template table (that is, that table did not have the JET_bitTableCreateTemplateTable parameter value set).

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

An invalid index definition was specified. The following are some of the possible reasons for this error:

* A primary index is conditional (that is, the **grbit** member of the [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) structure has the JET_bitIndexPrimary value set, and the **cConditionalColumn** member of the [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) structure is greater than zero).
* Applies to versions of the Windows Server operating system starting with Windows Server 2003. An attempt to create a tuple index with tuple limits, but without passing the **ptuplelimits** member in the [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) structure (that is, the **grbit** member of the **JET_INDEXCREATE2** structure has JET_bitIndexTupleLimits value set, but the **ptuplelimits** pointer is null).
* Passing in an invalid key definition in the **szKey** member of the [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) structure. For information about valid definitions, see [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md).
* Setting the **cbVarSegMac** member in [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) to be greater than the JET_cbPrimaryKeyMost value (for a primary index) or greater than the JET_cbSecondaryKeyMost value (for a secondary index).
* Passing an invalid combination for a user-defined Unicode index (one that has the JET_bitIndexUnicode value bit set in the **grbit** member of the [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) structure). Some common causes include the **pidxunicode** member of the [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) structure is null, or the LCID specified in the **pidxunicode** structure is invalid.
* Specifying a multivalued column for a primary index.
* Trying to index too many conditional columns. The **cConditionalColumn** member of the [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) structure must not be greater than **JET_ccolKeyMost**.

|
|

JET_errIndexTuplesInvalidLimits

|

Applies to versions of Windows starting with Windows XP. A [JET_TUPLELIMITS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269207(v=exchg.10).md) structure was specified, and its limits are not supported. For more information, see the remarks section of the [JET_TUPLELIMITS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269207(v=exchg.10).md) structure.

|
|

JET_errIndexTuplesNonUniqueOnly

|

Applies to versions of Windows starting with Windows XP. A tuple index cannot be unique (that is, the *grbit* member of the [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) structure must not have both JET_bitIndexPrimary and JET_bitIndexUnique values set).

|
|

JET_errIndexTuplesOneColumnOnly

|

Applies to versions of Windows starting with Windows XP. A tuple index can only be over a single column (that is, if the **grbit** member of the [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) structure has JET_bitIndexTuples value set, and the **szKey** member of the [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) structure specifies more than one column).

|
|

JET_errIndexTuplesSecondaryIndexOnly

|

Applies to versions of Windows starting with Windows XP. A tuple index cannot be a primary index (that is, the **grbit** member of the [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) structure must not have both JET_bitIndexPrimary and JET_bitIndexTuples set).

|
|

JET_errIndexTuplesTextColumnsOnly

|

Applies to versions of Windows starting with Windows XP. A tuple index can only be on a text or Unicode column. An attempt to index other columns (such as binary columns) will result in a JET_errIndexTuplesTextColumnsOnly response code.

|
|

JET_errIndexTuplesVarSegMacNotAllowed

|

Applies to versions of Windows starting with Windows XP. A tuple index does not allow the **cbVarSegMac** member of the [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) structure to be set.

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

The following are some reasons why this error may occur:

* The **rgindexcreate** member of the [JET_TABLECREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269203(v=exchg.10).md) structure was set to null.
* The **rgcolumncreate** member of the [JET_TABLECREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269203(v=exchg.10).md) structure was set to null.
* The **cbStruct** member of a [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) structure was not set to a valid value.

|
|

JET_errInvalidgrbit

|

An invalid combination of **grbit** members was specified in the [JET_TABLECREATE3](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269264(v=exchg.10).md) structure.

The index definition is invalid because the **grbit** member contains inconsistent values. The following are some possible reasons:

* A primary index had an ignore bit specified (that is, JET_bitIndexPrimary value was passed with the JET_bitIndexIgnoreNull, JET_bitIndexIgnoreAnyNull, or JET_bitIndexIgnoreFirstNull values).
* An empty index does not ignore any null members (that is, the **grbit** member of the [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) structure has the JET_bitIndexEmpty value set, but does not have JET_bitIndexIgnoreAnyNull value set).
* Passing in a [JET_CONDITIONALCOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269214(v=exchg.10).md) structure with an invalid **grbit** member.

|
|

JET_errInvalidLanguageId

|

An invalid Locale ID (LCID) was passed in (either through the **lcid** member of the [JET_UNICODEINDEX](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294097(v=exchg.10).md) structure that the **pidxunicode** member in the [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) structure points to, or through the **lcid** field of the [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) structure).

|
|

JET_errInvalidParameter

|

An invalid parameter was given. The following are some possible reasons:

* The **rgcolumncreate** member of the [JET_TABLECREATE3](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269264(v=exchg.10).md) structure is null.
* The **cbStruct** member of one of the [JET_COLUMNCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269252(v=exchg.10).md) structures given in the **rgcolumncreate** member of the [JET_TABLECREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269203(v=exchg.10).md) structure was not set to sizeof( JET_COLUMNCREATE ).
* The **cbKey** member of a [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) structure is set to zero.
* The **cbStruct** member of a [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) structure is not set to sizeof( JET_INDEXCREATE2 ).

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

An attempt was made to add too many columns to the table. A table can have no more than **JET_ccolFixedMost** fixed columns, no more than **JET_ccolVarMost** variable-length columns, and no more than **JET_ccolTaggedMost** tagged columns.

|
|

JET_errUnicodeTranslationFail

|

An error occurred when an attempt was made to normalize a Unicode column. This can be caused by running out of system resources.

|
|

JET_errSpaceHintsInvalid

|

An element of the JET space hints structure was not correct or actionable.

|

#### Remarks

The **JetCreateTableColumnIndex4W** function creates a table with an initial set of columns and indexes. Additional columns and indexes can be added and removed dynamically by means of the [JetAddColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetaddcolumn-function), [JetDeleteColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdeletecolumn-function), [JetDeleteColumn2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdeletecolumn2-function), [JetCreateIndex](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateindex-function), [JetCreateIndex2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateindex2-function), [JetCreateIndex3](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateindex3-function), [JetCreateIndex4W](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateindex4w-function), and [JetDeleteIndex](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdeleteindex-function) functions.

As with the [JetOpenTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopentable-function) function, when the application is done using the returned *tableid*, the [JetCloseTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosetable-function) function should close the application.

#### Requirements

| Requirement | Value |
|------------|----------|
|

**Client**

|

Requires Windows 8.

|
|

**Server**

|

Requires Windows Server 2012.

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

#### See also

[JET_CBTYP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-cbtyp)
[JET_DBID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-dbid)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexcreate-structure)
[JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexcreate2-structure)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JET_TABLECREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tablecreate2-structure)
[JET_TABLECREATE3](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tablecreate3-structure)
[JET_TUPLELIMITS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tuplelimits-structure)
[JetAddColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetaddcolumn-function)
[JetCreateIndex](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateindex-function)
[JetCreateIndex2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateindex2-function)
[JetCreateIndex3](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateindex3-function)
[JetCreateTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatetable-function)
[JetCreateTableColumnIndex](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatetablecolumnindex-function)
[JetDeleteColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdeletecolumn-function)
[JetDeleteColumn2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdeletecolumn2-function)