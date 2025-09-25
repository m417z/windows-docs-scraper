# _WWAN_GET_VISIBLE_PROVIDERS structure

## Description

The WWAN_GET_VISIBLE_PROVIDERS structure provides information about the type of visible providers to return.

## Members

### `Action`

Provides information about the type of visible providers to return. The following values are defined:

|  |  |
| --- | --- |
| **Value** | **Meaning** |
| WWAN_GET_VISIBLE_PROVIDERS_ALL | All providers that are currently visible should be returned. |
| WWAN_GET_VISIBLE_PROVIDERS_MULTICARRIER | Only providers that are currently visible and that can be set as home provider should be returned. |

## See also

[NDIS_WWAN_GET_VISIBLE_PROVIDERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_get_visible_providers)