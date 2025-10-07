# JetEnableMultiInstance Function

_**Applies to:** Windows | Windows Server_

## JetEnableMultiInstance Function

The **JetEnableMultiInstance** function configures the database engine for use with multiple instances in the same process. An optional array of global system parameters is available to the first caller allowing for the change to multi-instance mode.

**Windows XP: JetEnableMultiInstance** is introduced in Windows XP.

```cpp
    JET_ERR JET_API JetEnableMultiInstance(
      __in_opt      JET_SETSYSPARAM* psetsysparam,
      __in_opt      unsigned long csetsysparam,
      __out_opt     unsigned long* pcsetsucceed
    );
```

### Parameters

*psetsysparam*

An array of global system parameters to set if and only if the engine enters multi-instance mode as a result of this call. If *csetsysparam* is zero then *psetsysparam* is ignored.

*csetsysparam*

The count of elements for the array of global parameters to set if and only if the engine enters multi-instance mode as a result of this call. If *csetsysparam* is zero then *psetsysparam* is ignored.

*pcsetsucceed*

A pointer to the count of global system parameters that were successfully configured as a result of this call.

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

JET_errIndexTuplesInvalidLimits

|

The specified tuple index parameters were not allowed. This error can be returned by **JetEnableMultiInstance** only when setting [JET_paramIndexTuplesLengthMin](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294119(v=exchg.10).md), [JET_paramIndexTuplesLengthMax](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294119(v=exchg.10).md), or [JET_paramIndexTuplesToIndexMax](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294119(v=exchg.10).md) to an illegal value.

**Windows XP:** This return value is introduced in Windows XP.

|
|

JET_errInvalidPath

|

The specified file system path was invalid. This error can be returned by **JetEnableMultiInstance** only when setting system parameters that represent file system paths. For example, [JET_paramSystemPath](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269235(v=exchg.10).md) can return this error.

|
|

JET_errRunningInOneInstanceMode

|

The operation failed because it is illegal when the database engine is operating in single instance mode (Windows 2000 compatibility mode).

|
|

JET_errSystemParamsAlreadySet

|

**JetEnableMultiInstance** failed because the engine is already in multi-instance mode.

**Note** This will happen even if no system parameters are specified.

|

If this function succeeds, the database engine will be configured to run in multi-instance mode. The engine was also successfully configured with the optional list of global system parameters.

If this function fails, the database engine will remain in the current mode. If *pcsetsucceed* is non-zero, that number of system parameters will remain set.

#### Remarks

This function should only be used if the application must configure a given set of system parameters atomically when setting up the database engine for use in a multi-user scenario in the same process. If another method of synchronization is available, it is preferable to call [JetCreateInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateinstance-function) and [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function) separately.

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

Implemented as **JetEnableMultiInstanceW** (Unicode) and **JetEnableMultiInstanceA** (ANSI).

|

#### See Also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_SETSYSPARAM](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-setsysparam-structure)
[JetCreateInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateinstance-function)
[JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit-function)
[JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function)