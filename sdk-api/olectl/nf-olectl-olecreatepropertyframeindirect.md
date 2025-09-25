# OleCreatePropertyFrameIndirect function

## Description

Creates a property frame, that is, a property sheet dialog box, based on a structure ([OCPFIPARAMS](https://learn.microsoft.com/windows/desktop/api/olectl/ns-olectl-ocpfiparams)) that contains the parameters, rather than specifying separate parameters as when calling [OleCreatePropertyFrame](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-olecreatepropertyframe).

## Parameters

### `lpParams` [in]

Pointer to the caller-allocated structure containing the creation parameters for the dialog box.

## Return value

This function supports the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_UNEXPECTED, as well as the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The dialog box was invoked and operated successfully. |
| **E_POINTER** | The address in *lpParams* is not valid. For example, it may be **NULL**. |

## Remarks

Besides **cbStructSize** (the size of the structure) and **dispIDInitialProperty**, all of the members of the [OCPFIPARAMS](https://learn.microsoft.com/windows/desktop/api/olectl/ns-olectl-ocpfiparams) structure have the same semantics as the parameters for [OleCreatePropertyFrame](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-olecreatepropertyframe). When *dispIDInitialProperty* is DISPID_UNKNOWN, the behavior of the two functions is identical.

Working in conjunction with [IPerPropertyBrowsing](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iperpropertybrowsing) and [IPropertyPage2](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipropertypage2), *dispIDInitialProperty* allows the caller to specify which single property should be highlighted when the dialog box is made visible. This feature is not available when using [OleCreatePropertyFrame](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-olecreatepropertyframe). To determine the page and property to show initially, the property frame will do the following:

1. Call **(*ppUnk)->QueryInterface(IID_IPerPropertyBrowsing, ...)** to get an interface pointer to the first object.
2. Call **IPerPropertyBrowsing::MapPropertyToPage(dispIDInitialProperty, ...)** to determine which page CLSID contains the property to be highlighted. All objects for which this frame is being invoked must support the set of properties displayed in the frame.
3. When the dialog box is created, the property page with the CLSID retrieved in Step 2 is activated with **IPropertyPage::Activate**.
4. The property frame queries the active page for [IPropertyPage2](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipropertypage2).
5. If successful, the frame calls **IPropertyPage2::EditProperty(dispIDInitialProperty)** to highlight the correct field in that dialog box.

## See also

[OCPFIPARAMS](https://learn.microsoft.com/windows/desktop/api/olectl/ns-olectl-ocpfiparams)

[OleCreatePropertyFrame](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-olecreatepropertyframe)