# DispGetParam function

## Description

Retrieves a parameter from the DISPPARAMS structure, checking both named parameters and positional parameters, and coerces the parameter to the specified type.

## Parameters

### `pdispparams` [in]

The parameters passed to [Invoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke).

### `position`

The position of the parameter in the parameter list. **DispGetParam** starts at the end of the array, so if position is 0, the last parameter in the array is returned.

### `vtTarg`

The type the argument should be coerced to.

### `pvarResult` [out]

the variant to pass the parameter into.

### `puArgErr` [out, optional]

On return, the index of the argument that caused a DISP_E_TYPEMISMATCH error. This pointer is returned to [Invoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke) to indicate the position of the argument in DISPPARAMS that caused the error.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **DISP_E_BADVARTYPE** | The variant type *vtTarg* is not supported. |
| **DISP_E_OVERFLOW** | The retrieved parameter could not be coerced to the specified type. |
| **DISP_E_PARAMNOTFOUND** | The parameter indicated by *position* could not be found. |
| **DISP_E_TYPEMISMATCH** | The argument could not be coerced to the specified type. |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

The output parameter *pvarResult* must be a valid variant. Any existing contents are released in the standard way. The contents of the variant are freed with **VariantFree**.

If you have used **DispGetParam** to get the right side of a property put operation, the second parameter should be DISPID_PROPERTYPUT. For example:

```cpp
DispGetParam(&dispparams, DISPID_PROPERTYPUT, VT_BOOL, &varResult, &uiArg)
```

Named parameters cannot be accessed positionally, and vice versa.

#### Examples

The following example uses **DispGetParam** to set X and Y properties.

```cpp
STDMETHODIMP
CPoint::Invoke(
   DISPID dispidMember,
   REFIID riid,
   LCID lcid,
   unsigned short wFlags,
   DISPPARAMS * pdispparams,
   VARIANT * pvarResult,
   EXCEPINFO * pExcepInfo,
   unsigned int * puArgErr)
{
   unsigned int uArgErr;
   HRESULT hresult;
   VARIANTARG varg0;
   VARIANT varResultDummy;

   // Make sure the wFlags are valid.
   if(wFlags & ~(DISPATCH_METHOD | DISPATCH_PROPERTYGET |
      DISPATCH_PROPERTYPUT | DISPATCH_PROPERTYPUTREF))
      return E_INVALIDARG;

   // This object only exposes a "default" interface.
   if(!IsEqualIID(riid, IID_NULL))
      return DISP_E_UNKNOWNINTERFACE;

   // It simplifies the following code if the caller
   // ignores the return value.
   if(puArgErr == NULL)
      puArgErr = &uArgErr;
   if(pvarResult == NULL)
      pvarResult = &varResultDummy;

   VariantInit(&varg0);

   // Assume the return type is void, unless otherwise is found.
   VariantInit(pvarResult);

   switch(dispidMember){
   case IDMEMBER_CPOINT_GETX:
      V_VT(pvarResult) = VT_I2;
      V_I2(pvarResult) = GetX();
      break;

   case IDMEMBER_CPOINT_SETX:
      hresult = DispGetParam(pdispparams, 0, VT_I2, &varg0, puArgErr);
      if(hresult != NOERROR)
         return hresult;
      SetX(V_I2(&varg0));
      break;

   case IDMEMBER_CPOINT_GETY:
      V_VT(pvarResult) = VT_I2;
      V_I2(pvarResult) = GetY();
      break;

   case IDMEMBER_CPOINT_SETY:
      hresult = DispGetParam(pdispparams, 0, VT_I2, &varg0, puArgErr);
      if(hresult != NOERROR)
         return hresult;
      SetY(V_I2(&varg0));
      break;

   default:
      return DISP_E_MEMBERNOTFOUND;
   }
   return NOERROR;
}
```

## See also

[CreateStdDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-createstddispatch)

[Creation of Dispatch API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/automat/dispatch-functions)

[IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch)

[IDispatch::Invoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke)