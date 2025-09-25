# HTTP_QOS_SETTING_TYPE enumeration

## Description

The **HTTP_QOS_SETTING_TYPE** enumeration identifies the type of a QOS setting contained in a [HTTP_QOS_SETTING_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_qos_setting_info) structure.

## Constants

### `HttpQosSettingTypeBandwidth`

The setting is a bandwidth limit represented by a [HTTP_BANDWIDTH_LIMIT_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_bandwidth_limit_info) structure.

### `HttpQosSettingTypeConnectionLimit`

The setting is a connection limit represented by a [HTTP_CONNECTION_LIMIT_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_connection_limit_info) structure.

### `HttpQosSettingTypeFlowRate`

A flow rate represented by [HTTP_FLOWRATE_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_flowrate_info).

**Note** Windows Server 2008 R2 and Windows 7 only.

## See also

[HTTP_QOS_SETTING_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_qos_setting_info)