# ITBasicAudioTerminal::get_Balance

## Description

The
**get_Balance** method gets the balance. This method is not implemented for terminals shipped with TAPI 3.0 and higher.

## Parameters

### `plBalance` [out]

Pointer to balance.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_NOTSUPPORTED** | Terminal does not support balance operations. |
| **E_NOTIMPL** | Terminal's balance methods are not implemented. |

## Remarks

The balance property is a value between –10,000 and 10,000. A value of –10,000 indicates that the right speaker has been disabled and only the left speaker is receiving an audio signal. A value of 0 indicates that both speakers are receiving equivalent audio signals. A value of 10,000 indicates that the left speaker has been disabled and only the right speaker is receiving an audio signal.

## See also

[ITBasicAudioTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itbasicaudioterminal)

[Terminal Object](https://learn.microsoft.com/windows/desktop/Tapi/terminal-object)

[put_Balance](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasicaudioterminal-put_balance)