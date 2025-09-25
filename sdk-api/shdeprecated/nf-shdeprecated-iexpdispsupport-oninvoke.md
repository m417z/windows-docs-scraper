# IExpDispSupport::OnInvoke

## Description

Deprecated. Gets ambient properties.

## Parameters

### `dispidMember` [in]

Type: **DISPID**

A dispatch ID that identifies the member being invoked.

### `iid` [in]

Type: **REFIID**

Reserved. Must be IID_NULL.

### `lcid` [in]

Type: **LCID**

A locale ID providing a locale context in which to interpret arguments. Applications that do not support multiple languages can ignore this parameter.

### `wFlags` [in]

Type: **WORD**

Flags describing the context of the call, including the following.

#### DISPATCH_METHOD

The member is invoked as a method. If a property has the same name, both this and the DISPATCH_PROPERTYGET flag may be set. The member is invoked as a method. If a property has the same name, both this and the DISPATCH_PROPERTYGET flag may be set.

#### DISPATCH_PROPERTYGET

The member is retrieved as a property or data member.

#### DISPATCH_PROPERTYPUT

The member is changed as a property or data member.

#### DISPATCH_PROPERTYPUTREF

The member is changed by a reference assignment, rather than a value assignment. This flag is valid only when the property accepts a reference to an object.

### `pdispparams`

Type: **[DISPPARAMS](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-dispparams)***

A pointer to a [DISPPARAMS](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-dispparams) structure containing an array of arguments, an array of argument DISPIDs for named arguments, and counts for the number of elements in the arrays.

### `pVarResult`

Type: **VARIANT***

A pointer to the location where the result is to be stored, or **NULL** if the caller expects no result. This argument is ignored if DISPATCH_PROPERTYPUT or DISPATCH_PROPERTYPUTREF is specified.

### `pexcepinfo`

Type: **EXCEPINFO***

A pointer to a structure that contains exception information. This structure should be filled in if DISP_E_EXCEPTION is returned. Can be **NULL**.

### `puArgErr`

Type: **UINT***

The index within the **rgvarg** member of the [DISPPARAMS](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-dispparams) structure of the first argument that has an error. Arguments are stored in **rgvarg** in reverse order, so the first argument is the one with the highest index in the array. This parameter is returned only when the resulting return value is DISP_E_TYPEMISMATCH or DISP_E_PARAMNOTFOUND. This argument can be set to **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For more information, see [IDispatch::Invoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke).