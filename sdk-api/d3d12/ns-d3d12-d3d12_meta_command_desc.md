# D3D12_META_COMMAND_DESC structure

## Description

Describes a meta command.

## Members

### `Id`

Type: **[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)**

A [GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid) uniquely identifying the meta command.

### `Name`

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The meta command name.

### `InitializationDirtyState`

Type: **[D3D12_GRAPHICS_STATES](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_graphics_states)**

Declares the command list states that are modified by the call to initialize the meta command. If all state bits are set, then that's equivalent to calling [ID3D12GraphicsCommandList::ClearState](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-clearstate).

### `ExecutionDirtyState`

Type: **[D3D12_GRAPHICS_STATES](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_graphics_states)**

Declares the command list states that are modified by the call to execute the meta command. If all state bits are set, then that's equivalent to calling [ID3D12GraphicsCommandList::ClearState](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-clearstate).