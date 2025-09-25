# ASSERTMSG macro

## Description

**ASSERTMSG** tests an expression. If the expression is false, it breaks into the kernel debugger and sends it the specified message.

## Parameters

### `msg`

Specifies the null-delimited string to be displayed by the debugger.

### `exp`

Specifies any logical expression.

## Remarks

**ASSERTMSG** is identical to **ASSERT**, except that it sends an additional message to the debugger.

This macro will only be included in your binary if your code is compiled in a Debug configuration.

If *Expression* evaluates to **TRUE**, this routine has no effect.

If *Expression* evaluates to **FALSE**, a message is displayed in the Debugger Command window. The message contains the source-code string of *Expression*, as well as the path of the source-code file and the line number of the instruction that called the macro. In this event, **ASSERTMSG** can be ignored and the process or thread in which **ASSERTMSG** occurred can be terminated. Alternatively, the debugger can be used to analyze the situation or to edit memory. If **ASSERTMSG** is ignored, execution continues as if the **g (Go)** command was entered.

## See also

[ASSERT](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/ff542107(v=vs.85))