# WDF_PDO_EVENT_CALLBACKS_INIT function

## Description

[Applies to KMDF only]

The **WDF_PDO_EVENT_CALLBACKS_INIT** function initializes a [WDF_PDO_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/ns-wdfpdo-_wdf_pdo_event_callbacks) structure.

## Parameters

### `Callbacks` [out]

A pointer to the driver's [WDF_PDO_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/ns-wdfpdo-_wdf_pdo_event_callbacks) structure.

## Remarks

The **WDF_PDO_EVENT_CALLBACKS_INIT** function zeros the specified [WDF_PDO_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/ns-wdfpdo-_wdf_pdo_event_callbacks) structure and sets the structure's **Size** member.

#### Examples

For a code example that uses **WDF_PDO_EVENT_CALLBACKS_INIT**, see [WdfPdoInitSetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitseteventcallbacks).

## See also

[WDF_PDO_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/ns-wdfpdo-_wdf_pdo_event_callbacks)

[WdfPdoInitSetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitseteventcallbacks)