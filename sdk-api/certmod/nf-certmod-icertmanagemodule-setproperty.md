# ICertManageModule::SetProperty

## Description

The **SetProperty** method allows a module to set a property value.

## Parameters

### `strConfig` [in]

Represents the configuration string for the Certificate Services server in the form COMPUTERNAME\CANAME, where COMPUTERNAME is the Certificate Services server's network name, and CANAME is the common name of the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) as entered for the CA during Certificate Services setup. For information about the configuration string name, see
[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig).

### `strStorageLocation` [in]

The location that provides storage for the property values, as described in the definition of *strStorageLocation* in
[ICertManageModule::GetProperty](https://learn.microsoft.com/windows/desktop/api/certmod/nf-certmod-icertmanagemodule-getproperty).

### `strPropertyName` [in]

The name of the property whose value is being assigned. Policy and exit modules should support the following properties, which are used by Certificate Services Manager.

| Value | Meaning |
| --- | --- |
| **Name** | Name of the module. |
| **Description** | Description of the module. |
| **Copyright** | Copyright pertaining to the module. |
| **File Version** | Version of the module file. |
| **Product Version** | Version of the module. |

### `Flags` [in]

This parameter is reserved and must be set to zero.

### `pvarProperty` [in]

A value that is being assigned to the property specified by *strPropertyName*.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

This method is intended for future functionality. A minimal implementation is required, however, to meet the requirements of the [ICertManageModule](https://learn.microsoft.com/windows/desktop/api/certmod/nn-certmod-icertmanagemodule) interface.

#### Examples

```cpp
#include <windows.h>
#include <Certmod.h>

HRESULT CCertManagePolicyModule::SetProperty(
            /* [in] */ const BSTR strConfig,
            /* [in] */ BSTR strStorageLocation,
            /* [in] */ BSTR strPropertyName,
            /* [in] */ LONG Flags,
            /* [in] */ const VARIANT *pvarProperty)
{
    // This implementation fulfills the minimal requirement
    // needed for ICertManageModule::SetProperty.
    return S_OK;
}
```

## See also

**CCertManageModule**

[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig)

[ICertManageModule](https://learn.microsoft.com/windows/desktop/api/certmod/nn-certmod-icertmanagemodule)

[ICertManageModule::GetProperty](https://learn.microsoft.com/windows/desktop/api/certmod/nf-certmod-icertmanagemodule-getproperty)