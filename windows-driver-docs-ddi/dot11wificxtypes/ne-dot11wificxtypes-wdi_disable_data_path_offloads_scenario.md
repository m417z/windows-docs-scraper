## Description

The **WDI_DISABLE_DATA_PATH_OFFLOADS_SCENARIO** enumeration is used to instruct the OS to disable datapath offloads for this connection only.

## Constants

### `WDI_DISABLE_DATA_PATH_OFFLOADS_SCENARIO_NONE`

This is the default scenario and indicates that offloads should not be disabled.

### `WDI_DISABLE_DATA_PATH_OFFLOADS_SCENARIO_ENCRYPTION_CONNECTION`

Indicates that the IHV may need to perform encryption/decryption operations on packets in software instead of hardware and therefore can’t enable offloads.

### `WDI_DISABLE_DATA_PATH_OFFLOADS_SCENARIO_HARDWARE_ERROR`

Indicates that the IHV has encountered a hardware error that is preventing supported offloads from being enabled.

## Remarks

The **WDI_DISABLE_DATA_PATH_OFFLOADS_SCENARIO** enum is a value in the [**WDI_TLV_ASSOCIATION_RESULT_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-association-result-parameters) TLV.

## See also

[**WDI_TLV_ASSOCIATION_RESULT_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-association-result-parameters)