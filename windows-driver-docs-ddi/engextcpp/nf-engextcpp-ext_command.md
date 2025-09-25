# EXT_COMMAND macro

## Description

The EXT_COMMAND macro is used to define an extension command that was declared by using the [EXT_COMMAND_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-ext_command_method) macro.

An extension command is defined as follows:

## Parameters

### `_Name`

The name of the extension command. This must be the same as the *_Name* parameter that is used to declare the extension command by using [EXT_COMMAND_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-ext_command_method).

Because EXT_COMMAND is a macro, *_Name* must be the bare name of the extension command and should not be enclosed in quotation marks or be a variable.

### `_Desc`

A string describing the extension command.

### `_Args`

A string describing the arguments that are expected by the extension command. For information about how the *_Args* string is formatted, see [Parsing Extension Arguments](https://learn.microsoft.com/windows-hardware/drivers/debugger/parsing-extension-arguments).

**Note** As an alternative to supplying a string that describes the arguments, you can use the string "{{custom}}" to indicate that the extension command will parse the arguments itself. The method [GetRawArgStr](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/ff548226(v=vs.85)) can be used to fetch the raw argument for parsing.

## Remarks

The body of the extension command does not take any arguments. However, because the extension command is declared as a method of the [EXT_CLASS](https://learn.microsoft.com/previous-versions/ff544508(v=vs.85)) class, it has access to all the members of the [ExtExtension](https://learn.microsoft.com/previous-versions/ff543981(v=vs.85)) base class, some of which are initialized for the execution of the extension command.

The macro [EXT_COMMAND_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-ext_command_method) should be used to declare the extension command. As with all C++ declarations, the EXT_COMMAND_METHOD declaration should appear in the source files before the EXT_COMMAND definition.

When the debugger engine calls an extension command method, it wraps the call in a **try / except** block. This protects the engine from some types of bugs in the extension code; but, since the extension calls are executed in the same thread as the engine, they can still cause it to crash.

This macro also creates a function called *_Name* (which calls the method defined by the macro). In order for the engine to call the extension, this function must be exported from the extension library DLL.

The [EXT_CLASS](https://learn.microsoft.com/previous-versions/ff544508(v=vs.85)) constant specifies the name of the C++ class that represents the EngExtCpp extension library.

EXT_CLASS

```cpp
    #ifndef EXT_CLASS
    #define EXT_CLASS Extension
    #endif
```

The default value of [EXT_CLASS](https://learn.microsoft.com/previous-versions/ff544508(v=vs.85)) is **Extension**. You can change this value by defining EXT_CLASS before you include the header file Engextcpp.hpp.

Each extension command in the library is declared as a member of the class EXT_CLASS using the macro [EXT_COMMAND_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-ext_command_method). For example, a library with two extension commands, **extcmd** and **anotherextcmd**, could define the class EXT_CLASS as follows:

```
class EXT_CLASS : public ExtExtension
{
public:
    EXT_COMMAND_METHOD(extcmd);
    EXT_COMMAND_METHOD(anotherextcmd);
}
```

Extension commands that have been declared by using EXT_COMMAND_METHOD should be defined by using **EXT_COMMAND** and should be exported from the library.

The [EXT_DECLARE_GLOBALS](https://learn.microsoft.com/previous-versions/ff544527(v=vs.85)) macro creates a single instance of the EXT_CLASS class.

The [EXT_DECLARE_GLOBALS](https://learn.microsoft.com/previous-versions/ff544527(v=vs.85)) macro sets up some global variables for use by the EngExtCpp extension framework. This include creating a single instance of the [EXT_CLASS](https://learn.microsoft.com/previous-versions/ff544508(v=vs.85)) class that represents the EngExtCpp extension library.

One of the source files to be compiled into the EngExtCpp extension library should include the following command

```
EXT_DECLARE_GLOBALS()
```

## See also

[EXT_CLASS](https://learn.microsoft.com/previous-versions/ff544508(v=vs.85))

[EXT_COMMAND_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-ext_command_method)

[ExtExtension](https://learn.microsoft.com/previous-versions/ff543981(v=vs.85))