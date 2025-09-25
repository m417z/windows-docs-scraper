# CreateDispTypeInfo function

## Description

Creates simplified type information for use in an implementation of [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch).

## Parameters

### `pidata`

The interface description that this type information describes.

### `lcid`

The locale identifier for the names used in the type information.

### `pptinfo`

On return, pointer to a type information implementation for use in [DispGetIDsOfNames](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-dispgetidsofnames) and [DispInvoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-dispinvoke).

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The interface is supported. |
| **E_INVALIDARG** | Either the interface description or the LCID is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

You can construct type information at run time by using **CreateDispTypeInfo** and an INTERFACEDATA structure that describes the object being exposed.

The type information returned by this function is primarily designed to automate the implementation of [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch). **CreateDispTypeInfo** does not return all of the type information described in [Type Description Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/automat/type-description-interfaces). The argument *pidata* is not a complete description of an interface. It does not include Help information, comments, optional parameters, and other type information that is useful in different contexts.

Accordingly, the recommended method for providing type information about an object is to describe the object using the Object Description Language (ODL), and to compile the object description into a type library using the Microsoft Interface Definition Language (MIDL) compiler.

To use type information from a type library, use the [LoadTypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-loadtypelib) and [GetTypeInfoOfGuid](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-itypelib-gettypeinfoofguid) functions instead of **CreateDispTypeInfo**. For more information [Type Description Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/automat/type-description-interfaces).

#### Examples

The code that follows creates type information from INTERFACEDATA to expose the CCalc object.

```cpp
static METHODDATA NEARDATA rgmdataCCalc[] =
{
      PROPERTY(VALUE,  IMETH_ACCUM,    IDMEMBER_ACCUM,    VT_I4),
      PROPERTY(ACCUM,  IMETH_ACCUM,    IDMEMBER_ACCUM,    VT_I4),
      PROPERTY(OPND,   IMETH_OPERAND,  IDMEMBER_OPERAND,  VT_I4),
      PROPERTY(OP,     IMETH_OPERATOR, IDMEMBER_OPERATOR, VT_I2),
      METHOD0(EVAL,    IMETH_EVAL,     IDMEMBER_EVAL,     VT_BOOL),
      METHOD0(CLEAR,   IMETH_CLEAR,    IDMEMBER_CLEAR,    VT_EMPTY),
      METHOD0(DISPLAY, IMETH_DISPLAY,  IDMEMBER_DISPLAY,  VT_EMPTY),
      METHOD0(QUIT,    IMETH_QUIT,     IDMEMBER_QUIT,     VT_EMPTY),
      METHOD1(BUTTON,  IMETH_BUTTON,   IDMEMBER_BUTTON,   VT_BOOL),
};

INTERFACEDATA NEARDATA g_idataCCalc =
{
   rgmdataCCalc, DIM(rgmdataCCalc)
};

// Use Dispatch interface API functions to implement IDispatch.
CCalc *
CCalc::Create()
{
   HRESULT hresult;
   CCalc * pcalc;
   CArith * parith;
   ITypeInfo * ptinfo;
   IUnknown * punkStdDisp;
   extern INTERFACEDATA NEARDATA g_idataCCalc;

   if((pcalc = new CCalc()) == NULL)
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

   ptinfo->Release();

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