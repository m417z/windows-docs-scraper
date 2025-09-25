# IAzTask::SetProperty

## Description

The **SetProperty** method sets the specified value to the [IAzTask](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iaztask) object property with the specified property ID.

## Parameters

### `lPropId` [in]

Property ID of the [IAzTask](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iaztask) object property to set. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **AZ_PROP_APPLICATION_DATA** | Also accessed through the [ApplicationData](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iaztask-get_applicationdata) property |
| **AZ_PROP_DESCRIPTION** | Also accessed through the [Description](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iaztask-get_description) property |
| **AZ_PROP_NAME** | Also accessed through the [Name](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iaztask-get_name) property |
| **AZ_PROP_TASK_BIZRULE** | Also accessed through the [BizRule](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iaztask-get_bizrule) property |
| **AZ_PROP_TASK_BIZRULE_LANGUAGE** | Also accessed through the [BizRuleLanguage](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iaztask-get_bizrulelanguage) property |
| **AZ_PROP_TASK_IS_ROLE_DEFINITION** | Also accessed through the [IsRoleDefinition](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iaztask-get_isroledefinition) property |

### `varProp` [in]

Value to set to the [IAzTask](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iaztask) object property specified by the *lPropId* parameter. The following table shows the type of data that must be used depending on the value of the *lPropId* parameter.

| *lPropId* value | Data type |
| --- | --- |
| **AZ_PROP_APPLICATION_DATA** | **BSTR** |
| **AZ_PROP_DESCRIPTION** | **BSTR** |
| **AZ_PROP_NAME** | **BSTR** |
| **AZ_PROP_TASK_BIZRULE** | **BSTR** |
| **AZ_PROP_TASK_BIZRULE_LANGUAGE** | **BSTR** |
| **AZ_PROP_IS_ROLE_DEFINITION** | **BOOL** |

### `varReserved` [in, optional]

Reserved for future use.

## Return value

The return value is an **HRESULT**. A value of **S_OK** indicates success. Any other value indicates that the operation failed.

## Remarks

You must call the [Submit](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iaztask-submit) method to persist any changes made by this method.