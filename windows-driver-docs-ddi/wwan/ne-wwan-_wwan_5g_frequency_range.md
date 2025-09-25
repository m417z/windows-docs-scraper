# _WWAN_5G_FREQUENCY_RANGE enumeration

## Description

The **WWAN_5G_FREQUENCY_RANGE** enumeration specifies the frequency ranges that the device is using for 5G.

## Constants

### `Wwan5GFrequencyRangeUnknown`

Indicates that the system type is not 5G.

### `Wwan5GFrequencyRange1`

Indicates Frequency range 1 (FR1) in [3GPP TS 38.101-1](https://portal.3gpp.org/desktopmodules/Specifications/SpecificationDetails.aspx?specificationId=3283) (Sub-6G).

### `Wwan5GFrequencyRange2`

Indicates FR2 in [3GPP TS 38.101-2](https://portal.3gpp.org/desktopmodules/Specifications/SpecificationDetails.aspx?specificationId=3284) (mmWave).

### `Wwan5GFrequencyRange1AndRange2`

Indicates that both FR1 and FR2 carriers are connected.

## Remarks

This enumeration is used in the [**WWAN_PACKET_SERVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_packet_service) structure.

## See also

[MB 5G data class support](https://learn.microsoft.com/windows-hardware/drivers/network/mb-5g-data-class-support)

[OID_WWAN_SAR_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-packet-service)

[**WWAN_PACKET_SERVICE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_packet_service)