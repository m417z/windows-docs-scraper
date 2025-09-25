# ITPluggableTerminalSuperclassRegistration::put_Name

## Description

The
**put_Name** method sets the friendly name for the terminal superclass.

## Parameters

### `bstrName` [in]

The **BSTR** representation of the friendly name.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *bstrName* parameter is not a valid pointer. |

## See also

[ITPluggableTerminalSuperclassRegistration](https://learn.microsoft.com/windows/desktop/api/termmgr/nn-termmgr-itpluggableterminalsuperclassregistration)

[get_Name](https://learn.microsoft.com/windows/desktop/api/termmgr/nf-termmgr-itpluggableterminalsuperclassregistration-get_name)