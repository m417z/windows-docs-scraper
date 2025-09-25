## Description

Used to retrieve an interface pointer, supplying the IID value of the requested interface automatically based on the type of the interface pointer used. This avoids a common coding error by checking the type of the value passed at compile time.

## Parameters

### `ppType`

An address of an interface pointer whose type **T** is used to determine the type of object being requested. The macro returns the interface pointer through this parameter.

## Remarks

A common syntax in methods that retrieve an interface pointer (most notably [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) and [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance)) includes two parameters:

* An [in] parameter, normally of type **REFIID**, to specify the IID of the interface to retrieve.
* An [out] parameter, normally of type **void****, to receive the interface pointer.

This macro computes the IID based on the type of interface pointer, which prevents coding errors in which the IID and interface pointer type do not match. Windows developers should always use this macro with any method that requires separate IID and interface pointer parameters.

While Windows 7 is the first inclusion of this macro in a public header, it can be used on older systems by defining it manually in your project headers or source code.

The following example shows the use of **IID_PPV_ARGS** to create the memory property store object using [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore).

```cpp
IPropertyStore *pPropertyStore;

CoCreateInstance(CLSID_PropertyStore, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pPropertyStore));
```

## Syntax

```cpp
void IID_PPV_ARGS(
    T **ppType
);
```