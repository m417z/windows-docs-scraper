# _USBFN_BUS_CONFIGURATION_INFO structure

## Description

Configuration packet that stores information about
an available USB configuration.

## Members

### `ConfigurationName`

A NULL-terminated string that indicates the name of a configuration.

### `IsCurrent`

Indicates whether this configuration is the
current configuration.

### `IsActive`

 Indicates whether the configuration is active. This is a read-only information that is returned by USB function class extension (UFX) and is ignored in requests sent to UFX.