# IOleLink::GetUpdateOptions

## Description

Retrieves a value indicating how often the linked object updates its cached data.

## Parameters

### `pdwUpdateOpt` [out]

A pointer to a variable that receives the current value for the linked object's update option, indicating how often the linked object updates the cached data for the linked object. The possible values for *pdwUpdateOpt* are taken from the enumeration [OLEUPDATE](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-oleupdate).

## Return value

This method returns S_OK on success.

## See also

[IOleLink](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolelink)

[IOleLink::SetUpdateOptions](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-setupdateoptions)

[IOleUILinkContainer](https://learn.microsoft.com/windows/desktop/api/oledlg/nn-oledlg-ioleuilinkcontainera)

[OleUIEditLinks](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuieditlinksa)