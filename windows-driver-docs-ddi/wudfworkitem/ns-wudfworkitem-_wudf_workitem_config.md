# _WUDF_WORKITEM_CONFIG structure

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The
**WUDF_WORKITEM_CONFIG** structure contains information that is associated with a work item.

## Members

### `Size`

The size, in bytes, of this structure.

### `OnWorkItemFunc`

The address of an [OnWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfworkitem/nc-wudfworkitem-wudf_workitem_function) callback function.

### `AutomaticSerialization`

A Boolean value that, if TRUE, indicates that the framework will synchronize execution of the [OnWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfworkitem/nc-wudfworkitem-wudf_workitem_function) callback function with callback functions from other objects that are underneath the work-item object's parent object. If FALSE, the framework does not synchronize execution of the *OnWorkItem* callback function.

## Remarks

Your driver must initialize the **WUDF_WORKITEM_CONFIG** structure by calling [WUDF_WORKITEM_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfworkitem/nf-wudfworkitem-wudf_workitem_config_init). Your driver can then pass the structure to the [IWDFDevice3::CreateWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-createworkitem) method as an input parameter.

Setting the **AutomaticSerialization** member of **WUDF_WORKITEM_CONFIG** to TRUE has no effect if the driver did not enable automatic callback synchronization by calling [IWDFDeviceInitialize::SetLockingConstraint](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdeviceinitialize-setlockingconstraint).

## See also

[IWDFDevice3::CreateWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-createworkitem)

[OnWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfworkitem/nc-wudfworkitem-wudf_workitem_function)

[WUDF_WORKITEM_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfworkitem/nf-wudfworkitem-wudf_workitem_config_init)