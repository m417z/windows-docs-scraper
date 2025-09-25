# IOleLink::Update

## Description

Updates the compound document's cached data for a linked object. This involves binding to the link source, if it is not already bound.

## Parameters

### `pbc` [in]

A pointer to the [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx) interface on the bind context to be used in binding the link source. This parameter can be **NULL**. The bind context caches objects bound during the binding process, contains parameters that apply to all operations using the bind context, and provides the means by which the binding implementation should retrieve information about its environment. For more information, see **IBindCtx**.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **CACHE_E_NOCACHE_UPDATE** | The bind operation worked but no caches were updated. |
| **CACHE_S_SOMECACHES_NOTUPDATED** | The bind operation worked but not all caches were updated. |
| **OLE_E_CANT_BINDTOSOURCE** | Unable to bind to the link source. |

## Remarks

### Notes to Callers

Your container application should call **Update** if the end user updates the cached data for a linked object.

The end user can update the cached data for a linked object by choosing the **Update Now** button in the **Links** dialog box. If you use the [OleUIEditLinks](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuieditlinksa) function to display the **Links** dialog box, you must implement the [IOleUILinkContainer](https://learn.microsoft.com/windows/desktop/api/oledlg/nn-oledlg-ioleuilinkcontainera) interface. The dialog box calls your implementations of [IOleUILinkContainer::UpdateLink](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-ioleuilinkcontainera-updatelink) when the end user chooses the **Update Now** button. Your implementation of that method can call **Update**.

Your container application can also call **Update** to update a linked object, because that method calls **Update** when it is called on a linked object.

This method updates both automatic links and manual links. For manual links, calling **Update** or **Update** is the only way to update the caches. For more information on automatic and manual links, see [IOleLink::SetUpdateOptions](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-setupdateoptions).

### Notes on Implementation

If *pbc* is non-**NULL**, the linked object's implementation of **Update** calls [IBindCtx::RegisterObjectBound](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-registerobjectbound) to register the bound link source. This ensures that the link source remains running until the bind context is released.

The current caches are left intact if the link source cannot be bound.

## See also

[IBindCtx::RegisterObjectBound](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-registerobjectbound)

[IOleLink](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolelink)

[IOleLink::SetUpdateOptions](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-setupdateoptions)

[IOleLink::Update](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-update)

[IOleUILinkContainer](https://learn.microsoft.com/windows/desktop/api/oledlg/nn-oledlg-ioleuilinkcontainera)

[OleUIEditLinks](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuieditlinksa)