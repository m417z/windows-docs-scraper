# IManipulationProcessor::CompleteManipulation

## Description

The **CompleteManipulation** method is called when the developer chooses to end the manipulation.

## Return value

Returns **S_OK** on success, otherwise returns an error code such as **E_FAIL**.

## Remarks

This method raises the ManipulationCompleted() event in response.

During a Windows Touch gesture, manipulation gets started as soon as first touch input is sent for processing.
If **CompleteManipulation** is called before the second touch input gets a chance to be processed,
the second touch input will start a new manipulation.

## See also

[IManipulationProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-imanipulationprocessor)

[Methods](https://learn.microsoft.com/windows/desktop/wintouch/mtmethods)