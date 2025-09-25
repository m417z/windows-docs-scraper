# WSD_CONFIG_PARAM structure

## Description

Represents configuration parameters for creating `WSDAPI` objects.

## Members

### `configParamType`

A [WSD_CONFIG_PARAM_TYPE](https://learn.microsoft.com/windows/win32/api/wsdbase/ne-wsdbase-wsd_config_param_type) value that indicates the type configuration data contained in this structure.

### `pConfigData`

A pointer to a single configuration data structure. The *configParamType* member specifies the type of data passed in.

### `dwConfigDataSize`

The size of the configuration data in *pConfigData*.