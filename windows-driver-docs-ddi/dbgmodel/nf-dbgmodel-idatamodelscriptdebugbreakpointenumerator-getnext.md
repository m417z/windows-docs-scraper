# IDataModelScriptDebugBreakpointEnumerator::GetNext

## Description

The GetNext method moves the enumerator forward to the next breakpoint to be enumerated and returns the [IDataModelScriptDebugBreakpoint](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebugbreakpoint) interface for that breakpoint. If the enumerator has reached the end of the enumeration, it returns E_BOUNDS. Once the E_BOUNDS error has been produced, subsequent calls to the GetNext method will continue to produce E_BOUNDS unless an intervening call to the Reset method has been made.

## Parameters

### `breakpoint`

The next enumerated breakpoint is returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDataModelScriptDebugBreakpointEnumerator interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebugbreakpointenumerator)