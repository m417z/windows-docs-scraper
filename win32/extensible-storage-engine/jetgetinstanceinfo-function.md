# JetGetInstanceInfo Function

_**Applies to:** Windows | Windows Server_

## JetGetInstanceInfo Function

The **JetGetInstanceInfo** function retrieves information about the instances that are running.

**Windows XP: JetGetInstanceInfo** is introduced in Windows XP.

```cpp
    JET_ERR JET_API JetGetInstanceInfo(
      __out         unsigned long* pcInstanceInfo,
      __out         JET_INSTANCE_INFO** paInstanceInfo
    );
```

### Parameters

*pcInstanceInfo*

A pointer to a buffer which will receive the number of elements stored in *paInstanceInfo*.

*paInstanceInfo*

A pointer to a buffer which will receive the address of the first element of an array of structures.

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

One of the parameters provided contained an unexpected value or contained a value that did not make sense when combined with the value of another parameter. This error will be returned by **JetGetInstanceInfo** when:

* *pcInstanceInfo* or *paInstanceInfo* are NULL.

|
|

JET_errOutOfMemory

|

There is insufficient memory to process the request.

|

#### Remarks

The database engine will allocate an array of [JET_INSTANCE_INFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-instance-info-structure) structures. The caller is responsible for freeing this memory with [JetFreeBuffer](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetfreebuffer-function).

If there are no active instances, **JetGetInstanceInfo** will return JET_errSuccess, and *pcInstanceInfo* will receive a value of 0.

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

Implemented as **JetGetInstanceInfoW** (Unicode) and **JetGetInstanceInfoA** (ANSI).

|

#### See Also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_INSTANCE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-instance)
[JET_INSTANCE_INFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-instance-info-structure)
[JetFreeBuffer](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetfreebuffer-function)