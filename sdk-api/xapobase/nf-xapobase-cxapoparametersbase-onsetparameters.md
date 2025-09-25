# CXAPOParametersBase::OnSetParameters

## Description

Called by [IXAPOParameters::SetParameters](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapoparameters-setparameters) to allow for user-defined parameter validation.

## Parameters

### `pParameters`

Effect-specific parameter block.

### `ParameterByteSize`

Size, in bytes, of pParameters.

## Remarks

Users are expected to use asserts for parameter validation in **OnSetParameters**.

The [CXAPOParametersBase](https://learn.microsoft.com/windows/desktop/api/xapobase/nl-xapobase-cxapoparametersbase) class's implementation of [IXAPOParameters::SetParameters](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapoparameters-setparameters) validates that *ParameterByteSize* is equal to the **m_uParameterBlockByteSize** private member before calling **OnSetParameters** so it may be assumed that *ParameterByteSize* == **m_uParameterBlockByteSize**. **m_uParameterBlockByteSize** will be equal to the *uParameterBlockByteSize* parameter passed into the [CXAPOParametersBase::CXAPOParametersBase](https://learn.microsoft.com/windows/desktop/api/xapobase/nf-xapobase-cxapoparametersbase-cxapoparametersbase) constructor.

This method should not block as it is called from the realtime audio processing thread.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[CXAPOParametersBase](https://learn.microsoft.com/windows/desktop/api/xapobase/nl-xapobase-cxapoparametersbase)