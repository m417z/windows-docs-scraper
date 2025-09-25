# InitCommonControls function

## Description

Registers and initializes certain common control window classes. This function is obsolete. New applications should use the [InitCommonControlsEx](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-initcommoncontrolsex) function.

## Remarks

Under Comctl32.dll version 5.x, only Windows 95 classes (ICC_WIN95_CLASSES) can be registered through **InitCommonControls**. Programs which require additional common control classes must use the [InitCommonControlsEx](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-initcommoncontrolsex) function.

Under Comctl32.dll version 6.0 and later, **InitCommonControls** does nothing. Applications must explicitly register all common controls through [InitCommonControlsEx](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-initcommoncontrolsex).