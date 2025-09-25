# PFND3D11_1DDI_QUERYAUTHENTICATEDCHANNEL callback function

## Description

Queries an authenticated channel for capability and state information. Implemented by a Windows Display Driver Model (WDDM) 1.2 or later user-mode display driver.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `hCAuthChannel`

A handle to an authenticated channel object that was created through a call to the [CreateAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createauthenticatedchannel) function.

### `InputDataSize`

The size, in bytes, of the data in the *pInputData* array.

### `pInputData`

A pointer to a buffer that describes the information to query. The data in this buffer is formatted as a [D3D11_1DDI_AUTHENTICATED_QUERY_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_query_input) structure.

### `OutputDataSize`

The size, in bytes, of the data in the *pOutputData* array.

### `pOutputData`

A pointer to a buffer that contains the queried information. For more information, see the Remarks section.

## Return value

Returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The authenticated channel was queried successfully.|
|E_FAIL|The display miniport driver does not support the specified command|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|
|E_OUTOFMEMORY|Memory was not available to complete the operation.|

## Remarks

The *pInputData* parameter references a buffer that contains a [D3D11_1DDI_AUTHENTICATED_QUERY_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_query_input) structure. This structure contains the driver's handle to the authenticated channel, a sequence number, and a GUID that indicates the type of query to perform. The driver must return **E_INVALIDARG** if the sequence number was not previously initialized by using the [ConfigureAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_configureauthenticatedchannel) function. The driver must also return **E_INVALIDARG** if the sequence number is not greater than the sequence number of the previous query call.

The byte array that is referenced by the *pOutputData* parameter is in a format that is specified by the **QueryType** member of the [D3D11_1DDI_AUTHENTICATED_QUERY_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_query_input) structure. The following list describes the format of this data based on the **QueryType** member.

The driver prepares the output buffer that is referenced by the *pOutputData* parameter by following these steps:

1. Each structure that is returned based on the **QueryType** member starts with a [D3D11_1DDI_AUTHENTICATED_QUERY_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_query_output) structure. The driver must copy the members of the [D3D11_1DDI_AUTHENTICATED_QUERY_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_query_input) to the **D3D11_1DDI_AUTHENTICATED_QUERY_OUTPUT** structure.
2. The driver must set the **ReturnCode** member to the same return code that it will return for the *QueryAuthenticatedChannel(D3D11_1)* call. This provides the application with a secure mechanism of accessing the return code.
3. Based on the value of the **QueryType** member, the driver must initialize the corresponding structure that follows the [D3D11_1DDI_AUTHENTICATED_QUERY_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_query_output) structure in the *pOutputData* buffer.
4. The driver must sign the *pOutputData* buffer in a way that is identical to the way it handles Output Protection Manager (OPM) queries.

   The [D3D11_1DDI_AUTHENTICATED_QUERY_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_query_output) structure contains an AES-based one-key CBC message authentication code (OMAC) of the data. The display miniport driver must calculate an OMAC over the data in the output buffer to authenticate the data. The driver does this by first setting the **omac** member to zero and then calculating an OMAC for the data in the buffer. The driver then sets the **omac** member to the OMAC that it calculated.

The display miniport driver must return **E_INVALIDARG** for the *QueryAuthenticatedChannel(D3D11_1)* call under the following conditions:

* The sequence number is not greater than a sequence number that was specified in a previous configuration call.
* The sequence number has not yet been initialized by a call to the [ConfigureAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_configureauthenticatedchannel) function.
* The *OutputDataSize* parameter is less than size of the structure specified by the **D3D11_1DDI_AUTHENTICATED_CONFIGURE_INPUT.QueryType** member.

## See also

[ConfigureAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_configureauthenticatedchannel)

[CreateAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createauthenticatedchannel)

[D3D11_1DDI_AUTHENTICATED_QUERY_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_query_input)

[D3D11_1DDI_AUTHENTICATED_QUERY_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_query_output)