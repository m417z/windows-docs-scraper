# ITypeInfo::Invoke

## Description

Invokes a method, or accesses a property of an object, that implements the interface described by the type description.

## Parameters

### `pvInstance` [in]

An instance of the interface described by this type description.

### `memid` [in]

The interface member.

### `wFlags` [in]

Flags describing the context of the invoke call.

| Value | Meaning |
| --- | --- |
| **DISPATCH_METHOD** | The member is accessed as a method. If there is ambiguity, both this and the DISPATCH_PROPERTYGET flag can be set. |
| **DISPATCH_PROPERTYGET** | The member is retrieved as a property or data member. |
| **DISPATCH_PROPERTYPUT** | The member is changed as a property or data member. |
| **DISPATCH_PROPERTYPUTREF** | The member is changed by using a reference assignment, rather than a value assignment. This flag is valid only when the property accepts a reference to an object. |

### `pDispParams` [in, out]

An array of arguments, an array of DISPIDs for named arguments, and counts of the number of elements in each array.

### `pVarResult` [out]

The result. Should be null if the caller does not expect any result. If *wFlags* specifies DISPATCH_PROPERTYPUT or DISPATCH_PROPERTYPUTREF, *pVarResultis* is ignored.

### `pExcepInfo` [out]

An exception information structure, which is filled in only if DISP_E_EXCEPTION is returned. If *pExcepInfo* is null on input, only an HRESULT error will be returned.

### `puArgErr` [out]

If Invoke returns DISP_E_TYPEMISMATCH, *puArgErr* indicates the index (within *rgvarg*) of the argument with incorrect type. If more than one argument returns an error, *puArgErr* indicates only the first argument with an error. Arguments in pDispParams->rgvarg appear in reverse order, so the first argument is the one having the highest index in the array. This parameter cannot be null.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **DISP_E_EXCEPTION** | The member being invoked has returned an error HRESULT. If the member implements [IErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ierrorinfo), details are available in the error object. Otherwise, the *pExcepInfo* parameter contains details. |

Any of the [IDispatch::Invoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke) errors may also be returned.

## Remarks

Use the function **ITypeInfo::Invoke** to access a member of an object or invoke a method that implements the interface described by this type description. For objects that support the [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface, you can use **Invoke** to implement [IDispatch::Invoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke).

**ITypeInfo::Invoke** takes a pointer to an instance of the class. Otherwise, its parameters are the same as [IDispatch::Invoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke), except that **ITypeInfo::Invoke** omits the *refiid* and *lcid* parameters. When called, **ITypeInfo::Invoke** performs the actions described by the **IDispatch::Invoke** parameters on the specified instance.

For VTBL interface members, **ITypeInfo::Invoke** passes the LCID of the type information into parameters tagged with the lcid attribute, and the returned value into the retval attribute.

If the type description inherits from another type description, this function recurses on the base type description to find the item with the requested member ID.

## See also

[ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo)