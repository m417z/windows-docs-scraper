# JetGetErrorInfoW Function

_**Applies to:** Windows | Windows Server_

## JetGetErrorInfoW Function

The **JetGetErrorInfoW** function BAS_ of the database engine.

Note: This documentation is based on a preliminary release of the Extensible Storage Engine. This information is subject to change.

```cpp
JET_ERR JET_API JetGetErrorInfoW(
    _In_opt_ void *                      pvContext,
    _Out_writes_bytes_( cbMax ) void *   pvResult,
    _In_ unsigned long                   cbMax,
    _In_ unsigned long                   InfoLevel,
    _In_ JET_GRBIT                       grbit );
```

### Parameters

*pvContext*

The context or error value for which the extended error information is needed. The value passed in depends on the *InfoLevel* parameter value.

*pvResult*

A pointer to a buffer that will receive the information. The type of the buffer depends on the *InfoLevel* parameter value. The caller must be configured to align the buffer appropriately.

*cbMax*

The maximum size of the *pvResult* structure that is passed in.

*InfoLevel*

The type of information that will be retrieved for the error info/context is specified by the *pvContext* parameter. The format of the data that is stored in *pvResult* is dependent on *InfoLevel*.

The following table lists the possible values for this parameter.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_ErrorInfoSpecificErr

|

*pvContext* is interpreted as a [JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269297(v=exchg.10).md)/error code, *pvResult* is interpreted as a [JET_ERRINFOBASIC_W](https://learn.microsoft.com/windows/win32/extensible-storage-engine/hh475861(v=exchg.10).md), and the fields of the [JET_ERRINFOBASIC_W](https://learn.microsoft.com/windows/win32/extensible-storage-engine/hh475861(v=exchg.10).md) structure are filled in appropriately.

|

*grbit*

Reserved.

### Return Value

This function returns the [JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-error-codes) data type with one of the return codes listed in the following table. For more information about the possible ESE errors, see [Extensible Storage Engine Errors](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-errors) and [Error Handling Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/error-handling-parameters).

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

JET_errInvalidParameter

|

One of the parameters provided contains an unexpected value or contains a value that does not make sense when combined with the value of another parameter. This can happen for **JetGetErrorInfo** when the following occurs:

* The specified *InfoLevel* parameter value is invalid.
* The specified *grbit* value is invalid.
* The specified *pvResult* parameter buffer’s *cbMax* value is less than the required size for output of this *InfoLevel* parameter.
* For *InfoLevel* = JET_ErrorInfoSpecificErr, the [JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294092(v=exchg.10).md) value passed in is unknown to the engine.

|
|

JET_errDisabledFunctionality

|

If this SKU of windows doesn’t support this function, this error will be returned.

|

On success, the output buffer that is appropriate for the requested error context/value will be set to the extended error info requested.

On failure, the state of the output buffers will be undefined.

### Remarks

The [JET_ERRINFOBASIC_W](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-errinfobasic-w-structure) function and [JET_ERRCAT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-errcat) group of constants contain documentation about the extended error information that is returned for *InfoLevel* = JET_ErrorInfoSpecificErr.

### Requirements

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

Requires Windows 8 Server.

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

Note: Only the **JetGetErrorInfoW** (Unicode) is implemented. This API does not have an A (ANSI) version.

|