# IBDA_DiseqCommand::put_EnableDiseqCommands

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Enables or disables the use of Digital Satellite Equipment Control (DiSEqC) commands.

## Parameters

### `bEnable` [in]

If **TRUE**, DiSEqC commands are enabled. Otherwise, DiSEqC commands are disabled.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Depending on the satellite installation, DiSEqC commands might be required. However, enabling DiSEqC can result in the driver taking longer to switch transponders (typically by 100300 milliseconds). Therefore, it is recommended to disable DiSEqC commands if they are not required.

## See also

[IBDA_DiseqCommand](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_diseqcommand)