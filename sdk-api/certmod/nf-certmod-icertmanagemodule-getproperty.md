# ICertManageModule::GetProperty

## Description

The **GetProperty** method retrieves a module's property value.

## Parameters

### `strConfig` [in]

Represents the configuration string for the Certificate Services server in the form COMPUTERNAME\CANAME, where COMPUTERNAME is the Certificate Services server's network name, and CANAME is the common name of the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) as entered for the CA during Certificate Services setup. For information about the configuration string name, see
[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig).

### `strStorageLocation` [in]

A registry key that denotes the storage location in the **HKEY_LOCAL_MACHINE** hive for the property values. This value is in the following form:

```
SYSTEM
   CurrentControlSet
      Services
         CertSvc
            Configuration
               CAName
                  PolicyOrExitModules
                     MyModule.PolicyOrExit
```

The *CAName* is the name of the certification authority's configuration string, *PolicyOrExitModules* will be either "Policy" or "Exit" (depending on whether a Policy or Exit module applies to this implementation of **ICertManageModule**), and *MyModule.PolicyOrExit* is the application-specific identifier for the module. Note that *CAName* is the [sanitized name](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) for the certification authority. For information about the sanitized name, see
[ICertConfig::GetConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertconfig-getconfig). The use of this storage location is for future use.

### `strPropertyName` [in]

The name of the property being queried. Policy and exit modules should support the following properties.

| Value | Meaning |
| --- | --- |
| **Name** | Name of the module. |
| **Description** | Description of the module. |
| **Copyright** | Copyright pertaining to the module. |
| **File Version** | Version of the module file. |
| **Product Version** | Version of the module. |

### `Flags` [in]

This parameter is reserved and must be set to zero.

### `pvarProperty` [out, retval]

A pointer to a **VARIANT** that is the retrieved value for the property specified by *strPropertyName*.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is a **Variant** that represents the value of the property named *strPropertyName*.

## Remarks

Implementing **ICertManageModule** allows the Certificate Services Manager to retrieve the module's properties by calling **GetProperty**. The properties can then be displayed in Certificate Services Manager property pages for Policy and Exit Modules. The Certificate Services Manager will pass the location referenced by *strStorageLocation* to this module, and in future versions the implementation of this method can then use this location as needed. The following example does not use *strStorageLocation* but instead, maintains the property values in memory.

#### Examples

```cpp
#include <windows.h>
#include <Certmod.h>

HRESULT CCertManagePolicyModule::GetProperty(
            /* [in] */ const BSTR strConfig,
            /* [in] */ BSTR strStorageLocation,
            /* [in] */ BSTR strPropertyName,
            /* [in] */ LONG Flags,
            /* [retval][out] */ VARIANT *pvarProperty)
{
    // Array of property Names.
    // These values are defined in Certmod.h.
    wchar_t const * awszPropName[] =
    {
        wszCMM_PROP_NAME,
        wszCMM_PROP_DESCRIPTION,
        wszCMM_PROP_COPYRIGHT,
        wszCMM_PROP_FILEVER,
        wszCMM_PROP_PRODUCTVER
    };

    // Array of property Values.
    // These values are module-specific, and
    // correspond to the property names in
    // awszPropName (same index).
    wchar_t const * awszPropValue[] =
   {
        L"MyModule",                      // NAME
        L"Description of MyModule",       // DESCRIPTION
        L"Copyright 1998",                // COPYRIGHT
        L"1.0",                           // FILE VERSION
        L"1.0"                            // PRODUCT VERSION
    };
    int     i;
    bool    bFound = FALSE;
    HRESULT hr;

    // Return appropriate error if strPropertyName is NULL.
    if (NULL == strPropertyName)
        return E_INVALIDARG;

    // Return appropriate error if pvarProperty is NULL.
    if (NULL == pvarProperty)
        return E_POINTER;
    // Determine whether the requested property is in the Name array.
    for (i=0; i<sizeof(awszPropName)/sizeof(wchar_t *); i++)
        if (!wcscmp( strPropertyName, awszPropName[i]))
        {
            bFound = TRUE;  // Found the index for the property.
            break;
        }
    if ( !bFound )
        return S_FALSE;     // Requested property not found.

    // Allocate storage for the property value.
    pvarProperty->bstrVal = SysAllocString(awszPropValue[i]);
    if (NULL == pvarProperty->bstrVal)
        return E_OUTOFMEMORY;

    pvarProperty->vt = VT_BSTR;

    return S_OK;
}
```

## See also

**CCertManageModule**

[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig)

[ICertManageModule](https://learn.microsoft.com/windows/desktop/api/certmod/nn-certmod-icertmanagemodule)

[ICertManageModule::SetProperty](https://learn.microsoft.com/windows/desktop/api/certmod/nf-certmod-icertmanagemodule-setproperty)