# IOleInPlaceActiveObject::TranslateAccelerator

## Description

Processes menu accelerator-key messages from the container's message queue. This method should only be used for objects created by a DLL object application.

## Parameters

### `lpmsg` [in]

A pointer to an [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) structure for the message that might need to be translated.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | The message was not translated. |
| **E_INVALIDARG** | The specified parameter values are not valid. |
| **E_OUTOFMEMORY** | IThere is insufficient memory available for the operation. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## Remarks

### Notes to Callers

Active in-place objects must always be given the first chance at translating accelerator keystrokes. You can provide this opportunity by calling **IOleInPlaceActiveObject::TranslateAccelerator** from your container's message loop before doing any other translation. You should apply your own translation only when this method returns S_FALSE.

If you call **IOleInPlaceActiveObject::TranslateAccelerator** for an object that is not created by a DLL object application, the default object handler returns S_FALSE.

### Notes to Implementers

An object created by an EXE object application gets keystrokes from its own message pump, so the container does not get those messages.

If you need to implement this method, you can do so by simply wrapping the call to the [TranslateAccelerator](https://learn.microsoft.com/windows/desktop/DirectShow/cbasepropertypage-translateaccelerator) function.

## See also

[IOleInPlaceActiveObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceactiveobject)

[OleTranslateAccelerator](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oletranslateaccelerator)

[TranslateAccelerator](https://learn.microsoft.com/windows/desktop/DirectShow/cbasepropertypage-translateaccelerator)