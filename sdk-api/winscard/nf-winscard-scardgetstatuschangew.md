# SCardGetStatusChangeW function

## Description

The **SCardGetStatusChange** function blocks execution until the current availability of the cards in a specific set of readers changes.

The caller supplies a list of [readers](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) to be monitored by an SCARD_READERSTATE array and the maximum amount of time (in milliseconds) that it is willing to wait for an action to occur on one of the listed readers. Note that **SCardGetStatusChange** uses the user-supplied value in the **dwCurrentState** members of the *rgReaderStates*[SCARD_READERSTATE](https://learn.microsoft.com/windows/desktop/api/winscard/ns-winscard-scard_readerstatea) array as the definition of the current [state](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) of the readers. The function returns when there is a change in availability, having filled in the **dwEventState** members of *rgReaderStates* appropriately.

## Parameters

### `hContext` [in]

A handle that identifies the [resource manager context](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly). The resource manager context is set by a previous call to
the [SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext) function.

### `dwTimeout` [in]

The maximum amount of time, in milliseconds, to wait for an action. A value of zero causes the function to return immediately. A value of INFINITE causes this function never to time out.

### `rgReaderStates` [in, out]

An array of
[SCARD_READERSTATE](https://learn.microsoft.com/windows/desktop/api/winscard/ns-winscard-scard_readerstatea) structures that specify the readers to watch, and that receives the result.

To be notified of the arrival of a new smart card reader, set the **szReader** member of a [SCARD_READERSTATE](https://learn.microsoft.com/windows/desktop/api/winscard/ns-winscard-scard_readerstatea) structure to "\\\\?PnP?\\Notification", and set all of the other members of that structure to zero.

**Important** Each member of each structure in this array must be initialized to zero and then set to specific values as necessary. If this is not done, the function will fail in situations that involve remote card readers.

### `cReaders` [in]

The number of elements in the *rgReaderStates* array.

## Return value

This function returns different values depending on whether it succeeds or fails.

| Return code | Description |
| --- | --- |
| **Success** | SCARD_S_SUCCESS. |
| **Failure** | An error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values). |

## Remarks

The **SCardGetStatusChange** function is a [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) tracking function. For more information about other tracking functions, see
[Smart Card Tracking Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/smart-card-tracking-functions).

#### Examples

For information about how to call this function, see the example in
[SCardLocateCards](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardlocatecardsa).

> [!NOTE]
> The winscard.h header defines SCardGetStatusChange as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SCARD_READERSTATE](https://learn.microsoft.com/windows/desktop/api/winscard/ns-winscard-scard_readerstatea)

[SCardCancel](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardcancel)

[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext)

[SCardLocateCards](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardlocatecardsa)