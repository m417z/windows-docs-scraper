# IDiscMaster::SetActiveDiscMasterFormat

## Description

Sets the currently active disc recorder format. The active format specifies both the structure of the staged image file content (audio/data) and the COM interface that must be used to manipulate that staged image.

## Parameters

### `riid` [in]

IID of the currently active format.

### `ppUnk` [out]

Pointer to the COM interface for the new disc format.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## Remarks

A successful call to this method clears the contents of the currently staged image. In addition, it may change the list of supported disc recorders. This is because not all recorders support all formats. Changes to the recorder list are announced with
[IDiscMasterProgressEvents::NotifyPnPActivity](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscmasterprogressevents-notifypnpactivity). If the currently selected recorder is not a member of the new set of supported devices, then there will no longer be an active recorder (similar to the state after the first call to
[Open](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscmaster-open)). In this case, the application must select a new active recorder before initiating a burn.

**MSDiscMasterObj** supports only the following IIDs: IID_IRedbookDiscMaster ([IRedbookDiscMaster](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-iredbookdiscmaster)) and IID_IJolietDiscMaster ([IJolietDiscMaster](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-ijolietdiscmaster)). If there is no format set, the default is Joliet format. It is the responsibility of every application to select a format master through the use of
[EnumDiscMasterFormats](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscmaster-enumdiscmasterformats) and this method.

**Note** A call to this method may change the list of available recorders. See the Remarks section of
[EnumDiscRecorders](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscmaster-enumdiscrecorders) for more information.

## See also

[IDiscMaster](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscmaster)