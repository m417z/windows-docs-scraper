# IOleLink::SetUpdateOptions

## Description

Specifies how often a linked object should update its cached data.

## Parameters

### `dwUpdateOpt` [in]

Specifies how often a linked object should update its cached data. The possible values for *dwUpdateOpt* are taken from the enumeration [OLEUPDATE](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-oleupdate).

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The supplied value is invalid. |

## Remarks

### Notes to Callers

Your container application should call **IOleLink::SetUpdateOptions** when the end user changes the update option for a linked object.

The end user selects the update option for a linked object using the **Links** dialog box. If you use the [OleUIEditLinks](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuieditlinksa) function to display this dialog box, you must implement the [IOleUILinkContainer](https://learn.microsoft.com/windows/desktop/api/oledlg/nn-oledlg-ioleuilinkcontainera) interface. The dialog box calls your [IOleUILinkContainer::SetLinkUpdateOptions](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-ioleuilinkcontainera-setlinkupdateoptions) method to specify the update option chosen by the end user. Your implementation of this method should call the **IOleLink::SetUpdateOptions** method to pass the selected option to the linked object.

### Notes to Implementers

The default update option is OLEUDPATE_ALWAYS. The linked object's implementation of [IPersistStorage::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-save) saves the current update option.

If OLEUDPATE_ALWAYS is specified as the update option, the linked object updates the link's caches in the following situations:

* When the update option is changed from manual to automatic, if the link source is running.
* Whenever the linked object binds to the link source.
* Whenever the link source is running and the linked object's [IOleObject::Close](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-close), [IPersistStorage::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-save), or [IAdviseSink::OnSave](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-onsave) implementations are called.

For both manual and automatic links, the linked object updates the cache whenever the container application calls [IOleObject::Update](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-update) or [IOleLink::Update](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-update).

## See also

[IOleLink](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolelink)

[IOleLink::GetUpdateOptions](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-getupdateoptions)

[IOleLink::Update](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-update)

[IOleObject::Update](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-update)

[IOleUILinkContainer](https://learn.microsoft.com/windows/desktop/api/oledlg/nn-oledlg-ioleuilinkcontainera)

[OleUIEditLinks](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuieditlinksa)