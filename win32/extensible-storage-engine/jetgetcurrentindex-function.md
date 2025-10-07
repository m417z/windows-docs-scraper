# JetGetCurrentIndex Function

_**Applies to:** Windows | Windows Server_

## JetGetCurrentIndex Function

The **JetGetCurrentIndex** function determines the name of the current index of a given cursor. This name is also used to later re-select that index as the current index using [JetSetCurrentIndex](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcurrentindex-function). It can also be used to discover the properties of that index using [JetGetTableIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgettableindexinfo-function).

```cpp
    JET_ERR JET_API JetGetCurrentIndex(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid,
      __out         JET_PSTR szIndexName,
      __in          unsigned long cchIndexName
    );
```

### Parameters

*sesid*

The session to use for this call.

*tableid*

The cursor to use for this call.

*szIndexName*

The output buffer that receives the name of the current index of the cursor.

*cchIndexName*

The maximum size in characters of the output buffer.

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

JET_errClientRequestToStopJetService

|

It is not possible to complete the operation because all activity on the instance associated with the session has ceased as a result of a call to [JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269240(v=exchg.10).md).

|
|

JET_errInstanceUnavailable

|

It is not possible to complete the operation because the instance associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data. This error will only be returned by Windows XP and later releases.

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

The same session cannot be used for more than one thread at the same time. This error will only be returned by Windows XP and later releases.

|
|

JET_errTermInProgress

|

It is not possible to complete the operation because the instance associated with the session is being shut down.

|
|

JET_wrnBufferTruncated

|

The operation completed successfully, but the output buffer was too small to receive the entire index name.

The output buffer has been filled with as much of the index name as would fit. If the output buffer is at least one character in length then the string in that output buffer will be null terminated.

**Note** This error will not be returned if cchIndexName is zero. Please see the Remarks section for more information.

|

On success, the name of the current index of the given cursor will be returned in the output buffer. If JET_wrnBufferTruncated is returned then the output buffer will contain as much of the index name as will fit in the space provided. If the output buffer is at least one character in length then the string returned in that buffer will be null terminated. No change to the database state will occur.

On failure, the state of the output buffer will be undefined. No change to the database state will occur.

#### Remarks

If there is no current index for the cursor then an empty string will be returned. This can happen when the cursor is on the clustered index of the table and no primary index was defined. This index is known as the sequential index of the table and has no definition. In any case, setting the current index to an empty string using [JetSetCurrentIndex](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcurrentindex-function) will select the clustered index regardless of the presence of a primary index definition.

There is an important bug in this function that is present in all releases. If the output buffer is too small to receive the entire index name and the output buffer is at least one character in length then JET_wrnBufferTruncated will NOT be returned. JET_errSuccess will be returned instead. To avoid this issue, the output buffer should always be at least JET_cbNameMost + 1 (65) characters in length.

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

Implemented as **JetGetCurrentIndexW** (Unicode) and **JetGetCurrentIndexA** (ANSI).

|

#### See Also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JetGetTableIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgettableindexinfo-function)
[JetSetCurrentIndex](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcurrentindex-function)