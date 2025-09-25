# D3D12_COMMAND_LIST_SUPPORT_FLAGS enumeration

## Description

Used to determine which kinds of command lists are capable of supporting various operations. For example, whether a command list supports immediate writes.

## Constants

### `D3D12_COMMAND_LIST_SUPPORT_FLAG_NONE:0`

Specifies that no command list supports the operation in question.

### `D3D12_COMMAND_LIST_SUPPORT_FLAG_DIRECT`

Specifies that direct command lists can support the operation in question.

### `D3D12_COMMAND_LIST_SUPPORT_FLAG_BUNDLE`

Specifies that command list bundles can support the operation in question.

### `D3D12_COMMAND_LIST_SUPPORT_FLAG_COMPUTE`

Specifies that compute command lists can support the operation in question.

### `D3D12_COMMAND_LIST_SUPPORT_FLAG_COPY`

Specifies that copy command lists can support the operation in question.

### `D3D12_COMMAND_LIST_SUPPORT_FLAG_VIDEO_DECODE`

Specifies that video-decode command lists can support the operation in question.

### `D3D12_COMMAND_LIST_SUPPORT_FLAG_VIDEO_PROCESS`

Specifies that video-processing command lists can support the operation is question.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)

[D3D12_COMMAND_LIST_TYPE.](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_command_list_type)