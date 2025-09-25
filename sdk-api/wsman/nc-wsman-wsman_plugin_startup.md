# WSMAN_PLUGIN_STARTUP callback function

## Description

Defines the startup callback for the plug-in. Because multiple applications can be hosted in the same process, this method can be called multiple times, but only once for each application initialization. A plug-in can be initialized more than once within the same process but only once for each *applicationIdentification* value. The context that is returned from this method should be application specific. The returned context will be passed into all future plug-in calls that are specific to the application. All Windows Remote Management (WinRM) plug-ins must implement this callback function.

The DLL entry point name for this method must be **WSManPluginStartup**.

## Parameters

### `flags`

Reserved for future use. Must be zero.

### `applicationIdentification`

A unique identifier for the hosted application. For the main WinRM service, the default is **wsman**. For an Internet Information Services (IIS) host, this identifier is related to the application endpoint for that host. For example, **wsman/MyCompany/MyApplication**.

### `extraInfo`

A string that contains configuration information, if any information was stored when the plug-in was registered. When the plug-in is registered using the WinRM configuration, the plug-in can add extra configuration parameters that are useful during initialization to an optional node. This information can be especially useful if a plug-in is used in different IIS hosting scenarios and requires slightly different run-time semantics during initialization. This string is a copy of the XML from the configuration, if one is present. Otherwise, this parameter is set to **NULL**.

### `pluginContext`

The context for the specific application initialization. This context is passed through to all other WinRM plug-in calls that are associated with this *applicationIdentifier*.

## Return value

The method returns **NO_ERROR** if it succeeded; otherwise, it returns an error code. If this method returns an error, the [WSManPluginShutdown](https://learn.microsoft.com/windows/desktop/api/wsman/nc-wsman-wsman_plugin_shutdown) entry point will not be called.