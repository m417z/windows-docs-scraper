# JET_PFNSTATUS Callback Function

_**Applies to:** Windows | Windows Server_

## JET_PFNSTATUS Callback Function

The **JET_PFNSTATUS** callback function receives information about the progress of long-running operations, such as defragmentation, backup, or restore operations. During such operations, the database engine calls this callback function to give an update on the progress of the operation.

```cpp
    JET_ERR JET_API JET_PFNSTATUS(
                           JET_SESID  sesid,
                           JET_SNP snp,
                           JET_SNT snt,
                           void* pv
    );
```

### Parameters

*sesid*

The session of type [JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid) with which the long-running function was called.

*snp*

The type of operation as specified in [JET_SNP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-snp). Types of operations include repair, compact, restore, backup, update, scrub, and update the record format.

*snt*

The status of an operation. Status types include beginning, in progress, completion, or failure. The status will be specified with the third parameter of type [JET_SNT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-snt).

*pv*

An optional pointer to a structure of type [JET_SNPROG](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-snprog-structure).

### Return Value

This function returns the [JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err) datatype with one of the [Extensible Storage Engine error codes](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-error-codes). For more information about the possible ESE errors, see [Extensible Storage Engine Errors](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-errors) and [Error Handling Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/error-handling-parameters).

On success, the operation that issued the callback can proceed normally. In some cases, the callback might return a warning that influences that operation.

On failure, the operation that issued the callback might proceed normally or might fail.

### Remarks

This callback function will be used in a progress notification in which the structure will indicate the current state of the progress. Note that the callback function might be called multiple times for the progress of the operation.

### Requirements

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

### See Also

[Extensible Storage Engine error codes](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-error-codes)
[Extensible Storage Engine Errors](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-errors)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_SNP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-snp)
[JET_SNPROG](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-snprog-structure)
[JET_SNT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-snt)