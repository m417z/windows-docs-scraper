# WSDSetConfigurationOption function

## Description

Sets a WSDAPI configuration option.

## Parameters

### `dwOption`

The type of configuration data to set.

| Value | Meaning |
| --- | --- |
| **WSDAPI_OPTION_MAX_INBOUND_MESSAGE_SIZE**<br><br>0x0001 | Set the maximum size, in bytes, of an inbound message. |

### `pVoid` [in]

Pointer to the configuration data. If *dwOption* is set to WSDAPI_OPTION_MAX_INBOUND_MESSAGE_SIZE, then *pVoid* should point to a DWORD that represents the size of an inbound message. The size of the message is a value between 32768 and 1048576.

### `cbInBuffer`

The size, in bytes, of the data pointed to by *pVoid*. If *dwOption* is set to WSDAPI_OPTION_MAX_INBOUND_MESSAGE_SIZE, this parameter should be set to `sizeof(DWORD)`.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | The *dwOption* is not set to WSDAPI_OPTION_MAX_INBOUND_MESSAGE_SIZE, *cbInBuffer* is 0, *cbInBuffer* is not the correct size for the type of configuration data, or *pVoid* is NULL. |