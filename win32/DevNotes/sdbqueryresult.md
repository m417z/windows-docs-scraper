# SDBQUERYRESULT structure

Contains the results from querying the shim database for a matching executable.

## Members

**atrExes**

The **TAGREF** values of the matching executable files. Note that **SDB\_MAX\_EXES** is defined as 16.

**adwExeFlags**

This parameter can be one or more of the following values.

**SHIMREG\_DISABLE\_SHIM** (0x00000001)

**SHIMREG\_DISABLE\_APPHELP** (0x00000002)

**SHIMREG\_APPHELP\_NOUI** (0x00000004)

**SHIMREG\_APPHELP\_CANCEL** (0x10000000)

**SHIMREG\_DISABLE\_SXS** (0x00000010)

**SHIMREG\_DISABLE\_LAYER** (0x00000020)

**SHIMREG\_DISABLE\_DRIVER** (0x00000040)

**atrLayers**

The **TAGREF** values of the matching layers. Note that **SDB\_MAX\_LAYERS** is defined as 8.

**dwLayerFlags**

This parameter can be one or more of the following values.

**SHIMREG\_DISABLE\_SHIM** (0x00000001)

**SHIMREG\_DISABLE\_APPHELP** (0x00000002)

**SHIMREG\_APPHELP\_NOUI** (0x00000004)

**SHIMREG\_APPHELP\_CANCEL** (0x10000000)

**SHIMREG\_DISABLE\_SXS** (0x00000010)

**SHIMREG\_DISABLE\_LAYER** (0x00000020)

**SHIMREG\_DISABLE\_DRIVER** (0x00000040)

**trApphelp**

The **TAGREF** value of the apphelp message of the corresponding executable.

**dwExeCount**

The number of elements in **atrExes**.

**dwLayerCount**

The number of elements in **atrLayers**.

**guidID**

The GUID of the last executable file.

**dwFlags**

This parameter can be one or more of the following values.

**SHIMREG\_DISABLE\_SHIM** (0x00000001)

**SHIMREG\_DISABLE\_APPHELP** (0x00000002)

**SHIMREG\_APPHELP\_NOUI** (0x00000004)

**SHIMREG\_APPHELP\_CANCEL** (0x10000000)

**SHIMREG\_DISABLE\_SXS** (0x00000010)

**SHIMREG\_DISABLE\_LAYER** (0x00000020)

**SHIMREG\_DISABLE\_DRIVER** (0x00000040)

**dwCustomSDBMap**

A map of the custom shim databases. The corresponding bits are set if **rgGuidDB** is valid.

**rgGuidDB**

The GUIDs of the shim databases. Note that **SDB\_MAX\_SDBS** is defined as 16.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |

## See also

[**SdbGetMatchingExe**](https://learn.microsoft.com/windows/win32/devnotes/sdbgetmatchingexe)

