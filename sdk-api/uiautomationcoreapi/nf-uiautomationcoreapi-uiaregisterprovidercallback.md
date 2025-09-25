# UiaRegisterProviderCallback function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Registers the application-defined method that is called by UI Automation
to obtain a provider for an element.

## Parameters

### `pCallback` [in]

Type: **[UiaProviderCallback](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/nc-uiautomationcoreapi-uiaprovidercallback)***

The address of the [UiaProviderCallback](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/nc-uiautomationcoreapi-uiaprovidercallback) callback function that returns the provider.