# WDF_WORKITEM_CONFIG_INIT function

## Description

[Applies to KMDF and UMDF]

The **WDF_WORKITEM_CONFIG_INIT** function initializes a driver's [WDF_WORKITEM_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/ns-wdfworkitem-_wdf_workitem_config) structure.

## Parameters

### `Config` [out]

A pointer to the caller-allocated [WDF_WORKITEM_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/ns-wdfworkitem-_wdf_workitem_config) structure to initialize.

### `EvtWorkItemFunc` [in]

The address of the driver's [EvtWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nc-wdfworkitem-evt_wdf_workitem) event callback function.

## Remarks

Drivers must call **WDF_WORKITEM_CONFIG_INIT** before calling [WdfWorkItemCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nf-wdfworkitem-wdfworkitemcreate).

The **WDF_WORKITEM_CONFIG_INIT** function stores the pointer that the *EvtWorkItemFunc* parameter specifies and sets the **AutomaticSerialization** member of the [WDF_WORKITEM_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/ns-wdfworkitem-_wdf_workitem_config) structure that is pointed to by the *Config* parameter to **TRUE**.

#### Examples

For a code example that uses **WDF_WORKITEM_CONFIG_INIT**, see [WdfWorkItemCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nf-wdfworkitem-wdfworkitemcreate).

## See also

[EvtWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nc-wdfworkitem-evt_wdf_workitem)

[WDF_WORKITEM_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/ns-wdfworkitem-_wdf_workitem_config)

[WdfWorkItemCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nf-wdfworkitem-wdfworkitemcreate)