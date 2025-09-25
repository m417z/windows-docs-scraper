# SecPkgContext_Bindings structure

## Description

Specifies a structure that contains channel binding information for a security [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

## Members

### `BindingsLength`

The size, in bytes, of the structure specified by the **Bindings** member

### `Bindings`

A pointer to a [SEC_CHANNEL_BINDINGS](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_channel_bindings) structure that specifies channel binding information.

## See also

[QueryContextAttributes (Schannel)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesw)