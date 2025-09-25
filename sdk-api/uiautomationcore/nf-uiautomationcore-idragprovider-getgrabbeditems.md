# IDragProvider::GetGrabbedItems

## Description

Retrieves the collection of elements that are being dragged as part of a drag operation.

## Parameters

### `pRetVal` [out, retval, optional]

An array of VT_UNKNOWN pointers to the [IRawElementProviderSimple](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementprovidersimple) interfaces
of the elements that are being dragged. This parameter is **NULL** if only a single item is being dragged.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the user is dragging multiple items, the items are represented by a single master element with an associated set of grabbed elements. The master element raises the appropriate events, to avoid having a large set of duplicate events. The client can call **GetGrabbedItems** to retrieve the full list of grabbed items. The provider should allocate a [SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray) of appropriate length and add the Component Object Model (COM) pointers of the elements that are part of the drag operation.

## See also

[IDragProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-idragprovider)