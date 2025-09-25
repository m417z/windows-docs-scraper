# ITargetInfo::SetTargetProcessorArchitecture

## Description

Sets the processor architecture associated with the current target.

## Parameters

### `ProcessorArchitecture` [in]

The processor architecture associated with the current target.

## Return value

This method returns an HRESULT value. **S_OK** indicates success. Returns **HRESULT_FROM_WIN32** (**ERROR_INVALID_OPERATION**) if the target processor architecture has been set. May return **E_OUTOFMEMORY** if system resources are low.

## See also

[ITargetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-itargetinfo)