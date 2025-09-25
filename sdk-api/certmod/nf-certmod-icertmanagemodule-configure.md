# ICertManageModule::Configure

## Description

The **Configure** method displays the module user interface.

## Parameters

### `strConfig` [in]

Represents the configuration string for the Certificate Services server in the form COMPUTERNAME\CANAME, where COMPUTERNAME is the Certificate Services server's network name, and CANAME is the common name of the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) as entered for the CA during Certificate Services setup. For information about the configuration string name, see
[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig).

### `strStorageLocation` [in]

A location that provides storage for the property values, as described in the definition of *strStorageLocation* in
[ICertManageModule::GetProperty](https://learn.microsoft.com/windows/desktop/api/certmod/nf-certmod-icertmanagemodule-getproperty).

### `Flags` [in]

A value used to determine whether the configuration interface is to be presented to the user. If this value is zero, the user will be presented with an interface for configuring the module. If this value is CMM_REFRESHONLY, Certificate Services will not display the user interface, but the latest changes to the configuration of the module will be in effect when future certificate requests are processed (this allows changes to be incorporated without requiring a response to a user interface).

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The **Configure** method displays the module user interface (if one exists), which allows the user to view and change the module's configurable items. A module that implements
[ICertManageModule](https://learn.microsoft.com/windows/desktop/api/certmod/nn-certmod-icertmanagemodule) can have its **Configure** method called when the Certificate Services Manager Policy or Exit Module property page is active and the user chooses the **Configure** button. The Certificate Services Manager will pass the location referenced by *strStorageLocation* to this module, and the implementation of this method can then use this location as needed. Note that it is possible that a module may not have configurable items (hence, a user interface would not be necessary), but it would still be necessary to implement this method. The example below does not allow a user to make a configuration change, but it does implement this method.

#### Examples

```cpp
#include <windows.h>
#include <Certmod.h>

HRESULT CCertManagePolicyModule::Configure(
            /* [in] */ const BSTR strConfig,
            /* [in] */ BSTR strStorageLocation,
            /* [in] */ LONG Flags)
{
    if ( CMM_REFRESHONLY != Flags )
        MessageBox(NULL,
                   L"This module has no configurable items",
                   L"MyModule",
                   (MB_OK|MB_ICONINFORMATION));

    return S_OK;
}
```

## See also

[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig)

[ICertManageModule](https://learn.microsoft.com/windows/desktop/api/certmod/nn-certmod-icertmanagemodule)