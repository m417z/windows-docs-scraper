# OP_POLICY_ELEMENT_LIST structure

Defines a root registry key and an array of registry key elements to be configured under that key.

## Members

### pSource

Contains the path of the Group Policy file that the contained elements were sourced from.

### ulRootKeyId

Contains the identifier of the root registry key; currently must be set to HKEY_LOCAL_MACHINE.

### cElements

Contains the number of elements in pElements.

### pElements

Contains an array of OP_POLICY_ELEMENT elements.

## See also

[**Offline Domain Join IDL Definitions**](https://learn.microsoft.com/windows/win32/netmgmt/odj-idl)

[**OP\_POLICY\_ELEMENT**](https://learn.microsoft.com/windows/win32/netmgmt/odj-op_policy_element)