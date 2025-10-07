# JetCreateIndex4W Function

_**Applies to:** Windows | Windows Server_

The **JetCreateIndex4W** function creates indexes over data in an Extensible Storage Engine (ESE) database, which can be used to locate specific data quickly.

The **JetCreateIndex4W** function was introduced in the Windows 8 operating system.

``` c++
JET_ERR JET_API JetCreateIndex4W(
  __in          JET_SESID sesid,
  __in          JET_TABLEID tableid,
  __in          JET_INDEXCREATE2* pindexcreate,
  __in          unsigned long cIndexCreate
);
```

### Parameters

*sesid*

The database session context to use for the API call.

*tableid*

The table on which the index will be created.

*pindexcreate*

An array of [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexcreate2-structure) structures, each of which defines an index to be created.

*cIndexCreate*

The number of elements in the *pindexcreate* array.

### Return value

This function returns the [JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err) data type with one of the return codes listed in the following table. For more information about the possible ESE errors, see [Extensible Storage Engine Errors](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-errors) and [Error Handling Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/error-handling-parameters).

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

JET_errCannotIndex

|

An attempt was made to index over an escrow-update or SLV column (note that SLV columns are deprecated).

|
|

JET_errColumnNotFound

|

An attempt was made to index over a nonexistent column. An attempt to conditionally index over a nonexistent column can also produce this error.

|
|

JET_errDensityInvalid

|

This error will be returned if the **ulDensity** member of the [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) structure is set to a number less than 20 or greater than 100.

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

An invalid index definition was specified. The following are some possible reasons for this error:

* A primary index is conditional (**grbit** member of [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) has **JET_bitIndexPrimary** set, and the **cConditionalColumn** member of [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) is greater than zero).
* Applies to versions of Windows starting with Windows Server 2003. An attempt was made to create a tuple index with tuple limits, but without passing information in the **ptuplelimits** member in [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) (that is, *grbit* has **JET_bitIndexTupleLimits** set, but the **ptuplelimits** pointer is null).
* Passing in an invalid key definition in the **szKey** member of the [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) structure. For information about valid definitions, see [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md).
* Setting the **cbVarSegMac** member in [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) to be greater than **JET_cbPrimaryKeyMost** (for a primary index) or greater than **JET_cbSecondaryKeyMost** (for a secondary index).
* Passing an invalid combination for a user-defined Unicode index (one which has the **JET_bitIndexUnicode** bit set in the **grbit** member of [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md)). Some common causes may be that the pidxunicode field of the [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) structure is null, or the LCID specified in the pidxunicode structure is invalid.
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

Applies to versions of Windows starting with Windows XP. A tuple index cannot be unique (*grbit* must not have both **JET_bitIndexTuples** and **JET_bitIndexUnique** set).

|
|

JET_errIndexTuplesOneColumnOnly

|

Applies to versions of Windows starting with Windows XP. A tuple index can only be over a single column (that is, the **grbit** member of the [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) structure has **JET_bitIndexTuples** set, and the **szKey** member of the [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) structure specifies more than one column).

|
|

JET_errIndexTuplesSecondaryIndexOnly

|

Applies to versions of Windows starting with Windows XP. A tuple index cannot be a primary index (that is, the **grbit** member of the [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) structure must not have both **JET_bitIndexPrimary** and **JET_bitIndexTuples** set).

|
|

JET_errIndexTuplesTextColumnsOnly

|

Applies to versions of Windows starting with Windows XP. A tuple index can only be on a text or Unicode column. An attempt to index other columns (for example, binary columns) will result in **JET_errIndexTuplesTextColumnsOnly**.

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

JET_errInvalidgrbit

|

The index definition is invalid because the **grbit** member of the [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) structure contains inconsistent values. The following are some possible reasons:

* A primary index had an ignore bit specified (JET_bitIndexPrimary was passed with one of **JET_bitIndexIgnoreNull**, **JET_bitIndexIgnoreAnyNull**, or **JET_bitIndexIgnoreFirstNull**).
* An empty index does not ignore any null fields (that is, **grbit** member of the [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) structure has **JET_bitIndexEmpty** set, but does not have **JET_bitIndexIgnoreAnyNull** set).
* Passing in a [JET_CONDITIONALCOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269214(v=exchg.10).md) structure with an invalid **grbit** member. See [JET_CONDITIONALCOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269214(v=exchg.10).md).

When creating several indexes at once (that is, if the *cIndexCreate* parameter is greater than one), none of the indexes may contain any of the following bits:

* **JET_bitIndexPrimary**
* **JET_bitIndexUnversioned**
* **JET_bitIndexEmpty**

|
|

JET_errInvalidLanguageId

|

An invalid Locale ID (LCID) was passed in (either through the **lcid** member in the [JET_UNICODEINDEX](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294097(v=exchg.10).md) structure, which the **pidxunicode** member in the [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) structure contains a pointer to, or through the **lcid** member of the [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) structure).

|
|

JET_errInvalidName

|

An invalid index name was specified. See [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) for more details.

|
|

JET_errInvalidParameter

|

An invalid parameter was passed into the API. The following are some reasons why this error may be returned:

* The **cbKey** field of a [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) structure is set to zero.
* The **cbStruct** member of a [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294082(v=exchg.10).md) structure is not set to sizeof(JET_INDEXCREATE2).

|
|

JET_errUnicodeTranslationFail

|

An error occurred while trying to normalize a Unicode column. This can be caused by running out of system resources.

|
|

JET_errSpaceHintsInvalid

|

An element of the JET space hints structure was not correct or actionable.

|

#### Remarks

The **JetCreateIndex4W** function iterates through the indexes given in the *pindexcreate* parameter, and will sometimes abort on the first failure. Any indexes after the first index with an error may not have been attempted, even though the **err** member of the [JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexcreate2-structure) structure contains JET_errSuccess.

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

[JET_CONDITIONALCOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-conditionalcolumn-structure)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JET_INDEXCREATE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexcreate2-structure)
[JetCreateIndex](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateindex-function)
[JetCreateTableColumnIndex](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatetablecolumnindex-function)
[JetCreateTableColumnIndex2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatetablecolumnindex2-function)
[JET_SPACEHINTS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-spacehints-structure)