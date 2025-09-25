# ITLegacyCallMediaControl2::CreateCustomToneObject

## Description

The
**CreateCustomToneObject** method creates a custom tone object to use with the
[GenerateCustomTonesByCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacycallmediacontrol2-generatecustomtonesbycollection) method.

This method is intended for Visual Basic and scripting applications. C/C++ applications should use the
[GenerateCustomTones](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacycallmediacontrol2-generatecustomtones) method instead.

## Parameters

### `ppCustomTone` [out]

Pointer to an
[ITCustomTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcustomtone) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppCustomTone* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | There is not enough memory to allocate the object. |

## Remarks

TAPI calls the **AddRef** method on the
[ITCustomTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcustomtone) interface returned by **ITLegacyCallMediaControl2::CreateCustomToneObject**. The application must call the **Release** method on the
**ITCustomTone** interface to free resources associated with it.

## See also

[GenerateCustomTonesByCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacycallmediacontrol2-generatecustomtonesbycollection)

[ITCustomTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcustomtone)

[ITLegacyCallMediaControl2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlegacycallmediacontrol2)