# IDataModelScript::Populate

## Description

The Populate method is called by the client in order to change or synchronize the "content" of the script. It is the notification that is made to the script provider that the code of the script has changed. It is important to note that this method does not cause execution of the script or changes to any of the objects that the script manipulates. This is merely a notification to the script provider that the content of the script has changed so that it may synchronize its own internal state.

The implementer of the Populate method may not hold the content stream between the Populate and Execute calls. It must synchronize any internal state and data structures to "remember" the script content after the Populate call returns.

It is also important to note that the implementation should not discard the state representing the currently executed version of the script until after an Execute call succeeds. If the populated content has syntax or other errors that prevent successful execution of the script, the provider must restore the state of the script to what was successfully executed.

## Parameters

### `contentStream`

A standard input stream representing the content of the entire script is passed here. The implementation must "remember" this content (or a data structure based form of it) after the Populate method returns. It is illegal to hold a reference to the passed stream after returning. Such will cause undefined behavior in the host.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDataModelScript interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscript)