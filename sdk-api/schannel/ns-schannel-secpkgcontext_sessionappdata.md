# SecPkgContext_SessionAppData structure

## Description

The **SecPkgContext_SessionAppData** structure stores application data for a session context.

This attribute is supported only by the Schannel [security support provider](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSP).

## Members

### `dwFlags`

Reserved for future use.

### `cbAppData`

Count of bytes used by **pbAppData**.

### `pbAppData`

Pointer to a **BYTE** that represents the session application data.