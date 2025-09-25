# SCardGetReaderIconA function

## Description

The **SCardGetReaderIcon** function gets an icon of the smart card reader for a given reader's name. This function does not affect the state of the card reader.

## Parameters

### `hContext` [in]

Handle that identifies the resource manager context for the query. You can set the resource manager context by a previous call to the [SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext) function. This parameter cannot be **NULL**.

### `szReaderName` [in]

Reader name. You can get this value by calling the [SCardListReaders](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardlistreadersa) function.

### `pbIcon` [out]

Pointer to a buffer that contains a BLOB of the smart card reader icon as read from the icon file. If this value is **NULL**, the function ignores the buffer length supplied in the *pcbIcon* parameter, writes the length of the buffer that would have been returned to *pcbIcon* if this parameter had not been NULL, and returns a success code.

### `pcbIcon` [in, out]

Length, in characters, of the *pbIcon* buffer. This parameter receives the actual length of the received attribute. If the buffer length is specified as SCARD_AUTOALLOCATE, then *pbIcon* is converted from a pointer to a byte pointer and receives the address of a block of memory that contains the attribute. This block of memory must be deallocated with the [SCardFreeMemory](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardfreememory) function.

## Return value

This function returns different values depending on whether it succeeds or fails.

| Return code | Description |
| --- | --- |
| **Success** | SCARD_S_SUCCESS. |
| **Failure** | An error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values). |

## Remarks

The icon should be 256 × 256 pixels with no alpha channel.

#### Examples

```cpp
PBYTE    pbIcon = NULL;
DWORD    cbIcon = SCARD_AUTOALLOCATE;
DWORD    i;
LONG     lReturn;
LPTSTR   szReaderName = "USB Smart Card Reader 0";

// Retrieve the reader's icon.
// hContext was set by a previous call to SCardEstablishContext.
lReturn = SCardGetReaderIcon(hContext,
                         szReaderName,
                         (PBYTE)&pbIcon,
                         &cbIcon);

if ( SCARD_S_SUCCESS != lReturn )
{
    printf("Failed SCardGetReaderIcon - %x\n", lReturn);
    // Take appropriate action.
}
else
{
    // Free the memory when done.
    lReturn = SCardFreeMemory(hContext, pbIcon);
}

```

> [!NOTE]
> The winscard.h header defines SCardGetReaderIcon as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).