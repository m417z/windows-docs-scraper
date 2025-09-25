# MODEMSETTINGS structure

## Description

Contains information about a modem's configuration.

## Members

### `dwActualSize`

The size of the data actually returned to the application, in bytes. This member may be less than the **dwRequiredSize** member if an application did not allocate enough space for the variable-length portion of the structure.

### `dwRequiredSize`

The number of bytes required for the entire
[MODEMDEVCAPS](https://learn.microsoft.com/windows/desktop/api/mcx/ns-mcx-modemdevcaps) structure, including the variable-length portion.

### `dwDevSpecificOffset`

The offset of the provider-defined portion of the structure, in bytes relative to the beginning of the structure.

### `dwDevSpecificSize`

The size of the provider-defined portion of the structure, in bytes.

### `dwCallSetupFailTimer`

The maximum number of seconds the modem should wait, after dialing is completed, for an indication that a modem-to-modem connection has been established. If a connection is not established in this interval, the call is assumed to have failed. This member is equivalent to register S7 in Hayes® compatible modems.

### `dwInactivityTimeout`

The maximum number of seconds of inactivity allowed after a connection is established. If no data is either transmitted or received for this period of time, the call is automatically terminated. This time-out is used to avoid excessive long-distance charges or online service charges if an application unexpectedly locks up or the user leaves.

### `dwSpeakerVolume`

The volume level of the monitor speaker when the speaker is on. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **MDMVOL_HIGH**<br><br>0x00000002 | High volume. |
| **MDMVOL_LOW**<br><br>0x00000000 | Low volume. |
| **MDMVOL_MEDIUM**<br><br>0x00000001 | Medium volume. |

The
[MODEMDEVCAPS](https://learn.microsoft.com/windows/desktop/api/mcx/ns-mcx-modemdevcaps) structure specifies the speaker volumes a modem supports. Actual volumes are hardware-specific.

### `dwSpeakerMode`

The speaker mode. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **MDMSPKR_CALLSETUP**<br><br>0x00000008 | The speaker is on until a connection is established. |
| **MDMSPKR_DIAL**<br><br>0x00000002 | The speaker is on until a connection is established, except that it is off while the modem is actually dialing. |
| **MDMSPKR_OFF**<br><br>0x00000001 | The speaker is always off. |
| **MDMSPKR_ON**<br><br>0x00000004 | The speaker is always on. |

### `dwPreferredModemOptions`

The modem options requested by the application. The local and remote modems negotiate modem options during call setup; this member specifies the initial negotiating position of the local modem.

The **dwModemOptions** member of the
[MODEMDEVCAPS](https://learn.microsoft.com/windows/desktop/api/mcx/ns-mcx-modemdevcaps) structure specifies the modem options supported by the local modem. For a list of modem options, see the description of the
**MODEMDEVCAPS** structure.

### `dwNegotiatedModemOptions`

The modem options that are actually in effect. This member is filled in after a connection is established and the local and remote modems negotiate modem options.

The **dwModemOptions** member of the
[MODEMDEVCAPS](https://learn.microsoft.com/windows/desktop/api/mcx/ns-mcx-modemdevcaps) structure specifies the modem options supported by the local modem. For a list of modem options, see the description of the
**MODEMDEVCAPS** structure.

### `dwNegotiatedDCERate`

The DCE rate in effect. This member is filled in after a connection is established and the local and remote modems negotiate modem modulations.

### `abVariablePortion`

Optional provider-defined information.

## See also

[MODEMDEVCAPS](https://learn.microsoft.com/windows/desktop/api/mcx/ns-mcx-modemdevcaps)