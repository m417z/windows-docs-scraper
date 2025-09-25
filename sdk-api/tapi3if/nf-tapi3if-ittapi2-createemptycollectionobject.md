# ITTAPI2::CreateEmptyCollectionObject

## Description

The
**CreateEmptyCollectionObject** method creates an empty collection object. The collection can be filled with
[ITDetectTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itdetecttone) or
[ITCustomTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcustomtone) objects for use with the
[DetectTonesByCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacycallmediacontrol2-detecttonesbycollection) method or the
[GenerateCustomTonesByCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacycallmediacontrol2-generatecustomtonesbycollection) method, respectively.

This method is intended for Visual Basic and scripting applications.

## Parameters

### `ppCollection` [out]

Pointer to an
[ITCollection2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection2) interface on the new collection object.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppCollection* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | There is not enough memory to allocate the object. |

## See also

[ITCollection2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection2)

[ITCustomTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcustomtone)

[ITDetectTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itdetecttone)

[ITTAPI2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittapi2)