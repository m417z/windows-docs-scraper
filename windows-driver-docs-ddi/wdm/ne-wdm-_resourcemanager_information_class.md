# _RESOURCEMANAGER_INFORMATION_CLASS enumeration

## Description

The **RESOURCEMANAGER_INFORMATION_CLASS** enumeration identifies the type of information that the [ZwQueryInformationResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationresourcemanager) routine can retrieve for a [resource manager object](https://learn.microsoft.com/windows-hardware/drivers/kernel/resource-manager-objects).

## Constants

### `ResourceManagerBasicInformation`

Information about a resource manager object is stored in a [RESOURCEMANAGER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_resourcemanager_basic_information) structure.

### `ResourceManagerCompletionInformation`

Information about a resource manager object is stored in a [RESOURCEMANAGER_COMPLETION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_resourcemanager_completion_information) structure.

## See also

[RESOURCEMANAGER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_resourcemanager_basic_information)

[RESOURCEMANAGER_COMPLETION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_resourcemanager_completion_information)

[ZwQueryInformationResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationresourcemanager)