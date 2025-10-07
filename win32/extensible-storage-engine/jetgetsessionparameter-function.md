# JetGetSessionParameter Function

_**Applies to:** Windows | Windows Server_

The **JetGetSessionParameter** function reads the session parameter for the given session.

The **JetGetSessionParameter** function was introduced in the Windows 8 operating system.

``` c++
JET_ERR JET_API JetGetSessionParameter (
  __in_opt      JET_SESID sesid,
  __in          unsigned long sesparamid,
  __out_cap_post_count_(cbParamMax, *pcbParamActual)  void* pvParam,
  __in          unsigned long cbParamMax,
  __out_opt_    unsigned long pcbParamActual
);
```

### Parameters

*sesid*

The session to use for this call.

When specified, the specified instance is ignored and the instance associated with the session will be used.

*sesparamid*

The ID of the session parameter to set.

*pvParam*

Data in this session parameter.

*cbParamMax*

The maximum size of the data set in this session parameter.

*pcbParamActual*

The actual size of the data set in this session parameter.

### Return value

On success, the output buffer appropriate for the requested session parameter will be set to the value of that session parameter.

On failure, the state of the output buffers will be undefined.

#### Remarks

The session parameter is used for the lifetime of the session or until the value is reset.

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
[JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit-function)
[JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function)
[JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopservice-function)
[System Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-system-parameters)