# IAzTask::DeletePropertyItem

## Description

The **DeletePropertyItem** method removes the specified entity from the specified list.

## Parameters

### `lPropId` [in]

Property ID of the list from which to remove the entity specified by the *varProp* parameter. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **AZ_PROP_TASK_OPERATIONS** | Can also be removed using the [DeleteOperation](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iaztask-deleteoperation) method |
| **AZ_PROP_TASK_TASKS** | Can also be removed using the [DeleteTask](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iaztask-deletetask) method |

### `varProp` [in]

Name of the entity to remove from the list specified by the *lPropId* parameter.

The variant must be a **BSTR** variant.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success. Any other value indicates that the operation failed.