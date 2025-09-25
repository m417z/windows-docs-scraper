# MsiEnumClientsW function

## Description

The
**MsiEnumClients** function enumerates the clients for a given installed component. The function retrieves one product code each time it is called.

## Parameters

### `szComponent` [in]

Specifies the component whose clients are to be enumerated.

### `iProductIndex` [in]

Specifies the index of the client to retrieve. This parameter should be zero for the first call to the
**MsiEnumClients** function and then incremented for subsequent calls. Because clients are not ordered, any new client has an arbitrary index. This means that the function can return clients in any order.

### `lpProductBuf` [out]

Pointer to a buffer that receives the product code. This buffer must be 39 characters long. The first 38 characters are for the GUID, and the last character is for the terminating null character.

## Return value

| Value | Meaning |
| --- | --- |
| **ERROR_BAD_CONFIGURATION** | The configuration data is corrupt. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. |
| **ERROR_NO_MORE_ITEMS** | There are no clients to return. |
| **ERROR_NOT_ENOUGH_MEMORY** | The system does not have enough memory to complete the operation. Available with Windows Server 2003. |
| **ERROR_SUCCESS** | A value was enumerated. |
| **ERROR_UNKNOWN_COMPONENT** | The specified component is unknown. |

## Remarks

To enumerate clients, an application should initially call the
**MsiEnumClients** function with the *iProductIndex* parameter set to zero. The application should then increment the  *iProductIndex* parameter and call
**MsiEnumClients** until there are no more clients (that is, until the function returns ERROR_NO_MORE_ITEMS).

When making multiple calls to
**MsiEnumClients** to enumerate all of the component's clients, each call should be made from the same thread.

> [!NOTE]
> The msi.h header defines MsiEnumClients as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[System Status Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)