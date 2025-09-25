# CoCreateInstance function

## Description

Creates and default-initializes a single object of the class associated with a specified CLSID.

Call **CoCreateInstance** when you want to create only one object on the local system. To create a single object on a remote system, call the [CoCreateInstanceEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstanceex) function. To create multiple objects based on a single CLSID, call the [CoGetClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetclassobject) function.

## Parameters

### `rclsid` [in]

The CLSID associated with the data and code that will be used to create the object.

### `pUnkOuter` [in]

If **NULL**, indicates that the object is not being created as part of an aggregate. If non-**NULL**, pointer to the aggregate object's [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface (the controlling **IUnknown**).

### `dwClsContext` [in]

Context in which the code that manages the newly created object will run. The values are taken from the enumeration [CLSCTX](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-clsctx).

### `riid` [in]

A reference to the identifier of the interface to be used to communicate with the object.

### `ppv` [out]

Address of pointer variable that receives the interface pointer requested in *riid*. Upon successful return, **ppv* contains the requested interface pointer. Upon failure, **ppv* contains **NULL**.

## Return value

This function can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | An instance of the specified object class was successfully created. |
| **REGDB_E_CLASSNOTREG** | A specified class is not registered in the registration database. Also can indicate that the type of server you requested in the [CLSCTX](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-clsctx) enumeration is not registered or the values for the server types in the registry are corrupt. |
| **CLASS_E_NOAGGREGATION** | This class cannot be created as part of an aggregate. |
| **E_NOINTERFACE** | The specified class does not implement the requested interface, or the controlling [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) does not expose the requested interface. |
| **E_POINTER** | The *ppv* parameter is **NULL**. |

## Remarks

The **CoCreateInstance** function provides a convenient shortcut by connecting to the class object associated with the specified CLSID, creating a default-initialized instance, and releasing the class object. As such, it encapsulates the following functionality:

``` syntax
CoGetClassObject(rclsid, dwClsContext, NULL, IID_IClassFactory, &pCF);
hresult = pCF->CreateInstance(pUnkOuter, riid, ppvObj);
pCF->Release();

```

It is convenient to use **CoCreateInstance** when you need to create only a single instance of an object on the local machine. If you are creating an instance on remote computer, call [CoCreateInstanceEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstanceex). When you are creating multiple instances, it is more efficient to obtain a pointer to the class object's [IClassFactory](https://learn.microsoft.com/windows/desktop/api/unknwnbase/nn-unknwnbase-iclassfactory) interface and use its methods as needed. In the latter case, you should use the [CoGetClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetclassobject) function.

In the [CLSCTX](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-clsctx) enumeration, you can specify the type of server used to manage the object. The constants can be CLSCTX_INPROC_SERVER, CLSCTX_INPROC_HANDLER, CLSCTX_LOCAL_SERVER, CLSCTX_REMOTE_SERVER or any combination of these values. The constant CLSCTX_ALL is defined as the combination of all four. For more information about the use of one or a combination of these constants, see [CLSCTX](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-clsctx).

### UWP applications
Although there are no restrictions on which CLSIDs a UWP application can pass to **CoCreateInstance**, many objects will fail with **E_ACCESSDENIED** for security reasons, especially if they do not run in-process. Additionally, even if you can successfully create an object, it might fail at a later time due to UWP security constraints, app-model differences, etc. In particular, background tasks should limit the objects they communicate with to avoid hangs or other complications due to connected stand-by.

## Examples

```cpp
// Create WIC factory
hr = CoCreateInstance(
    CLSID_WICImagingFactory,
    NULL,
    CLSCTX_INPROC_SERVER,
    IID_PPV_ARGS(&m_pIWICFactory)
    );
```

## See also

[CoCreateInstanceEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstanceex)

[CoGetClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetclassobject)

[IClassFactory::CreateInstance](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iclassfactory-createinstance)

[Instance Creation Helper Functions](https://learn.microsoft.com/windows/desktop/com/instance-creation-helper-functions)