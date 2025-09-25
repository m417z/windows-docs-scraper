# TAPE_SET_MEDIA_PARAMETERS structure

## Description

The
**TAPE_SET_MEDIA_PARAMETERS** structure describes the tape in the tape drive. It is used by the [SetTapeParameters](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-settapeparameters) function.

## Members

### `BlockSize`

Number of bytes per block. Maximum and minimum block sizes can be obtained by calling the
[GetTapeParameters](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-gettapeparameters) function.

## See also

[SetTapeParameters](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-settapeparameters)