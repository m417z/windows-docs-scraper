# IMsmError::get_Language

## Description

The
**get_Language** method retrieves the
[Language](https://learn.microsoft.com/windows/desktop/Msi/dependency-language) property of the
[Error](https://learn.microsoft.com/windows/desktop/Msi/error-object) object. This function returns the **LANGID** of the error.

## Parameters

### `ErrorLanguage` [out]

A pointer to a location in memory that receives the language value causing this error.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **E_INVALIDARG** | Language is null. |
| **S_OK** | The function succeeded. |

## Remarks

The function returns -1 unless the error is of type msmErrorLanguageUnsupported or msmErrorLanguageFailed. You can determine the type of error by calling [IMsmError::get_Type](https://learn.microsoft.com/windows/desktop/api/mergemod/nf-mergemod-imsmerror-get_type).

## See also

[Merge Module Automation](https://learn.microsoft.com/windows/desktop/Msi/merge-module-automation)