# _DXGK_DIAGTYPE_NOTIFICATIONS structure

## Description

A structure used to identify one or more diagnostic types in the Notifications category.

## Members

### `PanelSelfRefreshSoftware`

Indicates a diagnostic reported by the driver when the driver expects that panel self-refresh is being enabled or disabled. This should be a light-weight diagnostic, so reported in the NoninvasiveTypes in a call to DxgkDdiQueryDiagnosticTypesSupported, which would be sent during a DDI call from the OS which causes the state to change or in a normal code path where the state change would naturally be acted upon.

### `PanelSelfRefreshHardware`

Indicates a diagnostic reported by the driver when the driver receives a notification from the hardware or when the driver queries hardware to find that panel self-refresh has been enabled or disabled. This diagnostic is intended to be used for detailed investigation so accuracy in the reporting of PSR state changes is more important that efficiency however if hardware supports efficient notification, that is ideal.

### `Reserved`

Reserved.

### `Value`

The value of the notification.