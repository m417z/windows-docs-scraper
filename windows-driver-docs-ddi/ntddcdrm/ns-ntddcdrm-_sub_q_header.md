# _SUB_Q_HEADER structure

## Description

The SUB_Q_HEADER structure contains audio status information and the length of the Q subchannel data being returned. This structure is used in conjunction with [SUB_Q_CHANNEL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_sub_q_channel_data).

## Members

### `Reserved`

Reserved.

### `AudioStatus`

Reports the audio status with one of the following flags:

#### AUDIO_STATUS_NOT_SUPPORTED

Audio status byte not supported or not valid.

#### AUDIO_STATUS_IN_PROGRESS

Audio play operation is in progress.

#### AUDIO_STATUS_PAUSED

Audio play operation is paused.

#### AUDIO_STATUS_PLAY_COMPLETE

Audio play operation completed successfully.

#### AUDIO_STATUS_PLAY_ERROR

Audio play operation stopped due to error.

#### AUDIO_STATUS_NO_STATUS

No current audio status to return.

### `DataLength`

Gives the length of Q subchannel data that follows this header structure. The bytes in this array are arranged in big-endian order. **DataLength**[0] contains the most significant byte, and **DataLength**[1] contains the least significant byte.

## See also

[CDROM_SUB_Q_DATA_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_sub_q_data_format)

[IOCTL_CDROM_READ_Q_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_read_q_channel)

[SUB_Q_CHANNEL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_sub_q_channel_data)