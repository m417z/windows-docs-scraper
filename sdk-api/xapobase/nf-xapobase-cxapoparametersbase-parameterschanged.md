# CXAPOParametersBase::ParametersChanged

## Description

Indicates if [IXAPOParameters::SetParameters](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapoparameters-setparameters) has been called since the last processing pass.

## Return value

Returns TRUE if [IXAPOParameters::SetParameters](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapoparameters-setparameters) has been called since the last processing pass. May only be used within the XAPO's [IXAPO::Process](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapo-process) implementation, before [CXAPOParametersBase::BeginProcess](https://learn.microsoft.com/windows/desktop/api/xapobase/nf-xapobase-cxapoparametersbase-beginprocess) is called.

## Remarks

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[CXAPOParametersBase](https://learn.microsoft.com/windows/desktop/api/xapobase/nl-xapobase-cxapoparametersbase)