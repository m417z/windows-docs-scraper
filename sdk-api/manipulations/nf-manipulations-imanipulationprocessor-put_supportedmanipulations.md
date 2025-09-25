# IManipulationProcessor::put_SupportedManipulations

## Description

The **SupportedManipulations** property is used to indicate which manipulations are supported by an object.

This property is read/write.

## Parameters

## Remarks

With this property you can control which manipulations the supports and which it does not.
For example, you can block all y-translation manipulations while supporting x-translation manipulations.

#### Examples

```cpp

        CoInitialize(0);

        hr = spIManipProc.CoCreateInstance(CLSID_ManipulationProcessor, NULL, CLSCTX_ALL);

        MANIPULATION_PROCESSOR_MANIPULATIONS mpm;
        spIManipProc->get_SupportedManipulations(&mpm);

```

## See also

[IManipulationProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-imanipulationprocessor)

[MANIPULATION_PROCESSOR_MANIPULATIONS](https://learn.microsoft.com/windows/desktop/api/manipulations/ne-manipulations-manipulation_processor_manipulations)

[Properties](https://learn.microsoft.com/windows/desktop/wintouch/mtproperties)