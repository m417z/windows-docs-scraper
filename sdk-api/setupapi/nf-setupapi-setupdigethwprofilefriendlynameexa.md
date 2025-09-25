# SetupDiGetHwProfileFriendlyNameExA function

## Description

The **SetupDiGetHwProfileFriendlyNameEx** function retrieves the friendly name associated with a hardware profile ID on a local or remote computer.

## Parameters

### `HwProfile` [in]

Supplies the hardware profile ID associated with the friendly name to retrieve. If this parameter is 0, the friendly name for the current hardware profile is retrieved.

### `FriendlyName` [out]

A pointer to a character buffer to receive the friendly name.

### `FriendlyNameSize` [in]

The size, in characters, of the *FriendlyName* buffer.

### `RequiredSize` [out, optional]

A pointer to a variable to receive the number of characters required to store the friendly name (including a NULL terminator). This parameter is optional and can be **NULL**.

### `MachineName` [in, optional]

A pointer to NULL-terminated string that contains the name of a remote computer on which the hardware profile ID resides. This parameter is optional and can be **NULL**. If *MachineName* is **NULL**, the hardware profile ID is on the local computer.

> [!CAUTION]
> Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

### `Reserved`

Must be **NULL**.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved by making a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[SetupDiGetHwProfileFriendlyName](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigethwprofilefriendlynamea)

[SetupDiGetHwProfileListEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigethwprofilelistexa)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupDiGetHwProfileFriendlyNameEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).