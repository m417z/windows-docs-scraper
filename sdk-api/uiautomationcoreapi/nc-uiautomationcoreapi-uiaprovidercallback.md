# UiaProviderCallback callback function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

An application-defined function that is called by UI Automation
to obtain a client-side provider for an element.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The handle of the window served by the provider.

### `providerType` [in]

Type: **[ProviderType](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ne-uiautomationcoreapi-providertype)**

A value from the [ProviderType](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ne-uiautomationcoreapi-providertype) enumerated type specifying the type of provider that is being requested.

## Return value

Type: **[SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray)**

A [SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray) containing the requested provider.