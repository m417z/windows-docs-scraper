# SetupEnumInfSectionsA function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The **SetupEnumInfSections** function retrieves section names from an INF file.

## Parameters

### `InfHandle` [in]

Handle to the INF file that is to be queried.

### `Index` [in]

The zero-based index of the section name to retrieve. This index may not correspond to the order of sections as they appear in the INF file.

### `Buffer` [out, optional]

Pointer to a buffer that receives the section name. You can call the function once to get the required buffer size, allocate the necessary memory, and then call the function a second time to retrieve the name. Using this technique, you can avoid errors caused by an insufficient buffer size. This parameter is optional. For more information, see the Remarks section.

### `Size` [in]

Size of the buffer pointed to by *ReturnBuffer* in characters. This number includes the terminating **NULL** character.

### `SizeNeeded` [out, optional]

Pointer to a location that receives the required size of the buffer pointed to by *ReturnBuffer*. The size is specified as the number of characters required to store the section name, including the terminating **NULL** character.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_NO_MORE_ITEMS** if the value of **EnumerationIndex** is greater than or equal to the number of sections names in the INF file.

## Remarks

This function can enumerate all unique section names in the INF file. If a section name appears more than once in an INF file, the function returns the name only once using a single enumeration index. To return all section names in the INF file, call the function beginning with an enumeration index of zero and then make repeated calls to the function while incrementing the index until the function returns **FALSE** and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_NO_MORE_ITEMS**. Your application should not rely on the section names being returned in any order based on the enumeration index.

> [!NOTE]
> The setupapi.h header defines SetupEnumInfSections as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).