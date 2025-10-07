# JetSetColumns Function

_**Applies to:** Windows | Windows Server_

## JetSetColumns Function

The **JetSetColumns** function is similar in behavior to [JetSetColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcolumn-function) but allows an application to set multiple column values in a single operation. An array of [JET_SETCOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-setcolumn-structure) structures is used to describe the set of column values to be set, and to describe input buffers for each column value to be set.

```cpp
    JET_ERR JET_API JetSetColumns(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid,
      __in_out_opt  JET_SETCOLUMN* psetcolumn,
      __in          unsigned long csetcolumn
    );
```

### Parameters

*sesid*

The session to use for this call.

*tableid*

The cursor to use for this call.

*psetcolumn*

A pointer to an array of one or more [JET_SETCOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-setcolumn-structure) structures. Each structure includes descriptions of which column value to set and from where to get column data to set.

*csetcolumn*

The number of [JET_SETCOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-setcolumn-structure) structures in the array given by *psetcolumn*.

### Return Value

This function returns the [JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err) datatype with one of the following return codes. For more information about the possible ESE errors, see [Extensible Storage Engine Errors](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-errors) and [Error Handling Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/error-handling-parameters).

|

Return code

|

Description

|
|--------------------|--------------------|
|

JET_errBadColumnId

|

The column ID given is outside the legal limits of a column ID.

|
|

JET_errClientRequestToStopJetService

|

It is not possible to complete the operation because all activity on the instance associated with the session has ceased as a result of a call to [JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269240(v=exchg.10).md).

|
|

JET_errColumnIllegalNull

|

Same as JET_errNullInvalid.

|
|

JET_errColumnNotFound

|

The column described by the given *columnid* does not exist in the table.

|
|

JET_errColumnNotUpdatable

|

An illegal attempt was made to update a long value during an insert copy delete original update operation.

|
|

JET_errColumnTooBig

|

The given column value data given in the input buffer exceeds the size limitation either natural for a fixed length column or configured for fixed length text or binary columns. This error is also returned when passing more than 1024 bytes of data for a long column and setting the JET_bitSetIntrinsicLV flag.

|
|

JET_errInstanceUnavailable

|

It is not possible to complete the operation because the instance associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data. This error will only be returned by Windows XP and later releases.

|
|

JET_errInvalidBufferSize

|

The given column value data size does not match what is natural for the fixed length data type.

|
|

JET_errInvalidColumnType

|

An illegal attempt was made to update an auto-increment column either during an insert or update operation, or to update a version column during a replace operation.

|
|

JET_errInvalidgrbit

|

The options supplied are unknown or an illegal combination of known bit settings.

|
|

JET_errInvalidParameter

|

The given psetinfo->cbStruct is not a valid size for the [JET_SETINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294090(v=exchg.10).md) structure.

|
|

JET_errMultiValuedDuplicate

|

The set column operation attempted to create a duplicate value and specified either JET_bitSetUniqueMultiValues or JET_bitSetUniqueNormalizedMultiValues.

|
|

JET_errNotInitialized

|

It is not possible to complete the operation because the instance associated with the session has not been initialized yet.

|
|

JET_errNotInTransaction

|

An illegal attempt was made to update a long column value when the calling session was not in a transaction.

|
|

JET_errNullInvalid

|

An illegal attempt was made to set a non-NULL column to NULL.

|
|

JET_errRecordTooBig

|

The column value could not be set to the value in the input buffer because it would have caused the record to exceed its page size related size limitation. Columns of type [JET_coltypLongText](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269213(v=exchg.10).md) or [JET_coltypLongBinary](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269213(v=exchg.10).md) can be stored separately from the remaining record data. However, other columns must be stored with the record and can cause the record size limitation to be exceeded. Even long columns require 5-bytes of space within the record as a linkage and this too can lead to JET_errRecordTooBig being returned.

|
|

JET_errRestoreInProgress

|

It is not possible to complete the operation because a restore operation is in progress on the instance associated with the session.

|
|

JET_errSessionSharingViolation

|

The same session cannot be used for more than one thread at the same time. This error will only be returned by Windows XP and later releases.

|
|

JET_errTermInProgress

|

It is not possible to complete the operation because the instance associated with the session is being shut down.

|
|

JET_errUpdateNotPrepared

|

The cursor is not currently in the process of either inserting a new record or updating an existing record.

|
|

JET_wrnColumnMaxTruncated

|

The column value in the input buffer exceeded the maximum configured length for a variable length column and was truncated.

|

On success, for each column described in the psetcolumns, the desired portion of the column value is set with data copied from the input buffer. The column data set may have been truncated if it exceeded the maximum length specified for a variable length column.

On failure, the cursor location is left unchanged and no column value data is updated in the copy buffer.

#### Remarks

If any individual set column operation returns an error then the whole **JetSetColumns** operation will return an error. Warnings, in general, are returned in the psetcolumns-\>error and not in the return code from this function. However, if the last column set has a warning, then this warning will be returned from **JetSetColumns** itself.

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

#### See Also

[JET_COLTYP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JET_SETCOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-setcolumn-structure)
[JetRetrieveColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievecolumns-function)
[JetSetColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcolumn-function)