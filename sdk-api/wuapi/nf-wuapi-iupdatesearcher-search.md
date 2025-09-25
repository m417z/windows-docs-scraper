# IUpdateSearcher::Search

## Description

Performs a synchronous search for updates. The search uses the search options that are currently configured.

## Parameters

### `criteria` [in]

A string that specifies the search criteria.

### `retval` [out]

An [ISearchResult](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-isearchresult) interface that contains the following:

* The result of an operation
* A collection of updates that match the search criteria

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

This method can also return the following error codes.

| Return code | Description |
| --- | --- |
| **WU_E_LEGACYSERVER** | You cannot search for updates if the [ServerSelection](https://learn.microsoft.com/openspecs/windows_protocols/ms-uamg/07e2bfa4-6795-4189-b007-cc50b476181a) property of the [IUpdateSearcher](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesearcher) interface is set to [ssManagedServer](https://github.com/MicrosoftDocs/sdk-api/blob/docs/sdk-api-src/content/wuapicommon/ne-wuapicommon-serverselection.md) or [ssDefault](https://github.com/MicrosoftDocs/sdk-api/blob/docs/sdk-api-src/content/wuapicommon/ne-wuapicommon-serverselection.md), and the managed server on a computer is a Microsoft Software Update Services (SUS) 1.0 server. |
| **E_POINTER** | A parameter value is invalid or **NULL**. |
| **WU_E_INVALID_CRITERIA** | There is an invalid search criteria. |

## Remarks

The string that is used for the *criteria* parameter must match the custom search language for the **Search** method. The string consists of criteria that are evaluated to determine the updates to return.

Each criterion specifies an update property name and value. With some restrictions, multiple criteria can be connected with the **AND** and **OR** operators. The **=** (equal) and **!=** (not-equal) operators are both supported. When you use Windows Update Agent (WUA), the **!=** (not-equal) operator can be used only with the type criterion.

The search criteria syntax is based on the WHERE clause of an SQL query expression. Most of the supported criteria map directly to update properties. These update properties resemble the elements in a virtual XML document that contains the entire server catalog. For example, if you specify a search criteria string of "AutoSelectOnWebSites = 1", the search returns all the updates that have a AutoSelectOnWebSites property with a value of **VARIANT_TRUE**.

A single criterion consists of "*Name* = *Value*" or "*Name* != *Value*", where "*Name*" is one of the supported criterion names, and "*Value*" is a string or an integer. The **AND** and **OR** operators can be used to connect multiple criteria. However, **OR** can be used only at the top level of the search criteria. Therefore, "(x=1 and y=1) or (z=1)" is valid, but "(x=1) and (y=1 or z=1)" is not valid.

The supported value types are integers and strings. An integer must be specified in base 10, and negative numbers are prefixed with a minus sign (**-**). A string must be escaped and enclosed in single quotation marks ('). All string comparisons are case-insensitive unless specified.

The following table identifies all the public support criteria in the order of evaluation precedence. More criteria may be added to this list in the future.

| Criterion | Type | Allowed operators | Description |
| --- | --- | --- | --- |
| Type | **string** | **=**, **!=** | Finds updates of a specific type, such as "'Driver'" and "'Software'". |
| DeploymentAction | **string** | **=** | Finds updates that are deployed for a specific action, such as an installation or uninstallation that the administrator of a server specifies.<br><br>"DeploymentAction='Installation'" finds updates that are deployed for installation on a destination computer. "DeploymentAction='Uninstallation'" depends on the other query criteria.<br><br>"DeploymentAction='Uninstallation'" finds updates that are deployed for uninstallation on a destination computer. "DeploymentAction='Uninstallation'" depends on the other query criteria.<br><br>If this criterion is not explicitly specified, each group of criteria that is joined to an **AND** operator implies "DeploymentAction='Installation'". |
| IsAssigned | **int(bool)** | **=** | Finds updates that are intended for deployment by Automatic Updates.<br><br>"IsAssigned=1" finds updates that are intended for deployment by Automatic Updates, which depends on the other query criteria. At most, one assigned Windows-based driver update is returned for each local device on a destination computer.<br><br>"IsAssigned=0" finds updates that are not intended to be deployed by Automatic Updates. |
| BrowseOnly | **int(bool)** | **=** | "BrowseOnly=1" finds updates that are considered optional.<br><br>"BrowseOnly=0" finds updates that are not considered optional. |
| AutoSelectOnWebSites | **int(bool)** | **=** | Finds updates where the [AutoSelectOnWebSites](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdate-get_autoselectonwebsites) property has the specified value.<br><br>"AutoSelectOnWebSites=1" finds updates that are flagged to be automatically selected by Windows Update.<br><br>"AutoSelectOnWebSites=0" finds updates that are not flagged for Automatic Updates. |
| UpdateID | **string(UUID)** | **=**, **!=** | Finds updates for which the value of the [UpdateIdentity.UpdateID](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateidentity-get_updateid) property matches the specified value. Can be used with the **!=** operator to find all the updates that do not have an **UpdateIdentity.UpdateID** of the specified value.<br><br>For example, "UpdateID='12345678-9abc-def0-1234-56789abcdef0'" finds updates for [UpdateIdentity.UpdateID](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateidentity-get_updateid) that equal 12345678-9abc-def0-1234-56789abcdef0.<br><br>For example, "UpdateID!='12345678-9abc-def0-1234-56789abcdef0'" finds updates for [UpdateIdentity.UpdateID](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateidentity-get_updateid) that are not equal to 12345678-9abc-def0-1234-56789abcdef0.<br><br>**Note** A RevisionNumber clause can be combined with an UpdateID clause that contains an **=** (equal) operator. However, the RevisionNumber clause cannot be combined with an UpdateID clause that contains the **!=** (not-equal) operator.<br><br> For example, "UpdateID='12345678-9abc-def0-1234-56789abcdef0' and RevisionNumber=100" can be used to find the update for [UpdateIdentity.UpdateID](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateidentity-get_updateid) that equals 12345678-9abc-def0-1234-56789abcdef0 and whose [UpdateIdentity.RevisionNumber](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateidentity-get_revisionnumber) equals 100. |
| RevisionNumber | **int** | **=** | Finds updates for which the value of the [UpdateIdentity.RevisionNumber](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateidentity-get_revisionnumber) property matches the specified value.<br><br>For example, "RevisionNumber=2" finds updates where [UpdateIdentity.RevisionNumber](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateidentity-get_revisionnumber) equals 2.<br><br>This criterion must be combined with the UpdateID property. |
| CategoryIDs | **string(uuid)** | **contains** | Finds updates that belong to a specified category. |
| IsInstalled | **int(bool)** | **=** | Finds updates that are [installed](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdate-get_isinstalled) on the destination computer.<br><br>"IsInstalled=1" finds updates that are installed on the destination computer.<br><br>"IsInstalled=0" finds updates that are not installed on the destination computer. |
| IsHidden | **int(bool)** | **=** | Finds updates that are marked as [hidden](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdate-get_ishidden) on the destination computer.<br><br>"IsHidden=1" finds updates that are marked as hidden on a destination computer. When you use this clause, you can set the [UpdateSearcher.IncludePotentiallySupersededUpdates](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatesearcher-get_includepotentiallysupersededupdates) property to **VARIANT_TRUE** so that a search returns the hidden updates. The hidden updates might be superseded by other updates in the same results.<br><br>"IsHidden=0" finds updates that are not marked as hidden. If the [UpdateSearcher.IncludePotentiallySupersededUpdates](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatesearcher-get_includepotentiallysupersededupdates) property is set to **VARIANT_FALSE**, it is better to include that clause in the search filter string so that the updates that are superseded by hidden updates are included in the search results. **VARIANT_FALSE** is the default value. |
| IsPresent | **int(bool)** | **=** | When set to 1, finds updates that are present on a computer.<br><br>"IsPresent=1" finds updates that are present on a destination computer. If the update is valid for one or more products, the update is considered present if it is installed for one or more of the products.<br><br>"IsPresent=0" finds updates that are not installed for any product on a destination computer. |
| RebootRequired | **int(bool)** | **=** | Finds updates that require a computer to be restarted to complete an installation or uninstallation.<br><br>"RebootRequired=1" finds updates that require a computer to be restarted to complete an installation or uninstallation.<br><br>"RebootRequired=0" finds updates that do not require a computer to be restarted to complete an installation or uninstallation. |

The default search criteria for a search are as follows:

``` syntax
( IsInstalled = 0 and IsHidden = 0 )
```

To find all the hidden updates (by using the [UpdateSearcher.IncludePotentiallySupersededUpdates](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatesearcher-get_includepotentiallysupersededupdates) property set to **VARIANT_TRUE**), use the following criterion:

``` syntax
 ( IsHidden = 1 )
```

## See also

[IUpdateSearcher](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesearcher)