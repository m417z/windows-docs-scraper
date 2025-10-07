# JetGetSystemParameter Function

_**Applies to:** Windows | Windows Server_

## JetGetSystemParameter Function

The **JetGetSystemParameter** function reads the numerous configuration settings of the database engine.

```cpp
    JET_ERR JET_API JetGetSystemParameter(
      __in          JET_INSTANCE instance,
      __in          JET_SESID sesid,
      __in          unsigned long paramid,
      __in_out_opt  JET_API_PTR* plParam,
      __out_opt     JET_PSTR szParam,
      __in          unsigned long cbMax
    );
```

### Parameters

*instance*

The instance to use for this call.

For Windows 2000, this parameter is ignored and should always be **NULL**.

For Windows XP and later releases, this parameter is somewhat overloaded. If the engine is operating in legacy mode (Windows 2000 compatibility mode) where only one instance is supported, this parameter may be **NULL** or may contain the actual instance returned by [JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit-function). In either case, all system parameter settings are read from that one instance. If the engine is operating in multi-instance mode, this parameter may be **NULL** or a pointer to an instance created using [JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit-function) or [JetCreateInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateinstance-function). When this parameter is **NULL** then the global system parameter setting (or default) is read. When this parameter is an instance then the system parameter setting for that instance is read.

*sesid*

The session to use for this call.

When specified, the specified instance is ignored and the instance associated with the session will be used.

*paramid*

The ID of the system parameter that will be read.

See [System Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-system-parameters) for a complete list of system parameters and their properties.

*plParam*

The output buffer that receives the value of the selected system parameter if that system parameter is of an integer type.

*szParam*

The output buffer that receives the value of the selected system parameter if that system parameter is of a string type.

*cbMax*

The maximum size in bytes of the string output buffer.

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

JET_errInitInProgress

|

It is not possible to complete the operation because the instance associated with the session is being initialized.

|
|

JET_errInstanceUnavailable

|

It is not possible to complete the operation because the instance associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data. This error will only be returned by Windows XP and later releases.

|
|

JET_errInvalidParameter

|

One of the parameters provided contained an unexpected value or contained a value that did not make sense when combined with the value of another parameter.

This can happen for **JetGetSystemParameter** when:

* The specified system parameter ID is invalid or unsupported.
* The specified system parameter requires the integer output buffer to be provided and that output buffer pointer was **NULL**.
* The specified system parameter requires a string output buffer to be provided and that output buffer pointer was **NULL**.

  **Windows Vista:** This can only happen on Windows Vista and later releases.
* The specified system parameter requires a string output buffer to be provided and the size of that output buffer is too small to accept a null terminated string.

  **Windows Vista:** This can only happen on Windows Vista and later releases.
* The specified system parameter cannot be read because it is write-only.
* The specified system parameter is global only and an attempt was made to read an instance specific value for that system parameter. This can only happen on Windows XP and later releases.
* The specified system parameter is per-instance only and an attempt was made to read the global value for that system parameter. This can only happen on Windows XP and later releases.

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

JET_errTermInProgress

|

It is not possible to complete the operation because the instance associated with the session is being shut down.

|
|

JET_errInvalidSesid

|

The session handle is invalid or refers to a closed session. This error is not returned under all circumstances. Handles are validated on a best effort basis only.

|
|

JET_errInvalidInstance

|

The instance handle is invalid or refers to an instance that has been shutdown. This error is not returned under all circumstances. Handles are validated on a best effort basis only.

**Windows Vista:** This error will only be returned by Windows Vista and later releases.

|
|

JET_wrnBufferTruncated

|

The operation completed successfully, but the output buffer was too small to receive the entire system parameter setting.

The output buffer has been filled with as much of the system parameter setting as would fit. If the output buffer is at least one character in length then the string in that output buffer will be null terminated.

**Note** This error is not returned by all releases. Please see the Remarks section for more information.

|
|

JET_errBufferTooSmall

|

The operation failed because the output buffer was too small to receive the entire system parameter setting.

**Note** This error is not returned in some cases to preserve application compatibility. Please see the Remarks section for more information.

**Windows Vista:** This error will only be returned by Windows Vista and later releases.

|

On success, the output buffer appropriate for the requested system parameter will be set to the value of that system parameter.

On failure, the state of the output buffers will be undefined.

#### Remarks

There is an important problem in this API that is present in all releases. If a system parameter with a string value is requested and the output buffer is too small to receive the entire system parameter setting, JET_wrnBufferTruncated will NOT be returned. JET_errSuccess is returned instead. If the length of the returned string is equal to the size of the output buffer less the **NULL** terminator, the caller should react as if JET_wrnBufferTruncated were returned. If a zero-sized string output buffer is specified, the caller should react as if JET_errInvalidParameter were returned.

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

Implemented as **JetGetSystemParameterW** (Unicode) and **JetGetSystemParameterA** (ANSI).

|

#### See Also

[JET_API_PTR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-api-ptr)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_INSTANCE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-instance)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JetCreateInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateinstance-function)
[JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit-function)
[JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function)
[JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopservice-function)
[System Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-system-parameters)