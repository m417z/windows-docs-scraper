# WCM_CONNECTION_COST_DATA structure

## Description

The **WCM_CONNECTION_COST_DATA** structure specifies information about a connection cost.

## Members

### `ConnectionCost`

Type: **DWORD**

Specifies the connection cost type.

This must include one (and only one) of the following flags:

| Value | Meaning |
| --- | --- |
| **WCM_CONNECTION_COST_UNKNOWN**<br><br>0x0 | Connection cost information is not available. |
| **WCM_CONNECTION_COST_UNRESTRICTED**<br><br>0x1 | The connection is unlimited and has unrestricted usage constraints. |
| **WCM_CONNECTION_COST_FIXED**<br><br>0x2 | Usage counts toward a fixed allotment of data which the user has already paid for (or agreed to pay for). |
| **WCM_CONNECTION_COST_VARIABLE**<br><br>0x4 | The connection cost is on a per-byte basis. |

And may include any combination of the following flags:

| Value | Meaning |
| --- | --- |
| **WCM_CONNECTION_COST_OVERDATALIMIT**<br><br>0x10000 | The connection has exceeded its data limit. |
| **WCM_CONNECTION_COST_CONGESTED**<br><br>0x20000 | The connection is throttled due to high traffic. |
| **WCM_CONNECTION_COST_ROAMING**<br><br>0x40000 | The connection is outside of the home network. |

### `CostSource`

Type: **[WCM_CONNECTION_COST_SOURCE](https://learn.microsoft.com/windows/desktop/api/wcmapi/ne-wcmapi-wcm_connection_cost_source)**

Specifies the cost source.

## See also

[WCM_CONNECTION_COST_SOURCE](https://learn.microsoft.com/windows/desktop/api/wcmapi/ne-wcmapi-wcm_connection_cost_source)