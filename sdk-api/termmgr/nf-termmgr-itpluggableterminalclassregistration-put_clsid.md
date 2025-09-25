# ITPluggableTerminalClassRegistration::put_CLSID

## Description

The
**put_CLSID** method sets the CLSID used to **CoCreateInstance** the terminal.

## Parameters

### `bstrCLSID` [in]

The **BSTR** representation of the CLSID.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITPluggableTerminalClassRegistration](https://learn.microsoft.com/windows/desktop/api/termmgr/nn-termmgr-itpluggableterminalclassregistration)

[get_CLSID](https://learn.microsoft.com/windows/desktop/api/termmgr/nf-termmgr-itpluggableterminalclassregistration-get_clsid)