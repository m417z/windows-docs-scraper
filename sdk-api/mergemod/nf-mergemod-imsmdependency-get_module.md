# IMsmDependency::get_Module

## Description

The
**get_Module** method retrieves the
[Module](https://learn.microsoft.com/windows/desktop/Msi/dependency-module) property of the
[Dependency](https://learn.microsoft.com/windows/desktop/Msi/dependency-object) object. This method returns the ModuleID of the module required by the current string in the form of a **BSTR**. The ModuleID is of the same form as used in the
[ModuleSignature table](https://learn.microsoft.com/windows/desktop/Msi/modulesignature-table).

## Parameters

### `Module` [out]

A pointer to a location in memory that is filled in with a **BSTR** value.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **E_INVALIDARG** | Module is null |
| **S_OK** | The function succeeded |

## Remarks

The client is responsible for freeing the resulting string using **SysFreeString**.

## See also

[IMsmDependency](https://learn.microsoft.com/windows/desktop/api/mergemod/nn-mergemod-imsmdependency)

[Merge Module Automation](https://learn.microsoft.com/windows/desktop/Msi/merge-module-automation)