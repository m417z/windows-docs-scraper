# OP_POLICY_ELEMENT structure

Defines a registry key and a value name, type, and value that should be configured under that key.

## Members

### pKeyPath

Contains the path of the registry key.

### pValueName

Contains the name of the registry value.

### ulValueType

Contains one of the values from [Registry Value Types](https://learn.microsoft.com/windows/win32/sysinfo/registry-value-types).

### cbValueData

Contains the size of pValueData in bytes.

### ulValueType

Contains the value of the registry value.

## See also

[**Offline Domain Join IDL Definitions**](https://learn.microsoft.com/windows/win32/netmgmt/odj-idl)