# _WDF_WORKITEM_CONFIG structure

## Description

[Applies to KMDF and UMDF]

The **WDF_WORKITEM_CONFIG** structure contains information that is associated with a work item.

## Members

### `Size`

The size, in bytes, of this **WDF_WORKITEM_CONFIG** structure.

### `EvtWorkItemFunc`

The address of an [EvtWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nc-wdfworkitem-evt_wdf_workitem) event callback function.

### `AutomaticSerialization`

A Boolean value that, if **TRUE**, indicates that the framework will synchronize execution of the [EvtWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nc-wdfworkitem-evt_wdf_workitem) callback function with callback functions from other objects that are underneath the work-item object's parent object. For more information, see the following Remarks section. If **FALSE**, the framework does not synchronize execution of the *EvtWorkItem* callback function.

## Remarks

Your driver must initialize the **WDF_WORKITEM_CONFIG** structure by calling [WDF_WORKITEM_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nf-wdfworkitem-wdf_workitem_config_init). Your driver can then pass the structure to the [WdfWorkItemCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nf-wdfworkitem-wdfworkitemcreate) method as an input parameter.

Setting the **AutomaticSerialization** member of **WDF_WORKITEM_CONFIG** to **TRUE** has no effect if the parent object's [synchronization scope](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ne-wdfobject-_wdf_synchronization_scope) is set to **WdfSynchronizationScopeNone**.

If **AutomaticSerialization** is **TRUE**, the parent object's execution level must be **WdfExecutionLevelPassive**.

For more information about **AutomaticSerialization** and synchronizing driver callback functions, see [Synchronization Techniques for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/synchronization-techniques-for-wdf-drivers).

## See also

[EvtWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nc-wdfworkitem-evt_wdf_workitem)

[WDF_WORKITEM_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nf-wdfworkitem-wdf_workitem_config_init)

[WdfWorkItemCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/nf-wdfworkitem-wdfworkitemcreate)