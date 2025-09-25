## Description

Defines constants that specify hints about a level of network connectivity.

## Constants

### `NetworkConnectivityLevelHintUnknown:0`

Specifies a hint for an unknown level of connectivity. There is a short window of time during Windows (or application container) boot when this value might be returned.

### `NetworkConnectivityLevelHintNone`

Specifies a hint for no connectivity.

### `NetworkConnectivityLevelHintLocalAccess`

Specifies a hint for local network access only.

### `NetworkConnectivityLevelHintInternetAccess`

Specifies a hint for local and internet access.

### `NetworkConnectivityLevelHintConstrainedInternetAccess`

Specifies a hint for limited internet access.

This value indicates captive portal connectivity, where local access to a web portal is provided, but access to the internet requires that specific credentials are provided via the portal. This level of connectivity is generally encountered when using connections hosted in public locations (for example, coffee shops and book stores).

This doesn't guarantee detection of a captive portal. You should be aware that when Windows reports the connectivity level hint as **NetworkConnectivityLevelHintLocalAccess**, your application's network requests might be redirected, and thus receive a different response than expected. Other protocols might also be impacted; for example, HTTPS might be redirected, and fail authentication.

### `NetworkConnectivityLevelHintHidden`

Specifies a hint for a network interface that's hidden from normal connectivity (and is not, by default, accessible to applications). This could be because no packets are allowed at all over that network (for example, the adapter flags itself **NCF_HIDDEN**), or (by default) routes are ignored on that interface (for example, a cellular network is hidden when WiFi is connected).

## Remarks

## See also