# MFCreateASFMediaSinkActivate function

## Description

Creates an activation object that can be used to create the ASF media sink.

## Parameters

### `pwszFileName`

Null-terminated wide-character string that contains the output file name.

### `pContentInfo`

A pointer to the [IMFASFContentInfo](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfcontentinfo) interface of an initialized [ASF Header Object](https://learn.microsoft.com/windows/desktop/medfound/asf-file-structure) object. Use this interface to configure the ASF media sink.

### `ppIActivate`

Receives a pointer to the [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) interface. The caller must release the interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## See also

[Activation Objects](https://learn.microsoft.com/windows/desktop/medfound/activation-objects)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)