# JetSetSystemParameter Function

_**Applies to:** Windows | Windows Server_

## JetSetSystemParameter Function

The **JetSetSystemParameter** function is used to set the numerous configuration settings of the database engine.

```cpp
    JET_ERR JET_API JetSetSystemParameter(
      __in_out_opt  JET_INSTANCE* pinstance,
      __in          JET_SESID sesid,
      __in          unsigned long paramid,
      __in          JET_API_PTR lParam,
      __in_opt      JET_PCSTR szParam
    );
```

### Parameters

*pinstance*

Specifies the instance to use for this call.

**Windows 2000:** For Windows 2000, this parameter is ignored and should always be **NULL**.

**Windows XP:** For Windows XP and later releases, this parameter is somewhat overloaded. If the engine is operating in legacy mode (Windows 2000 compatibility mode) where only one instance is supported, then this parameter may be **NULL** or may contain the actual instance returned by [JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit-function). In either case, all system parameter settings are read from that one instance. If the engine is operating in multi-instance mode, then this parameter may be **NULL** or a pointer to an instance created using [JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit-function) or [JetCreateIndex](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateindex-function). When this parameter is **NULL** then the global system parameter setting (or default) is read. When this parameter is an instance then the system parameter setting for that instance is read.

Even though this is technically an out parameter, this API never modifies the contents of the provided buffer.

*sesid*

Specifies the session to use for this call.

When specified, the specified instance is ignored and the instance associated with the session will be used.

*paramid*

The ID of the system parameter that will be set. See [System Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-system-parameters) for a complete list of system parameters and their properties.

*lParam*

Provides the value to be set for the selected system parameter if that system parameter is of an integer type.

*szParam*

Provides the value for the selected system parameter if that system parameter is of a string type.

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

**Windows Vista:** On Windows Vista and later releases, success can be returned without a change to the system parameter's value. See the JET_paramEnableAdvanced system parameter in the [Meta Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269346(v=exchg.10).md) topic for more information.

|
|

JET_errAlreadyInitialized

|

The instance has been initialized using a call to [JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294068(v=exchg.10).md) and this operation cannot be performed as a result. This can happen for **JetSetSystemParameter** when an attempt is made to configure a system parameter after a change in its value cannot affect the state of the database engine.

|
|

JET_errClientRequestToStopJetService

|

It is not possible to complete the operation because all activity on the instance associated with the session has ceased as a result of a call to [JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269240(v=exchg.10).md).

|
|

JET_errIndexTuplesInvalidLimits

|

The specified tuple index parameters were illegal. This error may be returned by **JetSetSystemParameter** only when setting [JET_paramIndexTuplesLengthMin](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294119(v=exchg.10).md), [JET_paramIndexTuplesLengthMax](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294119(v=exchg.10).md), or [JET_paramIndexTuplesToIndexMax](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294119(v=exchg.10).md) to an illegal value.

**Windows XP and Windows Server 2003:** This can only happen on Windows XP and Windows Server 2003.

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

**Windows XP:** This error will only be returned by Windows XP and later releases.

|
|

JET_errInvalidParameter

|

One of the parameters provided contained an unexpected value or contained a value that did not make sense when combined with the value of another parameter. This can happen for **JetSetSystemParameter** when:

* The specified system parameter ID is invalid or unsupported.
* An attempt was made to set a string-valued system parameter with a string whose length was outside the legal range for the parameter.
* An attempt was made to set a string-valued system parameter with a file path where the length of its absolute path representation was outside the legal range for that parameter.

  **Windows Vista:** This can only happen on Windows Vista and later releases.
* An attempt was made to set an integer-valued system parameter with an integer that was outside the legal range for the parameter.
* An attempt was made to set JET_paramUnicodeIndexDefault with a **NULL**[JET_UNICODEINDEX](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294097(v=exchg.10).md) pointer, an invalid LCID, or an unsupported set of LCMapString flags.

  **Windows Vista:** This can only happen on Windows Vista and later releases.
* The specified system parameter cannot be set because it is read-only.
* An attempt was made to set a system parameter after [JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294068(v=exchg.10).md) was called, the database engine is in single-instance mode, and a session was not specified.

  **Windows XP and Windows Server 2003:** This can only happen on Windows XP and Windows Server 2003.
* The specified system parameter is global only and an attempt was made to set an instance specific value for that system parameter.

  **Windows XP and Windows Server 2003:** This can only happen on Windows XP and Windows Server 2003.
* The specified system parameter is per-instance only and an attempt was made to set the global value for that system parameter.

  **Windows XP and Windows Server 2003:** This can only happen on Windows XP and Windows Server 2003.

|
|

JET_errInvalidPath

|

The specified file system path was invalid. This error may be returned by **JetSetSystemParameter** only when setting system parameters that represent file system paths. For example, [JET_paramSystemPath](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269235(v=exchg.10).md) may return this error.

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

The instance handle is invalid or refers to an instance that has been shutdown.

This error is not returned under all circumstances. Handles are validated on a best effort basis only.

**Windows Vista:** This error will only be returned by Windows Vista and later releases.

|

On success, the setting for the system parameter will be set to the provided value.

On failure, the setting for the system parameter will remain unchanged.

#### Remarks

**JetSetSystemParameter** does a poor job of validating the chosen setting for each system parameter. Care must be taken to not rely on this validation to enforce good settings. Please pay close attention to the description of each system parameter and follow those guidelines for a good system parameter setting.

There are a set of system parameters that should always be set to guarantee that the database engine works as intended. Specifically, any system parameters that affect the physical layout of the files used by the database engine should always be set. For more information, see [System Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-system-parameters).

Every system parameter has a default value. These default values have evolved over time and are quite arbitrary. It is highly recommended that an application evaluate all the default values to ensure that they are appropriate. If they are not appropriate, then they should be configured by the application. This is important as many of these parameters can greatly impact the reliability, performance, and resource utilization of the database engine.

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

Implemented as **JetSetSystemParameterW** (Unicode) and **JetSetSystemParameterA** (ANSI).

|

#### See Also

[JET_API_PTR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-api-ptr)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_INSTANCE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-instance)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JetCreateInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateinstance-function)
[JetGetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetsystemparameter-function)
[JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit-function)
[System Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-system-parameters)