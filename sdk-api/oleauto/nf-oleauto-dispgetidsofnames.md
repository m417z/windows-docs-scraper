# DispGetIDsOfNames function

## Description

Low-level helper for [Invoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke) that provides machine independence for customized **Invoke**.

## Parameters

### `ptinfo`

The type information for an interface. This type information is specific to one interface and language code, so it is not necessary to pass an interface identifier (IID) or LCID to this function.

### `rgszNames` [in]

An array of name strings that can be the same array passed to DispInvoke in the DISPPARAMS structure. If *cNames* is greater than 1, the first name is interpreted as a method name, and subsequent names are interpreted as parameters to that method.

### `cNames`

The number of elements in *rgszNames*.

### `rgdispid` [out]

An array of DISPIDs to be filled in by this function. The first ID corresponds to the method name. Subsequent IDs are interpreted as parameters to the method.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The interface is supported. |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **DISP_E_UNKNOWNNAME** | One or more of the specified names were not known. The returned array of DISPIDs contains DISPID_UNKNOWN for each entry that corresponds to an unknown name. |

Any of the **ITypeInfo::Invoke** errors can also be returned.