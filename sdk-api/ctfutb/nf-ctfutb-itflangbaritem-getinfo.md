# ITfLangBarItem::GetInfo

## Description

Obtains information about the language bar item.

## Parameters

### `pInfo` [out]

Pointer to a [TF_LANGBARITEMINFO](https://learn.microsoft.com/windows/desktop/api/ctfutb/ns-ctfutb-tf_langbariteminfo) structure that receives the language bar item information.

Starting with Windows 8, the item will be ignored if the structure does not include GUID_LBI_INPUTMODE. For more information, see [Third-party input method editors](https://docs.microsoft.com/en-us/windows/win32/w8cookbook/third-party-input-method-editors#manifestation) in the Compatibility cookbook for Windows.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *pInfo* is invalid. |

## See also

[ITfLangBarItem](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritem)

[TF_LANGBARITEMINFO](https://learn.microsoft.com/windows/desktop/api/ctfutb/ns-ctfutb-tf_langbariteminfo)