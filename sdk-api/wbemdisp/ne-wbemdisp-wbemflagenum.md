# WbemFlagEnum enumeration

## Description

The **WbemFlagEnum** enumeration defines constants
that are used by [SWbemServices.ExecQuery](https://learn.microsoft.com/windows/desktop/WmiSdk/swbemservices-execquery),
[SWbemServices.ExecQueryAsync](https://learn.microsoft.com/windows/desktop/WmiSdk/swbemservices-execqueryasync),
[SWbemServices.SubclassesOf](https://learn.microsoft.com/windows/desktop/WmiSdk/swbemservices-subclassesof), and
[SWbemServices.InstancesOf](https://learn.microsoft.com/windows/desktop/WmiSdk/swbemservices-instancesof).

The WMI scripting type library, wbemdisp.tlb, defines these constants. Visual Basic applications can access this
library; script languages must use the value of the constant directly, unless they use the Windows Script Host
(WSH) XML file format. For more information, see
[Using the WMI Scripting Type Library](https://learn.microsoft.com/windows/desktop/WmiSdk/using-the-wmi-scripting-type-library).

## Constants

### `wbemFlagReturnImmediately:0x10`

Causes the call to return immediately.

### `wbemFlagReturnWhenComplete:0`

Causes this call to block until the call has completed.

### `wbemFlagBidirectional:0`

Causes WMI to retain pointers to objects of the enumeration until the client releases the enumerator.

### `wbemFlagForwardOnly:0x20`

Causes a forward-only enumerator to be returned. Use this flag in combination with
**wbemFlagReturnImmediately** to request semisynchronous access. For more information, see
[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

You can only iterate (as in a VBScript For Each statement) through a forward-only enumerator one time. The
memory containing the instances is released by WMI so that the enumerator cannot be rewound. Therefore, the
[SWbemObjectSet.Count](https://learn.microsoft.com/windows/desktop/WmiSdk/swbemobjectset-count) method cannot be used since
it requires rewinding the enumerator.

Forward-only enumerators are generally much faster and use less
memory than conventional enumerators, but they do not allow calls to
[SWbemObject.Clone](https://learn.microsoft.com/windows/desktop/WmiSdk/swbemobject-clone-).

### `wbemFlagNoErrorObject:0x40`

This flag must not be set, and must be ignored on receipt.

### `wbemFlagReturnErrorObject:0`

Causes asynchronous calls to return an error object in the event of an error.

### `wbemFlagSendStatus:0x80`

Causes asynchronous calls to send status updates to the
[SWbemSink.OnProgress](https://learn.microsoft.com/windows/desktop/WmiSdk/swbemsink-onprogress) event handler for your object
sink.

### `wbemFlagDontSendStatus:0`

Prevents asynchronous calls from sending status updates to the
[SWbemSink.OnProgress](https://learn.microsoft.com/windows/desktop/WmiSdk/swbemsink-onprogress) event handler for your object
sink.

### `wbemFlagEnsureLocatable:0x100`

### `wbemFlagDirectRead:0x200`

### `wbemFlagSendOnlySelected:0`

### `wbemFlagUseAmendedQualifiers:0x20000`

Causes WMI to return class amendment data along with the base class definition. For more information about
amended qualifiers, see
[Localizing WMI Class Information](https://learn.microsoft.com/windows/desktop/WmiSdk/localizing-wmi-class-information).

### `wbemFlagGetDefault:0`

### `wbemFlagSpawnInstance:0x1`

### `wbemFlagUseCurrentTime:0x1`

## See also

[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method)

[Making a Semisynchronous Call with VBScript](https://learn.microsoft.com/windows/desktop/WmiSdk/making-a-semisynchronous-call-with-vbscript)

[Scripting API Constants](https://learn.microsoft.com/windows/desktop/WmiSdk/scripting-api-constants)