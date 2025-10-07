# JetStopServiceInstance Function

_**Applies to:** Windows | Windows Server_

## JetStopServiceInstance Function

The **JetStopServiceInstance** function prepares an instance for termination.

**Windows XP:** **JetStopServiceInstance** is introduced in Windows XP.

```cpp
    JET_ERR JET_API JetStopServiceInstance(
      __in          JET_INSTANCE instance
    );
```

### Parameters

*instance*

The running instance to use for the API call.

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

JET_errInvalidParameter

|

The specified instance parameter has an invalid value (not an instance that is currently running).

**Windows XP:** This return value is introduced in Windows XP.

|

If this function succeeds, it prepares for a future termination. The steps taken to prepare for a termination include the following:

  - Stop online defragmentation if it is running.

  - Start a version store clean-up.

  - Reduce the checkpoint depth by starting to flush dirty pages in the buffer manager.

  - Prevent future calls to most functions for that instance.

If this function fails, none of the steps to prepare for an instance termination will be taken, so no change to the instance state will occur.

#### Remarks

This function will reduce the work the instance will have to do when terminated but will not terminate the instance. As a result, this function is just an optimization and is not mandatory to use. Note that the amount of work done in preparation was less in Windows 2000 and Windows XP. Once the function succeeds, calling functions that are no longer allowed will return JET_errClientRequestToStopJetService. Functions that are still allowed after this call are: [JetRollback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetrollback-function), [JetCloseTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosetable-function), [JetEndSession](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetendsession-function), [JetCloseDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosedatabase-function), [JetDetachDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdetachdatabase-function) and [JetResetSessionContext](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetresetsessioncontext-function).

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

#### See Also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_INSTANCE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-instance)
[JetCloseDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosedatabase-function)
[JetCloseTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosetable-function)
[JetDetachDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdetachdatabase-function)
[JetEndSession](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetendsession-function)
[JetResetSessionContext](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetresetsessioncontext-function)
[JetRollback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetrollback-function)
[JetTerm](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetterm-function)
[JetTerm2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetterm2-function)