# ITTerminalSupport2::get_PluggableTerminalClasses

## Description

The
**get_PluggableTerminalClasses** method returns a collection of
[ITPluggableTerminalClassInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itpluggableterminalclassinfo) terminal class information interface pointers.

This method is intended for Visual Basic and scripting applications. C/C++ applications can use the
[EnumeratePluggableTerminalClasses](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itterminalsupport2-enumeratepluggableterminalclasses) method.

## Parameters

### `bstrTerminalSuperclass` [in]

The **BSTR** representation of the CLSID for the terminal superclass.

### `lMediaType` [in]

Bitwise ORed list of
[media types](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants) supported by the terminal classes.

### `pVariant` [out]

Pointer to a **VARIANT** containing an
[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection) of
[ITPluggableTerminalClassInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itpluggableterminalclassinfo) interface pointers.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *lMediaType* parameter is not valid. |
| **E_FAIL** | The method failed. |
| **E_POINTER** | The *bstrTerminalSuperclass* or *pVariant* parameter is not a valid pointer. |

## Remarks

TAPI calls the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on the
[ITPluggableTerminalClassInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itpluggableterminalclassinfo) interface returned by **ITTerminalSupport2::get_PluggableTerminalClasses**. The application must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the
**ITPluggableTerminalClassInfo** interface to free resources associated with it.

## See also

[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection)

[ITPluggableTerminalClassInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itpluggableterminalclassinfo)

[ITTerminalSupport2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminalsupport2)