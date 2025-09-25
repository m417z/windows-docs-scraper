# UcmUcsiPpmSetUcsiCommandRequestQueue function

## Description

Provides a framework queue object that is used to dispatch UCSI commands to the client driver.

## Parameters

### `PpmObject` [in]

A handle to a Platform Policy Manager (PPM) object that the client driver received in the previous call to [**UcmUcsiPpmCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippm/nf-ucmucsippm-ucmucsippmcreate).

### `PpmRequestQueue` [in]

A WDFQUEUE handle that the client driver in a previous call to [**WdfIoQueueCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuecreate)

## Remarks

The client driver is expected to call UcmUcsiPpmSetUcsiCommandRequestQueue after calling [**UcmUcsiPpmCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippm/nf-ucmucsippm-ucmucsippmcreate) and before [**UcmUcsiPpmStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippm/nf-ucmucsippm-ucmucsippmstart).

## See also