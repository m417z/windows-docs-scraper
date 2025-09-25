# IAccessibleWindowlessSite::GetParentAccessible

## Description

Retrieves an [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) pointer for the parent of a windowless Microsoft ActiveX control in the accessibility tree.

## Parameters

### `ppParent` [out, optional]

Type: **[IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible)****

Receives the [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) pointer for the parent of the windowless ActiveX control.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To return its parent [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) object, an object that implements **IAccessible** must be able to implement the [get_accParent](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessible-get_accparent) method. Implementing **get_accParent** is difficult for a windowless ActiveX control because the control might be unable to determine its location in the accessible tree of the parent object. The **GetParentAccessible** method enables a windowless ActiveX control to query its site for the parent object, and then return the parent object to the client that called **get_accParent**.

## See also

[IAccessibleWindowlessSite](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessiblewindowlesssite)