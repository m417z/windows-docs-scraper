# NRESARRAY structure

## Description

Defines the CF_NETRESOURCE clipboard format.

## Members

### `cItems`

Type: **UINT**

The number of elements in the **nr** array.

### `nr`

Type: **[NETRESOURCE](https://learn.microsoft.com/windows/desktop/api/rrascfg/nn-rrascfg-ieapproviderconfig)[1]**

The array of [NETRESOURCE](https://learn.microsoft.com/windows/desktop/api/rrascfg/nn-rrascfg-ieapproviderconfig) structures that contain information about network resources. The string members (**LPSTR** types) in the structure contain offsets instead of addresses.