# IGPMSearchCriteria::Add

## Description

Adds a criterion for search operations.

## Parameters

### `searchProperty` [in]

The search property to evaluate. For a valid combination of search properties, search operations, and values, see the Remarks section.

### `searchOperation` [in]

The operation to use to evaluate *searchProperty* using the value specified by *varValue*.

### `varValue` [in]

The value to evaluate *searchProperty* against.

## Return value

### JScript

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### VB

Returns **S_OK** if successful. Returns a failure code if an error occurs.

## Remarks

Following is a table that contains the valid combinations for the *searchProperty*, *searchOperation*, and *varValue* parameters.

**Note** Multiple calls to **IGPMSearchCriteria::Add** will result in a logical **And** operation of search criteria. This call does not support the **Or** logical operation functionality. Also, you can perform a **Not** of an individual criteria, but cannot perform a **Not** of a search result.

| Search Property | Search Operator | Value |
| --- | --- | --- |
| **gpoPermissions** | opContains<br><br>opNotContains | GPMPermission |
| **gpoEffectivePermissions** | opContains<br><br>opNotContains | GPMPermission |
| **gpoID** | opEquals<br><br>opNotEquals | **GUID** |
| **somLinks** | opContains | GPMGPO |
| **gpoDomain** | opEquals | GPMDomain |
| **backupMostRecent** | opEquals | TRUE |
| **gpoWMIFilter** | opEquals | GPMWMIFilter |
| **backupDomain** | opEquals | String containing the domain name |
| **gpoComputerExtensions** | opContains<br><br>opNotContains | **GUID** |
| **gpoUserExtensions** | opContains<br><br>opNotContains | **GUID** |
| **gpoDisplayName** | opEquals<br><br>opContains<br><br>opNotContains | User-friendly GPO display name. |
| **starterGPOPermissions** | opContains<br><br>opNotContains | GPMPermission |
| **starterGPOEffectivePermissions** | opContains<br><br>opNotContains | GPMPermission |
| **starterGPODisplayName** | opEquals<br><br>opContains<br><br>opNotContains | User-friendly Starter GPO display name. |
| **starterGPOID** | opEquals<br><br>opNotEquals | **GUID** |
| **starterGPODomain** | opEquals | GPMDomain |

## See also

[IGPM](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpm)

[IGPMDomain](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmdomain)

[IGPMSearchCriteria](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsearchcriteria)