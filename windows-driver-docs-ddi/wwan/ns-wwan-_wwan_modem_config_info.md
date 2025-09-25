# _WWAN_MODEM_CONFIG_INFO structure

## Description

The **WWAN_MODEM_CONFIG_INFO** structure represents the modem's configuration information.

## Members

### `ConfigMode`

The modem's configuration mode. For a list of defined values, see [WWAN_MODEM_CONFIG_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_modem_config_mode).

### `ConfigState`

The modem's configuration state. For a list of defined values, see [**WWAN_MODEM_CONFIG_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_modem_config_state).

### `ConfigReason`

The reason for the modem's configuration state change. For a list of defined values, see [**WWAN_MODEM_CONFIG_REASON**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_modem_config_reason).

### `PreviousConfigID`

A formatted [**WWAN_MODEM_CONFIG_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_modem_config_id) structure that represents the modem's previous configuration ID.

### `CurrentConfigID`

A formatted [**WWAN_MODEM_CONFIG_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_modem_config_id) structure that represents the modem's current configuration ID.

### `IsCurrentConfigDefault`

A DWORD value that indicates if the current configuration is the default configuration.

### `ConfigName`

### `NSSAIListHeader`

A [**WWAN_LIST_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_list_header) object that represents a pre-configured Single Network Slice Selection Assistance Information (S-NSSAI).

## See also

[NDIS_STATUS_WWAN_MODEM_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-modem-config-info)

[NDIS_WWAN_MODEM_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_modem_config_info)

[OID_WWAN_MODEM_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-modem-config-info)

[WWAN_MODEM_CONFIG_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_modem_config_mode)

[WWAN_MODEM_CONFIG_STATUS](https://learn.microsoft.com/previous-versions/mt813894(v=vs.85))