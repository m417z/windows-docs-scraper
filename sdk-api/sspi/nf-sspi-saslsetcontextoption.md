# SaslSetContextOption function

## Description

The **SaslSetContextOption** function sets the value of the specified property for the specified SASL context.

## Parameters

### `ContextHandle` [in]

Handle of the SASL context.

### `Option` [in]

Property to set for the SASL context. The following table lists the possible values.

| Value | Meaning |
| --- | --- |
| **SASL_OPTION_AUTHZ_PROCESSING** | Data type of buffer: **ULONG**<br><br>State of SASL processing of the Authz value provided by the SASL application. The valid states for processing are Sasl_AuthZIDForbidden and Sasl_AuthZIDProcessed. The default value is Sasl_AuthZIDProcessed. |
| **SASL_OPTION_AUTHZ_STRING** | Data type of buffer: Array of binary characters<br><br>String of characters passed from the SASL client to the server. If the AuthZ_Processing state is Sasl_AuthZIDForbidden, the return value SEC_E_UNSUPPORTED_FUNCTION is returned. |
| **SASL_OPTION_RECV_SIZE** | Data type of buffer: **ULONG**<br><br>Maximum size of the receiving buffer on the local computer. The default value is 0x0FFFF bytes. |
| **SASL_OPTION_SEND_SIZE** | Data type of buffer: **ULONG**<br><br>Maximum message data size that can be transmitted. This value is the maximum buffer size that can be transmitted to the remote SASL process minus the block size, the trailer size, and the maximum signature size. The default value is 0x0FFFF bytes. |

### `Value` [in]

A pointer to a buffer that contains the value to set to the requested property. For the data type of the buffer for each value of the *Option* parameter, see the *Option* parameter.

### `Size` [in]

The size, in bytes, of the buffer specified by the *Value* parameter.

## Return value

If the call is completed successfully, this function returns SEC_E_OK. The following table shows some possible error return values.

| Return code | Description |
| --- | --- |
| **SEC_E_BUFFER_TOO_SMALL** | The buffer specified by the *Value* parameter is not large enough to contain the data value of the property specified by the *Option* parameter. |
| **SEC_E_INVALID_HANDLE** | The SASL context handle specified by the *ContextHandle* parameter was not found in the SASL list. |
| **SEC_E_UNSUPPORTED_FUNCTION** | The option specified in the *Option* parameter is not valid. |