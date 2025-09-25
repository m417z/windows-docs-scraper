# IBDA_DiseqCommand::put_DiseqSendCommand

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Sends a Digital Satellite Equipment Control (DiSEqC) command.

## Parameters

### `ulRequestId` [in]

An identifier for the command that is assigned by the application.

### `ulcbCommandLen` [in]

The size of the *pbCommand* array, in bytes.

### `pbCommand` [in]

Pointer to a byte array that contains the DiSEqC command, starting with the framing byte. The driver inserts the parity bits for the command.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is required for version 1.2 and later of the DiSEqC command set.

To get the command response from the driver, call [IBDA_DiseqCommand::get_DiseqResponse](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_diseqcommand-get_diseqresponse).

## See also

[IBDA_DiseqCommand](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_diseqcommand)