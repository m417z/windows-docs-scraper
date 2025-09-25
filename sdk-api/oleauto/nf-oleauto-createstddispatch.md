# CreateStdDispatch function

## Description

Creates a standard implementation of the [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface through a single function call. This simplifies exposing objects through Automation.

## Parameters

### `punkOuter`

The object's **IUnknown** implementation.

### `pvThis`

The object to expose.

### `ptinfo`

The type information that describes the exposed object.

### `ppunkStdDisp`

The private unknown for the object that implements the [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface QueryInterface call. This pointer is null if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One of the first three arguments is not valid. |
| **E_OUTOFMEMORY** | There was insufficient memory to complete the operation. |

## Remarks

You can use **CreateStdDispatch** when creating an object instead of implementing the [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) member functions for the object. However, the implementation that **CreateStdDispatch** creates has these limitations:

* Supports only one national language.
* Supports only dispatch-defined exception codes returned from [Invoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke).

[LoadTypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-loadtypelib), [GetTypeInfoOfGuid](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-itypelib-gettypeinfoofguid), and **CreateStdDispatch** comprise the minimum set of functions that you need to call to expose an object using a type library. For more information on **LoadTypeLib** and **GetTypeInfoOfGuid**, see [Type Description Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/automat/type-description-interfaces).

[CreateDispTypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-createdisptypeinfo) and **CreateStdDispatch** comprise the minimum set of dispatch components you need to call to expose an object using type information provided by the INTERFACEDATA structure.

#### Examples

The following code implements the **IDispatch** interface for the **CCalc** class using **CreateStdDispatch**.

```cpp
CCalc FAR*
CCalc::Create()
{
   HRESULT hresult;
   CCalc * pcalc;
   CArith * parith;
   ITypeInfo* ptinfo;
   IUnknown * punkStdDisp;
extern INTERFACEDATA NEARDATA g_idataCCalc;

   if((pcalc = new FAR CCalc()) == NULL)
      return NULL;
   pcalc->AddRef();

   parith = &(pcalc->m_arith);

   // Build type information for the functionality on this object that
   // is being exposed for external programmability.
   hresult = CreateDispTypeInfo(
      &g_idataCCalc, LOCALE_SYSTEM_DEFAULT, &ptinfo);
   if(hresult != NOERROR)
      goto LError0;

   // Create an aggregate with an instance of the default
   // implementation of IDispatch that is initialized with
   // type information.
   hresult = CreateStdDispatch(
      pcalc,            // Controlling unknown.
      parith,            // Instance to dispatch on.
      ptinfo,            // Type information describing the instance.
      &punkStdDisp);

   ptinfo-&>Release();

   if(hresult != NOERROR)
      goto LError0;

   pcalc->m_punkStdDisp = punkStdDisp;

   return pcalc;

LError0:;
   pcalc->Release();
   return NULL;
}
```

## See also

[Creation of Dispatch API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/automat/dispatch-functions)

[IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch)