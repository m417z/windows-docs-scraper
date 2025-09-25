# IAzApplication::SetProperty

## Description

The **SetProperty** method sets the specified value to the [IAzApplication](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplication) object property with the specified property ID.

## Parameters

### `lPropId` [in]

Property ID of the [IAzApplication](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplication) object property to set. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **AZ_PROP_APPLICATION_DATA** | Also accessed through the [ApplicationData](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-get_applicationdata) property |
| **AZ_PROP_APPLICATION_AUTHZ_INTERFACE_CLSID** | Also accessed through the [AuthzInterfaceClsid](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-get_authzinterfaceclsid) property |
| **AZ_PROP_APPLICATION_VERSION** | Also accessed through the [Version](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-get_version) property |
| **AZ_PROP_APPLY_STORE_SACL** | Also accessed through the [ApplyStoreSacl](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-get_applystoresacl) property |
| **AZ_PROP_DESCRIPTION** | Also accessed through the [Description](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-get_description) property |
| **AZ_PROP_GENERATE_AUDITS** | Also accessed through the [GenerateAudits](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-get_generateaudits) property |
| **AZ_PROP_NAME** | Also accessed through the [Name](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-get_name) property |

### `varProp` [in]

Value to set to the [IAzApplication](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplication) object property specified by the *lPropId* parameter. The type of data that must be used depends on the value of the *lPropId* parameter.

| *lPropId* value | Data type (C++/Visual Basic) |
| --- | --- |
| **AZ_PROP_APPLICATION_DATA** | **BSTR**/**String** |
| **AZ_PROP_APPLICATION_INTERFACE_CLSID** | **BSTR**/**String** |
| **AZ_PROP_APPLICATION_VERSION** | **BSTR**/**String** |
| **AZ_PROP_APPLY_STORE_SACL** | **BSTR**/**String** |
| **AZ_PROP_DESCRIPTION** | **BSTR**/**String** |
| **AZ_PROP_GENERATE_AUDITS** | **BSTR**/**String** |
| **AZ_PROP_NAME** | **BSTR**/**String** |

### `varReserved` [in, optional]

Reserved for future use.

## Return value

 If the method succeeds, the method returns S_OK.

Any other **HRESULT** value indicates that the operation failed.

## Remarks

You must call the [Submit](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-submit) method to persist any changes made by this method.