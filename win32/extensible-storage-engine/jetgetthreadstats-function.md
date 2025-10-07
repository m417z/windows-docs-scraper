# JetGetThreadStats Function

_**Applies to:** Windows | Windows Server_

## JetGetThreadStats Function

The **JetGetThreadStats** function retrieves performance information from the database engine for the current thread. Multiple calls can be used to collect statistics that reflect the activity of the database engine on this thread between those calls.

**Windows Vista:** **JetGetThreadStats** is introduced in Windows Vista.

```cpp
    JET_ERR JET_API JetGetThreadStats(
      __out         void* pvResult,
      __in          unsigned long cbMax
    );
```

### Parameters

*pvResult*

The output buffer which receives the thread statistics data. The buffer contains a [JET_THREADSTATS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-threadstats-structure) structure after a successful call.

*cbMax*

The maximum size in bytes of the output buffer.

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

JET_errBufferTooSmall

|

The operation failed because the provided output buffer was too small to contain the requested data. The **JetGetThreadStats** function will return this error when the output buffer is too small to contain the smallest version of the [JET_THREADSTATS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269227(v=exchg.10).md) structure supported by the database engine.

|

On success, the output buffer will contain a [JET_THREADSTATS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-threadstats-structure) structure that contains database engine statistics for the current thread.

On failure, the state of the output buffer is undefined.

#### Remarks

The information provided by two consecutive calls of this API are intended to be used to compute the expense of any other database engine operations on the current thread. Generally, this is done by taking a before and after reading of the statistics and subtracting the after count from the before count to get the net count of operations performed.

For example, an application could call **JetGetThreadStats** once to get an initial reading of the statistics for the current thread. It could then call the [JetMove](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetmove-function) function with the *cRow* parameter set to JET_MoveNext to move to the next index entry on an index. It could then call **JetGetThreadStats** again to get another reading of the thread's statistics. It could then subtract the cPageReferenced counter from the second reading from the first. The result would be the number of database pages referenced by the database engine to perform the [JetMove](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetmove-function) operation.

The statistics for each thread are accumulated for the lifetime of that thread. The statistics are reset if the database engine's DLL is unloaded from the host process.

The [JET_THREADSTATS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-threadstats-structure) structure will likely be expanded in the future to contain more statistics. New statistics will be added to the end of the structure and can be retrieved with an increased output buffer size. The presence of additional statistics can be inferred by a larger cbStruct value.

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
[JET_THREADSTATS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-threadstats-structure)
[JetMove](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetmove-function)