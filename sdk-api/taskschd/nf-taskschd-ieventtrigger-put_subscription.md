# IEventTrigger::put_Subscription

## Description

Gets or sets a query string that identifies the event that fires the trigger.

This property is read/write.

## Parameters

## Remarks

When reading or writing your own XML for a task, the event subscription is specified using the [Subscription](https://learn.microsoft.com/windows/desktop/TaskSchd/taskschedulerschema-subscription-eventtriggertype-element) element of the Task Scheduler schema.

For more information about writing a query string for certain events, see [Event Selection](https://learn.microsoft.com/previous-versions//aa385231(v=vs.85)) and [Subscribing to Events](https://learn.microsoft.com/windows/win32/wes/subscribing-to-events).

#### Examples

The following query string defines a subscription to all level 2 events in the System channel.

```xml
"<QueryList>
    <Query Id='1'>
        <Select Path='System'>*[System/Level=2]</Select>
    </Query>
</QueryList>"
```

## See also

[IEventTrigger](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-ieventtrigger)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)