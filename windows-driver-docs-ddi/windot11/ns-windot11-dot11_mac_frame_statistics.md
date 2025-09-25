# DOT11_MAC_FRAME_STATISTICS structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_MAC_FRAME_STATISTICS structure records statistical counters for the IEEE media access
control (MAC) sublayer of the 802.11 station.

## Members

### `ullTransmittedFrameCount`

The number of MAC service data unit (MSDU) packets and MAC management protocol data unit (MMPDU)
frames that the IEEE MAC sublayer of the 802.11 station successfully transmitted.

### `ullReceivedFrameCount`

The number of MSDU packets and MMPDU frames that the IEEE MAC sublayer of the 802.11 station
successfully received. This member should not be incremented for received packets that failed cipher
decryption or MIC validation.

### `ullTransmittedFailureFrameCount`

The number of MSDU packets and MMPDU frames that the IEEE MAC sublayer of the 802.11 station
failed to transmit successfully.

### `ullReceivedFailureFrameCount`

The number of MSDU packets and MMPDU frames that the IEEE MAC sublayer of the 802.11 station
failed to receive successfully.

### `ullWEPExcludedCount`

The number of unencrypted received MAC protocol data unit (MPDU) frames that the MAC sublayer
discarded when the IEEE 802.11
**dot11ExcludeUnencrypted** management information base (MIB) object is enabled. For more information
about this MIB object, see
[OID_DOT11_EXCLUDE_UNENCRYPTED](https://learn.microsoft.com/previous-versions/windows/embedded/gg159162(v=winembedded.80)).

MPDU frames are considered unencrypted when the Protected Frame subfield of the Frame Control field
in the IEEE 802.11 MAC header is set to zero.

### `ullTKIPLocalMICFailures`

The number of received MSDU packets that the 802.11 station discarded because of MIC
failures.

### `ullTKIPReplays`

The number of received MPDU frames that the 802.11 station discarded because of the TKIP replay
protection procedure.

### `ullTKIPICVErrorCount`

The number of encrypted MPDU frames that the 802.11 station failed to decrypt because of a TKIP
ICV error.

### `ullCCMPReplays`

The number of received MPDU frames that the 802.11 station discarded because of the AES-CCMP
replay protection procedure.

### `ullCCMPDecryptErrors`

The number of received MPDU frames that the 802.11 station discarded because of errors detected by
the AES-CCMP decryption algorithm.

### `ullWEPUndecryptableCount`

The number of encrypted MPDU frames received for which a WEP decryption key was not available on
the 802.11 station.

### `ullWEPICVErrorCount`

The number of encrypted MPDU frames that the 802.11 station failed to decrypt because of a WEP ICV
error.

### `ullDecryptSuccessCount`

The number of received encrypted packets that the 802.11 station successfully decrypted.

For the WEP and TKIP cipher algorithms, the miniport driver must increment this counter for each
received encrypted MPDU that was successfully decrypted. For the AES-CCMP cipher algorithm, the miniport
driver must increment this counter on each received encrypted MSDU packet that was successfully
decrypted.

### `ullDecryptFailureCount`

The number of encrypted packets that the 802.11 station failed to decrypt.

For the WEP and TKIP cipher algorithms, the miniport driver must increment this counter for each
received encrypted MPDU that was not successfully decrypted. For the AES-CCMP cipher algorithm, the
miniport driver must increment this counter on each received encrypted MSDU packet that was not
successfully decrypted.

The miniport driver must not increment this counter for packets that are decrypted successfully, but
are discarded for other reasons. For example, the miniport driver must not increment this counter for
packets discarded because of TKIP MIC failures or TKIP/CCMP replays.

## Syntax

```cpp
typedef struct DOT11_MAC_FRAME_STATISTICS {
  ULONGLONG ullTransmittedFrameCount;
  ULONGLONG ullReceivedFrameCount;
  ULONGLONG ullTransmittedFailureFrameCount;
  ULONGLONG ullReceivedFailureFrameCount;
  ULONGLONG ullWEPExcludedCount;
  ULONGLONG ullTKIPLocalMICFailures;
  ULONGLONG ullTKIPReplays;
  ULONGLONG ullTKIPICVErrorCount;
  ULONGLONG ullCCMPReplays;
  ULONGLONG ullCCMPDecryptErrors;
  ULONGLONG ullWEPUndecryptableCount;
  ULONGLONG ullWEPICVErrorCount;
  ULONGLONG ullDecryptSuccessCount;
  ULONGLONG ullDecryptFailureCount;
} DOT11_MAC_FRAME_STATISTICS, *PDOT11_MAC_FRAME_STATISTICS;
```

## Remarks

The members of the DOT11_MAC_STATISTICS structure are used to record MAC-level statistics for:

* 802.11 MSDU packets.
* 802.11 MMPDU frames.
* 802.11 MPDU frames. MPDU frame counters must include all MPDU fragments sent for an MSDU packet or
  MMPDU frame

## See also

[OID_DOT11_STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-statistics)

[Extensible Station MAC
Statistics](https://learn.microsoft.com/windows-hardware/drivers/network/extensible-station-mac-statistics)

[DOT11_STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_statistics)

[Native 802.11 Statistics](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-statistics)