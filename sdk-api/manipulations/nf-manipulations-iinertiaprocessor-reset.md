# IInertiaProcessor::Reset

## Description

The **Reset** method initializes the processor with initial timestamp and restarts inertia.

## Return value

Returns **S_OK** on success, otherwise returns an error code such as **E_FAIL**.

## Remarks

If you have changed properties on an object currently being manipulated by inertia, call [Complete](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-iinertiaprocessor-complete) before calling **Reset**.

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

[Complete](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-iinertiaprocessor-complete)

[IInertiaProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-iinertiaprocessor)

[Methods](https://learn.microsoft.com/windows/desktop/wintouch/imanipulationprocessor-methods)