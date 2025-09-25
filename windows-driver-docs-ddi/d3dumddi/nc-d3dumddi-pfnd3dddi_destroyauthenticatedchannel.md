# PFND3DDDI_DESTROYAUTHENTICATEDCHANNEL callback function

## Description

The **DestroyAuthenticatedChannel** function releases resources for the authenticated channel that the [CreateAuthenticatedChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createauthenticatedchannel) function creates.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_DESTROYAUTHENTICATEDCHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_destroyauthenicatedchannel) structure that contains one member that specifies the handle to the authenticated channel to destroy.

## Return value

**DestroyAuthenticatedChannel** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The authenticated channel is successfully destroyed.|
|E_OUTOFMEMORY|DestroyAuthenticatedChannel could not allocate the required memory for it to complete.|

## Remarks

The driver's **DestroyAuthenticatedChannel** function should disable any protections that were set through calls to the driver's [ConfigureAuthenticatedChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_configureauthenicatedchannel) function with the D3DAUTHETICATEDCONFIGURE_PROTECTION and D3DAUTHENTICATEDCONFIGURE_ENCRYPTIONWHENACCESIBLE GUIDs set. However, the driver should not disable shared surface protection (D3DAUTHETICATEDCONFIGURE_SHAREDRESOURCE).

## See also

[ConfigureAuthenticatedChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_configureauthenicatedchannel)

[CreateAuthenticatedChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createauthenticatedchannel)

[D3DDDIARG_DESTROYAUTHENTICATEDCHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_destroyauthenicatedchannel)