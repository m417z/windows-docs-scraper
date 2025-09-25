# IWDFDevice3::CreateWorkItem

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **CreateWorkItem** method creates a framework work-item object, which can subsequently be added to the framework’s work-item queue.

## Parameters

### `pConfig` [in]

A pointer to a caller-allocated [WUDF_WORKITEM_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfworkitem/ns-wudfworkitem-_wudf_workitem_config) structure that the driver must have already initialized by calling [WUDF_WORKITEM_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfworkitem/nf-wudfworkitem-wudf_workitem_config_init).

### `pParentObject` [in, optional]

A pointer to the parent object interface or NULL.

### `ppWorkItem` [out]

A pointer to a buffer that receives a pointer to the [IWDFWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfworkitem) interface for the new WorkItem object.

## Return value

The method returns S_OK if the operation succeeds. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## Remarks

If you specify a parent object, the framework automatically deletes the work-item when the parent object is deleted. Alternatively, the driver can call [IWDFObject::DeleteWdfObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfobject-deletewdfobject) to delete a work-item. The driver must not delete a work-item in its [OnWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfworkitem/nc-wudfworkitem-wudf_workitem_function) callback function.

For more information, see [Using Work Items](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-workitems).

#### Examples

```
WUDF_WORKITEM_CONFIG config;

WUDF_WORKITEM_CONFIG_INIT(&config, OnWorkItem);
hr = m_IWdfDevice3->CreateWorkItem(&config,
                                   m_IWdfDevice3,
                                   &m_WorkItem);

```

## See also

[IWDFDevice3](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice3)

[IWDFWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfworkitem)

[OnWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfworkitem/nc-wudfworkitem-wudf_workitem_function)

[WUDF_WORKITEM_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfworkitem/ns-wudfworkitem-_wudf_workitem_config)

[WUDF_WORKITEM_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfworkitem/nf-wudfworkitem-wudf_workitem_config_init)