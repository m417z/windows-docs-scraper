# IPicture::get_CurDC

## Description

Retrieves the handle of the current device context. This property is valid only for bitmap pictures.

## Parameters

### `phDC` [out]

A pointer a variable that receives the device context.

## Return value

This method supports the standard return value E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The attribute bits were returned successfully. |
| **E_POINTER** | The value of *phDC* is not valid. For example, it may be **NULL**. |

## Remarks

The CurDC property and the [IPicture::SelectPicture](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipicture-selectpicture) method exist to circumvent restrictions in Windows; specifically, that an object can only be selected into exactly one device context at a time. In some cases, a picture object may be permanently selected into a particular device context (for example, a control may use a certain picture for a background). To use this picture property elsewhere, it must be temporarily deselected from its old device context, selected into the new device context for the operation, then reselected back into the old device context. The **IPicture::get_CurDC** method returns the device context handle into which the picture is currently selected. The **IPicture::SelectPicture** method selects the picture into a new device context, returning the old device context and the picture's GDI handle. The caller should select the picture back into the old device context when the caller is done with it, as is normal for Windows code.

### Notes to Callers

The caller always owns any device contexts passed between it and the picture object. Because the picture object maintains a copy of the HDC, the caller should use a memory device context (created with the [CreateCompatibleDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createcompatibledc) function) and not a screen device context (from [GetDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdc), [CreateDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdca), or [BeginPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-beginpaint)), because the screen device contexts are a limited system resource.

## See also

[IPicture](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipicture)

[IPicture::SelectPicture](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipicture-selectpicture)