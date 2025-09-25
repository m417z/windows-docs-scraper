# IMsmDependency::get_Language

## Description

The
**get_Language** method retrieves the
[Language](https://learn.microsoft.com/windows/desktop/Msi/dependency-language) property of the
[Dependency](https://learn.microsoft.com/windows/desktop/Msi/dependency-object) object. This method returns the **LANGID** of the required module.

## Parameters

### `Language` [out]

A pointer to a location in memory that receives the language.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **E_INVALIDARG** | Language is null. |
| **S_OK** | The function succeeded. |

## See also

[IMsmDependency](https://learn.microsoft.com/windows/desktop/api/mergemod/nn-mergemod-imsmdependency)

[Merge Module Automation](https://learn.microsoft.com/windows/desktop/Msi/merge-module-automation)