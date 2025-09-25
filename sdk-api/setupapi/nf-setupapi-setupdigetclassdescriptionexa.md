# SetupDiGetClassDescriptionExA function

## Description

The **SetupDiGetClassDescriptionEx** function retrieves the description of a setup class installed on a local or remote computer.

## Parameters

### `ClassGuid` [in]

A pointer to the GUID for the setup class whose description is to be retrieved.

### `ClassDescription` [out]

A pointer to a character buffer that receives the class description.

### `ClassDescriptionSize` [in]

The size, in characters, of the buffer that is pointed to by the *ClassDescription* parameter. The maximum length, in characters, of a NULL-terminated class description is LINE_LEN. For more information, see the following **Remarks** section.

### `RequiredSize` [out, optional]

A pointer to a DWORD-typed variable that receives the size, in characters, that is required to store the requested NULL-terminated class description. This pointer is optional and can be **NULL**.

### `MachineName` [in, optional]

A pointer to a NULL-terminated string that supplies the name of a remote computer on which the setup class resides. This pointer is optional and can be **NULL**. If the class is installed on a local computer, set the pointer to **NULL**.

> [!CAUTION]
> Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

### `Reserved`

Reserved for system use. A caller of this function must set this parameter to **NULL**.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved with a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If there is a friendly name in the registry key for the class, this routine returns the friendly name. Otherwise, this routine returns the class name.

**SetupDiGetClassDescriptionEx** does not enforce a restriction on the length of the class description that it can return. This function returns the required size for a NULL-terminated class description even if it is greater than LINE_LEN. However, LINE_LEN is the maximum length of a valid NULL-terminated class description. A caller should never need a buffer that is larger than LINE_LEN.

> [!NOTE]
> The setupapi.h header defines SetupDiGetClassDescriptionEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SetupDiBuildClassInfoList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdibuildclassinfolist)

[SetupDiBuildClassInfoListEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdibuildclassinfolistexa)

[SetupDiGetDeviceInfoListDetail](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceinfolistdetaila)

[SetupDiGetINFClass](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetinfclassa)