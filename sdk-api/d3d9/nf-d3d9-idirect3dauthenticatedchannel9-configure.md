# IDirect3DAuthenticatedChannel9::Configure

## Description

Sends a configuration command to the authenticated channel.

## Parameters

### `InputSize`

The size of the *pInput* array, in bytes.

### `pInput`

A pointer to a byte array that contains input data for the command. This buffer always starts with a [D3DAUTHENTICATEDCHANNEL_CONFIGURE_INPUT](https://learn.microsoft.com/windows/desktop/medfound/d3dauthenticatedchannel-configure-input) structure. The **ConfigureType** member of the structure specifies the command and defines the meaning of the rest of the buffer.

### `pOutput`

A pointer to a [D3DAUTHENTICATEDCHANNEL_CONFIGURE_OUTPUT](https://learn.microsoft.com/windows/desktop/medfound/d3dauthenticatedchannel-configure-output) structure that receives the response to the command.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For a list of commands, see [Content Protection Commands](https://learn.microsoft.com/windows/desktop/medfound/content-protection-commands).

## See also

[Content Protection Commands](https://learn.microsoft.com/windows/desktop/medfound/content-protection-commands)

[GPU-Based Content Protection](https://learn.microsoft.com/windows/desktop/medfound/gpu-based-content-protection)

[IDirect3DAuthenticatedChannel9](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3dauthenticatedchannel9)