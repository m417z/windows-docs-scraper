# JetSetColumn Function

_**Applies to:** Windows | Windows Server_

## JetSetColumn Function

The **JetSetColumn** function modifies a single column value in a modified record to be inserted or to update the current record. It can overwrite an existing value, add a new value to a sequence of values in a multi-valued column, remove a value from a sequence of values in a multi-valued column, or update all or part of a long value, a column of type [JET_coltypLongText](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp) or [JET_coltypLongBinary](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp).

```cpp
    JET_ERR JET_API JetSetColumn(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid,
      __in          JET_COLUMNID columnid,
      __in_opt      const void* pvData,
      __in          unsigned long cbData,
      __in          JET_GRBIT grbit,
      __in_opt      JET_SETINFO* psetinfo
    );
```

### Parameters

*sesid*

The session to use for this call.

*tableid*

The cursor to use for this call.

*columnid*

The [JET_COLUMNID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columnid) of the column to be retrieved. Alternatively, a *columnid* value of 0 (zero) can be given. When *columnid* 0 (zero) is given, all tagged columns, sparse and multi-valued columns, are treated as a single column. This facilitates retrieving all sparse columns that are present in a record.

*pvData*

Input buffer containing data to use for column value.

*cbData*

Size in bytes of the input buffer.

*grbit*

A group of bits that contain the options to be used for this call, which include zero or more of the following:

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitSetAppendLV

|

This option is used to append data to a column of type [JET_coltypLongText](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269213(v=exchg.10).md) or [JET_coltypLongBinary](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269213(v=exchg.10).md). The same behavior can be achieved by determining the size of the existing long value and specifying *ibLongValue* in *psetinfo*. However, it's simpler to use this *grbit* since knowing the size of the existing column value is not necessary.

|
|

JET_bitSetOverwriteLV

|

This option is used replace the existing long value with the newly provided data. When this option is used, it is as though the existing long value has been set to 0 (zero) length prior to setting the new data.

|
|

JET_bitSetRevertToDefaultValue

|

This option is only applicable for tagged, sparse or multi-valued columns. It causes the column to return the default column value on subsequent retrieve column operations. All existing column values are removed.

|
|

JET_bitSetSeparateLV

|

This option is used to force a long value, columns of type [JET_coltypLongText](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269213(v=exchg.10).md) or [JET_coltypLongBinary](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269213(v=exchg.10).md), to be stored separately from the remainder of record data. This occurs normally when the size of the long value prevents it from being stored with remaining record data. However, this option can be used to force the long value to be stored separately. Note that long values four bytes in size of smaller cannot be forced to be separate. In such cases, the option is ignored.

|
|

JET_bitSetSizeLV

|

This option is used to interpret the input buffer as an integer number of bytes to set as the length of the long value described by the given *columnid* and if provided, the sequence number in psetinfo->itagSequence. If the size given is larger than the existing column value, the column will be extended with 0s. If the size is smaller than the existing column value then the value will be truncated.

|
|

JET_bitSetUniqueMultiValues

|

This option is used to enforce that all values in a multi-valued column are distinct. This option compares the source column data, without any transformations, to other existing column values and an error is returned if a duplicate is found. If this option is given, then JET_bitSetAppendLV, JET_bitSetOverwriteLV and JET_bitSetSizeLV cannot also be given.

|
|

JET_bitSetUniqueNormalizedMultiValues

|

This option is used to enforce that all values in a multi-valued column are distinct. This option compares the key normalized transformation of column data, to other similarly transformed existing column values and an error is returned if a duplicate is found. If this option is given, then JET_bitSetAppendLV, JET_bitSetOverwriteLV and JET_bitSetSizeLV cannot also be given.

|
|

JET_bitSetZeroLength

|

This option is used to set a value to zero length. Normally, a column value is set to **NULL** by passing a cbMax of 0 (zero). However, for some types, like [JET_coltypText](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269213(v=exchg.10).md), a column value can be 0 (zero) length instead of **NULL**, and this option is used to differentiate between **NULL** and 0 (zero) length.

**Note** In general, if the column is a fixed-length column, this bit is ignored and the column is set to **NULL**. However, if the column is a fixed-length tagged column, the column length is set to 0. When the fixed-length tagged column is set to 0 length, attempts to retrieve the column with [JetRetrieveColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269198(v=exchg.10).md) or [JetRetrieveColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294135(v=exchg.10).md) will succeed, but the actual length that is returned in the *cbActual* parameter is 0.

|
|

JET_bitSetIntrinsicLV

|

This option is used to store the entire long value in the record.

|
|

JET_bitSetCompressed

|

This option is used to attempt data compression when storing the data.

**Windows 7:** JET_bitSetCompressed is introduced in Windows 7.

|
|

JET_bitSetUncompressed

|

This option is used not attempt compression when storing the data.

**Windows 7:** JET_bitSetUnCompressed is introduced in Windows 7.

|

*psetinfo*

Pointer to optional input parameters that can be set for this function using the [JET_SETINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-setinfo-structure) structure.

If *psetinfo* is given as **NULL** then the function behaves as though an *itagSequence* of 1 and an *ibLongValue* of 0 (zero) were given. This causes column set to set the first value of a multi-valued column, and to set long data beginning at offset 0 (zero).

The following options can be set for this parameter:

|

Value

|

Meaning

|
|--------------|----------------|
|

ibLongValue

|

Binary offset into a long column value where set data should begin.

|
|

itagSequence

|

Sequence number of the desired multi-valued column value to set. If *itagSequence* is set to 0 (zero), then the value provided should be appended to then end of the sequence of multi-valued values. If the sequence number provided is greater than the last existing multi-valued value, then again the given value is appended to the end of the sequence of values. If the sequence number corresponds to an existing value then that value is replaced with the given value.

|

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

JET_errColumnNotFound

|

The column described by the given *columnid* does not exist in the table.

|
|

JET_errColumnNotUpdatable

|

An illegal attempt was made to update a long value during a insert copy delete original update operation.

|
|

JET_errColumnTooBig

|

The given column value data given in the input buffer exceeds the size limitation either natural for a fixed length column or configured for fixed length text or binary columns. This error is also returned when passing more than 1024 bytes of data for a long column and setting the JET_bitSetIntrinsicLV flag.

|
|

JET_errInstanceUnavailable

|

It is not possible to complete the operation because the instance associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data.

**Windows XP:** This error will only be returned by Windows XP and later releases.

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

An illegal attempt was made to set a non-**NULL** column to **NULL**.

|
|

JET_errColumnIllegalNull

|

Same as JET_errNullInvalid.

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

The same session cannot be used for more than one thread at the same time.

**Windows XP:** This error will only be returned by Windows XP and later releases.

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

JET_errVersionStoreOutOfMemory

|

This error will occur when the configured size of the version store is insufficient to hold all outstanding updates.

|
|

JET_wrnColumnMaxTruncated

|

The column value in the input buffer exceeded the maximum configured length for a variable length column and was truncated.

|

On success, the desired portion of a column value for the given column is set with data copied from the input buffer. The data set may have been truncated if it exceeded the maximum length specified for a variable length column.

On failure, the cursor location is left unchanged and no column value data is updated in the copy buffer.

#### Remarks

Setting long values, values for columns [JET_coltypLongBinary](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp) of type [JET_coltypLongText](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp) or [JET_coltypLongBinary](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp), should be done only when the calling session is in a transaction. If the calling session is not in a transaction, modifications to long values which are stored separately may be committed fully even when the update operation is later cancelled. If the calling session is in a transaction, then the effects of the update can be fully rolled back by canceling the update and rolling back the session transaction.

Index updates are not performed as a result of **JetSetColumn** operations. Instead, indexes are updated only after all column modifications are complete and [JetUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetupdate-function) is called. This permits the most efficient updating of indexes when indexes involve more than one column being modified.

A record is limited in size based on the database page size. Any long values in the record larger than five bytes will be stored separate from the record should the data in the record exceed its limit as a result of a **JetSetColumn** operation. The error JET_errRecordTooBig will only be returned after all separable record column data has been stored separately from the record and the record still exceeds the record size limit.

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

[JET_COLUMNID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columnid)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JET_SETINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-setinfo-structure)
[JetRetrieveColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievecolumn-function)
[JetSetColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcolumns-function)