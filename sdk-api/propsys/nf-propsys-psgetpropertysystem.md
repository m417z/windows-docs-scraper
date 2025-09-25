# PSGetPropertySystem function

## Description

Gets an instance of the subsystem object that implements [IPropertySystem](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertysystem).

## Parameters

### `riid` [in]

Type: **REFIID**

Reference to the IID of the requested interface.

### `ppv` [out]

Type: **void****

When this function returns, contains the interface pointer requested in *riid*. This is typically [IPropertySystem](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertysystem).

## Return value

Type: **PSSTDAPI**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The interface was obtained. |
| **E_INVALIDARG** | The *ppv* parameter is **NULL**. |

## Remarks

You must initialize Component Object Model (COM) with [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize) or [OleInitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleinitialize) prior to calling [PSGetPropertySystem](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetpropertysystem). COM must remain initialized for the lifetime of this object. The property system object aggregates the free-threaded marshaller and is thread-safe.

We recommend that you use the IID_PPV_ARGS macro defined in Objbase.h to package the *riid* and *ppv* parameters. This macro provides the correct IID based on the interface pointed to by the value in *ppv*, which eliminates the possibility of a coding error.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PSGetPropertySystem](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetpropertysystem).

```cpp
IPropertySystem *pSystem;

HRESULT hr = PSGetPropertySystem(IID_PPV_ARGS(&pSystem));

if (SUCCEEDED(hr))
{
    // pSystem is now valid.

    pSystem->Release();
}
```