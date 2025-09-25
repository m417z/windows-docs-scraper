# SCardListReadersWithDeviceInstanceIdW function

## Description

The **SCardListReadersWithDeviceInstanceId** function gets the list of readers that have provided a device instance identifier. This function does not affect the state of the reader.

## Parameters

### `hContext` [in]

Handle that identifies the resource manager context for the query. You can set the resource manager context by a previous call to the [SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext) function. This parameter cannot be **NULL**.

### `szDeviceInstanceId` [in]

Device instance ID of the reader. You can get this value by calling the [SCardGetReaderDeviceInstanceId](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardgetreaderdeviceinstanceida) function with the reader name or by calling the [SetupDiGetDeviceInstanceId](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceinstanceida) function from the DDK.

### `mszReaders` [out, optional]

A multi-string that contain the smart card readers within the supplied device instance identifier. If this value is **NULL**, then the function ignores the buffer length supplied in the *pcchReaders* parameter, writes the length of the buffer that would have been returned if this parameter had not been **NULL** to *pcchReaders*, and returns a success code.

### `pcchReaders` [in, out]

The length, in characters, of the *mszReaders* buffer. This parameter receives the actual length of the multiple-string structure, including all terminating null characters. If the buffer length is specified as SCARD_AUTOALLOCATE, then *mszReaders* is converted to a pointer to a byte pointer, and receives the address of a block of memory that contains the multiple-string structure. When you have finished using this memory, deallocated it by using the [SCardFreeMemory](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardfreememory) function.

## Return value

This function returns different values depending on whether it succeeds or fails.

| Return code | Description |
| --- | --- |
| **Success** | SCARD_S_SUCCESS. |
| **Failure** | An error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values). |

## Remarks

 This function is not redirected. Calling the **SCardListReadersWithDeviceInstanceId** function when inside a Remote Desktop session fails with the SCARD_E_READER_UNAVAILABLE error code.

#### Examples

```cpp

szDeviceInstanceIdcchReaderNameLONG     lReturn, lReturn2;

LPTSTR   pmszReaders = NULL;
LPTSTR   pReader = NULL;WCHAR
DWORD    cchReaderName = SCARD_AUTOALLOCATE;

// Retrieve the reader’s name from it’s device instance ID
// hContext was set by a previous call to SCardEstablishContext.

// szDeviceInstanceId was obtained by calling SetupDiGetDeviceInstanceId
lReturn = SCardListReadersWithDeviceInstanceId (hContext,
                         szDeviceInstanceId,
                         (LPTSTR)&pmszReaders,
                         &cchReaderName);

switch( lReturn )
{
    case SCARD_E_NO_READERS_AVAILABLE:
        printf("No readers have the provided device instance ID.\n");
        // Take appropriate action.
        // ...
        break;

    case SCARD_S_SUCCESS:
        // Do something with the multi string of readers.
        // Output the values.
        // A double-null terminates the list of values.
        pReader = pmszReaders;
        while ( '\0' != *pReader )
        {
            // Display the value.
            printf("Reader: %S\n", pReader );
            // Advance to the next value.
            pReader = pReader + wcslen((wchar_t *)pReader) + 1;
        }
        // Free the memory.
        lReturn2 = SCardFreeMemory( hContext,
                                   pmszReaders );
        if ( SCARD_S_SUCCESS != lReturn2 )
            printf("Failed SCardFreeMemory\n");
        break;

default:
        printf("Failed SCardListReaders\n");
        // Take appropriate action.
        // ...
        break;

```

> [!NOTE]
> The winscard.h header defines SCardListReadersWithDeviceInstanceId as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).