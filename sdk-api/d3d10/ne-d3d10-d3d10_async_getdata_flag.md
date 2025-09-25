# D3D10_ASYNC_GETDATA_FLAG enumeration

## Description

Optional flags that control the behavior of [ID3D10Asynchronous::GetData](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10asynchronous-getdata).

## Constants

### `D3D10_ASYNC_GETDATA_DONOTFLUSH:0x1`

Do not flush the command buffer. This can potentially cause an infinite loop if GetData is continually called until it returns S_OK as there may still be commands in the command buffer that need to be processed in order for GetData to return S_OK. Since the commands in the command buffer are not flushed they will not be processed and therefore GetData will never return S_OK.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-enums)