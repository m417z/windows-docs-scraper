# ITfSystemDeviceTypeLangBarItem::GetIconMode

## Description

Obtains the current icon display mode for a system language bar item.

## Parameters

### `pdwFlags` [out]

Pointer to a **DWORD** that receives the current icon display mode for a system language bar item. For more information about possible values, see the dwFlags parameter in [ITfSystemDeviceTypeLangBarItem::SetIconMode](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itfsystemdevicetypelangbaritem-seticonmode).

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOTIMPL** | The system language bar item does not support this method. |

## See also

[ITfSystemDeviceTypeLangBarItem](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itfsystemdevicetypelangbaritem)

[ITfSystemDeviceTypeLangBarItem::SetIconMode](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itfsystemdevicetypelangbaritem-seticonmode)