# SetupDiGetINFClassA function

## Description

The **SetupDiGetINFClass** function returns the class of a specified device INF file.

## Parameters

### `InfName` [in]

A pointer to a NULL-terminated string that supplies the name of a device INF file. This name can include a path. However, if just the file name is specified, the file is searched for in each directory that is listed in the **DevicePath** entry under the **HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion** subkey of the registry. The maximum length in characters, including a NULL terminator, of a NULL-terminated INF file name is MAX_PATH.

### `ClassGuid` [out]

A pointer to a variable of type GUID that receives the class GUID for the specified INF file. If the INF file does not specify a class name, the function returns a GUID_NULL structure. Call [SetupDiClassGuidsFromName](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiclassguidsfromnamea) to determine whether one or more classes with this name are already installed.

### `ClassName` [out]

A pointer to a buffer that receives a NULL-terminated string that contains the name of the class for the specified INF file. If the INF file does not specify a class name but does specify a GUID, this buffer receives the name that is retrieved by calling [SetupDiClassNameFromGuid](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiclassnamefromguida). However, if **SetupDiClassNameFromGuid** cannot retrieve a class name (for example, the class is not installed), it returns an empty string.

### `ClassNameSize` [in]

 The size, in characters, of the buffer that is pointed to by the *ClassName* parameter. The maximum length of a NULL-terminated class name, in characters, is MAX_CLASS_NAME_LEN.

### `RequiredSize` [out, optional]

A pointer to a DWORD-typed variable that receives the number of characters that are required to store the class name, including a terminating **NULL**. This pointer is optional and can be **NULL**.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved with a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Do not use this function with INF files for Windows 9x or Millennium Edition.

> [!NOTE]
> The setupapi.h header defines SetupDiGetINFClass as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SetupDiBuildClassInfoList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdibuildclassinfolist)

[SetupDiClassGuidsFromName](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiclassguidsfromnamea)

[SetupDiClassNameFromGuid](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiclassnamefromguida)

[SetupDiGetClassDescription](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassdescriptiona)