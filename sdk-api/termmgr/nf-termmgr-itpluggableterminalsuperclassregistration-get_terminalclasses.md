# ITPluggableTerminalSuperclassRegistration::get_TerminalClasses

## Description

The
**get_TerminalClasses** method gets the terminal classes for this pluggable terminal superclass.

## Parameters

### `pTerminals` [out]

 Pointer to a **VARIANT** containing a **SAFEARRAY** of **BSTR** strings. Each string represents a terminal class.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *pTerminals* parameter is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[ITPluggableTerminalSuperclassRegistration](https://learn.microsoft.com/windows/desktop/api/termmgr/nn-termmgr-itpluggableterminalsuperclassregistration)