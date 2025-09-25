# CXAPOParametersBase::CXAPOParametersBase

## Description

Creates an instance of the [CXAPOParametersBase](https://learn.microsoft.com/windows/desktop/api/xapobase/nl-xapobase-cxapoparametersbase) class.

## Parameters

### `pRegistrationProperties`

Type: **const XAPO_REGISTRATION_PROPERTIES***

A pointer to an [XAPO_REGISTRATION_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/xapo/ns-xapo-xapo_registration_properties) structure that contains the registration properties for the XAPO.

### `pParameterBlocks`

Type: **BYTE***

Pointer to three contiguous process parameter blocks used for synchronization.

### `uParameterBlockByteSize`

Type: **UINT32**

Size of a parameter block in *pParameterBlocks*.

### `fProducer`

Type: **BOOL**

If TRUE, indicates [IXAPO::Process](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapo-process) produces data to be returned by [IXAPOParameters::GetParameters](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapoparameters-getparameters) and disallows calls to [IXAPOParameters::SetParameters](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapoparameters-setparameters).

## Remarks

All process parameter blocks in *pParameterBlocks* must be initialized to the same default value before there is a call to the [IXAPO::Process](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapo-process), [IXAPOParameters::GetParameters](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapoparameters-getparameters), and [IXAPOParameters::SetParameters](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapoparameters-setparameters) methods. Usually this initialization should be handled in [IXAPO::Initialize](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapo-initialize) or in [IXAPO::LockForProcess](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapo-lockforprocess).

The object created by this [CXAPOParametersBase](https://learn.microsoft.com/windows/desktop/api/xapobase/nl-xapobase-cxapoparametersbase) will have a reference count of 1.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[CXAPOParametersBase](https://learn.microsoft.com/windows/desktop/api/xapobase/nl-xapobase-cxapoparametersbase)