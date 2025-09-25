## Description

Creates a single uninitialized object of the class associated with a specified CLSID (can be used to create an instance of the compiler with a custom memory allocator). Also see [DxcCreateInstance](https://learn.microsoft.com/windows/win32/api/dxcapi/nf-dxcapi-dxccreateinstance).

## Parameters

### `pMalloc`

An **IMalloc** interface pointer representing a custom memory allocator.

### `rclsid`

The CLSID associated with the data and code that will be used to create the object.

### `riid`

A reference to the identifier of the interface to be used to communicate with the object.

### `ppv`

Address of pointer variable that receives the interface pointer requested in *riid*. Upon successful return, `*ppv` contains the requested interface pointer. Upon failure, `*ppv` contains NULL.

## Return value

While this function is similar to **CoCreateInstance**, there's no COM involvement.

## Remarks

To make it more convenient for you to use **GetProcAddress** to call **DxcCreateInstance2**, the **DxcCreateInstance2Proc** typedef is provided:

```cpp
typedef HRESULT(__stdcall *DxcCreateInstance2Proc)(
  _In_ IMalloc    *pMalloc,
  _In_ REFCLSID   rclsid,
  _In_ REFIID     riid,
  _Out_ LPVOID*   ppv
);
```

## See also