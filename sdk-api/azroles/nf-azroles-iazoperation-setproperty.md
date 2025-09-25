# IAzOperation::SetProperty

## Description

The **SetProperty** method sets the specified value to the [IAzOperation](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazoperation) object property with the specified property ID.

## Parameters

### `lPropId` [in]

Property ID of the [IAzOperation](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazoperation) object property to set. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **AZ_PROP_APPLICATION_DATA** | Also accessed through the [ApplicationData](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazoperation-get_applicationdata) property |
| **AZ_PROP_DESCRIPTION** | Also accessed through the [Description](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazoperation-get_description) property |
| **AZ_PROP_NAME** | Also accessed through the [Name](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazoperation-get_name) property |
| **AZ_PROP_OPERATION_ID** | Also accessed through the [OperationID](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazoperation-get_operationid) property |

### `varProp` [in]

The value to set to the [IAzOperation](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazoperation) object property specified by the *lPropId* parameter. The following table shows the type of data that must be used depending on the value of the *lPropId* parameter.

| *lPropId* value | Data type (C++/Visual Basic) |
| --- | --- |
| **AZ_PROP_APPLICATION_DATA** | **BSTR**/**String** |
| **AZ_PROP_DESCRIPTION** | **BSTR**/**String** |
| **AZ_PROP_OPERATION_ID** | **LONG**/**Long** |
| **AZ_PROP_NAME** | **BSTR**/**String** |

### `varReserved` [in, optional]

Reserved for future use.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success. Any other value indicates that the operation failed.

## Remarks

You must call the [Submit](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazoperation-submit) method to persist any changes made by this method.