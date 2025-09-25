# IMbnSignal::GetSignalStrength

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets the signal strength received by the device.

## Parameters

### `signalStrength` [out, retval]

Pointer to the signal quality received by the device. When the signal strength is not known or it is not detectable by the device then this is set to **MBN_RSSI_UNKNOWN**.
If this method returns any value other than S_OK, this parameter is 0.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_PENDING** | The signal quality is not available. The Mobile Broadband service is currently probing the device to retrieve this information. When the signal quality is available, the Mobile Broadband service will call the [OnSignalStateChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnsignalevents-onsignalstatechange) method of [IMbnSignalEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsignalevents). |

## Remarks

**GetSignalStrength** reports signal strength received by the Mobile Broadband device. For GSM based devices it reports signal strength as signal strength received in a coded value. For CDMA devices it reports based on the Compensated RSSI (accounts for noise) and not based on Raw RSSI.

The following table contains the coded values that may be returned.

| Signal Strength (in dBm) | Coded Value (Min: 0 Max: 31) |
| --- | --- |
| -113 or less | 0 |
| -111 | 1 |
| -109 | 2 |
| ... | ... |
| ... | ... |
| -51 or greater | 31 |
| Unknown or undetectable | **MBN_RSSI_UNKNOWN** |

For recoverable errors **E_MBN_PIN_REQUIRED**, and **E_MBN_RADIO_POWER_OFF**, the Mobile Broadband service will query the device again for signal state when the error condition is over. This method will return E_PENDING until the query operation is complete. When the new query is complete, the Mobile Broadband service will call the [OnSignalStateChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnsignalevents-onsignalstatechange) method of [IMbnSignalEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsignalevents).

## See also

[IMbnSignal](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsignal)