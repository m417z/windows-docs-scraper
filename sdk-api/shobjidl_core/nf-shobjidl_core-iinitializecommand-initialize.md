# IInitializeCommand::Initialize

## Description

Initialize objects that share an implementation of [IExplorerCommandState](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iexplorercommandstate), [IExecuteCommand](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iexecutecommand) or [IDropTarget](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idroptarget) with the application-specified command name and its registered properties.

## Parameters

### `pszCommandName` [in]

Type: **LPCWSTR**

Pointer to a string that contains the command name (the name of the command key as found in the registry). For instance, if the command is registered under **...**\**shell**\**MyCommand**, *pszCommandName* points to "MyCommand".

### `ppb` [in]

Type: **[IPropertyBag](https://learn.microsoft.com/windows/win32/api/oaidl/nn-oaidl-ipropertybag)***

Pointer to an [IPropertyBag](https://learn.microsoft.com/windows/win32/api/oaidl/nn-oaidl-ipropertybag) instance that can be used to read the properties related to the command in the registry. For example, a command may registry a string property under its **...**\**shell**\**MyCommand** subkey.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.