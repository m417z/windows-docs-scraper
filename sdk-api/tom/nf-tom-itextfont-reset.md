# ITextFont::Reset

## Description

Resets the character formatting to the specified values.

## Parameters

### `Value` [in]

Type: **long**

The kind of reset. This parameter can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **tomDefault** | Set to the document default character format if this font object is attached to a range; otherwise, set the defaults to the basic TOM engine defaults. |
| **tomUndefined** | Sets all properties to undefined values. This value is valid only for a duplicate (clone) font object. |
| **tomApplyLater** | Allow property values to be set, but don’t apply them to the attached range yet. |
| **tomApplyNow** | Apply the current properties to attached range. |
| **tomCacheParms** | Do not update the current font with the attached range properties. |
| **tomTrackParms** | Update the current font with the attached range properties. |
| **tomApplyTmp** | Apply temporary formatting. |
| **tomDisableSmartFont** | Do not apply smart fonts. |
| **tomEnableSmartFont** | Do apply smart fonts. |
| **tomUsePoints** | Use points for floating-point measurements. |
| **tomUseTwips** | Use twips for floating-point measurements. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **S_FALSE** | Protected from change. |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The font object is attached to a range that has been deleted. |

## Remarks

Calling
**ITextFont::Reset** with **tomUndefined** sets all properties to undefined values. Thus, applying the font object to a range changes nothing. This applies to a font object that is obtained by the
[ITextFont::GetDuplicate](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-getduplicate) method.

## See also

**Conceptual**

[GetDuplicate](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextfont-getduplicate)

[ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)