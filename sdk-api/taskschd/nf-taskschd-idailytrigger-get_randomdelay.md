# IDailyTrigger::get_RandomDelay

## Description

Gets or sets a delay time that is randomly added to the start time of the trigger.

This property is read/write.

## Parameters

## Remarks

The specified random delay time is the upper bound for the random interval. The trigger will fire at random during the period specified by the *randomDelay* parameter, which doesn't begin until the specified start time of the trigger. For example, if the task trigger is set to every seventh day, and the *randomDelay* parameter is set to P2DT5S (2 day, 5 second time span), then once the seventh day is reached, the trigger will fire once randomly during the next 2 days, 5 seconds.

## See also

[IDailyTrigger](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-idailytrigger)