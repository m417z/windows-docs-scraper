# JetEnumerateColumns Function

_**Applies to:** Windows | Windows Server_

## JetEnumerateColumns Function

The **JetEnumerateColumns** function efficiently retrieves a set of columns and their values from the current record of a cursor or the copy buffer of that cursor. The columns and values retrieved can be restricted by a list of column IDs, *itagSequence* numbers, and other characteristics. This column retrieval API is unique in that it returns information in dynamically allocated memory that is obtained using a user-provided [realloc](https://learn.microsoft.com/cpp/c-runtime-library/reference/realloc) compatible callback. This new flexibility permits the efficient retrieval of column data with specific characteristics (such as size and multiplicity) that are unknown to the caller. This eliminates the need for the use of the discovery modes of [JetRetrieveColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievecolumn-function) to determine those characteristics in order to setup a final call to [JetRetrieveColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievecolumn-function) that will successfully retrieve the desired data.

**Windows XP: JetEnumerateColumns** is introduced in Windows XP.

```cpp
    JET_ERR JET_API JetEnumerateColumns(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid,
      __in          unsigned long cEnumColumnId,
      __in_opt      JET_ENUMCOLUMNID* rgEnumColumnId,
      __out         unsigned long* pcEnumColumn,
      __out         JET_ENUMCOLUMN** prgEnumColumn,
      __in          JET_PFNREALLOC pfnRealloc,
      __in          void* pvReallocContext,
      __in          unsigned long cbDataMost,
      __in          JET_GRBIT grbit
    );
```

### Parameters

*sesid*

The session to use for this call.

*tableid*

The cursor to use for this call.

*cEnumColumnId*

An array of column IDs, each with an optional array of *itagSequence* numbers to enumerate.

If *cEnumColumnId* is 0 (zero) then *rgEnumColumnId* is ignored and all column values are enumerated and returned to the caller. If an element of the column ID array refers to a column ID of 0 (zero) then enumeration of that column is skipped and a corresponding slot in the output will be generated with a column status of JET_wrnColumnSkipped.

If *ctagSequence* is 0 (zero) for a given element of the column ID array then *rgtagSequence* is ignored and all column values for that column ID are enumerated and returned to the caller. If an element of an *itagSequence* number array refers to a *itagSequence* number of 0 (zero) then the enumeration of that *itagSequence* number is skipped and a corresponding slot in the output will be generated with a column value status of JET_wrnColumnSkipped.

*rgEnumColumnId*

See *cEnumColumnId*.

*pcEnumColumn*

Returns the enumerated array of columns and their values in memory allocated through the provided *itagSequence* compatible callback.

If an array of column IDs is requested on input then the order and size of the output array will reflect the order and size of the input array. Similarly, if an array of *itagSequence* numbers is requested for a particular column ID on input then the order and size of the output array of column values for that column will reflect the order and size of the input array.

The output parameters are set to 0 (zero) and **NULL** on any error except for JET_errBadColumnId and JET_errColumnNotFound. When these errors are returned, the output data is valid and complete for all but the affected column IDs. The status code for each of the affected column IDs is set to one of these errors so that the caller may determine which column IDs were bad and potentially take corrective action.

*prgEnumColumn*

See *pcEnumColumn*.

*pfnRealloc*

Identifies a [realloc](https://learn.microsoft.com/cpp/c-runtime-library/reference/realloc) compatible callback and an optional context pointer used to allocate memory for the output array of columns and their values.

*pvReallocContext*

See *pfnRealloc*.

*cbDataMost*

Sets a cap on the amount of data to return from a long text or long binary column.

This parameter can be used to prevent the enumeration of an extremely large column value. Ordinarily, such an enumeration might fail the API call with JET_errOutOfMemory. If a large column value is truncated in such a manner then the column value's status will be JET_wrnColumnTruncated.

*grbit*

A group of bits specifying zero or more of the following options.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitEnumerateCompressOutput

|

When enumerating column values, all columns for which we are retrieving all values and that have only one non-NULL column value may be returned in a compressed format. The status for such columns will be set to JET_wrnColumnSingleValue and the size of the column value and the memory containing the column value will be returned directly in the [JET_ENUMCOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294138(v=exchg.10).md) structure. It is not guaranteed that all eligible columns are compressed in this manner. See [JET_ENUMCOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294138(v=exchg.10).md) for more information.

|
|

JET_bitEnumerateCopy

|

This option indicates that the modified column values of the record should be enumerated rather than the original column values. If a column value has not been modified, the original column value is enumerated. In this way, a column value that has not yet been inserted or updated may be enumerated when inserting or updating a record.

This option is identical to JET_bitRetrieveCopy when used with [JetRetrieveColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269198(v=exchg.10).md) or [JetRetrieveColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294135(v=exchg.10).md).

|
|

JET_bitEnumerateIgnoreDefault

|

If a given column is not present in the record then no column value will be returned. Ordinarily, the default value for the column, if any, would be returned in this case. It is guaranteed that if the column is set to a value different than the default value then that different value will be returned (that is, if a column with a default value is explicitly set to **NULL** then a **NULL** will be returned as the value for that column). Note that, even if this option is requested, it is still possible to see a column value that happens to be equal to the default value. No effort is made to remove column values that match their default values.

It is important to note that this option affects the output of **JetEnumerateColumns** when used with JET_bitEnumeratePresenceOnly or JET_bitEnumerateTaggedOnly.

|
|

JET_bitEnumerateIgnoreUserDefinedDefault

|

If a given column is not present in the record and it has a user defined default value then no column value will be returned. This option will prevent the callback that computes the user defined default value for the column from being called when enumerating the values for that column.

**Windows Server 2003 and earlier:** For Windows Server 2003 and earlier releases, the operation will fail with JET_errCallbackFailed.

**Windows Server 2003 SP1:** This possible value is only available for Windows Server 2003 SP1 and later operating systems. If this possible value is specified and the table contains a column that has a user defined default value, then the operation will fail with JET_errCallbackFailed.

|
|

JET_bitEnumeratePresenceOnly

|

If a non-NULL value exists for the requested column or column value then the associated data is not returned. Instead, the associated status for that column or column value will be set to JET_wrnColumnPresent. If the column or column value is **NULL** then JET_wrnColumnNull will be returned as usual.

|
|

JET_bitEnumerateTaggedOnly

|

When enumerating all column values in the record (for example,that is when *cEnumColumnId* is zero), only tagged column values will be returned. This option is not allowed when enumerating a specific array of column IDs.

|
|

JET_bitEnumerateInRecordOnly

|

**Windows 7:** JET_bitEnumerateInRecordOnly is introduced in Windows 7.

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

The column ID given is outside the legal limits of a column ID. This error will be returned by **JetEnumerateColumns** if specific column ids were requested, one of those column ids was invalid, and the first invalid column ID failed with this error for its column status code.

|
|

JET_errClientRequestToStopJetService

|

It is not possible to complete the operation because all activity on the instance associated with the session has ceased as a result of a call to [JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269240(v=exchg.10).md).

|
|

JET_errColumnNotFound

|

The column described by the given column ID does not exist in the table. This error will be returned by **JetEnumerateColumns** if specific column IDs were requested, one of those column IDs was invalid, and the first invalid column ID failed with this error for its column status code.

|
|

JET_errInstanceUnavailable

|

It is not possible to complete the operation because the instance associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data.

**Windows XP:** This error will only be returned by Windows XP and later releases.

|
|

JET_errInvalidgrbit

|

One of the options requested was invalid or not implemented. This error will be returned by **JetEnumerateColumns** when:

* JET_bitEnumerateLocal is specified.
* An illegal *grbit* is specified.

|
|

JET_errInvalidParameter

|

One of the parameters provided contained an unexpected value or contained a value that did not make sense when combined with the value of another parameter. This error will be returned by **JetEnumerateColumns** when:

* *pcEnumColumn* is **NULL**.
* *prgEnumColumn* is **NULL**.
* *pfnRealloc* is **NULL**.

|
|

JET_errNoCurrentRecord

|

The cursor is not positioned on a record. This can happen for many different reasons. For example, this will happen if the cursor is currently positioned after the last record on the current index.

|
|

JET_errNotInitialized

|

It is not possible to complete the operation because the instance associated with the session has not been initialized yet.

|
|

JET_errRecordDeleted

|

The cursor is positioned on a record that has been deleted. This can happen for many different reasons. The most common reason is that the session is not in a transaction, the cursor was positioned on a record, that record was deleted, and then the cursor attempted to reference that record.

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

On success, the requested data will be returned in the output buffers. It is the caller's responsibility to free any memory allocated by this callback and returned in the output buffers. That memory should be freed through the provided [realloc](https://learn.microsoft.com/cpp/c-runtime-library/reference/realloc) compatible callback. No change to the database state will occur.

On failure, none of the requested data will be returned. Any memory that was allocated during the call will be freed automatically using the provided [realloc](https://learn.microsoft.com/cpp/c-runtime-library/reference/realloc) compatible callback. No change to the database state will occur.

#### Remarks

If you are enumerating all column values in the record and you did not specify JET_bitEnumerateIgnoreDefaults then you cannot assume that you will never see a column or column value with a status code of JET_wrnColumnNull. You can see this status code if a column has a default value and was explicitly set to **NULL** or if the column is a non-sparse column (for example, a fixed or variable column).

The *cbDataMost* parameter does not apply to all column values. This parameter will only truncate long text and long binary column values that are so large that they have been stored separately from the record.

If **JetEnumerateColumns** returns data in its output parameters then the caller is responsible for freeing the memory in the array as well as any memory referred to by pointers embedded in that array.

#### Requirements

| Requirement | Value |
|------------|----------|
|

**Client**

|

Requires Windows Vista or Windows XP.

|
|

**Server**

|

Requires Windows Server 2008 or Windows Server 2003.

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

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JET_ENUMCOLUMNID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-enumcolumnid-structure)
[JET_ENUMCOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-enumcolumn-structure)
[JET_ENUMCOLUMNVALUE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-enumcolumnvalue-structure)
[JET_PFNREALLOC](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-pfnrealloc-callback-function)
[realloc](https://learn.microsoft.com/cpp/c-runtime-library/reference/realloc)
[JetRetrieveColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievecolumn-function)
[JetRetrieveColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievecolumns-function)