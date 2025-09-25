# INPUT_MESSAGE_ORIGIN_ID enumeration

## Description

The ID of the input message source.

## Constants

### `IMO_UNAVAILABLE:0x00000000`

The source isn't identified.

### `IMO_HARDWARE:0x00000001`

The input message is from a hardware device or has been injected into the message queue by an application that has the **UIAccess** attribute set to TRUE in its manifest file.

For more information about the **UIAccess** attribute and application manifests, see [UAC References](https://learn.microsoft.com/previous-versions/bb756883(v=msdn.10)).

### `IMO_INJECTED:0x00000002`

The input message has been injected (through the [SendInput](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendinput) function) by an application that doesn't have the **UIAccess** attribute set to TRUE in its manifest file.

### `IMO_SYSTEM:0x00000004`

The system has injected the input message.

## See also

[Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/input_sourceid/enumerations)