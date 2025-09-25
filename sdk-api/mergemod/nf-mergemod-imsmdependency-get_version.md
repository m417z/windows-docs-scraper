# IMsmDependency::get_Version

## Description

The
**get_Version** method retrieves the
[Version](https://learn.microsoft.com/windows/desktop/Msi/dependency-version) property of the
[Dependency](https://learn.microsoft.com/windows/desktop/Msi/dependency-object) object. This method returns the version of the required module in the form of a **BSTR**.

## Parameters

### `Version` [out]

A pointer to a location in memory that is filled in with a **BSTR** value.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **E_INVALIDARG** | Version is null. |
| **S_OK** | The function succeeded. |

## Remarks

The client is responsible for freeing the resulting string using **SysFreeString**.

## See also

[IMsmDependency](https://learn.microsoft.com/windows/desktop/api/mergemod/nn-mergemod-imsmdependency)

[Merge Module Automation](https://learn.microsoft.com/windows/desktop/Msi/merge-module-automation)