# JetFreeBuffer Function

_**Applies to:** Windows | Windows Server_

## JetFreeBuffer Function

The **JetFreeBuffer** function frees memory that was allocated by a database engine call.

**Windows XP: JetFreeBuffer** is introduced in Windows XP.

```cpp
    JET_ERR JET_API JetFreeBuffer(
      __in          char* pbBuf
    );
```

### Parameters

*pbBuf*

Pointer to a region of memory that was previously allocated by a call to the database engine. **NULL** is acceptable, and will be ignored.

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

#### Remarks

It is undefined behavior to pass memory that was not allocated by the database engine in to *pbBuf*.

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
[JetGetInstanceInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetinstanceinfo-function)