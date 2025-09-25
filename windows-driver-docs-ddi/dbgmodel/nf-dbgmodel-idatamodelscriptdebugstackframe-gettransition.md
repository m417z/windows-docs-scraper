# IDataModelScriptDebugStackFrame::GetTransition

## Description

If a given stack frame is a transition point as determined by the IsTransition method (see the documentation there for a definition of transition points), the GetTransition method returns information about the transition. In particular, this method returns the previous script -- the one which made a call into the script represented by the stack segment containing this [IDataModelScriptDebugStackFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebugstackframe).

In addition to returning the [IDataModelScript](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscript) interface for the previous script, this call is expected to make an attempt to determine whether the transition is contiguous or not. A contiguous transition is one where one script/provider directly called another (ignoring whatever proxy/stub code may exist to facilitate communication between script contexts). A non-contiguous transition is one where there is intermediate code -- either native or another script/provider which cannot be detected -- in between.

An example of a contiguous transition stack (where all properties are extensions on the same object):
- [Script1] get firstProperty() { return 42; }
- (Marshaling or proxy/stub code to transition from Script2 to Script1)
- [Script2] get secondProperty() { return this.firstProperty(); }

An example of a non-contiguous transition stack (where all properties are extensions on the same object) where we imagine two different script providers -- one JavaScript and one Python:
- (JavaScript) [Script1] get firstProperty() { return 42; }
- (Marshaling or proxy/stub code to transition from IntermediateScript to Script1)
- (Python) [IntermediateScript get intermediateProperty() { return this.firstProperty; }
- (Marshaling or proxy/stub code to transition from Script2 to IntermediateScript
- (JavaScript) [Script2] get secondProperty() { return this.intermediateProperty; }

In the second case, it is entirely possible that the debugger for the imagined JavaScript debugger can see get firstProperty and get secondProperty without visibility into get intermediateProperty because it is an entirely different script provider (an imagined Python one here). The script debugger may indicate in the GetTransition method that the transition was from Script1 to Script2 as a non-contiguous transition.

If the overall debug interface is capable of stitching together information for the imagined Python portion, it will do so. The imagined JavaScript provider simply indicates the discontinuity.

## Parameters

### `transitionScript`

The debugger returns the previous script here. The previous script is the one which called into the script represented by the stack segment containing this IDataModelStackDebugFrame.

### `isTransitionContiguous`

An indication of whether the transition is contiguous or not is returned here.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

## See also

[IDataModelScriptDebugStackFrame interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebugstackframe)