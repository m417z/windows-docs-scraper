# ITPluggableTerminalClassRegistration::Add

## Description

The
**Add** method adds terminal information to the registry. If an entry for the terminal already exists, the method edits the entry.

## Parameters

### `bstrSuperclass` [in]

The **BSTR** representation of the CLSID for the terminal superclass.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Delete](https://learn.microsoft.com/windows/desktop/api/termmgr/nf-termmgr-itpluggableterminalclassregistration-delete)

[ITPluggableTerminalClassRegistration](https://learn.microsoft.com/windows/desktop/api/termmgr/nn-termmgr-itpluggableterminalclassregistration)