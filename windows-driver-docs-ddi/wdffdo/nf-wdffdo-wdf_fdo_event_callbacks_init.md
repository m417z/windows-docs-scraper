# WDF_FDO_EVENT_CALLBACKS_INIT function

## Description

[Applies to KMDF only]

The **WDF_FDO_EVENT_CALLBACKS_INIT** function initializes a [WDF_FDO_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/ns-wdffdo-_wdf_fdo_event_callbacks) structure.

## Parameters

### `Callbacks` [out]

A pointer to the driver's [WDF_FDO_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/ns-wdffdo-_wdf_fdo_event_callbacks) structure.

## Remarks

The **WDF_FDO_EVENT_CALLBACKS_INIT** function zeros the specified [WDF_FDO_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/ns-wdffdo-_wdf_fdo_event_callbacks) structure and sets the structure's **Size** member.

#### Examples

For a code example that uses **WDF_FDO_EVENT_CALLBACKS_INIT**, see [WdfFdoInitSetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitseteventcallbacks).

## See also

[WdfFdoInitSetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitseteventcallbacks)