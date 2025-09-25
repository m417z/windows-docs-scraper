# SCardGetReaderDeviceInstanceIdA function

## Description

The **SCardGetReaderDeviceInstanceId** function gets the device instance identifier of the card reader for the given reader name. This function does not affect the state of the reader.

## Parameters

### `hContext` [in]

Handle that identifies the resource manager context for the query. You can set the resource manager context by a previous call to the [SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext) function. This parameter cannot be **NULL**.

### `szReaderName` [in]

Reader name. You can get this value by calling the [SCardListReaders](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardlistreadersa) function.

### `szDeviceInstanceId` [out, optional]

Buffer that receives the device instance ID of the reader. If this value is **NULL**, the function ignores the buffer length supplied in *cchDeviceInstanceId* parameter, writes the length of the buffer that would have been returned if this parameter had not been **NULL** to *cchDeviceInstanceId*, and returns a success code.

### `pcchDeviceInstanceId` [in, out]

Length, in characters, of the *szDeviceInstanceId* buffer, including the **NULL** terminator. If the buffer length is specified as SCARD_AUTOALLOCATE, then the *szDeviceInstanceId* parameter is converted to a pointer to a byte pointer, and receives the address of a block of memory containing the instance id. This block of memory must be deallocated with the [SCardFreeMemory](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardfreememory) function.

## Return value

This function returns different values depending on whether it succeeds or fails.

| Return code | Description |
| --- | --- |
| **Success** | SCARD_S_SUCCESS. |
| **Failure** | An error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values). |

## Remarks

 This function is not redirected. Calling the **SCardGetReaderDeviceInstanceId** function when inside a Remote Desktop session fails with the SCARD_E_READER_UNAVAILABLE error code.

#### Examples

```cpp

LONG     lReturn;
LPTSTR   szReaderName = "USB Smart Card Reader 0";
WCHAR    szDeviceInstanceId[256];
DWORD    cchDeviceInstanceId = 256;

// Retrieve the reader's device instance ID.
// hContext was set by a previous call to SCardEstablishContext.
lReturn = SCardGetReaderDeviceInstanceId (hContext,
                         szReaderName,
                         szDeviceInstanceId,
                         &cchDeviceInstanceId);

if ( SCARD_S_SUCCESS != lReturn )
{
    printf("Failed SCardGetReaderDeviceInstanceId - %x\n", lReturn);
    // Take appropriate action.
}

```

> [!NOTE]
> The winscard.h header defines SCardGetReaderDeviceInstanceId as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).