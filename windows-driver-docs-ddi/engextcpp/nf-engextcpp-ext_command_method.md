# EXT_COMMAND_METHOD macro

## Description

The EXT_COMMAND_METHOD macro declares an extension command from inside the definition of the [EXT_CLASS](https://learn.microsoft.com/previous-versions/ff544508(v=vs.85)) class.

## Parameters

### `_Name`

The name of the extension command. As with all extension commands, the name must consist entirely of lowercase letters.

## Remarks

This macro must be used inside the definition of the [EXT_CLASS](https://learn.microsoft.com/previous-versions/ff544508(v=vs.85)) class.

The macro [EXT_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-ext_command) should be used to define the extension command. As with all C++ declarations, the EXT_COMMAND_METHOD declaration should appear in the source files before the EXT_COMMAND definition.

## See also

[EXT_CLASS](https://learn.microsoft.com/previous-versions/ff544508(v=vs.85))

[EXT_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-ext_command)