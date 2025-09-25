# SCardGetDeviceTypeIdA function

## Description

The **SCardGetDeviceTypeId** function gets the device type identifier of the card reader for the given reader name. This function does not affect the state of the reader.

## Parameters

### `hContext` [in]

Handle that identifies the resource manager context for the query. You can set the resource manager context by calling the [SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext) function. This parameter cannot be NULL.

### `szReaderName` [in]

Reader name. You can get this value by calling the [SCardListReaders](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardlistreadersa) function.

### `pdwDeviceTypeId` [in, out]

The actual device type identifier. The list of reader types returned by this function are listed under **ReaderType** member in the [SCARD_READER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/smclib/ns-smclib-_scard_reader_capabilities) structure.

## Return value

This function returns different values depending on whether it succeeds or fails.

| Return code | Description |
| --- | --- |
| **Success** | SCARD_S_SUCCESS. |
| **Failure** | An error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values). |

## Remarks

> [!NOTE]
> The winscard.h header defines SCardGetDeviceTypeId as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).