# ITLegacyCallMediaControl2::CreateDetectToneObject

## Description

The
**CreateDetectToneObject** method creates a detect tone object to use with the
[DetectTonesByCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacycallmediacontrol2-detecttonesbycollection) method.

This method is intended for Visual Basic and scripting applications. C/C++ applications should use the
[DetectTones](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacycallmediacontrol2-detecttones) method instead.

## Parameters

### `ppDetectTone` [out]

Pointer to an
[ITDetectTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itdetecttone) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppDetectTone* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | There is not enough memory to allocate the object. |

## Remarks

TAPI calls the **AddRef** method on the
[ITDetectTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itdetecttone) interface returned by **ITLegacyCallMediaControl2::CreateDetectToneObject**. The application must call the **Release** method on the
**ITDetectTone** interface to free resources associated with it.

## See also

[DetectTonesByCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacycallmediacontrol2-detecttonesbycollection)

[ITDetectTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itdetecttone)

[ITLegacyCallMediaControl2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlegacycallmediacontrol2)