# DXGK_DSI_RESET structure

## Description

The **DXGK_DSI_RESET** structure is used with [**IOCTL_MIPI_DSI_RESET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_mipi_dsi_reset).

## Members

### `Flags`

Reserved. Must be set to zero.

### `MipiErrors`

A combination of the DXGK_DSI_* values indicating the errors reported by communication with the peripheral. Can be one or more of the following values.

| Error | Meaning |
| ----- | ------- |
| DXGK_DSI_SOT_ERROR | Possible error in Start of High-Speed transmission leader sequence |

| DXGK_DSI_SOT_SYNC_ERROR | Error in Start of High-Speed transmission leader sequence |

| DXGK_DSI_EOT_SYNC_ERROR | Peripheral detected incomplete bytes in High-Speed transmission |

| DXGK_DSI_ESCAPE_MODE_ENTRY_COMMAND_ERROR | Error or peripheral does not recognize escape sequence |

| DXGK_DSI_LOW_POWER_TRANSMIT_SYNC_ERROR | Peripheral detected incomplete bytes in Low-Speed transmission |

| DXGK_DSI_FALSE_CONTROL_ERROR | Peripheral detected error in escape sequence or turnaround sequence |

| DXGK_DSI_CONTENTION_DETECTED | Contention detected |

| DXGK_DSI_CHECKSUM_ERROR_CORRECTED | A checksum error was detected and corrected |

| DXGK_DSI_CHECKSUM_ERROR_NOT_CORRECTED | A checksum error was detected but could not be corrected |

| DXGK_DSI_LONG_PACKET_PAYLOAD_CHECKSUM_ERROR | The payload checksum was incorrect for a long packet |

| DXGK_DSI_DSI_DATA_TYPE_NOT_RECOGNIZED | Peripheral does not recognize the data type sent to it |

| DXGK_DSI_DSI_VC_ID_INVALID | Peripheral was sent a command for a virtual channel which it does not support |

| DXGK_DSI_INVALID_TRANSMISSION_LENGTH | Peripheral detected that number of bytes transmitted does not match what was specified in the header |

| DXGK_DSI_DSI_PROTOCOL_VIOLATION | Peripheral detected lack of EoTP on a transmission or host failed to signal bus turn-around for a read |

### `ResetFailed`

If set, the reset did not result in the panel returning to a working state.

### `NeedModeSet`

If set on return from calling the graphics driver, the OS must perform an unoptimized mode set to the device in order to complete the reset.

### `Results`

## Remarks

## See also

[**IOCTL_MIPI_DSI_QUERY_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_mipi_dsi_query_caps)

[**IOCTL_MIPI_DSI_RESET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_mipi_dsi_reset)

[**IOCTL_MIPI_DSI_TRANSMISSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_mipi_dsi_transmission)