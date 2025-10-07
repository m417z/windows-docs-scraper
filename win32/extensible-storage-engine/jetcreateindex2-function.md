# JetCreateIndex2 Function

_**Applies to:** Windows | Windows Server_

## JetCreateIndex2 Function

The **JetCreateIndex2** function creates indexes over data in an ESE database, which can be used to locate specific data quickly.

```cpp
    JET_ERR JET_API JetCreateIndex2(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid,
      __in          JET_INDEXCREATE* pindexcreate,
      __in          unsigned long cIndexCreate
    );
```

### Parameters

*sesid*

The database session context to use for the API call.

*tableid*

The table on which the index will be created.

*pindexcreate*

An array of [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexcreate-structure) structures, each of which defines an index to be created.

*cIndexCreate*

The number of elements in the *pindexcreate* array.

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

JET_errCannotIndex

|

An attempt was made to index over an escrow-update or SLV column (note that SLV columns are deprecated).

|
|

JET_errColumnNotFound

|

An attempt was made to index over a non-existent column. Attempting to conditionally index over a non-existent column can also produce this error.

|
|

JET_errDensityInvalid

|

This error will be returned if the **ulDensity** member of the [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) structure is set to a number less than 20 or more than 100.

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

* A primary index is conditional (**grbit** member of [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) has JET_bitIndexPrimary set, and the **cConditionalColumn** member of [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) is greater than zero).
* Windows Server 2003 and later. Attempting to create a tuple index with tuple limits, but without passing information in the **ptuplelimits** member in [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) (that is, *grbit* has JET_bitIndexTupleLimits set, but the **ptuplelimits** pointer is NULL).
* Passing in an invalid key definition in the **szKey** member of the [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) structure. See [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) for a discussion of valid definitions.
* Setting the **cbVarSegMac** member in [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) to be greater than JET_cbPrimaryKeyMost (for a primary index) or greater than JET_cbSecondaryKeyMost (for a secondary index).
* Passing an invalid combination for a user-defined Unicode index (one which has the JET_bitIndexUnicode bit set in the **grbit** member of [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md)). Some common causes may be that the pidxunicode field of the [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) structure is NULL, or the LCID specified in the pidxunicode structure is invalid.
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

Windows XP and later. A tuple index cannot be unique (*grbit* must not have both JET_bitIndexTuples and JET_bitIndexUnique set).

|
|

JET_errIndexTuplesOneColumnOnly

|

Windows XP and later. A tuple index can only be over a single column (that is, the **grbit** member of the [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) structure has JET_bitIndexTuples set, and the **szKey** member of the [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) structure specifies more than one column).

|
|

JET_errIndexTuplesSecondaryIndexOnly

|

Windows XP and later. A tuple index cannot be a primary index (that is, the **grbit** member of the [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) structure must not have both JET_bitIndexPrimary and JET_bitIndexTuples set).

|
|

JET_errIndexTuplesTextColumnsOnly

|

Windows XP and later. A tuple index can only be on a text or Unicode column. An attempt to index other columns (for example, binary columns) will result in JET_errIndexTuplesTextColumnsOnly.

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

JET_errInvalidgrbit

|

The index definition is invalid because the **grbit** member of the [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) structure contains inconsistent values. Some possible reasons are:

* A primary index had an ignore bit specified (JET_bitIndexPrimary was passed with one of JET_bitIndexIgnoreNull, JET_bitIndexIgnoreAnyNull, or JET_bitIndexIgnoreFirstNull).
* An empty index does not ignore any NULL fields (that is, **grbit** member of the [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) structure has JET_bitIndexEmpty set, but does not have JET_bitIndexIgnoreAnyNull set).
* Passing in a [JET_CONDITIONALCOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269214(v=exchg.10).md) structure with an invalid **grbit** member. See [JET_CONDITIONALCOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269214(v=exchg.10).md).

When creating several indexes at once (that is, if the *cIndexCreate* parameter is greater than one), none of the indexes may contain any of the following bits:

* JET_bitIndexPrimary
* JET_bitIndexUnversioned
* JET_bitIndexEmpty

|
|

JET_errInvalidLanguageId

|

An invalid Locale ID (LCID) was passed in (either through the **lcid** member in the [JET_UNICODEINDEX](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294097(v=exchg.10).md) structure, which the **pidxunicode** member in the [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) structure contains a pointer to, or through the **lcid** member of the [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) structure).

|
|

JET_errInvalidName

|

An invalid index name was specified. See [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) for more details.

|
|

JET_errInvalidParameter

|

An invalid parameter was passed into the API. Some of the reasons this error may be returned are:

* The **cbKey** field of a [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) structure is set to zero.
* The **cbStruct** member of a [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) structure is not set to sizeof([JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269186(v=exchg.10).md) ).

|
|

JET_errUnicodeTranslationFail

|

An error occurred attempting to normalize a Unicode column. This can be caused by running out of system resources.

|

#### Remarks

The return value is JET_errSuccess on successful completion of all indexes specified.

**JetCreateIndex2** iterates through the indexes given in **pindexcreate**, and will sometimes abort on the first failure. Any indexes after the first index with an error may not have been attempted, even though the **err** member of the [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexcreate-structure) structure contains JET_errSuccess.

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

Implemented as **JetCreateIndex2W** (Unicode) and **JetCreateIndex2A** (ANSI).

|

#### See Also

[JET_CONDITIONALCOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-conditionalcolumn-structure)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexcreate-structure)
[JetCreateIndex](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateindex-function)
[JetCreateTableColumnIndex](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatetablecolumnindex-function)
[JetCreateTableColumnIndex2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatetablecolumnindex2-function)