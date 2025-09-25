# TF_LBBALLOONINFO structure

## Description

The **TF_LBBALLOONINFO** structure contains information about a language bar balloon item.

## Members

### `style`

Contains one of the [TfLBBalloonStyle](https://learn.microsoft.com/windows/win32/api/ctfutb/ne-ctfutb-tflbballoonstyle) values that specify the type of balloon to display.

### `bstrText`

Contains a **BSTR** that contains the string for the balloon. This string must be allocated using the [SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) function. The caller free this buffer when it is no longer required by calling [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring).

## See also

[ITfLangBarItemBalloon::GetBalloonInfo](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritemballoon-getballooninfo)

[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring)

[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring)

[TfLBBalloonStyle](https://learn.microsoft.com/windows/win32/api/ctfutb/ne-ctfutb-tflbballoonstyle)