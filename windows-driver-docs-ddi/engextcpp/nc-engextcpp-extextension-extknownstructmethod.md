# ExtExtension::* ExtKnownStructMethod callback function

## Description

The **ExtKnownStructMethod** callback method is called by the engine to format an instance of a structure for output on a single line.

## Parameters

### `TypeName` [in]

Specifies the name of the type of the structure pointed to by *Offset*. This is the same as the **TypeName** field of the [ExtKnownStruct](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/ns-engextcpp-extknownstruct) structure used to register this callback method.

### `Flags` [in]

Specifies bit flags that indicate how the output should be formatted. Currently, this is set to DEBUG_KNOWN_STRUCT_GET_SINGLE_LINE_OUTPUT, which indicates that the output should be formatted for output on a single line.

### `Offset` [in]

Specifies the location in the target's memory of the instance of the structure to be formatted for output.

## Remarks

The debugger engine expects the output to be formatted for printing on a single line, hence it does not expect the formatted structure to have any line breaks.

The formatted output from this method should be placed in the buffer **m_AppendBuffer** -- a member of [ExtExtension](https://learn.microsoft.com/previous-versions/ff543981(v=vs.85)).

Instances of this callback method are registered with the engine by using an instance of the [ExtKnownStruct](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/ns-engextcpp-extknownstruct) structure that is placed into the array **m_KnownStructs** (a member of [ExtExtension](https://learn.microsoft.com/previous-versions/ff543981(v=vs.85))) by the [Initialize](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/ff550945(v=vs.85)) method. The **ExtKnownStruct** structure also specifies the name of the type of structure this method formats.

When the debugger engine calls a known structure method, it wraps the call in a **try / except** block. This protects the engine from some types of bugs in the extension code; but, because the extension calls are executed in the same thread as the engine, they can still cause it to crash.

## See also

[ExtExtension](https://learn.microsoft.com/previous-versions/ff543981(v=vs.85))

[ExtKnownStruct](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/ns-engextcpp-extknownstruct)

[Initialize](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/ff550945(v=vs.85))