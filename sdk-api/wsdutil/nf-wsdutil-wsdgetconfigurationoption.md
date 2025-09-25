# WSDGetConfigurationOption function

## Description

Gets a WSDAPI configuration option.

## Parameters

### `dwOption`

The type of configuration data to get.

| Value | Meaning |
| --- | --- |
| **WSDAPI_OPTION_MAX_INBOUND_MESSAGE_SIZE**<br><br>0x0001 | Get the maximum size, in bytes, of an inbound message. This message size is a value between 32768 and 1048576. |

### `pVoid` [out]

Pointer to the configuration data.

### `cbOutBuffer`

The size, in bytes, of the data pointed to by *pVoid*. If *dwOption* is set to WSDAPI_OPTION_MAX_INBOUND_MESSAGE_SIZE, then this parameter should be set to `sizeof(DWORD)`.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | The *dwOption* is not set to WSDAPI_OPTION_MAX_INBOUND_MESSAGE_SIZE, *cbOutBuffer* is 0, or *cbOutBuffer* is not the correct size for the type of configuration data. |
| **E_POINTER** | *pVoid* is **NULL**. |