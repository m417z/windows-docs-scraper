# JetCreateInstance2 Function

_**Applies to:** Windows | Windows Server_

## JetCreateInstance2 Function

The **JetCreateInstance2** function is used to allocate a new instance of the database engine for use in a single process, with a display name specified.

**Windows XP:** **JetCreateInstance2** is introduced in Windows XP.

```cpp
    JET_ERR JET_API JetCreateInstance2(
      __out         JET_INSTANCE* pinstance,
      __in_opt      const tchar* szInstanceName,
      __in_opt      const tchar* szDisplayName,
      __in          JET_GRBIT grbit
    );
```

### Parameters

*pinstance*

The output buffer that will receive the newly created instance.

*szInstanceName*

Specifies a unique string identifier for the instance to be created. This string must be unique within a given process hosting the database engine.

**Note** A NULL value is treated as a valid string identifier for an instance. Only one instance may have a NULL string identifier.

*szDisplayName*

A display name for the instance to be created. When this parameter is not present, its value is presumed to be NULL.

*grbit*

Reserved for future use. When this parameter is not present, its value is presumed to be zero.

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

JET_errInstanceNameInUse

|

The specified instance name is already in use for this process.

|
|

JET_errInvalidParameter

|

One of the parameters provided contained an unexpected value or contained a value that did not make sense when combined with the value of another parameter. This can happen for [JetCreateInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269354(v=exchg.10).md) when *pinstance* is NULL.

|
|

JET_errRunningInOneInstanceMode

|

The operation failed because it cannot be used when the database engine is operating in single instance mode (Windows 2000 compatibility mode).

|
|

JET_errTooManyInstances

|

A new instance could not be created because the maximum number of instances has been reached. The maximum number of supported instances is configured using [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294044(v=exchg.10).md) using *JET_paramMaxInstances*.

|

On success, a new instance will be allocated and the identifier for it will be returned. At this point, all system parameters for the instance will have the values of the global default system parameters. Once an instance will be allocated, it needs to be terminated and/or freed later on.

On failure, an error representing the cause of failure will be returned and no instance will be allocated.

#### Remarks

An instance must be initialized with a call to [JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit-function) before it can be used by anything other than [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function).

An instance is destroyed by a call to the [JetTerm](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetterm-function) function, even if that instance was never initialized using [JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit-function). The maximum number of instances that may be created at any one time is controlled by *JET_paramMaxInstances*, which can be configured by a call to [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function). An instance is the unit of recoverability for the database engine. It controls the life cycle of all the files used to protect the integrity of the data in a set of database files. These files include the checkpoint file and the transaction log files.

If the function succeeds, the database engine will automatically be changed to multi-instance mode as a side effect of this call. If the application desires to allow only one instance in the process then [JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit-function) should be used to start the database engine in Windows 2000 compatibility mode.

If present, the *szDisplayName* parameter will be used to identify the instance in places like Event Log or towards other callers like backup applications (through functions like [JetGetInstanceInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetinstanceinfo-function) or [JetOSSnapshotFreeze](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotfreeze-function)). If the display name is not provided, the unique *szInstanceName* parameter will be used instead, if present, otherwise an empty string will be returned. If the engine did not have the running mode set, after this call, it will be set to multi-instance mode.

The typical start-up sequence for a process potentially running multiple Jet instances would be:

  - A call to **JetCreateInstance2** which will allocate and name the instance.

  - Multiple calls to [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function) for that instance in order to set different system parameters. Note that some system parameters need to be unique for each instance (like *JET_paramSystemPath* or *JET_paramLogFilePath*) so most likely, each of these will need to be set.

  - Start the instance using [JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit-function) or [JetInit2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit2-function). In order to terminate and/or free an instance, use [JetTerm](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetterm-function) or [JetTerm2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetterm2-function).

If this is the first instance to be started, there are a number of additional steps which will be executed during this call in order to make basic system initialization and configuration. A number of those steps might result in specific errors starting with JET_errOutOfMemory but others as well (see Return Values for more information).

#### Requirements

| Requirement | Value |
|------------|----------|
|

**Client**

|

Requires Windows Vista or Windows XP.

|
|

**Server**

|

Requires Windows Server 2008 or Windows Server 2003.

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

Implemented as **JetCreateInstance2W** (Unicode) and **JetCreateInstance2A** (ANSI).

|

#### See Also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_INSTANCE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-instance)
[JetCreateInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateinstance-function)
[JetEnableMultiInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetenablemultiinstance-function)
[JetGetInstanceInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetinstanceinfo-function)
[JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit-function)
[JetInit2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit2-function)
[JetOSSnapshotFreeze](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotfreeze-function)
[JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function)
[JetTerm](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetterm-function)
[JetTerm2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetterm2-function)