# IXAPO::Initialize

## Description

Performs any effect-specific initialization.

## Parameters

### `pData`

Effect-specific initialization parameters, may be NULL if *DataByteSize* is 0.

### `DataByteSize`

Size of *pData* in bytes, may be 0 if *pData* is NULL.

## Return value

Returns S_OK if successful, an error code otherwise.

## Remarks

The contents of *pData* are defined by a given XAPO. Immutable parameters (constant for the lifetime of the XAPO) should be set in this method. Once initialized, an XAPO cannot be initialized again. An XAPO should be initialized before passing it to XAudio2 as part of an effect chain.

**Note** XAudio2 does not call this method, it should be called by the client before passing the XAPO to XAudio2.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAPO](https://learn.microsoft.com/windows/desktop/api/xapo/nn-xapo-ixapo)