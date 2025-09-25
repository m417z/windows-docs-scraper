# IAzAuthorizationStore::SetProperty

## Description

The **SetProperty** method sets the specified value to the [AzAuthorizationStore](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazauthorizationstore) object property with the specified property ID.

## Parameters

### `lPropId` [in]

Property ID of the [AzAuthorizationStore](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazauthorizationstore) object property to set. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **AZ_PROP_AZSTORE_DOMAIN_TIMEOUT** | Also accessed through the [DomainTimeout](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-get_domaintimeout) property |
| **AZ_PROP_AZSTORE_MAX_SCRIPT_ENGINES** | Also accessed through the [MaxScriptEngines](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-get_maxscriptengines) property |
| **AZ_PROP_AZSTORE_SCRIPT_ENGINE_TIMEOUT** | Also accessed through the [ScriptEngineTimeout](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-get_scriptenginetimeout) property |
| **AZ_PROP_APPLICATION_DATA** | Also accessed through the [ApplicationData](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-get_applicationdata) property |
| **AZ_PROP_APPLY_STORE_SACL** | Also accessed through the [ApplyStoreSacl](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-get_applystoresacl) property |
| **AZ_PROP_DESCRIPTION** | Also accessed through the [Description](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-get_description) property |
| **AZ_PROP_GENERATE_AUDITS** | Also accessed through the [GenerateAudits](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-get_generateaudits) property |

### `varProp` [in]

Value to set to the [AzAuthorizationStore](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazauthorizationstore) object property specified by the *lPropId* parameter. The following table shows the type of data that must be used depending on the value of the *lPropId* parameter.

| *lPropId* value | Data type |
| --- | --- |
| **AZ_PROP_AZSTORE_DOMAIN_TIMEOUT** | **LONG** |
| **AZ_PROP_AZSTORE_MAX_SCRIPT_ENGINES** | **LONG** |
| **AZ_PROP_AZSTORE_SCRIPT_ENGINE_TIMEOUT** | **LONG** |
| **AZ_PROP_APPLICATION_DATA** | **BSTR** |
| **AZ_PROP_APPLY_STORE_SACL** | **BOOL** |
| **AZ_PROP_DESCRIPTION** | **BSTR** |
| **AZ_PROP_GENERATE_AUDITS** | **BOOL** |

### `varReserved` [in, optional]

Reserved for future use.

## Return value

 If the method succeeds, the method returns **S_OK**.

Any other **HRESULT** value indicates that the operation failed.

## Remarks

You must call the [Submit](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-submit) method to persist any changes made by this method.