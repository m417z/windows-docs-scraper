# JetSetSessionParameter Function

_**Applies to:** Windows | Windows Server_

The **JetSetSessionParameter** function configures the database engine.

``` c++
JET_ERR JET_API JetSetSessionParameter (
  __in_opt      JET_SESID sesid,
  __in          unsigned long sesparamid,
  __in_read_bytes_opt_(cbParam)  void* pvParam,
  __in          unsigned long cbParam
);
```

### Parameters

*sesid*

Specifies the session to use for this call.

When specified, the specified instance is ignored and the instance associated with the session will be used.

*sesparamid*

The ID of the session parameter to set.

*pvParam*

The data to set in this session parameter.

*cbParam*

The size of the data provided.

### Return value

This function returns the [JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err) data type with one of the return codes listed in the following table. For more information about the possible Extensible Storage Engine (ESE) errors, see [Extensible Storage Engine Errors](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-errors) and [Error Handling Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/error-handling-parameters).

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

JET_errAlreadyInitialized

|

The instance has been initialized by using a call to the [JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294068(v=exchg.10).md) function and this operation cannot be performed as a result. This can happen when an attempt is made to configure a system parameter after a change in the parameter value can no longer affect the state of the database engine.

|
|

JET_errClientRequestToStopJetService

|

It is not possible to complete the operation because all activity on the instance associated with the session has ceased as a result of a call to the [JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269240(v=exchg.10).md) function.

|
|

JET_errIndexTuplesInvalidLimits

|

The specified tuple index parameters were illegal. This error is returned only when the *JET_paramIndexTuplesLengthMin*, *JET_paramIndexTuplesLengthMax*, or *JET_paramIndexTuplesToIndexMax* parameter is set to an illegal value. For information about these parameters, see [Index Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294119(v=exchg.10).md).

|
|

JET_errInitInProgress

|

It is not possible to complete the operation because the instance associated with the session is being initialized.

|
|

JET_errInstanceUnavailable

|

It is not possible to complete the operation because the instance associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data.

|
|

JET_errInvalidParameter

|

One of the parameters provided contained an unexpected value or contained a value that did not make sense when combined with the value of another parameter. This can happen when the following occurs:

* The specified system parameter ID is invalid or unsupported.
* An attempt was made to set a string-valued system parameter with a string the length of which was outside the legal range for the parameter.
* An attempt was made to set a string-valued system parameter with a file path where the length of its absolute path representation was outside the legal range for that parameter.
* An attempt was made to set an integer-valued system parameter with an integer that was outside the legal range for the parameter.
* An attempt was made to set JET_paramUnicodeIndexDefault with a null [JET_UNICODEINDEX](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294097(v=exchg.10).md) pointer, an invalid LCID, or an unsupported set of **LCMapString** flags.
* The specified system parameter cannot be set because it is read-only.
* An attempt was made to set a system parameter after the [JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294068(v=exchg.10).md) function was called, the database engine is in single-instance mode, and a session was not specified.
* The specified system parameter is global only and an attempt was made to set an instance-specific value for that system parameter.
* The specified system parameter is per-instance only and an attempt was made to set the global value for that system parameter.

|
|

JET_errInvalidPath

|

The specified file system path was invalid. This error may be returned by **JetSetSessionParameter** only when setting system parameters that represent file system paths. For example, the *JET_paramSystemPath* parameter may return this error. For information about this parameter, see [Transaction Log Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269235(v=exchg.10).md).

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

The session handle is invalid or refers to a closed session.

This error is not returned under all circumstances. Handles are validated on a best effort basis only.

|
|

JET_errInvalidInstance

|

The instance handle is invalid or refers to an instance that has been shut down.

This error is not returned under all circumstances. Handles are validated on a best effort basis only.

|

On success, the system parameter will be set to the provided value.

On failure, the system parameter value will remain unchanged.

#### Requirements

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

Requires Windows Server 2012.

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

#### See also

[JET_API_PTR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-api-ptr)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_INSTANCE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-instance)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JetCreateInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateinstance-function)
[JetGetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetsystemparameter-function)
[JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit-function)
[System Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-system-parameters)