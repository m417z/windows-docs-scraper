# WBEM_REFRESHER_FLAGS enumeration

## Description

Contains flags that modify the behavior of refresher methods.

## Constants

### `WBEM_FLAG_REFRESH_AUTO_RECONNECT:0`

If the connection is broken, the refresher attempts to reconnect to the provider automatically.

### `WBEM_FLAG_REFRESH_NO_AUTO_RECONNECT:1`

If the connection is broken, the refresher does not attempt to reconnect to the provider automatically.

## See also

[IWbemConfigureRefresher::Remove](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemconfigurerefresher-remove)

[IWbemRefresher::Refresh](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemrefresher-refresh)