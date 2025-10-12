# _NFC_CX_RF_DISCOVERY_CONFIG structure

## Description

The **NFC_CX_RF_DISCOVERY_CONFIG** structure contains RF discovery configuration settings. Discovery configuration should be completed during initialization after calling [NfcCxDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfccx/nf-nfccx-nfccxdeviceinitialize), otherwise an error is returned.

## Members

### `Size`

 Size of this structure in bytes.

### `TotalDuration`

 Total duration of the single discovery period in milliseconds. Default is 300 milliseconds.

This member corresponds to TOTAL_DURATION specified in the NCI specification. Values can be between 0 to 0xFFFF. Use an appropriate value that factors into account both the discovery latency as well as power consumption.

### `PollConfig`

Combination of [NFC_CX_POLL_MODE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfccx/ne-nfccx-_nfc_cx_poll_mode_config) values.

This member enables configuration of poll mode settings. The default enables polling for passive poll NFC-A, passive poll NFC-B, and passive poll NFC-F (212 and 424k). Its recommended that NFC clients configure additional active modes if they are supported.

### `NfcIPMode`

 Combination of [NFC_CX_NFCIP_MODE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfccx/ne-nfccx-_nfc_cx_nfcip_mode_config) values.

This member enables configuration of NFC-IP initiator mode settings. The value corresponds to combination of NFC_CX_NFCIP_MODE_CONFIG enum. The default enables polling for passive poll NFC-A and passive poll NFC-F (212 and 424k) phases.

### `NfcIPTgtMode`

 Combination of [NFC_CX_NFCIP_TGT_MODE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfccx/ne-nfccx-_nfc_cx_nfcip_tgt_mode_config) values.

This member enables configuration of NFC-IP target mode settings. The default enables passive listen NFC-A and passive listen NFC-F phases.

### `NfcCEMode`

 Combination of [NFC_CX_CE_MODE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfccx/ne-nfccx-_nfc_cx_ce_mode_config) values.

This member enables configuration of NFC-CE mode settings. The default enables passive listen NFC-A, passive listen NFC-B, and passive listen NFC-F phases.

### `BailoutConfig`

Combination of [NFC_CX_POLL_BAILOUT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfccx/ne-nfccx-_nfc_cx_poll_bailout_config) values. Default is disabled.

This member enables configuration of PA_BAIL_OUT and PB_BAIL_OUT as described in the NCI specification.

## See also

[NFC class extension design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/nfc-class-extension-)

[Near field communication (NFC) design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/)