# IDispatch::Invoke

## Description

Provides access to properties and methods exposed by an object. The dispatch function [DispInvoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-dispinvoke) provides a standard implementation of **Invoke**.

## Parameters

### `dispIdMember` [in]

Identifies the member. Use [GetIDsOfNames](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-getidsofnames) or the object's documentation to obtain the dispatch identifier.

### `riid` [in]

Reserved for future use. Must be IID_NULL.

### `lcid` [in]

The locale context in which to interpret arguments. The *lcid* is used by the [GetIDsOfNames](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-getidsofnames) function, and is also passed to **Invoke** to allow the object to interpret its arguments specific to a locale.

Applications that do not support multiple national languages can ignore this parameter. For more information, refer to [Supporting Multiple National Languages](https://learn.microsoft.com/previous-versions/windows/desktop/automat/supporting-multiple-national-languages) and [Exposing ActiveX Objects](https://learn.microsoft.com/previous-versions/windows/desktop/automat/exposing-activex-objects).

### `wFlags` [in]

Flags describing the context of the **Invoke** call.

| Value | Meaning |
| --- | --- |
| **DISPATCH_METHOD** | The member is invoked as a method. If a property has the same name, both this and the DISPATCH_PROPERTYGET flag can be set. |
| **DISPATCH_PROPERTYGET** | The member is retrieved as a property or data member. |
| **DISPATCH_PROPERTYPUT** | The member is changed as a property or data member. |
| **DISPATCH_PROPERTYPUTREF** | The member is changed by a reference assignment, rather than a value assignment. This flag is valid only when the property accepts a reference to an object. |

### `pDispParams` [in, out]

Pointer to a DISPPARAMS structure containing an array of arguments, an array of argument DISPIDs for named arguments, and counts for the number of elements in the arrays.

### `pVarResult` [out]

Pointer to the location where the result is to be stored, or NULL if the caller expects no result. This argument is ignored if DISPATCH_PROPERTYPUT or DISPATCH_PROPERTYPUTREF is specified.

### `pExcepInfo` [out]

Pointer to a structure that contains exception information. This structure should be filled in if DISP_E_EXCEPTION is returned. Can be NULL.

### `puArgErr` [out]

The index within rgvarg of the first argument that has an error. Arguments are stored in pDispParams->rgvarg in reverse order, so the first argument is the one with the highest index in the array. This parameter is returned only when the resulting return value is DISP_E_TYPEMISMATCH or DISP_E_PARAMNOTFOUND. This argument can be set to null. For details, see [Returning Errors](https://learn.microsoft.com/previous-versions/windows/desktop/automat/returning-errors).

## Return value

This method can return one of these values.

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
| **DISP_E_TYPEMISMATCH** | One or more of the arguments could not be coerced. The index of the first parameter with the incorrect type within rgvarg is returned in *puArgErr*. |
| **DISP_E_UNKNOWNINTERFACE** | The interface identifier passed in riid is not IID_NULL. |
| **DISP_E_UNKNOWNLCID** | The member being invoked interprets string arguments according to the LCID, and the LCID is not recognized. If the LCID is not needed to interpret arguments, this error should not be returned |
| **DISP_E_PARAMNOTOPTIONAL** | A required parameter was omitted. |

## Remarks

Generally, you should not implement **Invoke** directly. Instead, use the dispatch interface to create functions [CreateStdDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-createstddispatch) and [DispInvoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-dispinvoke). For details, refer to **CreateStdDispatch**, **DispInvoke**, [Creating the IDispatch Interface](https://learn.microsoft.com/previous-versions/windows/desktop/automat/creating-the-idispatch-interface) and [Exposing ActiveX Objects](https://learn.microsoft.com/previous-versions/windows/desktop/automat/exposing-activex-objects).

If some application-specific processing needs to be performed before calling a member, the code should perform the necessary actions, and then call [ITypeInfo::Invoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-itypeinfo-invoke) to invoke the member. **ITypeInfo::Invoke** acts exactly like **Invoke**. The standard implementations of **Invoke** created by **CreateStdDispatch** and **DispInvoke** defer to **ITypeInfo::Invoke**.

In an ActiveX client, **Invoke** should be used to get and set the values of properties, or to call a method of an ActiveX object. The *dispIdMember* argument identifies the member to invoke. The DISPIDs that identify members are defined by the implementer of the object and can be determined by using the object's documentation, the [IDispatch::GetIDsOfNames](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-getidsofnames) function, or the [ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo) interface.

When you use **IDispatch::Invoke()** with DISPATCH_PROPERTYPUT or DISPATCH_PROPERTYPUTREF, you have to specially initialize the **cNamedArgs** and **rgdispidNamedArgs** elements of your DISPPARAMS structure with the following:

```cpp
DISPID dispidNamed = DISPID_PROPERTYPUT;
dispparams.cNamedArgs = 1;
dispparams.rgdispidNamedArgs = &dispidNamed;
```

The information that follows addresses developers of ActiveX clients and others who use code to expose ActiveX objects. It describes the behavior that users of exposed objects should expect.

## See also

[IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch)