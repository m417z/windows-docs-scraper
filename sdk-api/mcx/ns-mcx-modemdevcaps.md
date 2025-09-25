# MODEMDEVCAPS structure

## Description

Contains information about the capabilities of a modem.

## Members

### `dwActualSize`

The size of the data actually returned to the application, in bytes. This member may be less than the **dwRequiredSize** member, if an application did not allocate enough space for the variable-length portion of the structure.

### `dwRequiredSize`

The number of bytes required for the entire
**MODEMDEVCAPS** structure, including the variable-length portion.

### `dwDevSpecificOffset`

The offset of the provider-defined portion of the structure, in bytes relative to the beginning of the structure.

### `dwDevSpecificSize`

The size of the provider-defined portion of the structure, in bytes.

### `dwModemProviderVersion`

The version of the service provider. The format and use of this member depends on the service provider.

### `dwModemManufacturerOffset`

The offset of a text string that contains the name of the modem manufacturer, in bytes relative to the beginning of the structure.

### `dwModemManufacturerSize`

The length of the modem manufacturer name, in bytes. The string is not null-terminated.

### `dwModemModelOffset`

The offset of a text string that contains the model of the modem, in bytes relative to the beginning of the structure.

### `dwModemModelSize`

The length of the model name, in bytes. The string is not null-terminated.

### `dwModemVersionOffset`

The offset of a text string that gives the version and revision of the attached modem, if the provider could determine the information. The offset is specified in bytes relative to the beginning of the structure.

### `dwModemVersionSize`

The length of the modem version string, in bytes. The string is not null-terminated.

### `dwDialOptions`

The dialing options supported by the modem device. This member can be zero or more of the following values.

| Value | Meaning |
| --- | --- |
| **DIALOPTION_BILLING**<br><br>0x00000040 | The modem supports waiting for billing tone (bong). |
| **DIALOPTION_DIALTONE**<br><br>0x00000100 | The modem supports waiting for a dial tone. |
| **DIALOPTION_QUIET**<br><br>0x00000080 | The modem supports waiting for quiet. |

### `dwCallSetupFailTimer`

The maximum call setup timeout supported by the modem, in seconds. This is the largest value that can be specified for the corresponding member of the
[MODEMSETTINGS](https://learn.microsoft.com/windows/desktop/api/mcx/ns-mcx-modemsettings) structure.

### `dwInactivityTimeout`

The maximum inactivity timeout supported by the modem, in tenths of seconds. This is the largest value that can be specified for the corresponding member of the
[MODEMSETTINGS](https://learn.microsoft.com/windows/desktop/api/mcx/ns-mcx-modemsettings) structure.

### `dwSpeakerVolume`

The speaker volume settings supported by the modem. This member can be zero or more of the following values.

| Value | Meaning |
| --- | --- |
| **MDMVOLFLAG_HIGH**<br><br>0x00000004 | The modem supports high (MDMVOL_HIGH) volume. |
| **MDMVOLFLAG_LOW**<br><br>0x00000001 | The modem supports low (MDMVOL_LOW) volume. |
| **MDMVOLFLAG_MEDIUM**<br><br>0x00000002 | The modem supports medium (MDMVOL_MEDIUM) volume. |

### `dwSpeakerMode`

The speaker mode settings supported by the modem. This member can be zero or more of the following values.

| Value | Meaning |
| --- | --- |
| **MDMSPKRFLAG_CALLSETUP**<br><br>0x00000008 | The modem supports the MDMSPKR_CALLSETUP speaker mode. |
| **MDMSPKRFLAG_DIAL**<br><br>0x00000002 | The modem supports the MDMSPKR_DIAL speaker mode. |
| **MDMSPKRFLAG_OFF**<br><br>0x00000001 | The modem supports the MDMSPKR_OFF speaker mode. |
| **MDMSPKRFLAG_ON**<br><br>0x00000004 | The modem supports the MDMSPKR_ON speaker mode. |

### `dwModemOptions`

The modem options. This member can be zero or more of the following values.

#### MDM_BLIND_DIAL (0x00000200)

#### MDM_CCITT_OVERRIDE (0x00000040)

#### MDM_CELLULAR (0x00000008)

#### MDM_COMPRESSION (0x00000001)

#### MDM_DIAGNOSTICS (0x000000800)

#### MDM_ERROR_CONTROL (0x00000002)

#### MDM_FLOWCONTROL_HARD (0x00000010)

#### MDM_FLOWCONTROL_SOFT (0x00000020)

#### MDM_FORCED_EC (0x00000004)

#### MDM_SPEED_ADJUST (0x00000080)

#### MDM_TONE_DIAL (0x00000100)

#### MDM_V23_OVERRIDE (0x00000400)

When
**MODEMDEVCAPS** is used to set modem options, as part of the
[MODEMSETTINGS](https://learn.microsoft.com/windows/desktop/api/mcx/ns-mcx-modemsettings) structure, these values are used as follows.

| Value | Meaning |
| --- | --- |
| **MDM_CCITT_OVERRIDE**<br><br>0x00000040 | When set, CCITT modulations are enabled for V.21 and V.22 or V.23. <br><br>When clear, bell modulations are enabled for 103 and 212A. |
| **MDM_V23_OVERRIDE**<br><br>0x00000400 | When set, CCITT modulations are enabled for V.23. <br><br>When clear, CCITT modulations are enabled for V.21 and V.22. |

For V.23 to be set, both MDM_CCITT_OVERRIDE and MDM_V23_OVERRIDE must be set.

### `dwMaxDTERate`

The maximum DTE rate in bits per second.

### `dwMaxDCERate`

The maximum DCE rate in bits per second.

### `abVariablePortion`

Variable-length information, including strings and any provider-defined information.

## See also

[MODEMSETTINGS](https://learn.microsoft.com/windows/desktop/api/mcx/ns-mcx-modemsettings)