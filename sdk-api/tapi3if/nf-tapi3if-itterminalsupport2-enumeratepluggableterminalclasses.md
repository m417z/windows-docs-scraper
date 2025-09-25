# ITTerminalSupport2::EnumeratePluggableTerminalClasses

## Description

The
**EnumeratePluggableTerminalClasses** method enumerates the pluggable terminal classes registered under a given superclass.

This method is intended for C/C++ applications. Visual Basic and scripting applications must use the
[get_PluggableTerminalClasses](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itterminalsupport2-get_pluggableterminalclasses) method.

## Parameters

### `iidTerminalSuperclass` [in]

CLSID for the terminal superclass.

### `lMediaType` [in]

Bitwise ORed list of
[media types](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants) supported by the terminal classes.

### `ppClassEnumerator` [out]

Pointer to the
[IEnumPluggableTerminalClassInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumpluggableterminalclassinfo) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *lMediaType* parameter is not valid. |
| **E_FAIL** | The method failed. |
| **E_POINTER** | The *ppClassEnumerator* parameter is not a valid pointer. |

## Remarks

TAPI calls the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on the
[IEnumPluggableTerminalClassInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumpluggableterminalclassinfo) interface returned by **ITTerminalSupport2::EnumeratePluggableTerminalClasses**. The application must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the
**IEnumPluggableTerminalClassInfo** interface to free resources associated with it.

## See also

[IEnumPluggableTerminalClassInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumpluggableterminalclassinfo)

[ITTerminalSupport2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminalsupport2)