# CREDUIWIN_MARSHALED_CONTEXT structure

## Description

Specifies credential information that has been serialized by using the [ICredentialProvider::SetSerialization](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovider-setserialization) method.

## Members

### `StructureType`

The type of the structure. This must be **CREDUIWIN_STRUCTURE_TYPE_SSPIPFC**.

### `cbHeaderLength`

The size, in bytes, of the header.

### `LogonId`

The user's logon ID.

### `MarshaledDataType`

A value that represents the type of structure that the serialized data specifies. If the value of this parameter is **SSPIPFC_STRUCTURE_TYPE_CREDUI_CONTEXT**, the data can be deserialized by calling the [SspiUnmarshalCredUIContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-sspiunmarshalcreduicontext) function.

### `MarshaledDataOffset`

The number of bytes from the beginning of this structure to the beginning of the serialized data.

### `MarshaledDataLength`

The size, in bytes, of the serialized data.

## See also

[SEC_WINNT_CREDUI_CONTEXT](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_credui_context)