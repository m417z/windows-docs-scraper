# IAzTask::AddPropertyItem

## Description

The **AddPropertyItem** method adds the specified entity to the specified list.

## Parameters

### `lPropId` [in]

Property ID of the list to which to add the entity specified by the *varProp* parameter. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **AZ_PROP_TASK_OPERATIONS** | Can also be added using the [AddOperation](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iaztask-addoperation) method |
| **AZ_PROP_TASK_TASKS** | Can also be added using the [AddTask](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iaztask-addtask) method |

### `varProp` [in]

Name of the entity to add to the list specified by the *lPropId* parameter.

The variant must be a **BSTR** variant.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success. Any other value indicates that the operation failed.

## Remarks

You must call the [Submit](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iaztask-submit) method to persist any changes made by this method.