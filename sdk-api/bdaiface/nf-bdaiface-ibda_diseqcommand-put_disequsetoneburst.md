# IBDA_DiseqCommand::put_DiseqUseToneBurst

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Enables or disables Tone-Burst commands.

## Parameters

### `bUseToneBurst` [in]

If **TRUE**, Tone-Burst commands are enabled. Otherwise, Tone-Burst commands are disabled.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The Tone-Burst command uses a 22-kHz carrier signal to select either source position A or source position B.

Typically the driver enables or disables Tone-Burst as needed when the application calls [IBDA_DiseqCommand::put_DiseqLNBSource](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_diseqcommand-put_diseqlnbsource). However, you can use the **put_DiseqUseToneBurst** method to switch this mode on or off, either to improve channel switching or to maintain compatibility with particular equipment. Note that using Tone-Burst can increase the amount of time required for tuning by about 40 milliseconds.

## See also

[IBDA_DiseqCommand](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_diseqcommand)