# _RESOURCEMANAGER_BASIC_INFORMATION structure

## Description

The **RESOURCEMANAGER_BASIC INFORMATION** structure contains information about a [resource manager object](https://learn.microsoft.com/windows-hardware/drivers/kernel/resource-manager-objects).

## Members

### `ResourceManagerId`

A GUID that KTM assigned to the resource manager.

### `DescriptionLength`

The length, in bytes, of the character array that the **Description** member provides.

### `Description`

A caller-allocated array of characters that receives a resource manager's description string.

## Remarks

The **RESOURCEMANAGER_BASIC INFORMATION** structure is used with the [ZwQueryInformationResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationresourcemanager) routine.

The resource manager's description string, which the **Description** member receives, is the description that the resource manager previously specified when it called [ZwCreateResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateresourcemanager).

## See also

[ZwCreateResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateresourcemanager)

[ZwQueryInformationResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntqueryinformationresourcemanager)