# IMsmMerge::OpenModule

## Description

The
**OpenModule** method opens a Windows Installer merge module in read-only mode. A module must be opened before it can be merged with an installation database. For more information, see the
[OpenModule](https://learn.microsoft.com/windows/desktop/Msi/merge-openmodule) method of the
[Merge](https://learn.microsoft.com/windows/desktop/Msi/merge-object) object.

**IMsmMerge2::OpenModule** Mergemod.dll version 2.0 and later.**IMsmMerge::OpenModule** All Mergemod.dll versions.

## Parameters

### `Path` [in]

Fully qualified file name that points to a merge module. A **LPCWSTR** can be used in place of a **BSTR**.

### `Language` [in]

A language identifier (**LANGID**).

## Return value

The **OpenModule** function returns the following values.

| Value | Meaning |
| --- | --- |
| **E_ABORT** | The file specified is a Windows Installer database, but is not a merge module (missing [ModuleSignature table](https://learn.microsoft.com/windows/desktop/Msi/modulesignature-table)). |
| **ERROR_INSTALL_LANGUAGE_UNSUPPORTED as HRESULT** | The language is not supported by the module. |
| **ERROR_INSTALL_TRANSFORM_FAILURE as HRESULT** | The language is supported by the module, but there was an error applying the transform. |
| **ERROR_OPEN_FAILED as HRESULT** | The file could not be opened as a Windows Installer database. |
| **ERROR_TOO_MANY_OPEN_FILES as HRESULT** | There is already a module open. Closes the current module first. |
| **S_OK** | The function succeeded. |

## Remarks

This function opens the merge module in read-only mode (MSIDBOPEN_READONLY), and excludes other programs from writing to the merge module until the
[CloseModule](https://learn.microsoft.com/windows/desktop/Msi/merge-closemodule) function is called. A merge module must be opened before it can be merged.

The installer attempts to open the module in the language specified by *Language* or in any more general language. For example, if 1033 is specified by the *Language* value, a module with a default language of 1033, 9, or 0 is opened in its default language. A *Language* value of 9 opens modules with a default language of 9 or 0. If the default language of the module does not meet the specified requirements, an attempt is made to transform the module into the requested language. If that fails, the installer attempts to transform the module into increasingly general languages, all the way to language neutral. If none of the transforms succeed, the module fails to open. In this case, an error is added to the error list of type msmErrorLanguageUnsupported and the function returns ERROR_INSTALL_LANGUAGE_UNSUPPORTED as HRESULT.

If there is an error transforming the module to the desired language, an error is created of type msmErrorLanguageFailed and the function returns ERROR_INSTALL_TRANSFORM_FAILURE as HRESULT.

For more information, see the
[Type](https://learn.microsoft.com/windows/desktop/Msi/error-type) property of the
[Error](https://learn.microsoft.com/windows/desktop/Msi/error-object) object.

Opening a merge module clears any errors that have not already been retrieved.

## See also

[Merge Module Automation](https://learn.microsoft.com/windows/desktop/Msi/merge-module-automation)