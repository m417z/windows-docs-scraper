# ITTerminalSupport2::get_PluggableSuperclasses

## Description

The
**get_PluggableSuperclasses** method returns a collection of
[ITPluggableTerminalSuperclassInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itpluggableterminalsuperclassinfo) superclass information interface pointers.

This method is intended for Visual Basic and scripting applications. C/C++ applications can use the
[EnumeratePluggableSuperclasses](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itterminalsupport2-enumeratepluggablesuperclasses) method.

## Parameters

### `pVariant` [out]

Pointer to a **VARIANT** containing an
[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection) of
[ITPluggableTerminalSuperclassInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itpluggableterminalsuperclassinfo) interface pointers.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_FAIL** | The method failed. |
| **E_POINTER** | The *pVariant* parameter is not a valid pointer. |

## Remarks

TAPI calls the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on the
[ITPluggableTerminalSuperclassInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itpluggableterminalsuperclassinfo) interface returned by **ITTerminalSupport2::get_PluggableSuperclasses**. The application must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the
[ITPluggableTerminalSuperclassInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itpluggableterminalsuperclassinfo) interface to free resources associated with it.

## See also

[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection)

[ITPluggableTerminalSuperclassInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itpluggableterminalsuperclassinfo)

[ITTerminalSupport2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminalsupport2)