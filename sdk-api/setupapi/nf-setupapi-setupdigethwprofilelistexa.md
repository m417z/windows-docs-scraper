# SetupDiGetHwProfileListExA function

## Description

The **SetupDiGetHwProfileListEx** function retrieves a list of all currently defined hardware profile IDs on a local or remote computer.

## Parameters

### `HwProfileList` [out]

A pointer to an array to receive the list of currently defined hardware profile IDs.

### `HwProfileListSize` [in]

The number of DWORDs in the *HwProfileList* buffer.

### `RequiredSize` [out]

A pointer to a variable of type DWORD that receives the number of hardware profiles that are currently defined. If the number is larger than *HwProfileListSize*, the list is truncated to fit the array size. The value returned in *RequiredSize* indicates the array size required to store the entire list of hardware profiles.

### `CurrentlyActiveIndex` [out, optional]

A pointer to a variable that receives the index of the currently active hardware profile in the retrieved hardware profile list. This parameter is optional and can be **NULL**.

### `MachineName` [in, optional]

A pointer to a NULL-terminated string that contains the name of a remote system for which to retrieve the list of hardware profile IDs. This parameter is optional and can be **NULL**. If this parameter is **NULL**, the list is retrieved for the local system.

> [!CAUTION]
> Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

### `Reserved`

Must be **NULL**.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved by making a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). If the required size is larger than *HwProfileListSize*, **SetupDiGetHwProfileListEx** returns **FALSE** and a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INSUFFICIENT_BUFFER.

## See also

[SetupDiGetHwProfileFriendlyNameEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigethwprofilefriendlynameexa)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupDiGetHwProfileListEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).