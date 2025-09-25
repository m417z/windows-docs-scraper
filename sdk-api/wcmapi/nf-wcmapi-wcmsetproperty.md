# WcmSetProperty function

## Description

The **WcmSetProperty** function sets the value of a WCM property.

## Parameters

### `pInterface` [in, optional]

Type: **const GUID***

The interface to set. For global properties, this parameter is NULL.

### `strProfileName` [in, optional]

Type: **LPCWSTR**

The profile name.

### `Property` [in]

Type: **[WCM_PROPERTY](https://learn.microsoft.com/windows/desktop/api/wcmapi/ne-wcmapi-wcm_property)**

The WCM property to set.

### `pReserved`

Type: **PVOID**

Reserved.

### `dwDataSize` [in]

Type: **DWORD**

The size of the new property value.

### `pbData` [in, optional]

Type: **const BYTE***

The new property value.

## Return value

Type: **DWORD**

Returns ERROR_SUCCESS if successful, or an error value otherwise.

## Remarks

The type of data stored in the *pbData* parameter will vary, depending on which property is being set. This table shows the data type of each property.

| Property name | Data type |
| --- | --- |
| wcm_global_property_domain_policy | [WCM_POLICY_VALUE](https://learn.microsoft.com/windows/desktop/api/wcmapi/ns-wcmapi-wcm_policy_value) |
| wcm_global_property_minimize_policy | [WCM_POLICY_VALUE](https://learn.microsoft.com/windows/desktop/api/wcmapi/ns-wcmapi-wcm_policy_value) |
| wcm_global_property_roaming_policy | [WCM_POLICY_VALUE](https://learn.microsoft.com/windows/desktop/api/wcmapi/ns-wcmapi-wcm_policy_value) |
| wcm_global_property_powermanagement_policy | [WCM_POLICY_VALUE](https://learn.microsoft.com/windows/desktop/api/wcmapi/ns-wcmapi-wcm_policy_value) |
| wcm_intf_property_connection_cost | [WCM_CONNECTION_COST_DATA](https://learn.microsoft.com/windows/desktop/api/wcmapi/ns-wcmapi-wcm_connection_cost_data) |
| wcm_intf_property_dataplan_status | [WCM_DATAPLAN_STATUS](https://learn.microsoft.com/windows/desktop/api/wcmapi/ns-wcmapi-wcm_dataplan_status) |
| wcm_intf_property_hotspot_profile | Variable-length XML string. See the [HotSpotProfile schema](https://learn.microsoft.com/uwp/schemas/mobilebroadbandschema/hotspotprofile/schema-root) for more information. |

## See also

[HotSpotProfile schema](https://learn.microsoft.com/uwp/schemas/mobilebroadbandschema/hotspotprofile/schema-root)

[WCM_PROPERTY](https://learn.microsoft.com/windows/desktop/api/wcmapi/ne-wcmapi-wcm_property)