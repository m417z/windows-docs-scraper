# JetGetInstanceMiscInfo Function

_**Applies to:** Windows | Windows Server_

## JetGetInstanceMiscInfo Function

The **JetGetInstanceMiscInfo** function retrieves information about the instance, while the instance is online.

**Windows Vista: JetGetInstanceMiscInfo** is introduced in Windows Vista.

```cpp
    JET_ERR JET_API JetGetInstanceMiscInfo(
      __in          JET_INSTANCE instance,
      __out         void* pvResult,
      __in          unsigned long cbMax,
      __in          unsigned long InfoLevel
    );
```

### Parameters

*instance*

Identifies the database instance that will be used for the API call.

*pvResult*

Pointer to a buffer that will receive the information. The type of the buffer is dependent on *InfoLevel*. The caller is responsible for aligning the buffer appropriately.

*cbMax*

The size, in bytes, of the buffer passed in *pvResult*.

*InfoLevel*

Determines what type of information will be retrieved for the instance specified by *instance*. The format of the data stored in *pvResult* is dependent on *InfoLevel*.

The following options are available for use with this parameter.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_InstanceMiscInfoLogSignature

|

*pvResult* is interpreted as a [JET_SIGNATURE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269340(v=exchg.10).md) structure of the transaction log sequence associated with this instance.

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

JET_errBufferTooSmall

|

The buffer was too small.

|
|

JET_errInvalidParameter

|

Either an invalid [JET_INSTANCE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294048(v=exchg.10).md) or an invalid *InfoLevel* was specified.

|

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
[JET_INSTANCE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-instance)
[JET_SIGNATURE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-signature-structure)