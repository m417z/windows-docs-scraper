# IInertiaProcessor::Complete

## Description

The **Complete** method finishes the current manipulation and stops inertia on the inertia processor.

## Return value

Returns **S_OK** on success, otherwise returns an error code such as **E_FAIL**.

## Remarks

The **Complete** method raises the [ManipulationCompleted](https://learn.microsoft.com/windows/win32/api/manipulations/nf-manipulations-_imanipulationevents-manipulationcompleted) event on an [_IManipulationEvents](https://learn.microsoft.com/windows/win32/api/manipulations/nn-manipulations-_imanipulationevents) interface implementation.

#### Examples

```cpp

    // set properties on the IInertiaProcessor interface
    this->m_spIInertProc->put_DesiredRotation(spin);
	
    // complete any unprocessed inertia
    this->m_spIInertProc->Complete();
	
    // reset the processor
    this->m_spIInertProc->Reset();		
	
    // If you have implemented a timer that handles inertia processing,
    // this should be started as well and the processor will raise
    // Manipulation* events
		
```

## See also

[CompleteTime](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-iinertiaprocessor-completetime)

[IInertiaProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-iinertiaprocessor)

[Methods](https://learn.microsoft.com/windows/desktop/wintouch/imanipulationprocessor-methods)