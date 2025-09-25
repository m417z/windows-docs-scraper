# lineGetAddressStatusW function

## Description

The
**lineGetAddressStatus** function allows an application to query the specified address for its current status.

## Parameters

### `hLine`

Handle to the open line device.

### `dwAddressID`

Address on the given open line device. This is the address to be queried. An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades.

### `lpAddressStatus`

Pointer to a variably sized data structure of type
[LINEADDRESSSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddressstatus). Prior to calling
**lineGetAddressStatus**, the application must set the **dwTotalSize** member of this structure to indicate the amount of memory available to TAPI for returning information.

**Note** If the size parameters in the structure are not correct, there is a possibility that data could get overwritten. For more information on setting structure sizes, see the
[memory allocation](https://learn.microsoft.com/windows/desktop/Tapi/memory-allocation) topic.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_INVALADDRESSID, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALLINEHANDLE, LINEERR_STRUCTURETOOSMALL, LINEERR_INVALPOINTER, LINEERR_UNINITIALIZED, LINEERR_NOMEM, LINEERR_OPERATIONUNAVAIL, LINEERR_OPERATIONFAILED.

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[LINEADDRESSSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddressstatus)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

## Remarks

> [!NOTE]
> The tapi.h header defines lineGetAddressStatus as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).