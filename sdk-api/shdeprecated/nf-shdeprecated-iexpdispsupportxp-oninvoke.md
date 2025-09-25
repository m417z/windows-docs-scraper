# IExpDispSupportXP::OnInvoke

## Description

Not implemented.

## Parameters

### `dispidMember`

Type: **DISPID**

Specifies a dispatch ID that identifies the member being invoked.

### `iid`

Type: **REFIID**

Reserved. Must be IID_NULL.

### `lcid`

Type: **LCID**

Specifies a locale ID providing a locale context in which to interpret arguments. Applications that do not support multiple national languages can ignore this parameter.

### `wFlags`

Type: **WORD**

Specifies flags describing the context of the call.

### `pdispparams` [in]

Type: **[DISPPARAMS](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-dispparams)***

Specifies a pointer to a [DISPPARAMS](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-dispparams) structure containing an array of arguments, an array of argument DISPIDs for named arguments, and counts for the number of elements in the arrays.

### `pVarResult` [out]

Type: **VARIANT***

Receives a pointer to the location where the result is to be stored, or **NULL** if the calling application expects no result. This argument is ignored if DISPATCH_PROPERTYPUT or DISPATCH_PROPERTYPUTREF is specified.

### `pexcepinfo` [out]

Type: **EXCEPINFO***

Receives a pointer to a structure that contains exception information. This structure should be filled in if DISP_E_EXCEPTION is returned. Can be **NULL**.

### `puArgErr` [out]

Type: **UINT***

Receives the index within the **rgvarg** member of the [DISPPARAMS](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-dispparams) structure of the first argument that has an error.

## Return value

Type: **HRESULT**

Returns E_NOTIMPL.