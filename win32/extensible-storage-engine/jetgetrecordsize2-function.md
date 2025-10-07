# JetGetRecordSize2 Function

_**Applies to:** Windows | Windows Server_

## JetGetRecordSize2 Function

The **JetGetRecordSize2** function retrieves record size information from the desired location.

**Windows 7: JetGetRecordSize2** is introduced in the Windows 7 operating system.

```cpp
    JET_ERR JET_API JetGetRecordSize2(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid,
      __out         JET_RECSIZE2* precsize,
      __in          const JET_GRBIT grbit
    );
```

### Parameters

*sesid*

Identifies the database session context that will be used for the API call.

*tableid*

Identifies the table or cursor that will be used for the API call. The cursor must be positioned on a record, or have an update prepared.

*precsize*

A pointer to an output buffer for the [JET_RECSIZE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-recsize2-structure) structure.

*grbit*

This is one or more of the following values.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitRecordSizeInCopyBuffer

|

This retrieves the size of the record that is in the copy buffer prepared for update. Otherwise, the *tableid* or cursor must be positioned on a record, and that record will be used.

|
|

JET_bitRecordSizeRunningTotal

|

When this bit is specified, the [JET_RECSIZE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269174(v=exchg.10).md) is not zeroed before filling the contents, effectively acting as an accumulation of the statistics for multiple records visited or updated.

|
|

JET_bitRecordSizeLocal

|

This causes the API to ignore non-intrinsic Long Values. For example, only the local record on the page will be used.

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

JET_errInvalidGrbit

|

One of the requested options was invalid or not implemented. This error will be returned by the **JetGetRecordSize2** function when an illegal *grbit* is specified.

|
|

JET_errNotInitialized

|

It is not possible to complete the operation because the instance associated with the session has not been initialized.

|
|

JET_errClientRequestToStopJetService

|

It is not possible to complete the operation because all activity on the instance associated with the session has ceased as a result of a call to [JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269240(v=exchg.10).md).

|
|

JET_errInstanceUnavailable

|

It is not possible to complete the operation because the instance associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data.

**Windows XP:** JET_errInstanceUnavailable will only be returned by the Windows XP operating system and later versions of Windows.

|
|

JET_errTermInProgress

|

It is not possible to complete the operation because the instance associated with the session is being shut down.

|
|

JET_errRestoreInProgress

|

It is not possible to complete the operation because a restore operation is in progress on the instance associated with the session.

|
|

JET_errSessionSharingViolation

|

It is illegal to use the same session for more than one thread at the same time.

**Windows XP:** JET_errInstanceUnavailable will only be returned by Windows XP and later versions of Windows.

|
|

JET_errNoCurrentRecord

|

This can happen if the cursor was positioned incorrectly.

|
|

JET_errRecordDeleted

|

If the cursor was not positioned in a transaction, this can happen if another thread deletes the record out from under this session.

|
|

JET_errInvalidParameter

|

This can be returned if a **NULL***precsize* was passed.

|

#### Remarks

The size of the key accumulated in the **cbOverhead** field of [JET_RECSIZE2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-recsize2-structure), is affected by JET_bitRecordSizeInCopyBuffer. If this bit is specified, the key size accumulated in the **cbOverhead** field is the full key size. If this bit is not used, the key size accumulated will not include any size saved due to key prefix compression.

#### Requirements

| Requirement | Value |
|------------|----------|
|

**Client**

|

Requires Windows Vista.

|
|

**Server**

|

Requires Windows Server 2008.

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
[JET_RECSIZE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-recsize-structure)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)