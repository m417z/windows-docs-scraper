# IBDA_DiseqCommand::get_DiseqResponse

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the driver's response to a Digital Satellite Equipment Control (DiSEqC) command.

## Parameters

### `ulRequestId` [in]

The identifier of the command. The application assigns this value when it calls [IBDA_DiseqCommand::put_DiseqSendCommand](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_diseqcommand-put_diseqsendcommand).

### `pulcbResponseLen` [in, out]

On input, specifies the size of the *pbResponse* array, in bytes. On output, receives the number of bytes of data written into the *pbResponse* buffer.

### `pbResponse` [in, out]

Pointer to a byte array that receives the driver's response.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| ****S_OK**** | The method succeeded. |
| ****BDA_E_BUFFER_TOO_SMALL**** | The buffer given in the *pbResponse* parameter is too small. |

## See also

[IBDA_DiseqCommand](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_diseqcommand)