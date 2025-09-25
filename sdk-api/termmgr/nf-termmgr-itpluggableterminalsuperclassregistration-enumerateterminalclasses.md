# ITPluggableTerminalSuperclassRegistration::EnumerateTerminalClasses

## Description

The
**EnumerateTerminalClasses** method lists all terminal classes for the current terminal superclass.

## Parameters

### `ppTerminals` [out]

Pointer to the
[IEnumTerminalClass](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumterminalclass) interface that enumerates the terminal classes.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *ppTerminals* parameter is not a valid pointer. |

## Remarks

TAPI calls the **AddRef** method on the
[IEnumTerminalClass](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumterminalclass) interface returned by **ITPluggableTerminalSuperclassRegistration::EnumerateTerminalClasses**. The application must call **Release** on the
**IEnumTerminalClass** interface to free resources associated with it.

## See also

[IEnumTerminalClass](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumterminalclass)

[ITPluggableTerminalSuperclassRegistration](https://learn.microsoft.com/windows/desktop/api/termmgr/nn-termmgr-itpluggableterminalsuperclassregistration)