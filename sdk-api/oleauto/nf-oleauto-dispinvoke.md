# DispInvoke function

## Description

Automatically calls member functions on an interface, given the type information for the interface. You can describe an interface with type information and implement [Invoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke) for the interface using this single call.

## Parameters

### `_this`

An implementation of the [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface described by *ptinfo*.

### `ptinfo`

The type information that describes the interface.

### `dispidMember`

The member to be invoked. Use [GetIDsOfNames](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-getidsofnames) or the object's documentation to obtain the DISPID.

### `wFlags`

Flags describing the context of the [Invoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke) call.

| Value | Meaning |
| --- | --- |
| **DISPATCH_METHOD** | The member is invoked as a method. If a property has the same name, both this and the DISPATCH_PROPERTYGET flag can be set. |
| **DISPATCH_PROPERTYGET** | The member is retrieved as a property or data member. |
| **DISPATCH_PROPERTYPUT** | The member is changed as a property or data member. |
| **DISPATCH_PROPERTYPUTREF** | The member is changed by a reference assignment, rather than a value assignment. This flag is valid only when the property accepts a reference to an object. |

### `pparams`

Pointer to a structure containing an array of arguments, an array of argument DISPIDs for named arguments, and counts for number of elements in the arrays.

### `pvarResult`

Pointer to where the result is to be stored, or Null if the caller expects no result. This argument is ignored if DISPATCH_PROPERTYPUT or DISPATCH_PROPERTYPUTREF is specified.

### `pexcepinfo`

Pointer to a structure containing exception information. This structure should be filled in if DISP_E_EXCEPTION is returned.

### `puArgErr`

The index within rgvarg of the first argument that has an error. Arguments are stored in pdispparams->rgvarg in reverse order, so the first argument is the one with the highest index in the array. This parameter is returned only when the resulting return value is DISP_E_TYPEMISMATCH or DISP_E_PARAMNOTFOUND.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **DISP_E_BADPARAMCOUNT** | The number of elements provided to DISPPARAMS is different from the number of arguments accepted by the method or property. |
| **DISP_E_BADVARTYPE** | One of the arguments in DISPPARAMS is not a valid variant type. |
| **DISP_E_EXCEPTION** | The application needs to raise an exception. In this case, the structure passed in *pexcepinfo* should be filled in. |
| **DISP_E_MEMBERNOTFOUND** | The requested member does not exist. |
| **DISP_E_NONAMEDARGS** | This implementation of [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) does not support named arguments. |
| **DISP_E_OVERFLOW** | One of the arguments in DISPPARAMS could not be coerced to the specified type. |
| **DISP_E_PARAMNOTFOUND** | One of the parameter IDs does not correspond to a parameter on the method. In this case, *puArgErr* is set to the first argument that contains the error. |
| **DISP_E_PARAMNOTOPTIONAL** | A required parameter was omitted. |
| **DISP_E_TYPEMISMATCH** | One or more of the arguments could not be coerced. The index of the first parameter with the incorrect type within rgvarg is returned in *puArgErr*. |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

Any of the **ITypeInfo::Invoke** errors can also be returned.

## Remarks

The parameter *_this* is a pointer to an implementation of the interface that is being deferred to. **DispInvoke** builds a stack frame, coerces parameters using standard coercion rules, pushes them on the stack, and then calls the correct member function in the VTBL.

#### Examples

The following code from the Lines sample file Lines.cpp implements [Invoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke) using **DispInvoke**. This implementation relies on **DispInvoke** to validate input arguments. To help minimize security risks, include code that performs more robust validation of the input arguments.

```cpp
STDMETHODIMP
CLines::Invoke(
   DISPID dispidMember,
   REFIID riid,
   LCID lcid,
   WORD wFlags,
   DISPPARAMS * pdispparams,
   VARIANT * pvarResult,
   EXCEPINFO* pexcepinfo,
   UINT * puArgErr)
{
   return DispInvoke(
   this, m_ptinfo,
   dispidMember, wFlags, pdispparams,
   pvarResult, pexcepinfo, puArgErr);
}
```

## See also

[CreateStdDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-createstddispatch)

[Creation of Dispatch API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/automat/dispatch-functions)

[IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch)

[IDispatch::Invoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke)

[ITypeInfo::Invoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-itypeinfo-invoke)