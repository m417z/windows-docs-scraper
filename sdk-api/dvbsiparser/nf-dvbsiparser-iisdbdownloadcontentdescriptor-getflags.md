# IIsdbDownloadContentDescriptor::GetFlags

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets flag values from an Integrated Services Digital Broadcasting (ISDB) download content descriptor.

## Parameters

### `pfReboot` [out]

Receives the value of the reboot flag. This flag is 1 if a reboot is required after the download, or 0 if it is not.

### `pfAddOn` [out]

Receives the value of the add_on flag. This flag is 1 if the download is added to an existing file, or 0 if the download overwrites the existing file.

### `pfCompatibility` [out]

Receives the value of the compatibility_flag field. This flag is 1 if the descriptor has a compatibility descriptor, or 0 if it does not.

### `pfModuleInfo` [out]

Receives the value of the module_info flag. This flag is 1 if the descriptor information for each module, or 0 if it does not.

### `pfTextInfo` [out]

Receives the value of the text_info_flag field. This flag is 1 if the descriptor includes a text description in its last field, or 0 if it does not.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbDownloadContentDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbdownloadcontentdescriptor)