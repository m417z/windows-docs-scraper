# UcmUcsiPpmNotification function

## Description

Informs the UcmUcsiCx class extension about a UCSI notification.

## Parameters

### `PpmObject` [in]

A handle to a Platform Policy Manager (PPM) object that the client driver received in the previous call to [**UcmUcsiPpmCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippm/nf-ucmucsippm-ucmucsippmcreate).

### `DataBlock` [in]

A pointer to a [**UCSI_DATA_BLOCK**] structure that contains information about the USCI notification.

## Remarks

The client driver calls UcmUcsiPpmNotification in the event of a UCSI notification. The driver must not call more than one instance of this function at the same time to avoid a race condition.

The client driver should assume that the driver can receive a request before this call returns. Hence, if it keeps a lock around this function and the same lock around handling a request, it will result into a deadlock.

## See also