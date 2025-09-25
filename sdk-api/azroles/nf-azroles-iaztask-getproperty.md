# IAzTask::GetProperty

## Description

The **GetProperty** method returns the [IAzTask](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iaztask) object property with the specified property ID.

## Parameters

### `lPropId` [in]

Property ID of the [IAzTask](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iaztask) object property to return. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **AZ_PROP_APPLICATION_DATA** | Also accessed through the [ApplicationData](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iaztask-get_applicationdata) property |
| **AZ_PROP_CHILD_CREATE** | Determines whether the current user has permission to create child objects. This value is **TRUE** if the current user has permission; otherwise, **FALSE**. |
| **AZ_PROP_DESCRIPTION** | Also accessed through the [Description](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iaztask-get_description) property |
| **AZ_PROP_NAME** | Also accessed through the [Name](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iaztask-get_name) property |
| **AZ_PROP_TASK_BIZRULE** | Also accessed through the [BizRule](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iaztask-get_bizrule) property |
| **AZ_PROP_TASK_BIZRULE_LANGUAGE** | Also accessed through the [BizRuleLanguage](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iaztask-get_bizrulelanguage) property |
| **AZ_PROP_TASK_IS_ROLE_DEFINITION** | Also accessed through the [IsRoleDefinition](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iaztask-get_isroledefinition) property |
| **AZ_PROP_TASK_OPERATIONS** | Also accessed through the [Operations](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iaztask-get_operations) property |
| **AZ_PROP_TASK_TASKS** | Also accessed through the [Tasks](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iaztask-get_tasks) property |
| **AZ_PROP_WRITABLE** | Also accessed through the [Writable](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iaztask-get_writable) property |

### `varReserved` [in, optional]

Reserved for future use.

### `pvarProp` [out]

A pointer to the returned [IAzTask](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iaztask) object property.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success. Any other value indicates that the operation failed.