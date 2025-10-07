# MCI\_SEQ\_SET\_PARMS structure

The **MCI\_SEQ\_SET\_PARMS** structure contains information for the [**MCI\_SET**](https://learn.microsoft.com/windows/win32/multimedia/mci-set) command for MIDI sequencer devices.

## Members

**dwCallback**

The low-order word specifies a window handle used for the MCI\_NOTIFY flag.

**dwTimeFormat**

Sequencer's time format.

**dwAudio**

Audio output channel.

**dwTempo**

Tempo.

**dwPort**

Port.

**dwSlave**

Type of synchronization used by the sequencer for subordinate operation.

**dwMaster**

Type of synchronization used by the sequencer for master operation.

**dwOffset**

Data offset.

## Remarks

When assigning data to the members of this structure, set the corresponding flags in the *fdwCommand* parameter of the [**mciSendCommand**](https://learn.microsoft.com/previous-versions//dd757160(v=vs.85)) function to validate the members.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Mciapi.h |

## See also

[**MCI**](https://learn.microsoft.com/windows/win32/multimedia/mci)

[**MCI Structures**](https://learn.microsoft.com/windows/win32/multimedia/mci-structures)

[**MCI\_SET**](https://learn.microsoft.com/windows/win32/multimedia/mci-set)

[**mciSendCommand**](https://learn.microsoft.com/previous-versions//dd757160(v=vs.85))

