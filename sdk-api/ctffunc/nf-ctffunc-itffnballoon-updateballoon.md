# ITfFnBalloon::UpdateBalloon

## Description

Changes the style and text of a language bar balloon item.

## Parameters

### `style` [in]

Contains one of the [TfLBBalloonStyle](https://learn.microsoft.com/windows/win32/api/ctfutb/ne-ctfutb-tflbballoonstyle) values that specifies the new balloon style.

### `pch` [in]

Pointer to a **WCHAR** buffer that contains the new text for the balloon.

### `cch` [in]

Contains the number of characters of the new text in *pch*.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | One or more parameters are invalid. |

## Remarks

The language bar balloon implementation should update its style and text by modifying the values returned from [ITfLangBarItemBalloon::GetBalloonInfo](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritem-getstatus) and then call [ITfLangBarItemSink::OnUpdate](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritemsink-onupdate) with TF_LBI_BALLOON to cause the language bar to obtain the updated information.

## See also

[ITfFnBalloon](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itffnballoon)

[ITfLangBarItemBalloon::GetBalloonInfo](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritem-getstatus)

[ITfLangBarItemSink::OnUpdate](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritemsink-onupdate)

[TfLBBalloonStyle](https://learn.microsoft.com/windows/win32/api/ctfutb/ne-ctfutb-tflbballoonstyle)