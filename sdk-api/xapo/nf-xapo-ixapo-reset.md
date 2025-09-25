# IXAPO::Reset

## Description

Resets variables dependent on frame history.

## Remarks

Constant and locked parameters such as the input and output formats remain unchanged. Variables set by [IXAPOParameters::SetParameters](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapoparameters-setparameters) remain unchanged.

For example, an effect with delay should zero out its delay line during this method, but should not reallocate anything as the XAPO remains locked with a constant input and output configuration.

XAudio2 only calls this method if the XAPO is locked.

This method is called from the realtime thread and should not block.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAPO](https://learn.microsoft.com/windows/desktop/api/xapo/nn-xapo-ixapo)