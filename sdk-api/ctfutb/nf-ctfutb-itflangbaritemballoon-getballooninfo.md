# ITfLangBarItemBalloon::GetBalloonInfo

## Description

Obtains information about the balloon.

## Parameters

### `pInfo` [out]

Pointer to a [TF_LBBALLOONINFO](https://learn.microsoft.com/windows/desktop/api/ctfutb/ns-ctfutb-tf_lbballooninfo) structure that receives the information about the balloon.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *pInfo* is invalid. |

## See also

[ITfLangBarItemBalloon](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritemballoon)

[TF_LBBALLOONINFO](https://learn.microsoft.com/windows/desktop/api/ctfutb/ns-ctfutb-tf_lbballooninfo)