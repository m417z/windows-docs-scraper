# WcmQueryProperty function

## Description

The **WcmQueryProperty** function retrieves the value of a specified WCM property.

## Parameters

### `pInterface` [in, optional]

Type: **const GUID***

The interface to query. For global properties, this parameter is NULL.

### `strProfileName` [in, optional]

Type: **LPCWSTR**

The name of the profile. If querying a non-global property (**connection_cost**, **dataplan_status**, or **hotspot_profile**), the profile must be specified or the call will fail.

### `Property` [in]

Type: **[WCM_PROPERTY](https://learn.microsoft.com/windows/desktop/api/wcmapi/ne-wcmapi-wcm_property)**

The WCM property to query.

### `pReserved`

Type: **PVOID**

Reserved.

### `pdwDataSize` [out]

Type: **PDWORD**

The size of the returned property value.

### `ppData` [out]

Type: **PBYTE***

The returned property value.

## Return value

Type: **DWORD**

Returns ERROR_SUCCESS if successful, or an error value otherwise.

## Remarks

The type of data stored in the *ppData* parameter will vary, depending on which property is being queried. This table shows the data type of each property.

| Property name | Data type |
| --- | --- |
| wcm_global_property_domain_policy | [WCM_POLICY_VALUE](https://learn.microsoft.com/windows/desktop/api/wcmapi/ns-wcmapi-wcm_policy_value) |
| wcm_global_property_minimize_policy | [WCM_POLICY_VALUE](https://learn.microsoft.com/windows/desktop/api/wcmapi/ns-wcmapi-wcm_policy_value) |
| wcm_global_property_roaming_policy | [WCM_POLICY_VALUE](https://learn.microsoft.com/windows/desktop/api/wcmapi/ns-wcmapi-wcm_policy_value) |
| wcm_global_property_powermanagement_policy | [WCM_POLICY_VALUE](https://learn.microsoft.com/windows/desktop/api/wcmapi/ns-wcmapi-wcm_policy_value) |
| wcm_intf_property_connection_cost | [WCM_CONNECTION_COST_DATA](https://learn.microsoft.com/windows/desktop/api/wcmapi/ns-wcmapi-wcm_connection_cost_data) |
| wcm_intf_property_dataplan_status | [WCM_DATAPLAN_STATUS](https://learn.microsoft.com/windows/desktop/api/wcmapi/ns-wcmapi-wcm_dataplan_status) |
| wcm_intf_property_hotspot_profile | Contains zero-length output. |

## See also

[WCM_PROPERTY](https://learn.microsoft.com/windows/desktop/api/wcmapi/ne-wcmapi-wcm_property)