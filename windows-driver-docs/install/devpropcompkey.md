# DEVPROPCOMPKEY structure

Describes a compound key for a device property.

## Members

`Key`

A [**DEVPROPKEY**](https://learn.microsoft.com/windows-hardware/drivers/install/devpropkey) structure that represents a key for a property.

`Store`

A **DEVPROPSTORE**-typed value that indicates the property store. Here are possible values:

| Value | Meaning |
| -- | -- |
| DEVPROP\_STORE\_SYSTEM | This value indicates to use the system wide property store. |
| DEVPROP\_STORE\_USER | This value indicates to use a property store specific to the current user. |

`LocaleName`

A string for the property's locale name.

## Requirements

|  |  |
| --- | --- |
| Header | Devpropdef.h |

## See also

[**DEVPROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/install/devproperty)