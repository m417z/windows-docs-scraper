# JetRetrieveColumns Function

_**Applies to:** Windows | Windows Server_

## JetRetrieveColumns Function

The **JetRetrieveColumns** function retrieves multiple column values from the current record in a single operation. An array of [JET_RETRIEVECOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-retrievecolumn-structure) structures is used to describe the set of column values to be retrieved, and to describe output buffers for each column value to be retrieved.

```cpp
    JET_ERR JET_API JetRetrieveColumns(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid,
      __in_out_opt  JET_RETRIEVECOLUMN* pretrievecolumn,
      __in          unsigned long cretrievecolumn
    );
```

### Parameters

*sesid*

The session to use for this call.

*tableid*

The cursor to use for this call.

*pretrievecolumn*

A pointer to an array of one or more [JET_RETRIEVECOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-retrievecolumn-structure) structures. Each structure includes descriptions of which column value to retrieve and where to store returned data.

*cretrievecolumn*

The number of [JET_RETRIEVECOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-retrievecolumn-structure) structures in the array given by *pretrievecolumn*.

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

JET_errBadItagSequence

|

An invalid multi-valued column sequence number value has been passed in pretinfo->itagSequence. Valid values for the multi-valued column value sequence numbers are 1 or greater. A value of 0 (zero) is valid for this function but is invalid for [JetRetrieveColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269198(v=exchg.10).md).

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

JET_errIndexTuplesCannotRetrieveFromIndex

|

Columns indexed as substrings cannot be retrieved from the index, since only a small portion of the column is typically present in each index entry.

|
|

JET_errInvalidBufferSize

|

In some cases, the buffer given for the retrieve column must be sufficiently sized in order to return any amount of the column value. For example, escrow updatable columns are adjusted to be consistent for the transactional context of the calling session and this adjustment requires the buffer provided by the caller. If insufficient buffer space is supplied, then JET_errInvalidBufferSize is returned and no column data whatsoever is returned.

|
|

JET_errInvalidgrbit

|

The options supplied are unknown or an illegal combination of known bit settings.

|
|

JET_errInvalidParameter

|

One or more of the parameters given is incorrect. This can happen if the retinfo.cbStruct is smaller that the size of [JET_RETINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294049(v=exchg.10).md).

|
|

JET_errInstanceUnavailable

|

It is not possible to complete the operation because the instance associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data.

**Windows XP:** This error will only be returned by Windows XP and later releases.

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

JET_wrnBufferTruncated

|

The entire column value could not be retrieved because the given buffer is smaller than the size of the column.

|

On success, columns data and column size are returned in provided buffers described in array of [JET_RETRIEVECOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-retrievecolumn-structure) structures. If an *itagSequence* was set to 0 (zero) to indicate that the number of instances of a multi-valued field was desired instead of column data, then the number of instances of a multi-valued column is returned in the *itagSequence* field itself. Each [JET_RETRIEVECOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-retrievecolumn-structure) structure has an error field that contains warnings for the column retrieved. If the column was **NULL** valued, then the error code will be set to JET_wrnColumnNull.

On failure, the cursor location is left unchanged and no data is copied into the provided buffer.

#### Remarks

**JetRetrieveColumns** supports one feature that [JetRetrieveColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievecolumn-function) does not. This is the ability to retrieve the number of instances of a multi-valued column. The purpose of this feature is to allow an application to retrieve all values of a column. This can be done by first determining the number of values that a column has. Next, their lengths can be determined by calling **JetRetrieveColumns** again with one [JET_RETRIEVECOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-retrievecolumn-structure) structure allocated for each value to determine the length of column data. This can be done by passing **NULL***pvData* pointers with *cbMax* of 0 (zero) and retrieving the column length in *cbActual*. The third and last call can be made with allocated memory for the column value data.

If any column retrieved is truncated due to an insufficient length buffer, then the API will return JET_wrnBufferTruncated. However, other errors, JET_wrnColumnNull are returned only in the error field in [JET_RETRIEVECOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-retrievecolumn-structure). The reason for this is that applications often want to ensure that all data has been retrieved and returning this error from **JetRetrieveColumns** facilitates this understanding.

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

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JET_RETRIEVECOLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-retrievecolumn-structure)
[JetEnumerateColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetenumeratecolumns-function)
[JetRetrieveColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievecolumn-function)
[JetSetColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcolumns-function)