# ExtExtension::Initialize

## Description

The **Initialize** method is called by the engine to initialize an EngExtCpp extension library after loading it.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The extension library was successfully initialized. |

## Remarks

The extension library version number should be set by this method. This can be done by setting the members **m_ExtMajorVersion** and **m_ExtMinorVersion** of the base class [ExtExtension](https://learn.microsoft.com/previous-versions/ff543981(v=vs.85)).

The **ExtExtension** member **m_KnownStructs** should be set by this method to indicate to the engine which structures the extension library is capable of formatting for output.

If this method is defined in the extension library class [EXT_CLASS](https://learn.microsoft.com/previous-versions/ff544508(v=vs.85)), it can be used by the extension library to initialize any variables it requires.

There may or may not be a debugging session active when this function is called, so you should not assume that the extension can query session information.

## See also

[EXT_CLASS](https://learn.microsoft.com/previous-versions/ff544508(v=vs.85))

[ExtExtension](https://learn.microsoft.com/previous-versions/ff543981(v=vs.85))

[Uninitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledeviceclassextension/nf-portabledeviceclassextension-iportabledeviceclassextension-uninitialize)