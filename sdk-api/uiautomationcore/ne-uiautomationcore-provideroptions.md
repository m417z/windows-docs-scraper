# ProviderOptions enumeration

## Description

Contains values that specify the type of UI Automation provider. The [IRawElementProviderSimple::ProviderOptions](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nf-uiautomationcore-irawelementprovidersimple-get_provideroptions) property uses this enumeration.

## Constants

### `ProviderOptions_ClientSideProvider:0x1`

The provider is a client-side (proxy) provider.

### `ProviderOptions_ServerSideProvider:0x2`

The provider is a server-side provider.

### `ProviderOptions_NonClientAreaProvider:0x4`

The provider is a non-client-area provider.

### `ProviderOptions_OverrideProvider:0x8`

The provider overrides another provider.

### `ProviderOptions_ProviderOwnsSetFocus:0x10`

The provider handles its own focus, and does not want UI Automation to set focus to the nearest window on its behalf. This option is typically used by providers for windows that appear to take focus without actually receiving Win32 focus, such as menus and drop-downs.

### `ProviderOptions_UseComThreading:0x20`

The provider has explicit support for COM threading models, so that calls by UI Automation on COM-based providers are received on the appropriate thread. This means that STA-based provider implementations will be called back on their own STA thread, and therefore do not need extra synchronization to safely access resources that belong to that STA. MTA-based provider implementations will be called back on some other thread in the MTA, and will require appropriate synchronization to be added, as is usual for MTA code.

### `ProviderOptions_RefuseNonClientSupport:0x40`

The provider handles its own non-client area and does not want UI Automation to provide default accessibility support for controls in the non-client area, such as minimize/maximize buttons and menu bars.

### `ProviderOptions_HasNativeIAccessible:0x80`

The provider implements the [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) interface.

### `ProviderOptions_UseClientCoordinates:0x100`

The provider works in client coordinates instead of screen coordinates.

## See also

[SetFocus](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nf-uiautomationcore-irawelementproviderfragment-setfocus)