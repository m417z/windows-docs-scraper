# ITfSystemDeviceTypeLangBarItem::SetIconMode

## Description

Modifies the type of icon displayed for a system language bar item.

## Parameters

### `dwFlags` [in]

Specifies how the system language bar item should display the icon. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | The system language bar item should display a default icon for the item. |
| **TF_DTLBI_USEPROFILEICON** | The system language bar item should display the icon specified for the language profile. |

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOTIMPL** | The system language bar item does not support this method. |

## See also

[ITfSystemDeviceTypeLangBarItem](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itfsystemdevicetypelangbaritem)

[Miscellaneous Language Bar Constants](https://learn.microsoft.com/windows/desktop/TSF/miscellaneous-language-bar-constants)