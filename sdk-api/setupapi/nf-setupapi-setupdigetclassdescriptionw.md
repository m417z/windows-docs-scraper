# SetupDiGetClassDescriptionW function

## Description

The **SetupDiGetClassDescription** function retrieves the class description associated with the specified setup class GUID.

## Parameters

### `ClassGuid` [in]

The GUID of the setup class whose description is to be retrieved.

### `ClassDescription` [out]

A pointer to a character buffer that receives the class description.

### `ClassDescriptionSize` [in]

The size, in characters, of the *ClassDescription* buffer.

### `RequiredSize` [out, optional]

A pointer to variable of type DWORD that receives the size, in characters, that is required to store the class description (including a NULL terminator). *RequiredSize* is always less than LINE_LEN. This parameter is optional and can be **NULL**.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved with a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Call **SetupDiGetClassDescriptionEx** to retrieve the description of a setup class installed on a remote computer.

> [!NOTE]
> The setupapi.h header defines SetupDiGetClassDescription as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SetupDiBuildClassInfoList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdibuildclassinfolist)

[SetupDiGetClassDescriptionEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassdescriptionexa)

[SetupDiGetINFClass](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetinfclassa)