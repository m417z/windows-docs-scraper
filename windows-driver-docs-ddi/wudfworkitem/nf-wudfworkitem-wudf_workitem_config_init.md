# WUDF_WORKITEM_CONFIG_INIT function

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The
**WUDF_WORKITEM_CONFIG_INIT** macro initializes a driver's [WUDF_WORKITEM_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfworkitem/ns-wudfworkitem-_wudf_workitem_config) structure.

## Parameters

### `pConfig` [out]

A pointer to the caller-allocated [WUDF_WORKITEM_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfworkitem/ns-wudfworkitem-_wudf_workitem_config) structure to initialize.

### `OnWorkItemFunc` [in]

The address of the driver's [OnWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfworkitem/nc-wudfworkitem-wudf_workitem_function) event callback function.

## Remarks

Drivers must call **WUDF_WORKITEM_CONFIG_INIT** before calling [IWDFDevice3::CreateWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-createworkitem).

The **WUDF_WORKITEM_CONFIG_INIT** function stores the pointer that the *OnWorkItemFunc* parameter specifies and sets the **AutomaticSerialization** member of the [WUDF_WORKITEM_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfworkitem/ns-wudfworkitem-_wudf_workitem_config) structure that is pointed to by the *pConfig* parameter to **TRUE**.

## See also

[IWDFDevice3::CreateWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-createworkitem)

[WUDF_WORKITEM_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfworkitem/ns-wudfworkitem-_wudf_workitem_config)