# _WWAN_UMTS_SERVING_CELL_INFO structure

## Description

The **WWAN_UMTS_SERVING_CELL_INFO** structure represents information about the UMTS serving cell.

## Members

### `ProviderIdOffset`

The offset in bytes, calculated from the beginning of this structure, to a numeric (0-9) string called *ProviderId* that represents the network provider identity. This string is a concatenation of a three-digit Mobile Country Code (MCC) and a two or three-digit Mobile Network Code (MNC). This member can be NULL when no *ProviderId* information is returned.

### `ProviderIdSize`

The size, in bytes, used for *ProviderId*.

### `LocationAreaCode`

The Location Area Code (0-65535). Use 0xFFFFFFFF when this information is not available.

### `CellId`

The Cell ID (0-268435455). Use 0xFFFFFFFF when this information is not available.

### `FrequencyInfoUL`

The Frequency Info Uplink (0-16383). Use 0xFFFFFFFF when this information is not available.

### `FrequencyInfoDL`

The Frequency Info Downlink (0-16383). Use 0xFFFFFFFF when this information is not available.

### `FrequencyInfoNT`

The Frequency Info for TDD (0-16383). Use 0xFFFFFFFF when this information is not available.

### `UARFCN`

The UTRA Absolute Radio Frequency Channel Number for the serving cell (0-16383). Use 0xFFFFFFFF when this information is not available.

### `PrimaryScramblingCode`

The Primary Scrambling Code of the serving cell (0-511). Use 0xFFFFFFFF when this information is not available.

### `RSCP`

The Received Signal Code Power of the serving cell. The range is -120 to -25, in units of 1dBm. Use 0xFFFFFFFF when this information is not available.

### `ECNO`

The signal to noise ratio of the serving cell; the ratio of the received energy per PN chip for the CPICH to the total received. The range is -50 to 0, in units of 1dBm. Use 1 when this information is not available.

### `PathLoss`

The path loss of the serving cell (46-173). Use 0xFFFFFFFF when this information is not available.

### `Data`

The data buffer containing *ProviderId*.

## See also

[MB base stations information query support](https://learn.microsoft.com/windows-hardware/drivers/network/mb-base-stations-information-query-support)

[WWAN_BASE_STATIONS_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_base_stations_info)

[WWAN_UMTS_MRL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_umts_mrl)

[WWAN_UMTS_MRL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_umts_mrl_info)