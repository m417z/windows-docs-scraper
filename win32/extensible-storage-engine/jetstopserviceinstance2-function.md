# JetStopServiceInstance2 Function

_**Applies to:** Windows | Windows Server_

The **JetStopServiceInstance2** function prepares an instance prior to Suspend, and prepares an instance after Resume. Suspend and Resume are execution states of the Windows Store App lifecycle model.

The **JetStopServiceInstance2** function was introduced in Windows 8.

``` c++
JET_ERR JET_API JetStopServiceInstance2(
  _In_          JET_INSTANCE       instance
  _In_          const JET_GRBIT    grbit
);
```

### Parameters

*instance*

The target instance. The **JET_INSTANCE** data type is a handle to the instance of the database to use for a call to the JET API. This handle is obtained when you create an instance of the database by calling the [JetCreateInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateinstance-function), [JetCreateInstance2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateinstance2-function), [JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit-function), or [JetInit2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit2-function) functions.

*grbit*

A group of bits that specifies one or more of the values listed and defined in the following table.

|

Value

|

Description

|
|--------------|--------------------|
|

JET_bitStopServiceAll

|

Stops all Extensible Storage Engine (ESE) services for the specified instance.

|
|

JET_bitStopServiceBackgroundUserTasks

|

Stops restartable client-specified background maintenance tasks (B+ Tree Defrag, for example).

|
|

JET_bitStopServiceQuiesceCaches

|

Quiesces all dirty caches to disk. This value is asynchronous and can be canceled.

|
|

JET_bitStopServiceResume

|

Resumes previously issued StopService operations; that is, it restarts the service. This value can be combined with the *grbits* parameter to resume specific services, or with JET_bitStopServiceAll to Resume all previously stopped services. This bit can only be used to resume StopServiceBackgroundUserTasks and JET_bitStopServiceQuiesceCaches. If you previously called with JET_bitStopServiceAll, an attempt to use JET_bitStopServiceResume will fail. If the second resume step does not get called, the application will have degraded performance. In this situation the checkpoint is kept at zero.

|

### Return value

This function returns the [JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err) data type with one of the following return codes. For more information about the possible ESE errors, see [Extensible Storage Engine Errors](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-errors) and [Error Handling Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/error-handling-parameters).

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

#### Remarks

This function allows a JET application to move the database cache to a clean or nearly clean state (with the operating system I/O idle), such that if the application were to be terminated, recovery would be quick. This approach is preferred over terminating JET by calling the [JetTerm](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetterm-function) or [JetDetachDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdetachdatabase-function) functions, so that in the more common scenario, the application is just unsuspended, and later the application has the whole cache and is ready to go as soon as possible.

If this function succeeds, it prepares the database cache for an imminent suspension. This function queues work to a background worker thread and returns to the caller immediately. The function should be called based on the PLM VisibilityNotice as opposed to calling from the application's suspension event handler to ensure that JET has time to flush dirty buffers before PLM suspends/terminates the process. Internally, JET triggers an immediate dispatch of checkpoint maintenance upon configuration change (either checkpoint update or this new quiesce caches bit). For more information about VisibilityNotice events, see [VisibilityChangedEventArgs class](https://learn.microsoft.com/uwp/api/windows.ui.core.visibilitychangedeventargs).

This function must be called twice. It is called after the application receives the suspension notice from the operating system, but before the application has been suspended. Then it is called again after the operating system resumes the application. For example:

When called to Suspend: JET_ERR JET_API JetStopServiceInstance2( instance, JET_bitStopServiceQuiesceCaches);

When Resumed: JET_ERR JET_API JetStopServiceInstance2( instance, JET_bitStopServiceQuiesceCaches|JET_bitStopServiceResume );

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