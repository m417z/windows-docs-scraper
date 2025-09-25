## Description

Describes a level of network connectivity, the usage charge for a network connection, and other members reflecting cost factors.

The last four members of **NL_NETWORK_CONNECTIVITY_HINT** collectively work together to allow you to resolve the cost of using a connection. See the guidelines in
[How to manage metered network cost constraints](https://learn.microsoft.com/previous-versions/windows/apps/jj835821(v=win.10)).

## Members

### `ConnectivityLevel`

Type: **[NL_NETWORK_CONNECTIVITY_LEVEL_HINT](https://learn.microsoft.com/windows/win32/api/nldef/ne-nldef-nl_network_connectivity_level_hint)**

The level of network connectivity.

### `ConnectivityCost`

Type: **[NL_NETWORK_CONNECTIVITY_COST_HINT](https://learn.microsoft.com/windows/win32/api/nldef/ne-nldef-nl_network_connectivity_cost_hint)**

The usage charge for the network connection.

### `ApproachingDataLimit`

Type: **[BOOLEAN](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

`TRUE` if the connection is approaching its data limit, otherwise `FALSE`.

### `OverDataLimit`

Type: **[BOOLEAN](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

`TRUE` if the connection has exceeded its data limit, otherwise `FALSE`.

### `Roaming`

Type: **[BOOLEAN](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

`TRUE` if the connection is roaming, otherwise `FALSE`.

## Remarks

## See also

[How to manage metered network cost constraints](https://learn.microsoft.com/previous-versions/windows/apps/jj835821(v=win.10))