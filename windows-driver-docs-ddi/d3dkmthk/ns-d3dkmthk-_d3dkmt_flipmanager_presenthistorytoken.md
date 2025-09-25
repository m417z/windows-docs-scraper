# D3DKMT_FLIPMANAGER_PRESENTHISTORYTOKEN structure

## Description

The **D3DKMT_FLIPMANAGER_PRESENTHISTORYTOKEN** structure identifies a flip present-history token.

## Members

### `hPrivateData`

Handle to the token's private data.

### `PresentAtQpc`

Present the frame at this QPC (Query Performance Counter) time.

### `Flags`

Attributes of a flip present-history token.

### `Flags.Discard`

Discard the token.

### `Flags.PresentAt`

Present the token.

### `Flags.hPrivateDataIsPointer`

The handle to the private data (**hPrivateData**) is a pointer.

### `Flags.Reserved`

This member is reserved.

### `Flags.Value`

An alternative way to access the flags.