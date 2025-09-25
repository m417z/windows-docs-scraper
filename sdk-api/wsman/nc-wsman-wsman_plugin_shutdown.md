# WSMAN_PLUGIN_SHUTDOWN callback function

## Description

Defines the shutdown callback for the plug-in. This function is called after all operations have been canceled and before the Windows Remote Management plug-in DLL is unloaded. All WinRM plug-ins must implement this callback function.

The DLL entry point name must be **WSManPluginShutdown**.

## Parameters

### `pluginContext`

Specifies the context that was returned by a call to the [WSManPluginStartup](https://learn.microsoft.com/windows/desktop/api/wsman/nc-wsman-wsman_plugin_startup) method. This parameter represents a specific application initialization of a WinRM plug-in. The shutdown entry point will be called for each application that initialized it.

### `flags`

Reserved for future use. Must be set to zero.

### `reason`

Specifies the reason that the plug-in is shutting down.

#### WSMAN_PLUGIN_SHUTDOWN_SYSTEM

The system shut down.

#### WSMAN_PLUGIN_SHUTDOWN_SERVICE

The WinRM service shut down.

#### WSMAN_PLUGIN_SHUTDOWN_IISHOST

The IIS host shut down.

## Return value

The method returns **NO_ERROR** if it succeeded; otherwise, it returns an error code.

**Note** If this method fails, the plug-in will not call back in.

## Remarks

Each successful call to [WSManPluginStartup](https://learn.microsoft.com/windows/desktop/api/wsman/nc-wsman-wsman_plugin_startup) will result in a call to this function before the WinRM plug-in DLL is unloaded. It is important to ensure that the WinRM plug-in tracks the number of times that this startup entry point is called so that the plug-in is not shut down prematurely.

This function must ensure that all plug-in threads are shut down before it returns. If the plug-in handles only synchronous operations and all threads report a cancellation result before they return, this function performs only plug-in cleanup. However, for an asynchronous plug-in, any threads that are used to process the plug-in threads, including the ones that just reported the cancellation for all operations, need to be completely shut down. If all of the threads are not shut down, crashes in the DLL might occur because code might be executed after the DLL is unloaded.