# IADsExtension::PrivateInvoke

## Description

The **IADsExtension::PrivateInvoke** method is normally called by ADSI after the [IADsExtension::PrivateGetIDsOfNames](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsextension-privategetidsofnames) method. This method can either have a custom implementation or it can delegate the operation to [IDispatch::DispInvoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-dispinvoke) method.

## Parameters

### `dispidMember` [in]

Identifies the member. Use the [IADsExtension::PrivateGetIDsOfNames](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsextension-privategetidsofnames) method to obtain the dispatch identifier.

### `riid` [in]

Reserved for future use. Must be IID_NULL.

### `lcid` [in]

The locale context in which to interpret arguments. The [IADsExtension::PrivateGetIDsOfNames](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsextension-privategetidsofnames) function uses *lcid*. It is also passed to the **PrivateInvoke** method to allow the object to interpret the arguments that are specific to a locale.

### `wFlags` [in]

Flags that describe the context of the **PrivateInvoke** call, include.

#### DISPATCH_METHOD

The member is invoked as a method. If a property has the same name, both this and the **DISPATCH_PROPERTYGET** flag may be set.

#### DISPATCH_PROPERTYGET

The member is retrieved as a property or data member.

#### DISPATCH_PROPERTYPUT

The member is changed as a property or data member.

#### DISPATCH_PROPERTYPUTREF

The member is changed by a reference assignment, rather than a value assignment. This flag is valid only when the property accepts a reference to an object.

### `pdispparams` [in]

Pointer to a [DISPPARAMS](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-dispparams) structure that receives an array of arguments, an array of argument DISPIDs for named arguments, and counts for the number of elements in the arrays.

### `pvarResult` [out]

Pointer to the location where the result is to be stored, or **NULL** if the caller expects no result. This argument is ignored if **DISPATCH_PROPERTYPUT** or **DISPATCH_PROPERTYPUTREF** is specified.

### `pexcepinfo` [out]

Pointer to a structure that contains exception data. This structure should be filled in if **DISP_E_EXCEPTION** is returned. Can be **NULL**.

### `puArgErr` [out]

The index within the **rgvarg** member of the [DISPPARAMS](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-dispparams) structure in *pdispparams* for the first argument that has an error. Arguments are stored in the **rgvarg** array in reverse order, so the first argument is the one with the highest index in the array. This parameter is returned only when the resulting return value is **DISP_E_TYPEMISMATCH** or **DISP_E_PARAMNOTFOUND**.

## Return value

This method supports the standard return values, as well as the following.

For more information about other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[DispInvoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-dispinvoke)

[IADsExtension](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsextension)

[IADsExtension::PrivateGetIDsOfNames](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsextension-privategetidsofnames)