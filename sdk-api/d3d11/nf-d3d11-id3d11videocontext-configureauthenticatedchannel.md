# ID3D11VideoContext::ConfigureAuthenticatedChannel

## Description

Sends a configuration command to an authenticated channel.

## Parameters

### `pChannel` [in]

A pointer to the [ID3D11AuthenticatedChannel](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11authenticatedchannel) interface.

### `InputSize` [in]

The size of the *pInput* array, in bytes.

### `pInput` [in]

A pointer to a byte array that contains input data for the command. This buffer always starts with a [D3D11_AUTHENTICATED_CONFIGURE_INPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_configure_input) structure. The **ConfigureType** member of the structure specifies the command and defines the meaning of the rest of the buffer.

### `pOutput` [out]

A pointer to a [D3D11_AUTHENTICATED_CONFIGURE_OUTPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_configure_output) structure that receives the response to the command.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)