# DllGetClassObject function

## Description

Retrieves the class object from a DLL object handler or object application.

OLE does not provide this function. DLLs that support the OLE Component Object Model (COM) must implement **DllGetClassObject** in OLE object handlers or DLL applications.

## Parameters

### `rclsid` [in]

The CLSID that will associate the correct data and code.

### `riid` [in]

A reference to the identifier of the interface that the caller is to use to communicate with the class object. Usually, this is IID_IClassFactory (defined in the OLE headers as the interface identifier for [IClassFactory](https://learn.microsoft.com/windows/desktop/api/unknwnbase/nn-unknwnbase-iclassfactory)).

### `ppv` [out]

The address of a pointer variable that receives the interface pointer requested in riid. Upon successful return, **ppv* contains the requested interface pointer. If an error occurs, the interface pointer is **NULL**.

## Return value

This function can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The object was retrieved successfully. |
| **CLASS_E_CLASSNOTAVAILABLE** | The DLL does not support the class (object definition). |

## Remarks

If a call to the [CoGetClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetclassobject) function finds the class object that is to be loaded in a DLL, **CoGetClassObject** uses the DLL's exported **DllGetClassObject** function.

### Notes to Callers

You should not call **DllGetClassObject** directly. When an object is defined in a DLL, [CoGetClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetclassobject) calls the [CoLoadLibrary](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coloadlibrary) function to load the DLL, which, in turn, calls **DllGetClassObject**.

### Notes to Implementers

You need to implement **DllGetClassObject** in (and export it from) DLLs that support COM.

#### Examples

The following is an example (in C++) of an implementation of **DllGetClassObject**. In this example, **DllGetClassObject** creates a class object and calls its [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method to retrieve a pointer to the interface requested in riid. The implementation releases the reference it holds to the [IClassFactory](https://learn.microsoft.com/windows/desktop/api/unknwnbase/nn-unknwnbase-iclassfactory) interface because it returns a reference-counted pointer to **IClassFactory** to the caller.

```cpp
HRESULT _export CALLBACK DllGetClassObject
    (REFCLSID rclsid, REFIID riid, LPVOID * ppvObj)
{
    HRESULT hr = E_OUTOFMEMORY;
    *ppvObj = NULL;

    CClassFactory *pClassFactory = new CClassFactory(rclsid);
    if (pClassFactory != NULL)   {
        hr = pClassFactory->QueryInterface(riid, ppvObj);
        pClassFactory->Release();
    }
    return hr;
}

```

## See also

[CoGetClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetclassobject)

[DllCanUnloadNow](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-dllcanunloadnow)