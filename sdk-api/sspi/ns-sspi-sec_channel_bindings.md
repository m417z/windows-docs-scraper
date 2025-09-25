# SEC_CHANNEL_BINDINGS structure

## Description

Specifies channel binding information for a security [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

## Members

### `dwInitiatorAddrType`

The type of address (for example, HTTP) specified for the client.

### `cbInitiatorLength`

The size, in bytes, of the data that specifies the client address.

### `dwInitiatorOffset`

The number of bytes from the beginning of this structure to the beginning of the data that specifies the client address.

### `dwAcceptorAddrType`

The type of address (for example, SPN) specified for the server.

### `cbAcceptorLength`

The size, in bytes, of the data that specifies the server address.

### `dwAcceptorOffset`

The number of bytes from the beginning of this structure to the beginning of the data that specifies the server address.

### `cbApplicationDataLength`

The size, in bytes, of the channel binding data.

### `dwApplicationDataOffset`

The size, in bytes, of this structure. The channel binding data immediately follows this structure.

## Remarks

Schannel sets to zero the value of all members of this structure other than **cbApplicationDataLength** and **dwApplicationDataOffset**.

[Security support providers](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSPs) other than Schannel should use the values of this structure obtained by a call to the [QueryContextAttributes (Schannel)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesw) function to pass as a [SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer) structure of type **SECBUFFER_CHANNEL_BINDINGS** as one of the buffers in the *pInput* parameter of a call to the [AcceptSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext) function.

An [security support provider](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSP) other than Schannel should obtain the channel binding information specified by this structure by calling the [QueryContextAttributes (Schannel)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesw) function on the Schannel context that the client used to authenticate. Pass this channel binding information as a [SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer) structure of type **SECBUFFER_CHANNEL_BINDINGS** to the *pInput* parameter of a call to the [AcceptSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext) function.

 If the value of the *ulAttribute* parameter of the [QueryContextAttributes (Schannel)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesw) function is **SECPKG_ATTR_UNIQUE_BINDINGS**, the channel binding data specified by this structure begins with "tls-unique:".

If the value of the *ulAttribute* parameter of the [QueryContextAttributes (Schannel)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesw) function is **SECPKG_ATTR_ENDPOINT_BINDINGS**, the channel binding data specified by this structure begins with "tls-server-end-point:".

## See also

[QueryContextAttributes (Schannel)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesw)

[SecPkgContext_Bindings](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_bindings)