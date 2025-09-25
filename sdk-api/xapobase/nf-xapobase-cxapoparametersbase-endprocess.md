# CXAPOParametersBase::EndProcess

## Description

Notifies [CXAPOParametersBase](https://learn.microsoft.com/windows/desktop/api/xapobase/nl-xapobase-cxapoparametersbase) that the XAPO has finished accessing the current process parameters.

## Remarks

XAPOs must call this method within their [IXAPO::Process](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapo-process) implementation to access the current process parameters in a thread-safe manner.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[CXAPOParametersBase](https://learn.microsoft.com/windows/desktop/api/xapobase/nl-xapobase-cxapoparametersbase)