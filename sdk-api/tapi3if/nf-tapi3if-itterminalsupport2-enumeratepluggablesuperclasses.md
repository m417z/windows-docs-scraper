# ITTerminalSupport2::EnumeratePluggableSuperclasses

## Description

The
**EnumeratePluggableSuperclasses** method enumerates the pluggable terminal superclasses registered on the current system.

This method is intended for Visual Basic and scripting applications. C/C++ applications must use the
[get_PluggableSuperClasses](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itterminalsupport2-get_pluggablesuperclasses) method.

## Parameters

### `ppSuperclassEnumerator` [out]

Pointer to the
[IEnumPluggableSuperclassInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumpluggablesuperclassinfo) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_FAIL** | The method failed. |
| **E_POINTER** | The *ppSuperclassEnumerator* parameter is not a valid pointer. |

## Remarks

TAPI calls the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on the
[IEnumPluggableSuperclassInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumpluggablesuperclassinfo) interface returned by **ITTerminalSupport2::EnumeratePluggableSuperclasses**. The application must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the
**IEnumPluggableSuperclassInfo** interface to free resources associated with it.

## See also

[IEnumPluggableSuperclassInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumpluggablesuperclassinfo)

[ITTerminalSupport2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminalsupport2)