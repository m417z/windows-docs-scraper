# TSPUB_PLUGIN_PD_RESOLUTION_TYPE enumeration

## Description

Specifies the type of personal desktop resolution being requested.

## Constants

### `TSPUB_PLUGIN_PD_QUERY_OR_CREATE:0`

Resolve an existing personal desktop for the user. If no personal desktop exists, the [ResolvePersonalDesktop](https://learn.microsoft.com/windows/desktop/api/tspubplugin2com/nf-tspubplugin2com-itspubplugin2-resolvepersonaldesktop) method should create a new one.

### `TSPUB_PLUGIN_PD_QUERY_EXISTING:1`

Resolve an existing personal desktop for the user. If no personal desktop exists, the [ResolvePersonalDesktop](https://learn.microsoft.com/windows/desktop/api/tspubplugin2com/nf-tspubplugin2com-itspubplugin2-resolvepersonaldesktop) method should return an error code.

## See also

[ResolvePersonalDesktop](https://learn.microsoft.com/windows/desktop/api/tspubplugin2com/nf-tspubplugin2com-itspubplugin2-resolvepersonaldesktop)