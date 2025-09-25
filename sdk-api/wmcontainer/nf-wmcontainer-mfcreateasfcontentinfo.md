# MFCreateASFContentInfo function

## Description

Creates the [ASF Header Object](https://learn.microsoft.com/windows/desktop/medfound/asf-file-structure) object.

## Parameters

### `ppIContentInfo`

Receives a pointer to the [IMFASFContentInfo](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfcontentinfo) interface. The caller must release the interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)