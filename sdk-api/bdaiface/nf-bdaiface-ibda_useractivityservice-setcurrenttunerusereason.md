# IBDA_UserActivityService::SetCurrentTunerUseReason

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Specifies the current tuner use reason for a Media Sink Device (MSD) in a Protected Broadcast Driver Architecture (PBDA) media graph. A *current tuner use reason* records the reason that the MSD is currently using the tuner on a Media Transform Device (MTD).

 An MSD calls this method every time the current tuner use reason changes. For example, when an MSD starts a recording, it calls this method and sets the use reason as "user directed recording." An MSD must also call this method every time it sets a tuner device, even if the use reason has not changed.

## Parameters

### `dwUseReason` [in]

Specifies the tuner use reason. This is one of the following values:

| Value | Meaning |
| --- | --- |
| 0x00000001 | Setup or scanning |
| 0x00000002 | Playback for a user |
| 0x00000004 | Picture in Picture (PIP) playback for a user |
| 0x00000008 | User-directed recording |
| 0x00000010 | Speculative recording |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBDA_UserActivityService](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_useractivityservice)