# SCardGetTransmitCount function

## Description

The **SCardGetTransmitCount** function retrieves the number of transmit operations that have completed since the specified card reader was inserted.

## Parameters

### `hCard` [in]

A handle to a smart card obtained from a previous call to
[SCardConnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardconnecta).

### `pcTransmitCount` [out]

A pointer to the number of transmit operations that have completed since the specified card reader was inserted.

## Return value

If the function succeeds, it returns **SCARD_S_SUCCESS**.

If the function fails, it returns an error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values).