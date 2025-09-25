# IEventTrigger::put_ValueQueries

## Description

Gets or sets a collection of named XPath queries. Each query in the collection is applied to the last matching event XML returned from the subscription query specified in the [Subscription](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-ieventtrigger-get_subscription) property.

This property is read/write.

## Parameters

## Remarks

The name of the query can be used as a variable in the following action properties:

* [MessageBody property of IShowMessageAction](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-ishowmessageaction-get_messagebody)
* [Title property of IShowMessageAction](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-ishowmessageaction-get_title)
* [Arguments property of IExecAction](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-iexecaction-get_arguments)
* [WorkingDirectory property of IExecAction](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-iexecaction-get_workingdirectory)
* [Server property of IEmailAction](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-iemailaction-get_server)
* [Subject property of IEmailAction](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-iemailaction-get_subject)
* [To property of IEmailAction](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-iemailaction-get_to)
* [Cc property of IEmailAction](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-iemailaction-get_cc)
* [Bcc property of IEmailAction](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-iemailaction-get_bcc)
* [ReplyTo property of IEmailAction](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-iemailaction-get_replyto)
* [From property of IEmailAction](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-iemailaction-get_from)
* [Body property of IEmailAction](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-iemailaction-get_body)
* [Data property of IComHandlerAction](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-icomhandleraction-get_data)

The following code example strings show two name-value pairs that can be used in a name-value collection.
The values returned by the XPath queries can replace variables in an action property. The values are referenced by name, with $(user) and $(machine), in the action property. For example, if the $(user) and $(machine) variables are used in the [MessageBody property of IShowMessageAction](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-ishowmessageaction-get_messagebody), then the value of the XPath queries will replace the variables in the string.

``` syntax
name: user
value: Event/UserData/SubjectUserName

name: machine
value: Event/UserData/MachineName
```

For more information about writing a query string for certain events, see [Event Selection](https://learn.microsoft.com/previous-versions//aa385231(v=vs.85)) and [Subscribing to Events](https://learn.microsoft.com/windows/win32/wes/subscribing-to-events).

## See also

[IEventTrigger](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-ieventtrigger)

[ITaskNamedValueCollection](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itasknamedvaluecollection)

[ITaskNamedValuePair](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itasknamedvaluepair)