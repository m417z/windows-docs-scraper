# ITTerminalSupport::EnumerateDynamicTerminalClasses

## Description

The
**EnumerateDynamicTerminalClasses** method enumerates the currently available dynamic
[terminal classes](https://learn.microsoft.com/windows/desktop/Tapi/terminal-class) that are supported. This method is provided for C and C++ applications. Automation client applications, such as those written in Visual Basic, must use the
[get_DynamicTerminalClasses](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itterminalsupport-get_dynamicterminalclasses) method.

## Parameters

### `ppTerminalClassEnumerator` [out]

Pointer to an
[IEnumTerminalClass](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumterminalclass) enumerator. TAPI returns these classes as GUIDs.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppTerminalClassEnumerator* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

An application calls this method to find out which dynamic terminal classes are supported by this address in a call to
[ITTerminalSupport::CreateTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itterminalsupport-createterminal).

TAPI calls the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on the
[IEnumTerminalClass](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumterminalclass) interface returned by **ITTerminalSupport::EnumerateDynamicTerminalClasses**. The application must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the
**IEnumTerminalClass** interface to free resources associated with it.

## See also

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[ITTerminalSupport](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminalsupport)

**Terminal Classes**

[Terminal Object](https://learn.microsoft.com/windows/desktop/Tapi/terminal-object)

[Terminal Object Interfaces](https://learn.microsoft.com/windows/desktop/Tapi/terminal-object-interfaces)

[terminal classes](https://learn.microsoft.com/windows/desktop/Tapi/terminal-class)