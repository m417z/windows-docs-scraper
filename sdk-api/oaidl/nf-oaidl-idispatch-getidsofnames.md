# IDispatch::GetIDsOfNames

## Description

Maps a single member and an optional set of argument names to a corresponding set of integer DISPIDs, which can be used on subsequent calls to [Invoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke). The dispatch function [DispGetIDsOfNames](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-dispgetidsofnames) provides a standard implementation of **GetIDsOfNames**.

## Parameters

### `riid` [in]

Reserved for future use. Must be IID_NULL.

### `rgszNames` [in]

The array of names to be mapped.

### `cNames` [in]

The count of the names to be mapped.

### `lcid` [in]

The locale context in which to interpret the names.

### `rgDispId` [out]

Caller-allocated array, each element of which contains an identifier (ID) corresponding to one of the names passed in the rgszNames array. The first element represents the member name. The subsequent elements represent each of the member's parameters.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Out of memory. |
| **DISP_E_UNKNOWNNAME** | One or more of the specified names were not known. The returned array of DISPIDs contains DISPID_UNKNOWN for each entry that corresponds to an unknown name. |
| **DISP_E_UNKNOWNLCID** | The locale identifier (LCID) was not recognized. |

## Remarks

An [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) implementation can associate any positive integer ID value with a given name. Zero is reserved for the default, or **Value** property; –1 is reserved to indicate an unknown name; and other negative values are defined for other purposes. For example, if **GetIDsOfNames** is called, and the implementation does not recognize one or more of the names, it returns DISP_E_UNKNOWNNAME, and the *rgDispId* array contains DISPID_UNKNOWN for the entries that correspond to the unknown names.

The member and parameter DISPIDs must remain constant for the lifetime of the object. This allows a client to obtain the DISPIDs once, and cache them for later use.

When **GetIDsOfNames** is called with more than one name, the first name (*rgszNames*[0]) corresponds to the member name, and subsequent names correspond to the names of the member's parameters.

The same name may map to different DISPIDs, depending on context. For example, a name may have a DISPID when it is used as a member name with a particular interface, a different ID as a member of a different interface, and different mapping for each time it appears as a parameter.

**GetIDsOfNames** is used when an [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) client binds to names at run time. To bind at compile time instead, an **IDispatch** client can map names to DISPIDs by using the type information interfaces described in [Type Description Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/automat/type-description-interfaces). This allows a client to bind to members at compile time and avoid calling **GetIDsOfNames** at run time. For a description of binding at compile time, see Type Description Interfaces.

The implementation of **GetIDsOfNames** is case insensitive. Users that need case-sensitive name mapping should use type information interfaces to map names to DISPIDs, rather than call **GetIDsOfNames**.

**Caution** You cannot use this method to access values that have been added dynamically, such as values added through JavaScript. Instead, use the GetDispID of the IDispatchEx interface. For more information, see the [IDispatchEx interface](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/windows-scripting/reference/idispatchex-interface).

#### Examples

The following code from the Lines sample file Lines.cpp implements the **GetIDsOfNames** member function for the CLine class. The ActiveX or OLE object uses the standard implementation, [DispGetIDsOfNames](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-dispgetidsofnames). This implementation relies on **DispGetIdsOfNames** to validate input arguments. To help minimize security risks, include code that performs more robust validation of the input arguments.

```cpp
STDMETHODIMP
CLine::GetIDsOfNames(
      REFIID riid,
      OLECHAR ** rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID * rgDispId)
{
      return DispGetIDsOfNames(m_ptinfo, rgszNames, cNames, rgDispId);
}
```

The following code might appear in an ActiveX client that calls **GetIDsOfNames** to get the DISPID of the **CLine****Color** property.

```cpp
HRESULT hresult;
IDispatch * pdisp = (IDispatch *)NULL;
DISPID dispid;
OLECHAR * szMember = "color";

// Code that sets a pointer to the dispatch (pdisp) is omitted.

hresult = pdisp->GetIDsOfNames(
   IID_NULL,
   &szMember,
   1, LOCALE_SYSTEM_DEFAULT,
   &dispid);
```

## See also

[CreateStdDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-createstddispatch)

[DispGetIDsOfNames](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-dispgetidsofnames)

[IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch)