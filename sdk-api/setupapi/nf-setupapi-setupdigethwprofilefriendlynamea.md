# SetupDiGetHwProfileFriendlyNameA function

## Description

The **SetupDiGetHwProfileFriendlyName** function retrieves the friendly name associated with a hardware profile ID.

## Parameters

### `HwProfile` [in]

The hardware profile ID associated with the friendly name to retrieve. If this parameter is 0, the friendly name for the current hardware profile is retrieved.

### `FriendlyName` [out]

A pointer to a string buffer to receive the friendly name.

### `FriendlyNameSize` [in]

The size, in characters, of the *FriendlyName* buffer.

### `RequiredSize` [out, optional]

A pointer to a variable of type DWORD that receives the number of characters required to retrieve the friendly name (including a NULL terminator).

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved by making a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Call [SetupDiGetHwProfileFriendlyNameEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigethwprofilefriendlynameexa) to get the friendly name of a hardware profile ID on a remote computer.

> [!NOTE]
> The setupapi.h header defines SetupDiGetHwProfileFriendlyName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SetupDiGetHwProfileFriendlyNameEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigethwprofilefriendlynameexa)

[SetupDiGetHwProfileList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigethwprofilelist)