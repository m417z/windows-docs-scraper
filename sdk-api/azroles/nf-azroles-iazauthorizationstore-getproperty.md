# IAzAuthorizationStore::GetProperty

## Description

The **GetProperty** method returns the [AzAuthorizationStore](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazauthorizationstore) object property with the specified property ID.

## Parameters

### `lPropId` [in]

Property ID of the [AzAuthorizationStore](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazauthorizationstore) object property to return. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **AZ_PROP_DESCRIPTION** | Also accessed through the [Description](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-get_description) property |
| **AZ_PROP_APPLICATION_DATA** | Also accessed through the [ApplicationData](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-get_applicationdata) property |
| **AZ_PROP_AZSTORE_DOMAIN_TIMEOUT** | Also accessed through the [DomainTimeout](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-get_domaintimeout) property |
| **AZ_PROP_AZSTORE_SCRIPT_ENGINE_TIMEOUT** | Also accessed through the [ScriptEngineTimeout](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-get_scriptenginetimeout) property |
| **AZ_PROP_AZSTORE_MAX_SCRIPT_ENGINES** | Also accessed through the [MaxScriptEngines](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-get_maxscriptengines) property |
| **AZ_PROP_AZSTORE_TARGET_MACHINE** | Also accessed through the [TargetMachine](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-get_targetmachine) property |
| **AZ_PROP_CHILD_CREATE** | Determines whether the current user has permission to create child objects. This value is **TRUE** if the current user has permission; otherwise, **FALSE**. |
| **AZ_PROP_GENERATE_AUDITS** | Also accessed through the [GenerateAudits](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-get_generateaudits) property |
| **AZ_PROP_APPLY_STORE_SACL** | Also accessed through the [ApplyStoreSacl](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-get_applystoresacl) property |
| **AZ_PROP_WRITABLE** | Also accessed through the [Writable](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-get_writable) property |

### `varReserved` [in, optional]

Reserved for future use.

### `pvarProp` [out]

A pointer to the returned [AzAuthorizationStore](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazauthorizationstore) object property.

## Return value

 If the method succeeds, the method returns S_OK.

Any other **HRESULT** value indicates that the operation failed.