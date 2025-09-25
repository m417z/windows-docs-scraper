# MsiFormatRecordW function

## Description

The
**MsiFormatRecord** function formats record field data and properties using a format string.

## Parameters

### `hInstall` [in]

Handle to the installation. This may be omitted, in which case only the record field parameters are processed and properties are not available for substitution.

### `hRecord` [in]

Handle to the record to format. The template string must be stored in record field 0 followed by referenced data parameters.

### `szResultBuf` [out]

Pointer to the buffer that receives the null terminated formatted string. Do not attempt to determine the size of the buffer by passing in a null (value=0) for *szResultBuf*. You can get the size of the buffer by passing in an empty string (for example ""). The function then returns **ERROR_MORE_DATA** and *pcchResultBuf* contains the required buffer size in **TCHAR**s, not including the terminating null character. On return of **ERROR_SUCCESS**, *pcchResultBuf* contains the number of **TCHAR**s written to the buffer, not including the terminating null character.

### `pcchResultBuf` [in, out]

Pointer to the variable that specifies the size, in **TCHAR**s, of the buffer pointed to by the variable *szResultBuf*. When the function returns **ERROR_SUCCESS**, this variable contains the size of the data copied to *szResultBuf*, not including the terminating null character. If *szResultBuf* is not large enough, the function returns **ERROR_MORE_DATA** and stores the required size, not including the terminating null character, in the variable pointed to by *pcchResultBuf*.

## Return value

The
**MsiFormatRecord** function returns one of the following values:

## Remarks

The
**MsiFormatRecord** function uses the following format process.

Parameters that are to be
[formatted](https://learn.microsoft.com/windows/desktop/Msi/formatted) are enclosed in square brackets [...]. The square brackets can be iterated because the substitutions are resolved from the inside out.

If a part of the string is enclosed in curly braces { } and contains no square brackets, it is left unchanged, including the curly braces.

If a part of the string is enclosed in curly braces { } and contains one or more property names, and if all the properties are found, the text (with the resolved substitutions) is displayed without the curly braces. If any of the properties is not found, all the text in the braces and the braces themselves are removed.

Note in the case of deferred execution custom actions,
**MsiFormatRecord** only supports **CustomActionData** and [ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode) properties. For more information, see
[Obtaining Context Information for Deferred Execution Custom Actions](https://learn.microsoft.com/windows/desktop/Msi/obtaining-context-information-for-deferred-execution-custom-actions).

The following steps describe how to format strings using the
**MsiFormatRecord** function:

**To format strings using the MsiFormatRecord function**

1. The numeric parameters are substituted by replacing the marker with the value of the corresponding record field, with missing or null values producing no text.
2. The resultant string is processed by replacing the nonrecord parameters with the corresponding values, described next.

   * If a substring of the form "[propertyname]" is encountered, it is replaced by the value of the property.
   * If a substring of the form "[%environmentvariable]" is found, the value of the environment variable is substituted.
   * If a substring of the form" [#*filekey*]" is found, it is replaced by the full path of the file, with the value *filekey* used as a key into the
     [File table](https://learn.microsoft.com/windows/desktop/Msi/file-table). The value of "[#*filekey*]" remains blank and is not replaced by a path until the installer runs the
     [CostInitialize action](https://learn.microsoft.com/windows/desktop/Msi/costinitialize-action),
     [FileCost action](https://learn.microsoft.com/windows/desktop/Msi/filecost-action), and
     [CostFinalize action](https://learn.microsoft.com/windows/desktop/Msi/costfinalize-action). The value of "[#*filekey*]" depends upon the installation state of the component to which the file belongs. If the component is being run from source, the value is the path to the source location of the file. If the component is being run locally, the value is the path to the target location of the file after installation. If the component is absent, the path is blank. For more information about checking the installation state of components, see
     [Checking the Installation of Features, Components, Files](https://learn.microsoft.com/windows/desktop/Msi/checking-the-installation-of-features-components-files).
   * If a substring of the form "[$*componentkey*]" is found, it is replaced by the install directory of the component, with the value *componentkey* used as a key into the
     [Component table](https://learn.microsoft.com/windows/desktop/Msi/component-table). The value of "[$*componentkey*]" remains blank and is not replaced by a directory until the installer runs the
     [CostInitialize action](https://learn.microsoft.com/windows/desktop/Msi/costinitialize-action),
     [FileCost action](https://learn.microsoft.com/windows/desktop/Msi/filecost-action), and
     [CostFinalize action](https://learn.microsoft.com/windows/desktop/Msi/costfinalize-action). The value of "[$*componentkey*]" depends upon the installation state of the component. If the component is being run from source, the value is the source directory of the file. If the component is being run locally, the value is the target directory after installation. If the component is absent, the value is left blank. For more information about checking the installation state of components, see
     [Checking the Installation of Features, Components, Files](https://learn.microsoft.com/windows/desktop/Msi/checking-the-installation-of-features-components-files).
   * Note that if a component is already installed, and is not being reinstalled, removed, or moved during the current installation, the action state of the component is null and therefore the string "[$componentkey]" evaluates to Null.
   * If a substring of the form "[\c]" is found, it is replaced by the character without any further processing. Only the first character after the backslash is kept; everything else is removed.

If **ERROR_MORE_DATA** is returned, the parameter which is a pointer gives the size of the buffer required to hold the string. If **ERROR_SUCCESS** is returned, it gives the number of characters written to the string buffer. Therefore you can get the size of the buffer by passing in an empty string (for example "") for the parameter that specifies the buffer. Do not attempt to determine the size of the buffer by passing in a Null (value=0).

> [!NOTE]
> The msiquery.h header defines MsiFormatRecord as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Passing Null as the Argument of Windows Installer Functions](https://learn.microsoft.com/windows/desktop/Msi/passing-null-as-the-argument-of-windows-installer-functions)