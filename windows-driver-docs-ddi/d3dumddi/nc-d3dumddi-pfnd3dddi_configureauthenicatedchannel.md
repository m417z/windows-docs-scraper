# PFND3DDDI_CONFIGUREAUTHENICATEDCHANNEL callback function

## Description

The **ConfigureAuthenticatedChannel** function sets state within an authenticated channel.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDIARG_CONFIGUREAUTHENTICATEDCHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_configureauthenicatedchannel) structure that describes how to configure an authenticated channel. This structure contains an input buffer that describes how to configure the authenticated channel and an output buffer with configuration information.

## Return value

**ConfigureAuthenticatedChannel** returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The authenticated channel is successfully configured. |
| **E_OUTOFMEMORY** | [ConfigureAuthenticatedChannel]() could not allocate the required memory for it to complete. |

## Remarks

The input buffer contains a One-key Cipher Block Chaining (CBC)-mode message authentication code (OMAC) that the driver must authenticate. The input buffer also contains the driver's handle to the authenticated channel, a sequence number, and a GUID that indicates the configuration type.

The driver should fail **ConfigureAuthenticatedChannel** if the input OMAC does not match, if the sequence number is not greater than a sequence number that was specified in a previous call, or if the sequence number has not yet been initialized (the exception to this last rule is for the initialization call itself).

The driver should duplicate the input data in the structure of the output buffer and should sign the output structure identically to how it currently handles [Output Protection Manager](https://learn.microsoft.com/windows-hardware/drivers/display/supporting-output-protection-manager) (OPM) queries.

Except for those situations in which the application incorrectly specifies an output buffer that is too small, the driver should always place the return code in the output structure. Therefore, the application has a secure mechanism to determine the return code.

**ConfigureAuthenticatedChannel** performs different operations depending on each of following GUIDs that is specified in the input structure. The driver should fail if the input buffer size does not match the size that is defined for the specified GUID.

## See also

[D3DDDIARG_CONFIGUREAUTHENTICATEDCHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_configureauthenicatedchannel)