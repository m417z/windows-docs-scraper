# PFND3DDDI_QUERYAUTHENTICATEDCHANNEL callback function

## Description

The *QueryAuthenticatedChannel* function queries an authenticated channel for capability and state information.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDIARG_QUERYAUTHENTICATEDCHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_queryauthenicatedchannel) structure that describes authenticated-channel information to query. This structure contains an input buffer that describes the query and an output buffer to return the queried information.

## Return value

*QueryAuthenticatedChannel* returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The authenticated channel is successfully queried.|
|E_OUTOFMEMORY|QueryAuthenticatedChannel could not allocate the required memory for it to complete.|

## Remarks

The input buffer contains the driver's handle to the authenticated channel, a sequence number, and a GUID that indicates the type of query. The driver should fail all queries if the driver did not previously initialize the sequence number through a call to its [ConfigureAuthenticatedChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_configureauthenicatedchannel) function. The driver should also fail the query if the sequence number is not greater than the sequence number of the previous query call.

The driver should duplicate the input data in the structure of the output buffer and should sign the output structure identically to how it currently handles [Output Protection Manager](https://learn.microsoft.com/windows-hardware/drivers/display/supporting-output-protection-manager) (OPM) queries.

Except for those situations in which the application incorrectly specifies an output buffer that is too small, the driver should always place the return code in the output structure. Therefore, the application has a secure mechanism to determine the return code.

*QueryAuthenticatedChannel* performs different operations depending on each of following GUIDs that is specified in the input structure. The driver should fail if the input and output buffer sizes do not match the sizes that are defined for the specified GUID.

## See also

[ConfigureAuthenticatedChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_configureauthenicatedchannel)

[D3DDDIARG_QUERYAUTHENTICATEDCHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_queryauthenicatedchannel)