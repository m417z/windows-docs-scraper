# ITStream::get_Direction

## Description

The
**get_Direction** method gets the stream's
[terminal direction](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-terminal_direction).

## Parameters

### `pTD` [out]

Pointer to
[TERMINAL_DIRECTION](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-terminal_direction) descriptor.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pTD* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

Terminals of either direction can, in general, be selected on any stream whose media type matches the terminal's media type. However, some MSPs allow only terminals whose terminal direction matches the stream's terminal direction to be selected on a stream.

## See also

[ITStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstream)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)

[TERMINAL_DIRECTION](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-terminal_direction)