# IBDA_DiseqCommand::put_DiseqRepeats

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Enables or disables repeated Digital Satellite Equipment Control (DiSEqC) commands.

## Parameters

### `ulRepeats` [in]

The number of times to repeat each DiSEqC command. To disable repeated commands, set *ulRepeats* to 0.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When two DiSEqC switches are cascaded, the tuner might have to repeat
commands for the far device. However, repeated commands can increase the amount of time required for tuning by about 100 milliseconds. Therefore, it is recommended to disable repeated commands if they are not required.

## See also

[IBDA_DiseqCommand](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_diseqcommand)