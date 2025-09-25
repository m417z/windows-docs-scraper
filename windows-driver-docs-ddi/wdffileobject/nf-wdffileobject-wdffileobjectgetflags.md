# WdfFileObjectGetFlags function

## Description

[Applies to KMDF only]

The **WdfFileObjectGetFlags** method returns the flags that a specified framework file object contains.

## Parameters

### `FileObject` [in]

A handle to a framework file object.

## Return value

**WdfFileObjectGetFlags** returns a bitwise OR of file object flags. The flag names have a format of FO_*XXX* and are defined in *Wdm.h*.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about framework file objects, see [Framework File Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-file-objects).

#### Examples

The following code example obtains the flags that a specified framework file object contains.

```cpp
ULONG flags;

flags = WdfFileObjectGetFlags(fileObject);
```