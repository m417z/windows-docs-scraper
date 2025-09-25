# IsAccelerator function

## Description

Determines whether the specified keystroke maps to an accelerator in the specified accelerator table.

## Parameters

### `hAccel` [in]

A handle to the accelerator table.

### `cAccelEntries` [in]

The number of entries in the accelerator table.

### `lpMsg` [in]

A pointer to the keystroke message to be translated.

### `lpwCmd` [out]

A pointer to a variable to receive the corresponding command identifier if there is an accelerator for the keystroke. This parameter may be **NULL**.

## Return value

If the message is for the object application, the return value is **TRUE**. If the message is not for the object and should be forwarded to the container, the return value is **FALSE**.

## Remarks

While an object is active in-place, the object always has first chance to translate the keystrokes into accelerators. If the keystroke corresponds to one of its accelerators, the object must not call the [OleTranslateAccelerator](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oletranslateaccelerator) function - even if its call to the [TranslateAccelerator](https://learn.microsoft.com/windows/desktop/DirectShow/cbasepropertypage-translateaccelerator) function fails. Failure to process keystrokes in this manner can lead to inconsistent behavior.

If the keystroke is not one of the object's accelerators, then the object must call [OleTranslateAccelerator](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oletranslateaccelerator) to let the container try its accelerator translation.

The object's server can call **IsAccelerator** to determine if the accelerator message belongs to it. Some servers do accelerator translation on their own and do not call [TranslateAccelerator](https://learn.microsoft.com/windows/desktop/DirectShow/cbasepropertypage-translateaccelerator). Those applications will not call **IsAccelerator**, because they already have the information.

## See also

[OleTranslateAccelerator](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oletranslateaccelerator)

[TranslateAccelerator](https://learn.microsoft.com/windows/desktop/DirectShow/cbasepropertypage-translateaccelerator)