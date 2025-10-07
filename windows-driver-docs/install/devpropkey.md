# DEVPROPKEY structure

In Windows Vista and later versions of Windows, the DEVPROPKEY structure represents a device property key for a device property in the [unified device property model](https://learn.microsoft.com/windows-hardware/drivers/install/unified-device-property-model--windows-vista-and-later-).

## Members

**fmtid**
A DEVPROPGUID-typed value that specifies a property category.

The DEVPROPGUID data type is defined as:

```cpp
typedef GUID  DEVPROPGUID, *PDEVPROPGUID;
```

**pid**
A DEVPROPID-typed value that uniquely identifies the property within the property category. For internal system reasons, a property identifier must be greater than or equal to two.

The DEVPROPID data type is defined as:

```cpp
typedef ULONG DEVPROPID, *PDEVPROPID;
```

## Remarks

The DEVPROPKEY structure is part of the [unified device property model](https://learn.microsoft.com/windows-hardware/drivers/install/unified-device-property-model--windows-vista-and-later-).

The basic set of system-supplied device property keys are defined in *Devpkey.h*.

The [**DEFINE\_DEVPROPKEY**](https://learn.microsoft.com/windows-hardware/drivers/install/define-devpropkey) macro creates an instance of a DEVPROPKEY structure that represents a device property key.

## Requirements

|  |  |
| --- | --- |
| Header | Devpropdef.h (include Devpropdef.h) |

## See also

[**DEFINE\_DEVPROPKEY**](https://learn.microsoft.com/windows-hardware/drivers/install/define-devpropkey)

